#include "Graphics/Shader/Code.hpp"
#include "FileContext.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



Shader::Code::Code() :
	ID(0),
	Type(0)
{ }
Shader::Code::Code(const FileContext & file) :
	ID(0),
	Type(ShaderTypeFromExtension(file.Extension())),
	File(file)
{ }
Shader::Code::~Code()
{ }



Shader::Code::Code(const Shader::Code & other) :
	ID(other.ID),
	Type(other.Type),
	File(other.File)
{ }
Shader::Code & Shader::Code::operator=(const Shader::Code & other)
{
	ID = other.ID;
	Type = other.Type;
	File = other.File;
	return *this;
}



void Shader::Code::Dispose()
{
	Debug::Log << "Shader::Code Dispose " << ID << Debug::Done;
	std::cout << "Shader::Code Dispose " << ID << '\n';
	glDeleteShader(ID);
	ID = 0;
}
void Shader::Code::Dispose(Container::Base<Shader::Code> & code)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		code[i].Dispose();
	}
}

void Shader::Code::Compile()
{
	ID = glCreateShader(Type);
	Debug::Log << "Compiling Shader::Code " << ID << " ..." << Debug::Done;
	std::string code = File.LoadText();
	const char * arr[1] = {
		code.c_str(),
	};
	glShaderSource(ID, 1, arr, NULL);
	glCompileShader(ID);

	char log_arr[1024];
	int log_len = 0;
	glGetShaderInfoLog(ID, 1024, &log_len, log_arr);
	if (log_len != 0)
	{
		std::string log = std::string(log_arr, log_len);
		throw ECompileLog(log, File.Path.ToString());
	}
	Debug::Log << "Compiling Shader::Code " << ID << " done" << Debug::Done;
}
void Shader::Code::Compile(Container::Base<Shader::Code> & code)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		code[i].Compile();
	}
}



int Shader::Code::getID() const
{
	return ID;
}

void Shader::Code::Attach(int ProgramID) const
{
	glAttachShader(ProgramID, ID);
}
void Shader::Code::Detach(int ProgramID) const
{
	glDetachShader(ProgramID, ID);
}





Shader::Code::ECompileLog::ECompileLog(const std::string log, const std::string path)
{
	Log = log;
	Path = path;
	Text = "Log returned from compiling File '" + Path + "'.\n\n" + Log;
}
const char * Shader::Code::ECompileLog::what() const throw()
{
	return Text.c_str();
}



GLenum Shader::Code::ShaderTypeFromExtension(const FileContext & file)
{
	std::string ext = file.Extension();
	GLenum type;
	if      (ext == ".glsg") { throw EInvalidFileExtention(file.Path.ToString()); }
	else if (ext == ".vert") { type = GL_VERTEX_SHADER; }
	else if (ext == ".geom") { type = GL_GEOMETRY_SHADER; }
	else if (ext == ".frag") { type = GL_FRAGMENT_SHADER; }
	else { throw EInvalidFileExtention(file.Path.ToString()); }
	return type;
}

Shader::Code::EInvalidFileExtention::EInvalidFileExtention(const std::string & path)
{
	Path = path;
	Text = "File '" + Path + "' has an invalid Extention.";
}
const char * Shader::Code::EInvalidFileExtention::what() const throw()
{
	return Text.c_str();
}
