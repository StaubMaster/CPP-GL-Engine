#ifndef  CONTAINER_DYNAMIC_HPP
# define CONTAINER_DYNAMIC_HPP

# include "Base.hpp"
# include "Behaviour.hpp"

namespace Container
{

template<typename T>
class Dynamic : public Base<T>
{
	protected:
	unsigned int _Count;
	IncreaseBehaviour IncB;
	DecreaseBehaviour DecB;



	public:
	unsigned int Count() const override { return _Count; }

	public:
	T & operator[](unsigned int idx) override
	{
		if (idx >= _Count) { throw ExceptionInvalidIndex(); }
		return this -> _Data[idx];
	}
	const T & operator[](unsigned int idx) const override
	{
		if (idx >= _Count) { throw ExceptionInvalidIndex(); }
		return this -> _Data[idx];
	}



	public:
	virtual void DebugInfo() override { }

	public:
	Dynamic() : Base<T>()
	{
		_Count = 0;
		IncB = IncreaseBehaviour::Binary;
		DecB = DecreaseBehaviour::Binary;
	}
	Dynamic(IncreaseBehaviour incB, DecreaseBehaviour decB) : Base<T>()
	{
		_Count = 0;
		IncB = incB;
		DecB = decB;
	}
	Dynamic(unsigned int limit, IncreaseBehaviour incB, DecreaseBehaviour decB) : Base<T>(limit)
	{
		_Count = 0;
		IncB = incB;
		DecB = decB;
	}
	virtual ~Dynamic()
	{
	}

	Dynamic(const Base<T> & other) : Base<T>(other)
	{
		_Count = this -> _Limit;
		IncB = IncreaseBehaviour::Binary;
		DecB = DecreaseBehaviour::Binary;
	}
	Dynamic & operator=(const Base<T> & other)
	{
		Dispose();
		this -> _Limit = other._Limit;
		this -> _Count = other._Limit;
		this -> _Data = new T[this -> _Limit];
		for (unsigned int i = 0; i < _Count; i++)
		{
			this -> _Data[i] = other._Data[i];
		}
		this -> Deletable = true;
		IncB = IncreaseBehaviour::Binary;
		DecB = DecreaseBehaviour::Binary;
		return *this;
	}
	Dynamic(const Dynamic<T> & other) : Base<T>(other)
	{
		_Count = other._Count;
		IncB = other.IncB;
		DecB = other.DecB;
	}
	Dynamic & operator=(const Dynamic<T> & other)
	{
		Dispose();
		this -> _Limit = other._Limit;
		this -> _Count = other._Count;
		this -> _Data = new T[this -> _Limit];
		for (unsigned int i = 0; i < _Count; i++)
		{
			this -> _Data[i] = other._Data[i];
		}
		this -> Deletable = true;
		IncB = IncreaseBehaviour::Binary;
		DecB = DecreaseBehaviour::Binary;
		return *this;
	}



	public:
	void Dispose() override
	{
		Base<T>::Dispose();
		_Count = 0;
	}
	void ResizeLimit(unsigned int limit) override
	{
		if (limit != this -> _Limit)
		{
			Base<T> other(limit);
			Base<T>::CopyData(*this, other, _Count);
			other.Swap(*this);
		}
	}
	void Trim()
	{
		if (_Count < this -> _Limit)
		{
			this -> ResizeLimit(_Count);
		}
	}

	/*	Gapped Copying
			used for optimized Copying when Removing / Inserting
			Inserting is currenty only done at the end
			Removing can happen anywhere

			Inserting inserts a Gap, for the new Data
			Removing  removes a Gap, from the Data

			during this, limit might change

		the simple way of doing this is
			use Container with larger size
			copy everything directly
			then insert gaps one by one

		handle the Size change somewhere else ?
	*/
	void InsertGap(Entry gap)
	{
		//	done in reverse, else it would override
		if (_Count != 0)
		{
			for (unsigned int i = _Count - 1; i >= gap.Offset; i--)
			{
				this -> _Data[i + gap.Length] = this -> _Data[i];
			}
		}
		_Count = _Count + gap.Length;
	}
	void RemoveGap(Entry gap)
	{
		for (unsigned int i = gap.Offset; i < _Count; i++)
		{
			this -> _Data[i] = this -> _Data[i + gap.Length];
		}
		_Count = _Count - gap.Length;
	}



	private:
	unsigned int IncLimit(unsigned int wanted_count)
	{
		if (IncB == IncreaseBehaviour::None)	{ return this -> _Limit; }
		if (IncB == IncreaseBehaviour::Fit)		{ return wanted_count; }
		if (IncB == IncreaseBehaviour::Binary)	{ return BinarySize(wanted_count); }
		return this -> _Limit;
	}
	unsigned int DecLimit(unsigned int wanted_count)
	{
		if (DecB == DecreaseBehaviour::None)	{ return this -> _Limit; }
		if (DecB == DecreaseBehaviour::Fit)		{ return wanted_count; }
		if (DecB == DecreaseBehaviour::Binary)	{ return BinarySize(wanted_count); }
		return this -> _Limit;
	}

	public:
	bool	Insert(T * items, unsigned int items_count)
	{
		unsigned int idx = _Count;
		unsigned int newCount = _Count + items_count;
		unsigned int newLimit = IncLimit(newCount);
		this -> ResizeLimit(newLimit);
		this -> InsertGap(Entry(_Count, 0));
		if (idx + items_count > this -> _Limit)
		{
			return false;
		}
		Base<T>::CopyData(items, 0, this -> _Data, _Count, items_count);
		_Count = newCount;
		return true;
	}
	bool	Insert(T item)
	{
		return Insert(&item, 1);
	}
	bool	Remove(Entry entry)
	{
		if (entry.Limit() > _Count) { throw ExceptionInvalidIndex(); }
		unsigned int newCount = this -> _Count - entry.Length;
		unsigned int newLimit = DecLimit(newCount);
		this -> RemoveGap(entry);
		this -> ResizeLimit(newLimit);
		this -> _Count = newCount;
		return true;
	}
	bool	Remove(unsigned int idx)
	{
		return Remove(Entry(idx, 1));
	}
};

};

#endif