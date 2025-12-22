#include "Graphics/Shader/Base.hpp"
#include "Graphics/Shader/Code.hpp"
#include "Graphics/Uniform/Base/Base.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



Shader::Base::Base() :
	ID(0),
	Code(),
	Uniforms()
{ }
Shader::Base::Base(Container::Base<Shader::Code> code) :
	ID(0),
	Code(code),
	Uniforms()
{ }
Shader::Base::~Base()
{ }

Shader::Base::Base(const Shader::Base & other) :
	ID(other.ID),
	Code(other.Code),
	Uniforms(other.Uniforms)
{ }
Shader::Base & Shader::Base::operator=(const Shader::Base & other)
{
	ID = other.ID;
	Code = other.Code;
	Uniforms = other.Uniforms;
	return *this;
}



bool Shader::Base::IsCompiled() const { return (ID != 0); }
bool Shader::Base::IsBound() const { return (Bound() == ID); }
void Shader::Base::Bind()
{
	if (!IsBound())
	{
		glUseProgram(ID);
		UniformsUpdate();
	}
}

int Shader::Base::Bound()
{
	int ID;
	glGetIntegerv(GL_CURRENT_PROGRAM, &ID);
	return ID;
}
void Shader::Base::BindNone()
{
	glUseProgram(0);
}



void Shader::Base::Dispose()
{
	if (ID == 0) { return; }

	Debug::Log << "Shader::Base Disposing " << ID << " ..." << Debug::Done;
	glDeleteProgram(ID);
	ID = 0;
	Uniforms.Dispose();
	/*
		this should probably also tell the Uniforms that the Shader is gone
	*/
	Debug::Log << "Shader::Base Disposing " << ID << " done" << Debug::Done;
}
void Shader::Base::Compile()
{
	if (ID != 0) { return; }

	Debug::Log << "Shader::Base Compiling " << ID << " ..." << Debug::Done;
	ID = glCreateProgram();

	Shader::Code::Compile(Code);
	Shader::Code::Attach(Code, ID);
	glLinkProgram(ID);
	Shader::Code::Detach(Code, ID);
	Shader::Code::Dispose(Code);

	char log_arr[1024];
	int log_len = 0;
	glGetShaderInfoLog(ID, 1024, &log_len, log_arr);
	if (log_len != 0)
	{
		std::string log = std::string(log_arr, log_len);
		throw ECompileLog(log);
	}

	Debug::Log << "Shader::Base Compiling " << ID << " done" << Debug::Done;
}

Shader::Base Shader::Base::Compiled(Container::Base<Shader::Code> & code)
{
	Shader::Base shader(code);
	shader.Compile();
	return shader;
}



void Shader::Base::UniformsUpdate()
{
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniforms[i] -> PutMultiformData();
	}
}
int Shader::Base::UniformFind(const std::string & name) const
{
	int location = glGetUniformLocation(ID, name.c_str());
	Debug::Log << "Shader " << ID << " Uniform " << name << " found at " << location << "." << Debug::Done;
	return location;
}



Shader::Base::ECompileLog::ECompileLog(const std::string log)
{
	Log = log;
	Text = "Log returned from compiling File.\n\n" + Log;
}
const char * Shader::Base::ECompileLog::what() const throw()
{
	return Text.c_str();
}
