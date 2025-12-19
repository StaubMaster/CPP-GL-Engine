
#ifndef  SHADER_BASE_HPP
# define SHADER_BASE_HPP

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
	public:
	Container::Dynamic<Uniform::Base *> Uniforms;

	public:
	Base(const Code * code, int count);
	virtual ~Base();

	public:
	void Use();
	bool Is() const;

	public:
	void UniformsUpdate();
	int UniformFind(const std::string & name) const;

	private:
	void Compile(const Code * code, int count);

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
