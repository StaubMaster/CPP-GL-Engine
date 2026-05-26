#ifndef  MULTIFORM_BASE_HPP
# define MULTIFORM_BASE_HPP

#include "Miscellaneous/Container/Array.hpp"
#include <string>

namespace Uniform { class Layout; class Base; };

namespace Multiform
{

class Base;

class Base
{
	public:
	std::string Name;

	protected:
	virtual ~Base();
	Base(std::string name);

	public:
	virtual void FindUniforms(Container::Array<Uniform::Layout *> & layouts) = 0;
	virtual void PutUniformData(Uniform::Base * uni_base) = 0;
};
};

#endif