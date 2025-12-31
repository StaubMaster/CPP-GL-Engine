#ifndef  CONTAINER_POINTER_HPP
# define CONTAINER_POINTER_HPP

# include "Base.hpp"

namespace Container
{

template<typename T>
class Pointer : public Base<T>
{
	public:
	Pointer() :
		Base<T>(Behaviour::EIncrease::None, Behaviour::EDecrease::None, Behaviour::EMemory::Bind)
	{ }
	Pointer(unsigned int limit) :
		Base<T>(limit, limit, Behaviour::EIncrease::None, Behaviour::EDecrease::None, Behaviour::EMemory::Bind)
	{ }
	Pointer(unsigned int limit, T * data) :
		Base<T>(limit, limit, data, Behaviour::EIncrease::None, Behaviour::EDecrease::None, Behaviour::EMemory::Bind)
	{ }
	virtual ~Pointer()
	{ }

	Pointer(const Pointer<T> & other) : Base<T>(other)
	{ }
	Pointer & operator=(const Pointer<T> & other)
	{
		Base<T>::operator=(other);
		return *this;
	}
};
};

#endif