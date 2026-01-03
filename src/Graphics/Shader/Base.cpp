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
	Code(Container::Fixed<Shader::Code>::Copy(code)),
	Uniforms()
{
	Create();
}
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



bool Shader::Base::IsBound() const { return (Bound() == ID); }
void Shader::Base::Bind()
{
	if (!IsBound())
	{
		glUseProgram(ID);
		for (unsigned int i = 0; i < Uniforms.Count(); i++)
		{
			Uniforms[i] -> PutMultiformData();
		}
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



bool Shader::Base::Exists() const { return (ID != 0); }
void Shader::Base::Delete()
{
	if (ID == 0) { return; }

	Debug::Log << "Shader::Base Deleting " << ID << " ..." << Debug::Done;
	glDeleteProgram(ID);
	ID = 0;
	Debug::Log << "Shader::Base Deleting " << ID << " done" << Debug::Done;

	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniforms[i] -> ReLocate();
	}
}
void Shader::Base::Create()
{
	if (ID != 0) { return; }

	Debug::Log << "Shader::Base Creating " << ID << " ..." << Debug::Done;
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

	Debug::Log << "Shader::Base Creating " << ID << " done" << Debug::Done;

	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniforms[i] -> ReLocate();
	}
}
void Shader::Base::Change(Container::Base<Shader::Code> code)
{
	if (Exists())
	{
		Delete();
		Code = Container::Fixed<Shader::Code>::Copy(code);
		Create();
	}
	else
	{
		Code = Container::Fixed<Shader::Code>::Copy(code);
	}
}



int Shader::Base::LocateUniform(const char * name)
{
	int location;
	if (Exists())
	{
		location = glGetUniformLocation(ID, name);
	}
	else
	{
		location = -1;
	}
	//Debug::Log << "Shader " << ID << " Uniform " << name << " found at " << location << "." << Debug::Done;
	Debug::Log << "Shader Uniform Location: " << '(' << ID << ')' << ' ' << '(' << name << ':' << location << ')' << Debug::Done;
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
