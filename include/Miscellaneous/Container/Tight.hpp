#ifndef  CONTAINER_TIGHT_HPP
# define CONTAINER_TIGHT_HPP

# include "Base.hpp"

namespace Container
{

template<typename T>
class Tight : public Base<T>
{
	public:
	Tight() :
		Base<T>(Behaviour::EIncrease::Fit, Behaviour::EDecrease::Fit, Behaviour::EMemory::Copy)
	{ }
	virtual ~Tight()
	{ }

	Tight(const Tight<T> & other) : Base<T>(other)
	{ }
	Tight & operator=(const Tight<T> & other)
	{
		Base<T>::operator=(other);
		return *this;
	}
};
};

#endif