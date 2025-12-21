#ifndef  SHADER_CODE_HPP
# define SHADER_CODE_HPP

//# include <exception>
//# include <string>
//# include <fstream>
//# include "FileManager/FileContext.hpp"
//# include "OpenGL/openGL.h"
# include "Miscellaneous/Container/Base.hpp"
# include <string>

typedef unsigned int GLenum;
class FileContext;

namespace Shader
{
class Code
{
	private:
	int ID;
	std::string Path;

	public:
	Code();
	private:
	Code(GLenum type, const std::string code, std::string path);
	public:
	~Code();

	Code(const Shader::Code & other);
	Code & operator=(const Shader::Code & other);

	public:
	void Dispose();
	static void Dispose(Container::Base<Shader::Code> & code);

	public:
	int getID() const;
	public:
	void Attach(int ProgramID) const;
	void Detach(int ProgramID) const;

	private:
	void Compile(const std::string code);

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

	public:
	static Code * FromFile(const FileContext & file);

	private:
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