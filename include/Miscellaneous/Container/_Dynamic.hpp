#ifndef  CONTAINER_DYNAMIC_HPP
# define CONTAINER_DYNAMIC_HPP

# include "Base.hpp"

namespace Container
{

template<typename T>
class Dynamic : public Base<T>
{
	public:
	virtual void DebugInfo() override { }

	public:
	Dynamic() :
		Base<T>(Behaviour::EIncrease::Binary, Behaviour::EDecrease::Binary, Behaviour::EMemory::Copy)
	{ }

	Dynamic(Behaviour::EIncrease incB, Behaviour::EDecrease decB) :
		Base<T>(incB, decB, Behaviour::EMemory::Copy)
	{ }
	/*Dynamic(unsigned int limit, Behaviour::EIncrease incB, Behaviour::EDecrease decB) :
		Base<T>(limit, incB, decB)
	{ }*/

	virtual ~Dynamic()
	{ }

	Dynamic(const Dynamic<T> & other) : Base<T>(other)
	{ }
	Dynamic & operator=(const Dynamic<T> & other)
	{
		Base<T>::operator=(other);

		//this -> Dispose();
		//Behaviour::Member<T> member(this -> ToBehaviour());
		//Behaviour::Delete(member, this -> MemB);
		//this -> _Limit = other._Limit;
		//this -> _Count = other._Count;
		//this -> _Data = new T[this -> _Limit];
		//for (unsigned int i = 0; i < this -> _Count; i++)
		//{
		//	this -> _Data[i] = other._Data[i];
		//}
		//this -> IncB = Behaviour::EIncrease::Binary;
		//this -> DecB = Behaviour::EDecrease::Binary;
		//this -> MemB = Behaviour::EMemory::Copy;
	
		return *this;
	}

	public:
	/*void Dispose() override
	{
		Base<T>::Dispose();
		this -> _Count = 0;
	}*/
	/*void ResizeLimit(unsigned int limit) override
	{
		if (limit != this -> _Limit)
		{
			Base<T> other(limit);
			other.IncB = this -> IncB;
			other.DecB = this -> DecB;
			other.DisposeB = this -> DisposeB;
			Base<T>::CopyData(*this, other, this -> _Count);
			other.Swap(*this);
		}
	}*/
};
};

#endif