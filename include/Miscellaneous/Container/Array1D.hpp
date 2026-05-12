#ifndef  ARRAY_1D_HPP
# define ARRAY_1D_HPP

# include "Exception.hpp"

/* default Value
	pass to a seperate mNew()
	only needed for Items that dont have a default Constructor
	so just base Types like int and Pointers
*/

//# include <iostream>

template<typename ItemType>
struct Array1D
{
	// basically like shaderd_ptr
	// but that one dosent have operator[] until 17 ?

	private:
	ItemType *		_Data = nullptr;
	unsigned int *	_Know = nullptr;
	unsigned int	_Size;

	public:
	bool				IsNull() const	{ return (_Data == nullptr); }
			ItemType *	Data()			{ return _Data; }
	const	ItemType *	Data() const	{ return _Data; }

	public:
	unsigned int	Size() const	{ return _Size; }
	unsigned int	Length() const	{ return _Size; }

	// bool IsValid(unsigned int)
	// bool Check(unsigned int)
	// bool CheckIndex(unsigned int)

	public:
			ItemType &	At(unsigned int idx)		{ return _Data[idx]; }
	const	ItemType &	At(unsigned int idx) const	{ return _Data[idx]; }

	public:
			ItemType &	operator[](unsigned int idx)		{ if ((idx < _Size)) { return _Data[idx]; } throw Container::Exception::InvalidIndex(); }
	const	ItemType &	operator[](unsigned int idx) const	{ if ((idx < _Size)) { return _Data[idx]; } throw Container::Exception::InvalidIndex(); }

	private:
	void	mDefault()
	{
		_Data = nullptr;
		_Know = nullptr;
		_Size = 0;
	}
	void	mDelete()
	{
		if (_Know != nullptr)
		{
			if ((*_Know) == 0)
			{
				delete _Know;
				delete[] _Data;
			}
			else
			{
				(*_Know)--;
			}
		}
	}
	void	mNew(unsigned int size)
	{
		_Data = new ItemType[size];
		_Know = new unsigned int; (*_Know) = 0;
		_Size = size;
	}
	void	mRemember(unsigned int size, ItemType * data)
	{
		_Data = data;
		_Know = nullptr;
		_Size = size;
	}
	// default Value

	private:
	void	mBind(const Array1D & other)
	{
		_Data = other._Data;
		_Know = other._Know;
		_Size = other._Size;
		if (_Know != nullptr) { (*_Know)++; }
	}
	void	mCopy(const Array1D & other)
	{
		unsigned int n = _Size;
		if (n < other._Size) { n = other._Size; }
		for (unsigned int i = 0; i < n; i++)
		{
			_Data[i] = other._Data[i];
		}
	}

	public:
	~Array1D()
	{
		mDelete();
	}
	Array1D()
	{
	}
	Array1D(unsigned int size)
	{
		mNew(size);
	}
	Array1D(unsigned int size, ItemType * data)
	{
		mRemember(size, data);
	}
	Array1D(unsigned int size, const ItemType * data)
	{
		mRemember(size, (ItemType*)data);
	}
	// default Value

	public:
	Array1D(const Array1D & other)
	{
		mBind(other);
	}
	Array1D & operator=(const Array1D & other)
	{
		mDelete();
		mBind(other);
		return *this;
	}

	public:
	void		Bind(const Array1D & other)
	{
		mDelete();
		mBind(other);
	}
	void		Copy(const Array1D & other)
	{
		mDelete();
		mNew(other._Size);
		mCopy(other);
	}
	Array1D		Bind() const
	{
		Array1D other;
		other.Bind(*this);
		return other;
	}
	Array1D		Copy() const
	{
		Array1D other;
		other.Copy(*this);
		return other;
	}

	public:
	void	Clear()
	{
		mDelete();
		mDefault();
	}
	void	ChangeSize(unsigned int size)
	{
		mDelete();
		mNew(size);
	}
	// default Value
};

#endif