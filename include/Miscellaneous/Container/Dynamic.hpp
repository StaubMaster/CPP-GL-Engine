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
		Dynamic() : Base<T>()
		{
			_Count = 0;
			IncB = IncreaseBehaviour::None;
			DecB = DecreaseBehaviour::None;
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
		Dynamic(const Base<T> & other) : Base<T>(other)
		{
			_Count = this -> _Limit;
			IncB = IncreaseBehaviour::None;
			DecB = DecreaseBehaviour::None;
		}
		Dynamic(const Dynamic<T> & other) : Base<T>(other)
		{
			_Count = other._Count;
			IncB = other.IncB;
			DecB = other.DecB;
		}
		virtual ~Dynamic()
		{ }

	public:
		unsigned int Count() const { return _Count; }

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
		//	changes Limit to fit Count. ignores Behaviour
		void Trim()
		{
			if (_Count < this -> _Limit)
			{
				this -> ResizeLimit(_Count, _Count);
			}
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

	private: // not fully tested
		unsigned int	Insert(T * items, unsigned int items_count)
		{
			unsigned int idx = _Count;

			unsigned int newCount = _Count + items_count;
			unsigned int newLimit = IncLimit(newCount);
			this -> ResizeLimit_GapNew(newLimit, _Count, Entry(_Count, 0));
			if (idx + items_count > this -> _Limit)
			{
				return 0xFFFFFFFF;
			}
			Base<T>::Copy(items_count, items, 0, this -> _Data, _Count);
			_Count = newCount;
			return idx;
		}
	public:
		unsigned int	Insert(T item)
		{
			return Insert(&item, 1);
		}
	private: // not fully tested
		T				Remove(Entry entry)
		{
			if (entry.Max() > _Count) { throw ExceptionInvalidIndex(); }

			T item = this -> _Data[entry.Offset];

			unsigned int newCount = this -> _Count - entry.Length;
			unsigned int newLimit = DecLimit(newCount);
			this -> ResizeLimit_GapOld(newLimit, _Count, entry);

			this -> _Count = newCount;

			return item; // should return array but dont feel like handling that right now
		}
	public:
		T				Remove(unsigned int idx)
		{
			return Remove(Entry(idx, 1));
		}
};

};

#endif