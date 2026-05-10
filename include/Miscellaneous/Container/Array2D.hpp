#ifndef  ARRAY_2D_HPP
# define ARRAY_2D_HPP

# include "ValueType/Vector/U2.hpp"
# include "Exception.hpp"

/* individual Axis
	LengthN are already
	operator[]
	Constructors
	ChangeSize()
	these would just convert to/from the Vector
*/

/* default Value
	pass to a seperate mNew()
	only needed for Items that dont have a default Constructor
	so just base Types like int and Pointers
*/

template<typename ItemType>
struct Array2D
{
	// basically like shaderd_ptr
	// but that one dosent have operator[] until 17 ?

	private:
	ItemType *		_Data = nullptr;
	unsigned int *	_Know = nullptr;
	VectorU2		_Size;

	public:
	bool				IsNull() const	{ return (_Data == nullptr); }
			ItemType *	Data()			{ return _Data; }
	const	ItemType *	Data() const	{ return _Data; }

	public:
	VectorU2		Size() const	{ return _Size; }
//	unsigned int	LengthX() const	{ return _Size.X; }
//	unsigned int	LengthY() const	{ return _Size.Y; }
	unsigned int	Length() const	{ return _Size.Product(); }

	// bool IsValid(VectorU2)
	// bool Check(VectorU2)
	// bool CheckIndex(VectorU2)

	public:
			ItemType &	At(unsigned int idx)		{ return _Data[idx]; }
	const	ItemType &	At(unsigned int idx) const	{ return _Data[idx]; }
			ItemType &	At(VectorU2 idx)			{ return _Data[_Size.Convert(idx)]; }
	const	ItemType &	At(VectorU2 idx) const		{ return _Data[_Size.Convert(idx)]; }

	public:
			ItemType &	operator[](unsigned int idx)		{ if ((idx < _Size.Product())) { return _Data[idx]; } throw Container::Exception::InvalidIndex(); }
	const	ItemType &	operator[](unsigned int idx) const	{ if ((idx < _Size.Product())) { return _Data[idx]; } throw Container::Exception::InvalidIndex(); }
			ItemType &	operator[](VectorU2 idx)			{ if ((idx < _Size).All(true)) { return _Data[_Size.Convert(idx)]; } throw Container::Exception::InvalidIndex(); }
	const	ItemType &	operator[](VectorU2 idx) const		{ if ((idx < _Size).All(true)) { return _Data[_Size.Convert(idx)]; } throw Container::Exception::InvalidIndex(); }
	// individual Axis

	private:
	void	mForget()
	{
		if (_Know != nullptr)
		{
			(*_Know)--;
		}
		_Data = nullptr;
		_Know = nullptr;
		_Size = VectorU2();
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
		}
	}
	void	mNew(VectorU2 size)
	{
		_Data = new ItemType[size.Product()];
		_Know = new unsigned int; (*_Know) = 0;
		_Size = size;
	}
	// default Value

	private:
	void	mBind(const Array2D & other)
	{
		_Data = other._Data;
		_Know = other._Know;
		_Size = other._Size;
		if (_Know != nullptr) { (*_Know)++; }
	}
	void	mCopy(const Array2D & other)
	{
		unsigned int n = _Size.Product();;
		if (n < other._Size.Product()) { n = other._Size.Product(); }
		for (unsigned int i = 0; i < n; i++)
		{
			_Data[i] = other._Data[i];
		}
	}

	public:
	~Array2D()
	{
		mDelete();
	}
	Array2D()
	{
	}
	Array2D(VectorU2 size)
	{
		mNew(size);
	}
	// individual Axis
	// default Value

	public:
	Array2D(const Array2D & other)
	{
		mBind(other);
	}
	Array2D & operator=(const Array2D & other)
	{
		mDelete();
		mBind(other);
		return *this;
	}

	public:
	void		Bind(const Array2D & other)
	{
		mDelete();
		mBind(other);
	}
	void		Copy(const Array2D & other)
	{
		mDelete();
		mNew(other._Size);
		mCopy(other);
	}
	Array2D		Bind() const
	{
		Array2D other;
		other.Bind(*this);
		return other;
	}
	Array2D		Copy() const
	{
		Array2D other;
		other.Copy(*this);
		return other;
	}

	public:
	void	Clear()
	{
		mDelete();
		mForget();
	}
	void	ChangeSize(VectorU2 size)
	{
		mDelete();
		mNew(size);
	}
	// individual Axis
	// default Value
};

#endif