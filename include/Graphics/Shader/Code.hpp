#ifndef  SHADER_CODE_HPP
# define SHADER_CODE_HPP

//# include <exception>
//# include <string>
//# include <fstream>
//# include "OpenGL/openGL.h"
# include "Miscellaneous/Container/Base.hpp"
# include "FileInfo.hpp"
# include <string>

#include "OpenGLTypes.hpp"



class FileInfo;

namespace Shader
{
class Code
{
	private:
	static GL::ShaderID None;

	private:
	public:
	GL::ShaderID ID;
	GL::ShaderType Type;
	FileInfo File;

	public:
	void LogInfo(bool self = true, bool log = false) const;



	public:
	Code();
	Code(const FileInfo & file);
	~Code();

	Code(const Shader::Code & other);
	Code & operator=(const Shader::Code & other);



	public:
	bool Valid() const;
	void Dispose();
	void Compile();
	void Attach(GL::ShaderID ProgramID) const;
	void Detach(GL::ShaderID ProgramID) const;

	public:
	static bool Valid(Container::Base<Shader::Code> & code);
	static void Dispose(Container::Base<Shader::Code> & code);
	static void Compile(Container::Base<Shader::Code> & code);
	static void Attach(Container::Base<Shader::Code> & code, GL::ShaderID ProgramID);
	static void Detach(Container::Base<Shader::Code> & code, GL::ShaderID ProgramID);

	private:
	static GL::ShaderType ShaderTypeFromExtension(const FileInfo & file);
};
};

#endif