#include "Graphics/Shader/Code.hpp"
#include "FileInfo.hpp"
#include "FileExceptions.hpp"

#include "OpenGL.hpp"
#include "Debug.hpp"
#include <sstream>



void Shader::Code::LogInfo(bool self, bool log) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "Shader Info\n";
		Debug::Log << Debug::TabInc;
	}
	//Debug::Log << Debug::Tabs << "Type " << typeid(*this).name() << '\n';
	Debug::Log << Debug::Tabs << "ID: " << ID << '\n';
	Debug::Log << Debug::Tabs << "Type: " << ((unsigned int)Type) << '\n';
	Debug::Log << Debug::Tabs << "File: " << File.Path.ToString() << '\n';
	{
		if (ID != 0)
		{
			int len = GL::GetShaderiv(ID, GL::ShaderParameterName::InfoLogLength);
			Debug::Log << Debug::Tabs << "InfoLog: " << len << '\n';
			if (log && len != 0)
			{
				char str[len];
				glGetShaderInfoLog(ID, len, &len, str);
				Debug::Log << "####\n";
				Debug::Log << str;
				Debug::Log << "####\n";
			}
			unsigned int status = GL::GetShaderiv(ID, GL::ShaderParameterName::CompileStatus);
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
	Type((GL::ShaderType)0),
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
	if (ID == 0) { return false; }
	if (GL::GetShaderiv(ID, GL::ShaderParameterName::InfoLogLength) != 0) { return false; }
	if (GL::GetShaderiv(ID, GL::ShaderParameterName::CompileStatus) == 0) { return false; }
	return true;
}
void Shader::Code::Dispose()
{
	if (ID == 0) { return; }
	//Debug::Log << "Shader::Code Disposing " << ID << " ..." << Debug::Done;
	GL::DeleteShader(ID);
	ID = 0;
	//Debug::Log << "Shader::Code Disposing " << ID << " done" << Debug::Done;
}
void Shader::Code::Compile()
{
	if (ID != 0) { return; }

	//Debug::Log << "Shader::Code Compiling " << ID << " ..." << Debug::Done;
	ID = GL::CreateShader(Type);

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
void Shader::Code::Attach(GL::ShaderID ProgramID) const
{
	//Debug::Log << "Shader::Code Attaching " << ID << " to " << ProgramID << " ..." << Debug::Done;
	glAttachShader(ProgramID, ID);
	//Debug::Log << "Shader::Code Attaching " << ID << " to " << ProgramID << " done" << Debug::Done;
}
void Shader::Code::Detach(GL::ShaderID ProgramID) const
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
void Shader::Code::Attach(Container::Base<Shader::Code> & code, GL::ShaderID ProgramID)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		code[i].Attach(ProgramID);
	}
}
void Shader::Code::Detach(Container::Base<Shader::Code> & code, GL::ShaderID ProgramID)
{
	for (unsigned int i = 0; i < code.Count(); i++)
	{
		code[i].Detach(ProgramID);
	}
}



GL::ShaderType Shader::Code::ShaderTypeFromExtension(const FileInfo & file)
{
	std::string ext = file.Extension();
	GL::ShaderType type;
	if      (ext == ".glsg") { throw (file.Path.ToString()); }
	else if (ext == ".vert") { type = GL::ShaderType::VertexShader; }
	else if (ext == ".geom") { type = GL::ShaderType::GeometryShader; }
	else if (ext == ".frag") { type = GL::ShaderType::FragmentShader; }
	else { throw InvalidExtension(file.Path.ToString()); }
	return type;
}
