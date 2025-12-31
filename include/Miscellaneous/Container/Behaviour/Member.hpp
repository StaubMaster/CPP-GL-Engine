#ifndef  CONTAINER_BEHAVIOUR_MEMBER_HPP
# define CONTAINER_BEHAVIOUR_MEMBER_HPP

namespace Container
{

template<typename T>
static void swap(T & a, T & b)
{
	T t;
	t = a;
	a = b;
	b = t;
}

namespace Behaviour
{

template<typename T>
struct Member
{
	typedef T * Pointer;

	unsigned int &	Limit;
	unsigned int &	Count;
	Pointer &		Data;

	Member() = delete;
	Member(unsigned int & limit, unsigned int & count, Pointer & data) :
		Limit(limit),
		Count(count),
		Data(data)
	{ }

	Member(const Member & other) :
		Limit(other.Limit),
		Count(other.Count),
		Data(other.Data)
	{ }
	Member & operator=(const Member & other) = delete;
};



template<typename T>
struct ConstMember
{
	typedef const T * Pointer;

	const unsigned int &	Limit;
	const unsigned int &	Count;
	const Pointer &			Data;

	ConstMember() = delete;
	ConstMember(const unsigned int & limit, const unsigned int & count, const Pointer & data) :
		Limit(limit),
		Count(count),
		Data(data)
	{ }

	ConstMember(const ConstMember & other) :
		Limit(other.Limit),
		Count(other.Count),
		Data(other.Data)
	{ }
	ConstMember & operator=(const ConstMember & other) = delete;
};

};
};

#endif