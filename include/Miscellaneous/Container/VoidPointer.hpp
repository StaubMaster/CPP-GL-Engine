#ifndef  CONTAINER_VOID_POINTER_HPP
# define CONTAINER_VOID_POINTER_HPP

# include "VoidPointerBase.hpp"

namespace Container
{
template<typename T>
class VoidPointer : public Container::VoidPointerBase
{
	private:
	unsigned int	_Size;
	T *				_Data;

	public:
	unsigned int VoidSize() const override { return _Size; }
	const void * VoidData() const override { return _Data; }
	void * VoidData() override { return _Data; }

	public:
	unsigned int Limit() const { return _Size / sizeof(T); }
	unsigned int Count() const { return _Size / sizeof(T); }

	public:
	const T & operator[](unsigned int idx) const
	{
		return _Data[idx];
	}
	T & operator[](unsigned int idx)
	{
		return _Data[idx];
	}

	public:
	VoidPointer() :
		_Size(0),
		_Data(0)
	{ }
	VoidPointer(unsigned int count) :
		_Size(count * sizeof(T)),
		_Data(new T[count])
	{ }
	VoidPointer(unsigned int count, T * data) :
		_Size(count * sizeof(T)),
		_Data((T*)data)
	{ }
	VoidPointer(unsigned int count, const T * data) :
		_Size(count * sizeof(T)),
		_Data((T*)data)
	{ }
	VoidPointer(unsigned int size, void * data) :
		_Size(size),
		_Data((T*)data)
	{ }
	VoidPointer(unsigned int size, const void * data) :
		_Size(size),
		_Data((T*)data)
	{ }
	~VoidPointer()
	{ }

	VoidPointer(const VoidPointer & other) :
		_Size(other._Size),
		_Data(other._Data)
	{ }
	VoidPointer & operator=(const VoidPointer & other)
	{
		_Size = other._Size;
		_Data = other._Data;
		return *this;
	}

	void Delete() override
	{
		delete[] _Data;
		_Data = 0;
		_Size = 0;
	}
};
};

#endif