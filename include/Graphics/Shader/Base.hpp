#ifndef  SHADER_BASE_HPP
# define SHADER_BASE_HPP

# include "Miscellaneous/Container/Base.hpp"
# include "Miscellaneous/Container/Dynamic.hpp"
# include <string>

namespace Uniform
{
	class Base;
};

namespace Shader
{
class Code;

class Base
{
	private:
	int ID;
	Container::Base<Shader::Code> Code;	// these are the Shaders. the whole class is technically a Shader Program
	public:
	Container::Dynamic<Uniform::Base*> Uniforms;



	public:
	Base();
	Base(Container::Base<Shader::Code> code);
	virtual ~Base();

	Base(const Shader::Base & other);
	Base & operator=(const Shader::Base & other);



	public:
	bool IsCompiled() const;
	bool IsBound() const;
	void Bind();

	static int Bound();
	static void BindNone();



	public:
	void Dispose();
	void Compile();

	static Shader::Base Compiled(Container::Base<Shader::Code> & code);



	public:
	void UniformsUpdate();
	int UniformFind(const std::string & name) const;

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