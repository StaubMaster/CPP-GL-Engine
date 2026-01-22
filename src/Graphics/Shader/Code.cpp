#include "Graphics/Shader/Code.hpp"
#include "FileInfo.hpp"
#include "FileExceptions.hpp"

#include "OpenGL/openGL.h"
#include "Debug.hpp"
#include <sstream>



ShaderID Shader::Code::None = 0;
int Shader::Code::GetShaderiv(ShaderID ID, unsigned int name)
{
	int params;
	glGetShaderiv(ID, name, &params);
	return params;
}



void Shader::Code::LogInfo(bool self, bool log) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "Shader Info\n";
		Debug::Log << Debug::TabInc;
	}
	//Debug::Log << Debug::Tabs << "Type " << typeid(*this).name() << '\n';
	Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	Debug::Log << Debug::Tabs << "Type: " << Type << '\n';
	Debug::Log << Debug::Tabs << "File: " << File.Path.ToString() << '\n';
	{
		if (ID != None)
		{
			int len = GetShaderiv(ID, GL_INFO_LOG_LENGTH);
			Debug::Log << Debug::Tabs << "InfoLog: " << len << '\n';
			if (log && len != 0)
			{
				char str[len];
				glGetShaderInfoLog(ID, len, &len, str);
				Debug::Log << "####\n";
				Debug::Log << str;
				Debug::Log << "####\n";
			}
			unsigned int status = GetShaderiv(ID, GL_COMPILE_STATUS);
			Debug::Log << Debug::Tabs << "Status: " << status << '\n';
		}
		else
		{
			Debug::Log << Debug::Tabs << "InfoLog:\n";
			Debug::Log << Debug::Tabs << "Status:\n";
		}
	}
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}



Shader::Code::Code() :
	ID(0),
	Type(0),
	File()
{ }
Shader::Code::Code(const FileInfo & file) :
	ID(0),
	Type(ShaderTypeFromExtension(file)),
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



bool Shader::Code::Valid() const
{
	if (ID == None) { return false; }
	if (GetShaderiv(ID, GL_INFO_LOG_LENGTH) != 0) { return false; }
	if (GetShaderiv(ID, GL_COMPILE_STATUS) == 0) { return false; }
	return true;
}
void Shader::Code::Dispose()
{
	if (ID == None) { return; }
	//Debug::Log << "Shader::Code Disposing " << ID << " ..." << Debug::Done;
	glDeleteShader(ID);
	ID = None;
	//Debug::Log << "Shader::Code Disposing " << ID << " done" << Debug::Done;
}
void Shader::Code::Compile()
{
	if (ID != None) { return; }

	//Debug::Log << "Shader::Code Compiling " << ID << " ..." << Debug::Done;
	ID = glCreateShader(Type);

	{
		std::string code = File.LoadText();
		const char * strs[1];
		strs[0] = code.c_str();
		glShaderSource(ID, 1, strs, NULL);
	}
	glCompileShader(ID);

	/*char log_arr[1024];
	int log_len = 0;
	glGetShaderInfoLog(ID, 1024, &log_len, log_arr);
	if (log_len != 0)
	{
		std::string log = std::string(log_arr, log_len);
		throw ECompileLog(log, File.Path.ToString());
	}*/

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

bool Shader::Code::Valid(Container::Base<Shader::Code> & code)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		if (!code[i].Valid()) { return false; }
	}
	return true;
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



ShaderType Shader::Code::ShaderTypeFromExtension(const FileInfo & file)
{
	std::string ext = file.Extension();
	ShaderType type;
	if      (ext == ".glsg") { throw (file.Path.ToString()); }
	else if (ext == ".vert") { type = GL_VERTEX_SHADER; }
	else if (ext == ".geom") { type = GL_GEOMETRY_SHADER; }
	else if (ext == ".frag") { type = GL_FRAGMENT_SHADER; }
	else { throw InvalidExtension(file.Path.ToString()); }
	return type;
}
