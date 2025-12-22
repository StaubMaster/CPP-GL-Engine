#ifndef  SHADER_CODE_HPP
# define SHADER_CODE_HPP

//# include <exception>
//# include <string>
//# include <fstream>
//# include "OpenGL/openGL.h"
# include "Miscellaneous/Container/Base.hpp"
# include "FileContext.hpp"
# include <string>

typedef unsigned int GLenum;

namespace Shader
{
class Code
{
	private:
	int ID;
	GLenum Type;
	FileContext File;

	public:
	Code();
	Code(const FileContext & file);
	~Code();

	Code(const Shader::Code & other);
	Code & operator=(const Shader::Code & other);

	public:
	void Dispose();
	static void Dispose(Container::Base<Shader::Code> & code);

	public:
	void Compile();
	static void Compile(Container::Base<Shader::Code> & code);

	public:
	int getID() const;

	public:
	void Attach(int ProgramID) const;
	void Detach(int ProgramID) const;

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
	static GLenum ShaderTypeFromExtension(const FileContext & file);
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