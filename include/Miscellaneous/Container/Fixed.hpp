#ifndef  CONTAINER_FIXED_HPP
# define CONTAINER_FIXED_HPP

# include "Base.hpp"

namespace Container
{

template<typename T>
class Fixed : public Base<T>
{
	public:
	Fixed() :
		Base<T>(Behaviour::EIncrease::None, Behaviour::EDecrease::None, Behaviour::EMemory::Copy)
	{ }
	Fixed(unsigned int limit) :
		Base<T>(limit, 0, Behaviour::EIncrease::None, Behaviour::EDecrease::None, Behaviour::EMemory::Copy)
	{ }
	virtual ~Fixed()
	{ }

	Fixed(const Fixed<T> & other) : Base<T>(other)
	{ }
	Fixed & operator=(const Fixed<T> & other)
	{
		Base<T>::operator=(other);
		return *this;
	}

	static Fixed<T> Copy(const Base<T> & other)
	{
		Fixed<T> container;
		Behaviour::Member<T> member(container.ToBehaviour());
		Behaviour::ConstMember<T> member_other(other.ToBehaviour());
		Behaviour::Assign(member, container.MemB, member_other, Behaviour::EMemory::Copy);
		return container;
	}
};
};

#endif