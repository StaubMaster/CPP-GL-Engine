#ifndef  SHADER_BASE_HPP
# define SHADER_BASE_HPP

# include "Miscellaneous/Container/Fixed.hpp"
# include "Miscellaneous/Container/Binary.hpp"
# include <string>
//# include <iosfwd>



typedef unsigned int ShaderID;
//std::ostream & operator<<(std::ostream & o, const ShaderID & val);

namespace Uniform { class Base; };

namespace Shader
{
class Code;

class Base
{
	private:
	static ShaderID None;
	static int GetProgramiv(ShaderID ID, unsigned int name);

	private:
	ShaderID ID;
	Container::Fixed<Shader::Code> Code;	// these are the Shaders. the whole class is technically a Shader Program
	public:
	Container::Binary<Uniform::Base*> Uniforms;

	public:
	void LogInfo(bool self = true, bool log = false) const;
	//void LogInfo(bool dent, bool code, bool uniforms, bool log) const;



	public:
	Base();
	Base(Container::Base<Shader::Code> code);
	virtual ~Base();

	Base(const Shader::Base & other);
	Base & operator=(const Shader::Base & other);



	public:
	bool IsBound() const;
	void Bind();

	static ShaderID Bound();
	static void BindNone();



	public:
	bool Validate() const;
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