#ifndef  CONTAINER_BASE_HPP
# define CONTAINER_BASE_HPP

# include <exception>

# include "Entry.hpp"

/*	Base vs Dynamic ?

Base is kind of an Array ?
threat it like an Array ?
basically just a Wrapper for a Pointer ?

*/

namespace Container
{

class ExceptionInvalidIndex : public std::exception { const char * what() const noexcept { return "Index invalid."; } };

template<typename T>
class Base
{
	protected:
	unsigned int _Limit;
	T * _Data;
	private:
	protected:
	bool Deletable;



	public:
	unsigned int Limit() const { return _Limit; }
	virtual unsigned int Count() const { return _Limit; }
	const T * Data() const { return _Data; }

	T & At(unsigned int idx) { return _Data[idx]; }
	const T & At(unsigned int idx) const { return _Data[idx]; }

	virtual T & operator[](unsigned int idx)
	{
		if (idx >= _Limit) { throw ExceptionInvalidIndex(); }
		return _Data[idx];
	}
	virtual const T & operator[](unsigned int idx) const
	{
		if (idx >= _Limit) { throw ExceptionInvalidIndex(); }
		return _Data[idx];
	}

	public:
	virtual void DebugInfo() { }

	public:
	Base()
	{
		_Limit = 0;
		_Data = NULL;
		Deletable = false;
	}
	Base(unsigned int limit)
	{
		_Limit = limit;
		_Data = new T[_Limit];
		Deletable = true;
	}

	Base(const T * data, unsigned int limit)
	{
		_Limit = limit;
		_Data = (T *)data;
		Deletable = false;
	}
	~Base()
	{
		if (Deletable)
		{
			delete[] _Data;
		}
	}

	Base(const Base<T> & other)
	{
		_Limit = other._Limit;
		_Data = new T[_Limit];
		for (unsigned int i = 0; i < _Limit; i++)
		{
			_Data[i] = other._Data[i];
		}
		Deletable = true;
	}
	Base<T> & operator=(const Base<T> & other)
	{
		Dispose();
		_Limit = other._Limit;
		_Data = new T[_Limit];
		for (unsigned int i = 0; i < _Limit; i++)
		{
			_Data[i] = other._Data[i];
		}
		Deletable = true;
		return *this;
	}



	public:
	virtual void Dispose()
	{
		if (Deletable)
		{
			delete[] _Data;
		}
		_Limit = 0;
		_Data = NULL;
		Deletable = false;
	}
	void Allocate(unsigned int limit)
	{
		Dispose();
		_Limit = limit;
		_Data = new T[_Limit];
		Deletable = true;
	}
	void Swap(Base<T> & other)
	{
		unsigned int limit;
		limit = _Limit;
		_Limit = other._Limit;
		other._Limit = limit;

		T * data;
		data = _Data;
		_Data = other._Data;
		other._Data = data;

		bool deletable;
		deletable = Deletable;
		Deletable = other.Deletable;
		other.Deletable = deletable;
	}

	void Bind(Base<T> & other)
	{
		Dispose();
		_Limit = other._Limit;
		_Data = other._Data;
		Deletable = false;
	}
	void Bind(const T * data, unsigned int limit)
	{
		Dispose();
		_Limit = limit;
		_Data = data;
		Deletable = false;
	}

	static unsigned int CopyData(Base<T> & src, Base<T> & dst, unsigned int count)
	{
		if (count > src._Limit) { count = src._Limit; }
		if (count > dst._Limit) { count = dst._Limit; }
		for (unsigned int i = 0; i < count; i++)
		{
			dst._Data[i] = src._Data[i];
		}
		return count;
	}
	static unsigned int CopyData(Base<T> & src, unsigned int src_off, Base<T> & dst, unsigned int dst_off, unsigned int count)
	{
		if (count > (src._Limit - src_off)) { count = (src._Limit - src_off); }
		if (count > (dst._Limit - dst_off)) { count = (dst._Limit - dst_off); }
		for (unsigned int i = 0; i < count; i++)
		{
			dst._Data[dst_off + i] = src._Data[src_off + i];
		}
		return count;
	}
	static unsigned int CopyData(T * src, unsigned int src_off, T * dst, unsigned int dst_off, unsigned int count)
	{
		//if (count > (src._Limit - src_off)) { count = (src._Limit - src_off); }
		//if (count > (dst._Limit - dst_off)) { count = (dst._Limit - dst_off); }
		for (unsigned int i = 0; i < count; i++)
		{
			dst[dst_off + i] = src[src_off + i];
		}
		return count;
	}

	virtual void ResizeLimit(unsigned int limit)
	{
		if (limit != _Limit)
		{
			Base<T> other(limit);
			CopyData(*this, other, 0xFFFFFFFF);
			other.Swap(*this);
		}
	}



	private:
	/*	optimized for copying with gaps in both input and output
		gaps are the opposite of Entrys
		invert for copying Entrys ?
		gaps should be in order ?
	*/
	/*	Problem
			these require a new Container to copy into
			what it I need to do it in the same container ?
			have a seperate function for that
	*/
	static void CopyOrderedGaps(
		Base<T> & inn_container, Base<Entry> inn_gaps,
		Base<T> & out_container, Base<Entry> out_gaps,
		unsigned int count)
	{
		unsigned int inn_off = 0;
		unsigned int out_off = 0;
		unsigned int inn_gap_idx = 0;
		unsigned int out_gap_idx = 0;
		for (unsigned int idx = 0; idx < count; idx++)
		{
			if (inn_gap_idx < inn_gaps.Limit() && inn_off >= inn_gaps[inn_gap_idx].Offset)
			{
				inn_gap_idx++;
				if (inn_gap_idx < inn_gaps.Limit())
				{
					inn_off = inn_gaps[inn_gap_idx].Limit();
				}
			}
			if (out_gap_idx < out_gaps.Limit() && out_off >= out_gaps[out_gap_idx].Offset)
			{
				out_gap_idx++;
				if (out_gap_idx < out_gaps.Limit())
				{
					out_off = out_gaps[out_gap_idx].Limit();
				}
			}
			out_container[out_off] = inn_container[inn_off];
			inn_off++;
			out_off++;
		}
	}

	/*
		old_gaps : are removed
		new_gaps : are inserted
	*/
	static void CopyOrderedGaps(
		Base<T> & container,
		Base<Entry> old_gaps, Base<Entry> new_gaps,
		unsigned int count)
	{
		/*	Problem
			old_gaps require moving forewards
				else they override themselves
			new_gaps require moving backwards
				else they override themselves
		*/
		/*	
			# Item
			n (Number) Item
			+ new Gap
			- old Gap
			before:	######----##	012345----67
			after:	####++++####	0123++++4567
			
		*/
		(void)container;
		(void)old_gaps;
		(void)new_gaps;
		(void)count;
	}
};

};

#endif