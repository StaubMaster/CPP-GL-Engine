#ifndef  SHADER_BASE_HPP
# define SHADER_BASE_HPP

# include "Miscellaneous/Container/Array.hpp"
# include "Miscellaneous/Container/Binary.hpp"
# include <string>
//# include <iosfwd>

# include "OpenGLTypes.hpp"



//std::ostream & operator<<(std::ostream & o, const GL::ShaderID & val);

class FileInfo;

namespace Uniform { class Layout; };

namespace Shader
{
class Code;

class Base
{
	private:
	GL::ShaderProgramID				ID;
	Container::Array<Shader::Code>	Code;
	public:
	Uniform::Layout *				UniformLayout;

	public:
	void LogInfo(bool self = true, bool log = false) const;
	//void LogInfo(bool dent, bool code, bool uniforms, bool log) const;



	public:
	virtual ~Base();
	Base();
	//Base(Container::Base<Shader::Code> code);

	Base(const Shader::Base & other);
	Base & operator=(const Shader::Base & other);



	public:
	bool	IsBound() const;
	void	Bind();

	static GL::ShaderID	Bound();
	static void			BindNone();



	public:
	bool	Validate() const;
	bool	Exists() const;
	void	Delete();
	void	Create();

	void	Change(const Container::Array<Shader::Code> & code);
	void	Change(const Container::Array<FileInfo> & files);
	void	Change(std::initializer_list<Shader::Code> code);
	void	Change(std::initializer_list<FileInfo> files);



	public:
	// return UniformLocation
	GL::UniformLocation		UniformLocation(const char * name) const;
	GL::BlockIndex			UniformBlockIndex(const char * name) const;

	void	UniformBlockBinding(GL::BlockIndex index, GL::BlockBinding binding);



	class ECompileLog : std::exception
	{
		private:
		std::string Log;
		std::string Text;

		public:
		ECompileLog(const std::string log);

		public:
		const char * what() const throw();
	};
};
};

#endif