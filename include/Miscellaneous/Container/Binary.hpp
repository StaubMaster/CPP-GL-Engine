#ifndef  CONTAINER_BINARY_HPP
# define CONTAINER_BINARY_HPP

# include "Dynamic.hpp"

namespace Container
{
template<typename T>
class Binary : public Dynamic<T>
{
	protected:
		static unsigned int BinarySize(unsigned int size)
		{
			for (unsigned char shift = 31; shift < 32; shift--)
			{
				unsigned int new_size = 0xFFFFFFFF >> shift;
				if (new_size >= size)
				{
					return new_size;
				}
			}
			return 0;
		}

	public:
		Binary() : Dynamic<T>()
		{ }
		~Binary()
		{ }

	protected:
		unsigned int NewLimit(unsigned int count) override
		{
			return BinarySize(count);
		}
};

/*template<typename T>
class Binary : public Base<T>
{
	protected:
		static unsigned int BinarySize(unsigned int size)
		{
			for (unsigned char shift = 31; shift < 32; shift--)
			{
				unsigned int new_size = 0xFFFFFFFF >> shift;
				if (new_size >= size)
				{
					return new_size;
				}
			}
			return 0;
		}

	private:
		unsigned int _Count;

	public:
		Binary() : Base<T>()
		{
			_Count = 0;
		}
		Binary(const Base<T> & other) : Base<T>(other)
		{ }
		Binary(const Binary<T> & other) : Base<T>(other)
		{
			_Count = other._Count;
		}
		~Binary()
		{ }

	public:
		unsigned int Count() const { return _Count; }

	public:
		void Trim()
		{
			if (_Count < this -> _Limit)
			{
				this -> ResizeLimit(_Count, _Count);
			}
		}

	public:
		unsigned int	Insert(T item)
		{
			unsigned int newCount = this -> _Count + 1;
			if (newCount >= this -> _Limit)
			{
				this -> ResizeLimit(this -> _Count, BinarySize(newCount));
			}
			unsigned int udx = this -> _Count;
			this -> _Data[this -> _Count] = item;
			this -> _Count = newCount;
			return udx;
		}
		T				Remove(unsigned int idx)
		{
			T item = this -> _Data[idx];
			for (unsigned int i = idx + 1; i < this -> _Count; i++)
			{
				this -> _Data[i - 1] = this -> _Data[i];
			}
			this -> _Count--;
			return item;
		}
};*/

};

#endif