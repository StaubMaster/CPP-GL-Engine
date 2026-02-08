#ifndef  CONTAINER_MEMBBER_HPP
# define CONTAINER_MEMBBER_HPP

# include "Void.hpp"
# include "Exception.hpp"
# include "Behaviour/Member.hpp"



namespace Container
{
template<typename T>
class Member : public Void
{
	protected:
	unsigned int	_Limit;
	unsigned int	_Count;
	T *				_Data;



	public:
	unsigned int VoidLimit() const override { return _Limit * sizeof(T); }
	unsigned int VoidCount() const override { return _Count * sizeof(T); }

	const void * VoidData() const override { return _Data; }
	void * VoidData() override { return _Data; }



	public:
	Container::Behaviour::Member<T> ToBehaviour()
	{
		return Container::Behaviour::Member<T>(_Limit, _Count, _Data);
	}
	Container::Behaviour::ConstMember<T> ToBehaviour() const
	{
		return Container::Behaviour::ConstMember<T>(_Limit, _Count, _Data);
	}



	public:
	unsigned int Limit() const override { return _Limit; }
	unsigned int Count() const override { return _Count; }

	const T * Data() const { return _Data; }
	T * Data() { return _Data; }

	const T & At(unsigned int idx) const { return _Data[idx]; }
	T & At(unsigned int idx) { return _Data[idx]; }

	const T & operator[](unsigned int idx) const
	{
		if (idx >= _Count) { throw Exception::InvalidIndex(); }
		return _Data[idx];
	}
	T & operator[](unsigned int idx)
	{
		if (idx >= _Count) { throw Exception::InvalidIndex(); }
		return _Data[idx];
	}



	public:
	Member() :
		_Limit(0),
		_Count(0),
		_Data(0)
	{ }

	/*Member(unsigned int size, void * data) :
		_Limit(size / sizeof(T)),
		_Count(size / sizeof(T)),
		_Data((T*)data)
	{ }*/
	/*Member(unsigned int size, const void * data) :
		_Limit(size / sizeof(T)),
		_Count(size / sizeof(T)),
		_Data((T*)data)
	{ }*/

	/*Member(unsigned int limit) :
		_Limit(limit),
		_Count(limit),
		_Data(new T[limit])
	{ }*/
	/*Member(unsigned int limit, T * data) :
		_Limit(limit),
		_Count(limit),
		_Data((T*)data)
	{ }*/
	/*Member(unsigned int limit, const T * data) :
		_Limit(limit),
		_Count(limit),
		_Data((T*)data)
	{ }*/

	Member(unsigned int limit, unsigned int count) :
		_Limit(limit),
		_Count(count),
		_Data(new T[limit])
	{ }
	Member(unsigned int limit, unsigned int count, T * data) :
		_Limit(limit),
		_Count(count),
		_Data((T*)data)
	{ }
	/*Member(unsigned int limit, unsigned int count, const T * data) :
		_Limit(limit),
		_Count(count),
		_Data((T*)data)
	{ }*/

	~Member()
	{ }

	public:
	Member(const Member & other) :
		_Limit(other._Limit),
		_Count(other._Count),
		_Data(other._Data)
	{ }
	Member & operator=(const Member & other)
	{
		_Limit = other._Limit;
		_Count = other._Count;
		_Data = other._Data;
		return *this;
	}

	void Swap(Member<T> & other)
	{
		swap(_Limit, other._Limit);
		swap(_Count, other._Count);
		swap(_Data, other._Data);
	}

	/*void Bind(const Member<T> & other)
	{
		_Limit = other._Limit;
		_Count = other._Count;
		_Data = other._Data;
	}*/
	/*void Copy(const Member<T> & other)
	{
		_Limit = other._Limit;
		_Count = other._Count;
		//_Data = new;
	}*/
};
};

#endif