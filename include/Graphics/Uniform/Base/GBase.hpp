
#ifndef  GENERIC_UNIFORM_BASE_HPP
# define GENERIC_UNIFORM_BASE_HPP

# include "Graphics/Uniform/Base/Base.hpp"

namespace Uniform
{
template <typename ValueType>
class GBase : public Uniform::Base // rename to TypeBase ?
{
	protected:
	virtual ~GBase() { }
	GBase(::Shader::Base & shader, std::string name)
		: Uniform::Base(shader, name)
	{ }

	protected:
	virtual void	Put(const ValueType & obj) = 0;
};
};

#endif
