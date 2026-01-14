#ifndef  CONTAINER_FIXED_HPP
# define CONTAINER_FIXED_HPP

# include "Base.hpp"

# include <iostream>

namespace Container
{

template<typename T>
class Fixed : public Base<T>
{
	public:
	Fixed() :
		Base<T>(Behaviour::EIncrease::None, Behaviour::EDecrease::None, Behaviour::EMemory::Copy)
	{
		std::cout << "  ++++  Fixed " << this << "\n";
	}
	Fixed(unsigned int limit) :
		Base<T>(limit, 0, Behaviour::EIncrease::None, Behaviour::EDecrease::None, Behaviour::EMemory::Copy)
	{
		std::cout << "  ++++  Fixed " << this << "\n";
	}
	virtual ~Fixed()
	{
		std::cout << "  ----  Fixed " << this << "\n";
	}

	Fixed(const Fixed<T> & other) : Base<T>(other)
	{
		std::cout << "  ++++  Fixed " << this << "\n";
	}
	Fixed & operator=(const Fixed<T> & other)
	{
		Base<T>::operator=(other);
		return *this;
	}

	void CopyHere(const Base<T> & other)
	{
		std::cout << "  Fixed  CopyHere " << this << "\n";
		Behaviour::Member<T> member(this -> ToBehaviour());
		Behaviour::ConstMember<T> member_other(other.ToBehaviour());
		Behaviour::Delete(member, this -> MemB);
		Behaviour::Assign(member, this -> MemB, member_other, Behaviour::EMemory::Copy);
		std::cout << "  Fixed  CopyHere " << this << " done\n";
	}
	static Fixed<T> Copy(const Base<T> & other)
	{
		Fixed<T> container;
		std::cout << "  Fixed  Copy " << &container << "\n";
		Behaviour::Member<T> member(container.ToBehaviour());
		Behaviour::ConstMember<T> member_other(other.ToBehaviour());
		Behaviour::Assign(member, container.MemB, member_other, Behaviour::EMemory::Copy);
		std::cout << "  Fixed  Copy " << &container << " done\n";
		return container;
	}
};
};

#endif