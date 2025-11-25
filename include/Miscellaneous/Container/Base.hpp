#ifndef  CONTAINER_BASE_HPP
# define CONTAINER_BASE_HPP

# include <exception>
# include <iostream>

namespace Container
{

template<typename T>
class Base
{
	protected:
		class Exception_OutOfRange : public std::exception { const char * what() const noexcept { return "Index was out of Range."; } };

	protected:
		unsigned int _Limit;
		unsigned int _Count;
		T * _Data;
		bool IsLocalData;

	public:
		Base()
		{
			_Limit = 0;
			_Data = new T[_Limit];
			IsLocalData = true;
		}
		Base(T * data, unsigned int limit)
		{
			_Limit = limit;
			_Data = data;
			IsLocalData = false;
		}
		Base(const Base<T> & other)
		{
			_Limit = other._Limit;
			_Data = new T[_Limit];
			for (unsigned int i = 0; i < _Limit; i++)
			{
				_Data[i] = other._Data[i];
			}
			IsLocalData = true;
		}
		~Base()
		{
			if (IsLocalData)
			{
				delete[] _Data;
			}
		}

	public:
		unsigned int Limit() const { return _Limit; }
		const T * Data() const { return _Data; }

	public:
		virtual T & operator[](unsigned int idx)
		{
			if (idx >= _Limit)
			{
				std::cout << "Out of Range\n";
				throw Exception_OutOfRange();
			}
			return _Data[idx];
		}
		virtual const T & operator[](unsigned int idx) const
		{
			if (idx >= _Limit)
			{
				std::cout << "Out of Range\n";
				throw Exception_OutOfRange();
			}
			return _Data[idx];
		}

	protected:
		void ResizeLimit(unsigned int & count, unsigned int limit)
		{
			_Limit = limit;
			T * data = new T[_Limit];
			IsLocalData = true;

			if (limit < count) { count = limit; }
			for (unsigned int i = 0; i < count; i++)
			{
				data[i] = _Data[i];
			}
			delete[] _Data;
			_Data = data;
		}
};

};

#endif