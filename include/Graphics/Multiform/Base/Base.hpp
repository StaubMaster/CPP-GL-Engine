#ifndef  MULTIFORM_BASE_HPP
# define MULTIFORM_BASE_HPP

#include "Miscellaneous/Container/Base.hpp"
#include <string>

namespace Shader { class Base; };

namespace Uniform { class Base; };

namespace Multiform
{

class Base;

class Base
{
	public:
	std::string Name;

	protected:
	Base(std::string name);
	~Base();

	public:
	virtual void FindUniforms(Container::Base<Shader::Base *> & shaders) = 0;
	virtual void PutUniformData(Uniform::Base * uni_base) = 0;
};
};

#endif