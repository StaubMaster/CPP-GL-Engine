#include "Graphics/Shader/Base.hpp"
#include "Graphics/Shader/Code.hpp"
#include "Graphics/Uniform/Base/Base.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



Shader::Base::Base() :
	ID(0)
{ }
Shader::Base::Base(Container::Base<Code> code) :
	ID(0)
{
	Compile(code);
}
Shader::Base::~Base()
{ }



Shader::Base::Base(const Shader::Base & other) :
	ID(other.ID),
	Uniforms(other.Uniforms)
{ }
Shader::Base & Shader::Base::operator=(const Shader::Base & other)
{
	ID = other.ID;
	Uniforms = other.Uniforms;
	return *this;
}



void Shader::Base::Dispose()
{
	Debug::Log << "Shader::Base Dispose " << ID << Debug::Done;
	std::cout << "Shader::Base Dispose " << ID << '\n';
	glDeleteProgram(ID);
	ID = 0;
}

void Shader::Base::Compile(Container::Base<Code> & code)
{
	Shader::Code::Compile(code);

	ID = glCreateProgram();
	Debug::Log << "Compiling BaseShader " << ID << " ..." << Debug::Done;
	Debug::Log << "BaseShader " << ID << " using Code";
	for (unsigned int i = 0; i < code.Count(); i++) { Debug::Log << " " << code[i].getID(); }
	Debug::Log << Debug::Done;

	for (unsigned int i = 0; i < code.Count(); i++) { code[i].Attach(ID); }
	glLinkProgram(ID);
	for (unsigned int i = 0; i < code.Count(); i++) { code[i].Detach(ID); }

	char log_arr[1024];
	int log_len = 0;
	glGetShaderInfoLog(ID, 1024, &log_len, log_arr);
	if (log_len != 0)
	{
		std::string log = std::string(log_arr, log_len);
		throw ECompileLog(log);
	}
	Debug::Log << "Compiling BaseShader " << ID << " done" << Debug::Done;
}



void Shader::Base::Use()
{
	if (!Is())
	{
		glUseProgram(ID);
		UniformsUpdate();
	}
}
bool Shader::Base::Is() const
{
	return (Bound() == ID);
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
	if (location == -1)
	{
		Debug::Log << "Shader " << ID << " Uniform " << name << " not found." << Debug::Done;
	}
	else
	{
		Debug::Log << "Shader " << ID << " Uniform " << name << " found at " << location << "." << Debug::Done;
	}
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
