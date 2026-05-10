#ifndef  ARRAY_3D_HPP
# define ARRAY_3D_HPP

# include "ValueType/Vector/U3.hpp"
# include "Exception.hpp"

template<typename ItemType>
struct Array3D
{
	// basically like shaderd_ptr
	// but that one dosent have operator[] until 17 ?
	private:
	ItemType *		_Data = nullptr;
	unsigned int *	_Know = nullptr;
	VectorU3		_Size;

	public:
	bool				IsNull() const	{ return (_Data == nullptr); }
			ItemType *	Data()			{ return _Data; }
	const	ItemType *	Data() const	{ return _Data; }

	public:
	VectorU3		Size() const	{ return _Size; }
//	unsigned int	LengthX() const	{ return _Size.X; }
//	unsigned int	LengthY() const	{ return _Size.Y; }
//	unsigned int	LengthZ() const	{ return _Size.Z; }
	unsigned int	Length() const	{ return _Size.Product(); }

	public:
			ItemType &	At(unsigned int idx)		{ return _Data[idx]; }
	const	ItemType &	At(unsigned int idx) const	{ return _Data[idx]; }
			ItemType &	At(VectorU3 idx)			{ return _Data[_Size.Convert(idx)]; }
	const	ItemType &	At(VectorU3 idx) const		{ return _Data[_Size.Convert(idx)]; }

	public:
			ItemType &	operator[](unsigned int idx)		{ if ((idx < _Size.Product())) { return _Data[idx]; } throw Container::Exception::InvalidIndex(); }
	const	ItemType &	operator[](unsigned int idx) const	{ if ((idx < _Size.Product())) { return _Data[idx]; } throw Container::Exception::InvalidIndex(); }
			ItemType &	operator[](VectorU3 idx)			{ if ((idx < _Size).All(true)) { return _Data[_Size.Convert(idx)]; } throw Container::Exception::InvalidIndex(); }
	const	ItemType &	operator[](VectorU3 idx) const		{ if ((idx < _Size).All(true)) { return _Data[_Size.Convert(idx)]; } throw Container::Exception::InvalidIndex(); }

	private:
	void	mForget()
	{
		if (_Know != nullptr)
		{
			(*_Know)--;
		}
		_Data = nullptr;
		_Know = nullptr;
		_Size = VectorU3();
	}
	void	mDelete()
	{
		if (_Know != nullptr)
		{
			if ((*_Know) == 0)
			{
				delete _Know; _Know = nullptr;
				delete[] _Data;
			}
		}
	}
	void	mNew(VectorU3 size)
	{
		_Data = new ItemType[size.Product()];
		_Know = new unsigned int; (*_Know) = 0;
		_Size = size;
	}

	private:
	void	mBind(const Array3D & other)
	{
		_Data = other._Data;
		_Know = other._Know;
		_Size = other._Size;
		if (_Know != nullptr) { (*_Know)++; }
	}
	void	mCopy(const Array3D & other)
	{
		unsigned int n = _Size.Product();;
		if (n < other._Size.Product()) { n = other._Size.Product(); }
		for (unsigned int i = 0; i < n; i++)
		{
			_Data[i] = other._Data[i];
		}
	}

	public:
	~Array3D()
	{
		mDelete();
	}
	Array3D()
	{
	}
	Array3D(VectorU3 size)
	{
		mNew(size);
	}

	public:
	Array3D(const Array3D & other)
	{
		mBind(other);
	}
	Array3D & operator=(const Array3D & other)
	{
		mDelete();
		mBind(other);
		return *this;
	}

	public:
	void		Bind(const Array3D & other)
	{
		mDelete();
		mBind(other);
	}
	void		Copy(const Array3D & other)
	{
		mDelete();
		mNew(other._Size);
		mCopy(other);
	}
	Array3D		Bind() const
	{
		Array3D other;
		other.Bind(*this);
		return other;
	}
	Array3D		Copy() const
	{
		Array3D other;
		other.Copy(*this);
		return other;
	}

	public:
	void	Clear()
	{
		mDelete();
		mForget();
	}
	void	ChangeSize(VectorU3 size)
	{
		mDelete();
		mNew(size);
	}
};

#endif