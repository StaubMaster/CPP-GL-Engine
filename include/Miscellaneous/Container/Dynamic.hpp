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
			std::cout << "  ++++  " << "Container::Dynamic()" << '\n';
			_Count = 0;
			IncB = IncreaseBehaviour::Binary;
			DecB = DecreaseBehaviour::Binary;
		}
		Dynamic(IncreaseBehaviour incB, DecreaseBehaviour decB) : Base<T>()
		{
			std::cout << "  ++++  " << "Container::Dynamic(inc, dec)" << '\n';
			_Count = 0;
			IncB = incB;
			DecB = decB;
		}
		Dynamic(unsigned int limit, IncreaseBehaviour incB, DecreaseBehaviour decB) : Base<T>(limit)
		{
			std::cout << "  ++++  " << "Container::Dynamic(limit, inc, dec)" << '\n';
			_Count = 0;
			IncB = incB;
			DecB = decB;
		}
		Dynamic(const Base<T> & other) : Base<T>(other)
		{
			std::cout << "  ====  " << "Container::Dynamic(base)" << '\n';
			_Count = this -> _Limit;
			IncB = IncreaseBehaviour::Binary;
			DecB = DecreaseBehaviour::Binary;
		}
		Dynamic(const Dynamic<T> & other) : Base<T>(other)
		{
			std::cout << "  ====  " << "Container::Dynamic(other)" << '\n';
			_Count = other._Count;
			IncB = other.IncB;
			DecB = other.DecB;
		}
		virtual ~Dynamic()
		{
			std::cout << "  ----  " << "Container::~Dynamic()" << '\n';
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
			std::cout << "Insert(n)\n";
			unsigned int idx = _Count;
			unsigned int newCount = _Count + items_count;
			unsigned int newLimit = IncLimit(newCount);
			std::cout << "newCount " << newCount << "\n";
			std::cout << "newLimit " << newLimit << "\n";
			std::cout << "Insert(n) 0\n";
			this -> ResizeLimit_GapNew(newLimit, _Count, Entry(_Count, 0));
			std::cout << "Insert(n) 1\n";
			if (idx + items_count > this -> _Limit)
			{
				std::cout << "no Space\n";
				std::cout << "need " << (idx + items_count) << ". have " << (this -> _Limit) << ".\n";
				return 0xFFFFFFFF;
			}
			std::cout << "Insert(n) 2\n";
			Base<T>::Copy(items_count, items, 0, this -> _Data, _Count);
			std::cout << "Insert(n) 3\n";
			_Count = newCount;
			return idx;
		}
		unsigned int	Insert(T item)
		{
			std::cout << "Insert(1)\n";
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