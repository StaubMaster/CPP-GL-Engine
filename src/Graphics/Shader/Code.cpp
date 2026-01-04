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
	if (ID == 0) { return; }
	//Debug::Log << "Shader::Code Disposing " << ID << " ..." << Debug::Done;
	glDeleteShader(ID);
	ID = 0;
	//Debug::Log << "Shader::Code Disposing " << ID << " done" << Debug::Done;
}
void Shader::Code::Compile()
{
	if (ID != 0) { return; }

	//Debug::Log << "Shader::Code Compiling " << ID << " ..." << Debug::Done;
	ID = glCreateShader(Type);

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

	//Debug::Log << "Shader::Code Compiling " << ID << " done" << Debug::Done;
}
void Shader::Code::Attach(ShaderID ProgramID) const
{
	//Debug::Log << "Shader::Code Attaching " << ID << " to " << ProgramID << " ..." << Debug::Done;
	glAttachShader(ProgramID, ID);
	//Debug::Log << "Shader::Code Attaching " << ID << " to " << ProgramID << " done" << Debug::Done;
}
void Shader::Code::Detach(ShaderID ProgramID) const
{
	//Debug::Log << "Shader::Code Detaching " << ID << " from " << ProgramID << " ..." << Debug::Done;
	glDetachShader(ProgramID, ID);
	//Debug::Log << "Shader::Code Detaching " << ID << " from " << ProgramID << " done" << Debug::Done;
}

void Shader::Code::Dispose(Container::Base<Shader::Code> & code)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		code[i].Dispose();
	}
}
void Shader::Code::Compile(Container::Base<Shader::Code> & code)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		code[i].Compile();
	}
}
void Shader::Code::Attach(Container::Base<Shader::Code> & code, ShaderID ProgramID)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		code[i].Attach(ProgramID);
	}
}
void Shader::Code::Detach(Container::Base<Shader::Code> & code, ShaderID ProgramID)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		code[i].Detach(ProgramID);
	}
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
