#ifndef  BINARY_HPP
# define BINARY_HPP

# include "Array.hpp"

template<typename TypeItem> struct Binary
{
	private:
	Array<TypeItem>		mData;
	unsigned long		mUsed = 0;

	public:
	bool					IsNull() const		{ return (mData.IsNull()); }
	const	Array<TypeItem>	Data() const		{ return mData; }

	public:
	unsigned long	Limit() const	{ return mData.Length(); }
	unsigned long	Count() const	{ return mUsed; }

	public:
	bool			Check(unsigned long idx) const	{ return (idx < Count()); }

	public:
	const	TypeItem &	At(unsigned long idx) const	{ return mData.At(idx); }
			TypeItem &	At(unsigned long idx)		{ return mData.At(idx); }

	public:
	const	TypeItem &	operator[](unsigned long idx) const	{ if (Check(idx)) { return At(idx); } throw Container::Exception::InvalidIndex(); }
			TypeItem &	operator[](unsigned long idx)		{ if (Check(idx)) { return At(idx); } throw Container::Exception::InvalidIndex(); }

	public:
	~Binary()
	{
	}
	Binary()
	{
	}

	public:
	Binary(const Binary & other)
		: mData(other.mData)
		, mUsed(other.mUsed)
	{ }
	Binary & operator=(const Binary & other)
	{
		mData = other.mData;
		mUsed = other.mUsed;
		return *this;
	}

	public:
	void	Clear()
	{
		mData.Clear();
		mUsed = 0;
	}

	private:
	unsigned long	CalculateBinarySize(unsigned long wanted)
	{
		for (unsigned char shift = 63; shift < 64; shift--)
		{
			unsigned long size = 0xFFFFFFFFFFFFFFFF >> shift;
			if (size >= wanted)
			{
				return size;
			}
		}
		return 0;
	}

	public:
	void	Trim()
	{
		mData.NewLengthHere(mUsed);
	}
	void	MakeNativeSize()
	{
		mData.NewLengthHere(CalculateBinarySize(mUsed));
	}

	public:
	void	Insert(const TypeItem & item)
	{
		unsigned int newCount = mUsed + 1;
		unsigned int newLimit = CalculateBinarySize(newCount);

		mData.NewLengthHere(newLimit);

		if (newCount <= mData.Length())
		{
			mData.At(mUsed) = item;
			mUsed = newCount;
		}
	}
	void	RemoveAt(unsigned long idx)
	{
		if (idx >= mUsed)
		{
			throw Container::Exception::InvalidIndex();
		}

		unsigned int newCount = mUsed - 1;
		unsigned int newLimit = CalculateBinarySize(newCount);

		// remove gap
		for (unsigned long i = idx; (i + 1) < mUsed; i++)
		{
			mData.At(i) = mData.At(i + 1);
		}

		mData.NewLengthHere(newLimit);
		mUsed = newCount;
	}
};

#endif