#ifndef  CONTAINER_BINARY_HPP
# define CONTAINER_BINARY_HPP

# include "Base.hpp"

namespace Container
{

template<typename T>
class Binary : public Base<T>
{
	public:
	Binary() :
		Base<T>(Behaviour::EIncrease::Binary, Behaviour::EDecrease::Binary, Behaviour::EMemory::Copy)
	{ }
	virtual ~Binary()
	{ }

	Binary(const Binary<T> & other) : Base<T>(other)
	{ }
	Binary & operator=(const Binary<T> & other)
	{
		Base<T>::operator=(other);
		return *this;
	}
};
};

#endif