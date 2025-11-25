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
		virtual unsigned int NewLimit(unsigned int count) = 0;
		/*{
			if (SizeB == SizeBehaviour::None) { return this -> _Limit; }
			if (SizeB == SizeBehaviour::Fit) { return count; }
			if (SizeB == SizeBehaviour::Binary) { return BinarySize(count); }
			return this -> _Limit;
		}*/

	public:
		unsigned int	Insert(T item)
		{
			unsigned int newCount = this -> _Count + 1;
			unsigned int newLimit = NewLimit(newCount);
			if (newLimit >= this -> _Limit)
			{
				this -> _Limit = newLimit;
				T * data = new T[newLimit];
				for (unsigned int i = 0; i < _Count; i++)
				{
					data[i] = this -> _Data[i];
				}
				_Count = newCount;
				delete[] this -> _Data;
				this -> _Data = data;
			}
			unsigned int udx = this -> _Count;
			this -> _Data[this -> _Count] = item;
			this -> _Count = newCount;
			return udx;
		}
		T				Remove(unsigned int idx)
		{
			unsigned int size = 1;

			unsigned int newCount = this -> _Count - size;
			unsigned int newLimit = NewLimit(newCount);
			T * data = this -> _Data;
			if (newLimit >= this -> _Limit)
			{
				this -> _Limit = newLimit;
				data = new T[newLimit];
				for (unsigned int i = 0; i < idx; i++)
				{
					data[i] = this -> _Data[i];
				}
			}

			T item = this -> _Data[idx];
			for (unsigned int i = idx; i < newCount; i++)
			{
				data[i] = this -> _Data[i + size];
			}

			this -> _Count = newCount;

			if (data != this -> _Data)
			{
				delete[] this -> _Data;
				this -> _Data = data;
			}

			return item;
		}
};

};

#endif