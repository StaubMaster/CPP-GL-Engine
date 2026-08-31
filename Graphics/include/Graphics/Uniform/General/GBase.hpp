
#ifndef  GENERIC_UNIFORM_BASE_HPP
# define GENERIC_UNIFORM_BASE_HPP

# include "Graphics/Uniform/General/Base.hpp"

namespace Uniform
{
template <typename ValueType>
class GBase : public Base // rename to TypeBase ?
{
	protected:
	virtual ~GBase()
	{ }
	GBase() = delete;

	protected:
	GBase(Layout & layout, std::string name)
		: Base(layout, name)
	{ }

	public:
	void	PutVoid(const void * val) override
	{
		Put(*((const ValueType *)val));
	};
	virtual void	Put(const ValueType & obj) = 0;
};
};

#endif
