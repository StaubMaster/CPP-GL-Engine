#ifndef  SHADER_BASE_HPP
# define SHADER_BASE_HPP

# include "Miscellaneous/Container/Fixed.hpp"
# include "Miscellaneous/Container/Binary.hpp"
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
	Container::Fixed<Shader::Code> Code;	// these are the Shaders. the whole class is technically a Shader Program
	public:
	Container::Binary<Uniform::Base*> Uniforms;



	public:
	Base();
	Base(Container::Base<Shader::Code> code);
	virtual ~Base();

	Base(const Shader::Base & other);
	Base & operator=(const Shader::Base & other);



	public:
	bool IsBound() const;
	void Bind();

	static int Bound();
	static void BindNone();



	public:
	bool Exists() const;
	void Delete();
	void Create();
	void Change(Container::Base<Shader::Code> code);



	public:
	int LocateUniform(const char * name);



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