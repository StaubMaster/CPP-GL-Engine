#ifndef  CONTAINER_DYNAMIC_HPP
# define CONTAINER_DYNAMIC_HPP

# include "Base.hpp"

namespace Container
{
template<typename T>
class Dynamic : public Base<T>
{
	protected:
		unsigned int _Count;

	public:
		Dynamic() : Base<T>()
		{
			_Count = 0;
		}
		Dynamic(unsigned int limit) : Base<T>(limit)
		{
			_Count = 0;
		}
		Dynamic(const Base<T> & other) : Base<T>(other)
		{
			_Count = this -> _Limit;
		}
		Dynamic(const Dynamic<T> & other) : Base<T>(other)
		{
			_Count = other._Count;
		}
		virtual ~Dynamic()
		{ }

	public:
		unsigned int Count() const { return _Count; }

	public:
		T & operator[](unsigned int idx) override
		{
			if (idx >= _Count)
			{
				//std::cout << "Out of Range\n";
				throw Exception_OutOfRange();
			}
			return this -> _Data[idx];
		}
		const T & operator[](unsigned int idx) const override
		{
			if (idx >= _Count)
			{
				//std::cout << "Out of Range\n";
				throw Exception_OutOfRange();
			}
			return this -> _Data[idx];
		}

	public:
		//	changes Limit to fit Count
		//	ignores Behaviour
		void Trim()
		{
			if (_Count < this -> _Limit)
			{
				this -> ResizeLimit(_Count, _Count);
			}
		}

	protected:
		virtual unsigned int NewLimit(unsigned int wanted_count) = 0;

	private: // not fully tested
		unsigned int	Insert(T * items, unsigned int items_count)
		{
			unsigned int idx = _Count;

			unsigned int newCount = _Count + items_count;
			unsigned int newLimit = NewLimit(newCount);
			this -> ResizeLimit_GapNew(newLimit, _Count, _Count, 0);
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
		T				Remove(unsigned int idx)
		{
			if (idx >= _Count) { throw Exception_OutOfRange(); }

			unsigned int size = 1;
			T item = this -> _Data[idx];

			unsigned int newCount = this -> _Count - size;
			unsigned int newLimit = NewLimit(newCount);
			this -> ResizeLimit_GapOld(newLimit, _Count, idx, size);

			this -> _Count = newCount;

			return item;
		}
};

};

#endif