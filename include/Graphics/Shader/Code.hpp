#ifndef  SHADER_CODE_HPP
# define SHADER_CODE_HPP

//# include <exception>
//# include <string>
//# include <fstream>
//# include "OpenGL/openGL.h"
# include "Miscellaneous/Container/Base.hpp"
# include "FileInfo.hpp"
# include <string>



typedef unsigned int ShaderID;
typedef unsigned int ShaderType;

class FileInfo;

namespace Shader
{
class Code
{
	private:
	public:
	ShaderID ID;
	ShaderType Type;
	FileInfo File;

	public:
	void LogInfo(bool self = true) const;



	public:
	Code();
	Code(const FileInfo & file);
	~Code();

	Code(const Shader::Code & other);
	Code & operator=(const Shader::Code & other);



	public:
	void Dispose();
	void Compile();
	void Attach(ShaderID ProgramID) const;
	void Detach(ShaderID ProgramID) const;

	public:
	static void Dispose(Container::Base<Shader::Code> & code);
	static void Compile(Container::Base<Shader::Code> & code);
	static void Attach(Container::Base<Shader::Code> & code, ShaderID ProgramID);
	static void Detach(Container::Base<Shader::Code> & code, ShaderID ProgramID);



	private:
	class ECompileLog : public std::exception
	{
		private:
		std::string Log;
		std::string Path;
		std::string Text;

		public:
		ECompileLog(const std::string log, const std::string path);

		public:
		const char * what() const throw();
	};

	private:
	static ShaderType ShaderTypeFromExtension(const FileInfo & file);
	class EInvalidFileExtention : std::exception
	{
		private:
		std::string Path;
		std::string Text;

		public:
		EInvalidFileExtention(const std::string & path);

		public:
		const char * what() const throw();
	};
};
};

#endif