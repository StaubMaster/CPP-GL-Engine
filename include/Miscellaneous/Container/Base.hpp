#ifndef  CONTAINER_BASE_HPP
# define CONTAINER_BASE_HPP

# include "Exception.hpp"
# include "Member.hpp"
# include "Behaviour.hpp"
# include "Entry.hpp"



namespace Container
{
template<typename T>
class Base : public Member<T>
{
	//protected:
	public:
	Container::Behaviour::EIncrease IncB;
	Container::Behaviour::EDecrease DecB;
	Container::Behaviour::EMemory MemB;
	//Container::Behaviour::EDispose DisposeB;
	//Container::Behaviour::EAssign AssignB;



	public:
	virtual void DebugInfo() { }

	public:
	Base() :
		Member<T>(),
		IncB(Behaviour::EIncrease::None),
		DecB(Behaviour::EDecrease::None),
		MemB(Behaviour::EMemory::Null)
	{ }

	Base(unsigned int limit) :
		Member<T>(limit, 0),
		IncB(Behaviour::EIncrease::None),
		DecB(Behaviour::EDecrease::None),
		MemB(Behaviour::EMemory::Copy)
	{ }
	/*Base(unsigned int limit, T * data) :
		Member<T>(limit, data),
		IncB(Behaviour::EIncrease::None),
		DecB(Behaviour::EDecrease::None),
		MemB(Behaviour::EMemory::Copy)
	{ }*/
	/*Base(unsigned int limit, const T * data) :
		Member<T>(limit, data),
		IncB(Behaviour::EIncrease::None),
		DecB(Behaviour::EDecrease::None),
		MemB(Behaviour::EMemory::Bind)
	{ }*/

	/*Base(unsigned int limit, unsigned int count) :
		Member<T>(limit, count),
		IncB(Behaviour::EIncrease::None),
		DecB(Behaviour::EDecrease::None),
		MemB(Behaviour::EMemory::Copy)
	{ }*/
	/*Base(unsigned int limit, unsigned int count, T * data) : Member<T>(limit, count, data)
	{
		Deletable = true;
	}*/
	/*Base(unsigned int limit, unsigned int count, const T * data) : Member<T>(limit, count, data)
	{
		Deletable = false;
	}*/

	/*Base(Container::Behaviour::EIncrease incB, Container::Behaviour::EDecrease decB) :
		Member<T>(),
		IncB(incB),
		DecB(decB),
		MemB(Behaviour::EMemory::Null)
	{ }*/
	/*Base(unsigned int limit, Behaviour::EIncrease incB, Behaviour::EDecrease decB) :
		Member<T>(limit),
		IncB(incB),
		DecB(decB),
		MemB(Behaviour::EMemory::Copy)
	{ }*/
	/*Base(unsigned int limit, unsigned int count, Behaviour::EIncrease incB, Behaviour::EDecrease decB) :
		Member<T>(limit, count),
		IncB(incB),
		DecB(decB),
		MemB(Behaviour::EMemory::Copy)
	{ }*/

	protected:
	/*Base(Behaviour::EMemory memB) :
		Member<T>(),
			IncB(Behaviour::EIncrease::None),
			DecB(Behaviour::EDecrease::None),
			MemB(memB)
	{ }*/
	Base(
		Behaviour::EIncrease incB,
		Behaviour::EDecrease decB,
		Behaviour::EMemory memB) :
		Member<T>(),
			IncB(incB),
			DecB(decB),
			MemB(memB)
	{ }
	Base(unsigned int limit, unsigned int count,
		Behaviour::EIncrease incB,
		Behaviour::EDecrease decB,
		Behaviour::EMemory memB) :
		Member<T>(limit, count),
			IncB(incB),
			DecB(decB),
			MemB(memB)
	{ }
	Base(unsigned int limit, unsigned int count, T * data,
		Behaviour::EIncrease incB,
		Behaviour::EDecrease decB,
		Behaviour::EMemory memB) :
		Member<T>(limit, count, data),
			IncB(incB),
			DecB(decB),
			MemB(memB)
	{ }

	public:
	~Base()
	{
		Behaviour::Member<T> member(this -> ToBehaviour());
		Behaviour::Delete(member, MemB);
	}

	Base(const Base<T> & other) : Member<T>()
	{
		Behaviour::Member<T> member(this -> ToBehaviour());
		Behaviour::ConstMember<T> other_member(other.ToBehaviour());
		Behaviour::Assign(member, MemB, other_member, other.MemB);

		//this -> _Limit = other._Limit;
		//this -> _Count = other._Count;
		//this -> _Data = new T[this -> _Limit];
		//for (unsigned int i = 0; i < this -> _Count; i++)
		//{
		//	this -> _Data[i] = other._Data[i];
		//}
		//IncB = other.IncB;
		//DecB = other.DecB;
		//DisposeB = other.DisposeB;
	}
	Base<T> & operator=(const Base<T> & other)
	{
		//Dispose();
		Behaviour::Member<T> member(this -> ToBehaviour());
		Behaviour::ConstMember<T> other_member(other.ToBehaviour());
		Behaviour::Delete(member, MemB);
		Behaviour::Assign(member, MemB, other_member, other.MemB);

		//this -> _Limit = other._Limit;
		//this -> _Count = other._Count;
		//this -> _Data = new T[this -> _Limit];
		//for (unsigned int i = 0; i < this -> _Count; i++)
		//{
		//	this -> _Data[i] = other._Data[i];
		//}
		//IncB = other.IncB;
		//DecB = other.DecB;
		//DisposeB = other.DisposeB;

		return *this;
	}

	//static Base<T> Bind() { return Base<T>(Behaviour::EMemory::Bind); }
	//static Base<T> Copy() { return Base<T>(Behaviour::EMemory::Copy); }

	public:
	void Dispose()
	{
		Behaviour::Member<T> member(this -> ToBehaviour());
		MemB = Behaviour::EMemory::Copy;
		Behaviour::Delete(member, MemB);
	}

	void Allocate(unsigned int limit)
	{
		Behaviour::Member<T> member(this -> ToBehaviour());
		Behaviour::Delete(member, MemB);
		Behaviour::Create(member, MemB, limit, 0);
	}

	void Swap(Base<T> & other)
	{
		Member<T>::Swap(other);
		swap(IncB, other.IncB);
		swap(DecB, other.DecB);
		swap(MemB, other.MemB);
	}

	//void AllocateBind(unsigned int limit);
	//void AllocateCopy(unsigned int limit);

	/*void Bind(const Base<T> & other)
	{
		Behaviour::Member<T> member(this -> ToBehaviour());
		Behaviour::Member<T> member_other(other.ToBehaviour());
		Behaviour::Delete(member, MemB);
		Behaviour::Assign(member, MemB, member_other, Behaviour::EMemory::Bind);
	}*/
	/*void Copy(const Base<T> & other)
	{
		Behaviour::Member<T> member(this -> ToBehaviour());
		Behaviour::Member<T> member_other(other.ToBehaviour());
		Behaviour::Delete(member, MemB);
		Behaviour::Assign(member, MemB, member_other, Behaviour::EMemory::Copy);
	}*/

	//static Base<T> Bind(unsigned int limit, T * data);
	//static Base<T> Copy(unsigned int limit, T * data);

	//static Base<T> Bind(unsigned int limit, unsigned int count, T * data);
	//static Base<T> Copy(unsigned int limit, unsigned int count, T * data);



	protected:
	/*static unsigned int CopyData(Base<T> & src, Base<T> & dst, unsigned int count)
	{
		if (count > src._Limit) { count = src._Limit; }
		if (count > dst._Limit) { count = dst._Limit; }
		for (unsigned int i = 0; i < count; i++)
		{
			dst._Data[i] = src._Data[i];
		}
		return count;
	}*/
	/*static unsigned int CopyData(Base<T> & src, unsigned int src_off, Base<T> & dst, unsigned int dst_off, unsigned int count)
	{
		if (count > (src._Limit - src_off)) { count = (src._Limit - src_off); }
		if (count > (dst._Limit - dst_off)) { count = (dst._Limit - dst_off); }
		for (unsigned int i = 0; i < count; i++)
		{
			dst._Data[dst_off + i] = src._Data[src_off + i];
		}
		return count;
	}*/
	static unsigned int CopyData(const T * src, unsigned int src_off, T * dst, unsigned int dst_off, unsigned int count)
	{
		//if (count > (src._Limit - src_off)) { count = (src._Limit - src_off); }
		//if (count > (dst._Limit - dst_off)) { count = (dst._Limit - dst_off); }
		for (unsigned int i = 0; i < count; i++)
		{
			dst[dst_off + i] = src[src_off + i];
		}
		return count;
	}



	public:
	void ResizeLimit(unsigned int limit)
	{
		Behaviour::Member<T> member(this -> ToBehaviour());
		Behaviour::Resize(member, MemB, limit);
		//if (limit != this -> _Limit)
		//{
		//	Base<T> other(limit, this -> _Count);
		//	other.IncB = IncB;
		//	other.DecB = DecB;
		//	other.MemB = MemB;
		//	CopyData(*this, other, this -> _Count);
		//	other.Swap(*this);
		//}
	}
	void Trim()
	{
		if (this -> _Count < this -> _Limit)
		{
			this -> ResizeLimit(this -> _Count);
		}
	}



	public:
	void InsertGap(Entry gap)
	{
		//	done in reverse, else it would override
		if (this -> _Count != 0)
		{
			for (unsigned int i = this -> _Count - 1; i >= gap.Offset; i--)
			{
				this -> _Data[i + gap.Length] = this -> _Data[i];
			}
		}
	}
	bool Insert(Entry entry, const T * items)
	{
		Behaviour::Member<T> member(this -> ToBehaviour());

		unsigned int newLimit = Behaviour::IncreaseLimit(IncB, member, entry.Limit());
		Behaviour::Resize(member, this -> MemB, newLimit);
		this -> InsertGap(entry);

		if (entry.Limit() > this -> _Limit) { return false; }
		Base<T>::CopyData(items, 0, this -> _Data, entry.Offset, entry.Length);
		this -> _Count = entry.Limit();

		return true;
	}
	bool Insert(T item)
	{
		return Insert(Entry(this -> _Count, 1), &item);
	}
	bool Insert(const Base<T> & other)
	{
		return Insert(Entry(this -> _Count, other._Count), other._Data);
	}



	public:
	void RemoveGap(Entry gap)
	{
		for (unsigned int i = gap.Offset; i < this -> _Count; i++)
		{
			this -> _Data[i] = this -> _Data[i + gap.Length];
		}
	}
	bool Remove(Entry entry)
	{
		if (entry.Limit() > this -> _Count) { throw Exception::InvalidIndex(); }
		Behaviour::Member<T> member(this -> ToBehaviour());

		unsigned int newCount = this -> _Count - entry.Length;
		//unsigned int newLimit = DecLimit(newCount);
		unsigned int newLimit = Behaviour::DecreaseLimit(this -> DecB, member, newCount);

		this -> RemoveGap(entry);
		//this -> ResizeLimit(newLimit);
		Behaviour::Resize(member, this -> MemB, newLimit);

		this -> _Count = newCount;
		return true;
	}
	bool Remove(unsigned int idx)
	{
		return Remove(Entry(idx, 1));
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
	/*static void CopyOrderedGaps(
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
	}*/

	private:
	/*
		old_gaps : are removed
		new_gaps : are inserted
	*/
	/*static void CopyOrderedGaps(
		Base<T> & container,
		Base<Entry> old_gaps, Base<Entry> new_gaps,
		unsigned int count)
	{
		//	Problem
		//	old_gaps require moving forewards
		//		else they override themselves
		//	new_gaps require moving backwards
		//		else they override themselves

		//	# Item
		//	n (Number) Item
		//	+ new Gap
		//	- old Gap
		//	before:	######----##	012345----67
		//	after:	####++++####	0123++++4567

		(void)container;
		(void)old_gaps;
		(void)new_gaps;
		(void)count;
	}*/
};
};

#endif