#ifndef  CONTAINER_BEHAVIOUR_DATA_HPP
# define CONTAINER_BEHAVIOUR_DATA_HPP

# include "Member.hpp"

namespace Container
{
namespace Behaviour
{
enum class EMemory
{
	Null,	//	currently NULL
	Copy,	//	every Object has its own Memory Pointer
	Bind,	//	every Object has the same Memory Pointer
};

template<typename T>
void Delete(Member<T> & member, EMemory & memory)
{
	if (memory == EMemory::Copy)
	{
		delete[] member.Data;
	}
	member.Limit = 0;
	member.Count = 0;
	member.Data = 0;
	memory = EMemory::Null;
}

template<typename T>
void Create(Member<T> & member, EMemory & memory, unsigned int limit, unsigned int count)
{
	member.Limit = limit;
	member.Count = count;
	member.Data = new T[limit];
	if (memory == EMemory::Null)
	{ memory = EMemory::Copy; }
}

template<typename T>
void Assign(Member<T> & member, EMemory & memory, const ConstMember<T> & member_other, const EMemory & memory_other)
{
	if (memory_other == EMemory::Bind)
	{
		member.Limit = member_other.Limit;
		member.Count = member_other.Count;
		member.Data = (T*)member_other.Data;

		if (memory == EMemory::Null)
		{ memory = EMemory::Bind; }
	}
	else if (memory_other == EMemory::Copy)
	{
		member.Limit = member_other.Limit;
		member.Count = member_other.Count;
		member.Data = new T[member.Limit];
		if (memory == EMemory::Null)
		{ memory = EMemory::Copy; }

		for (unsigned int i = 0; i < member.Count; i++)
		{
			member.Data[i] = member_other.Data[i];
		}
	}
}

template<typename T>
void Resize(Member<T> & member, EMemory & memory, unsigned int limit)
{
	//	if Bind, make Copy
	if (limit == member.Limit) { return; }

	T * data = new T[limit];

	unsigned int count = member.Count;
	if (limit < count) { count = limit; }
	for (unsigned int i = 0; i < count; i++)
	{
		data[i] = member.Data[i];
	}

	if (memory == Behaviour::EMemory::Copy)
	{
		delete[] (member.Data);
	}
	else
	{
		memory = Behaviour::EMemory::Copy;
	}

	member.Limit = limit;
	member.Count = count;
	member.Data = data;
}

/*	Change(limit, count, * data)
{
	Limit = limit
	Count = count
	if (data != 0)
	{ Data = data }
	else if (limit != 0)
	{ Data = new [limit] }
	else
	{ Data = 0 }
}
*/

};
};


#endif