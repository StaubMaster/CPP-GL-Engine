#ifndef  CONTAINER_DYNAMIC_HPP
# define CONTAINER_DYNAMIC_HPP

# include "DebugDefines.hpp"

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
		virtual void DebugInfo() override
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << ">>>> Container::Dynamic.Info()\n";
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << this << '\n';

			Debug::Console << Debug::Tabs << "Data" << ' ' << (this -> _Data) << '\n';
			Debug::Console << Debug::Tabs << "Limit" << ' ' << (this -> _Limit) << '\n';
			Debug::Console << Debug::Tabs << "Count" << ' ' << (this -> _Count) << '\n';

			Debug::Console << Debug::Tabs << "IsConstant" << ' ';
			if (this -> IsConstant) { Debug::Console << "true"; } else { Debug::Console << "false"; }
			Debug::Console << '\n';

			Debug::Console << Debug::Tabs << "IncB" << ' ';
			if (IncB == IncreaseBehaviour::None) { Debug::Console << "None"; }
			if (IncB == IncreaseBehaviour::Fit) { Debug::Console << "Fit"; }
			if (IncB == IncreaseBehaviour::Binary) { Debug::Console << "Binary"; }
			Debug::Console << '\n';

			Debug::Console << Debug::Tabs << "DecB" << ' ';
			if (DecB == DecreaseBehaviour::None) { Debug::Console << "None"; }
			if (DecB == DecreaseBehaviour::Fit) { Debug::Console << "Fit"; }
			if (DecB == DecreaseBehaviour::Binary) { Debug::Console << "Binary"; }
			Debug::Console << '\n';

			Debug::Console << Debug::TabDec;
			Debug::Console << Debug::Tabs << "<<<< Container::Dynamic.Info()\n";
#endif
		}

	public:
		Dynamic() : Base<T>()
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << "  ++++  " << "Dynamic()" << '\n';
#endif
			_Count = 0;
			IncB = IncreaseBehaviour::Binary;
			DecB = DecreaseBehaviour::Binary;
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		Dynamic(IncreaseBehaviour incB, DecreaseBehaviour decB) : Base<T>()
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << "  ++++  " << "Dynamic(inc, dec)" << '\n';
#endif
			_Count = 0;
			IncB = incB;
			DecB = decB;
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		Dynamic(unsigned int limit, IncreaseBehaviour incB, DecreaseBehaviour decB) : Base<T>(limit)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << "  ++++  " << "Dynamic(limit, inc, dec)" << '\n';
#endif
			_Count = 0;
			IncB = incB;
			DecB = decB;
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		Dynamic(const Base<T> & other) : Base<T>(other)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << "  ====  " << "Dynamic(base)" << '\n';
#endif
			_Count = this -> _Limit;
			IncB = IncreaseBehaviour::Binary;
			DecB = DecreaseBehaviour::Binary;
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		Dynamic(const Dynamic<T> & other) : Base<T>(other)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << "  ====  " << "Dynamic(other)" << '\n';
#endif
			_Count = other._Count;
			IncB = other.IncB;
			DecB = other.DecB;
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		virtual ~Dynamic()
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << "  ----  " << "~Dynamic()" << '\n';
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}

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

	public:
		unsigned int	Insert(T * items, unsigned int items_count)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << ' ' << "Insert(n)\n";
#endif
			unsigned int idx = _Count;
			unsigned int newCount = _Count + items_count;
			unsigned int newLimit = IncLimit(newCount);
			this -> ResizeLimit_GapNew(newLimit, _Count, Entry(_Count, 0));
			if (idx + items_count > this -> _Limit)
			{
#ifdef CONTAINER_DEBUG
				Debug::Console << Debug::Tabs << "no Space\n";
				Debug::Console << Debug::Tabs << "need " << (idx + items_count) << ". have " << (this -> _Limit) << ".\n";
#endif
				return 0xFFFFFFFF;
			}
			Base<T>::Copy(items_count, items, 0, this -> _Data, _Count);
			_Count = newCount;
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
			return idx;
		}
		unsigned int	Insert(T item)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << ' ' << "Insert(1)\n";
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
			return Insert(&item, 1);
		}
	private: // not fully tested
		T				Remove(Entry entry)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << ' ' << "Remove(entry)\n";
#endif
			if (entry.Max() > _Count) { throw ExceptionInvalidIndex(); }

			T item = this -> _Data[entry.Offset];

			unsigned int newCount = this -> _Count - entry.Length;
			unsigned int newLimit = DecLimit(newCount);
			this -> ResizeLimit_GapOld(newLimit, _Count, entry);

			this -> _Count = newCount;

#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
			return item; // should return array but dont feel like handling that right now
		}
	public:
		T				Remove(unsigned int idx)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "Container::Dynamic" << ' ' << "Remove(idx)\n";
#endif
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
			return Remove(Entry(idx, 1));
		}
};

};

#endif