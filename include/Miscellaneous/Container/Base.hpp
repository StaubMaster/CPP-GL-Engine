#ifndef  CONTAINER_BASE_HPP
# define CONTAINER_BASE_HPP

# include <exception>
# include <iostream>

namespace Container
{

class Exception_OutOfRange : public std::exception { const char * what() const noexcept { return "Index was out of Range."; } };

template<typename T>
class Base
{
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
		Base(unsigned int limit)
		{
			_Limit = limit;
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
				//std::cout << "Out of Range\n";
				throw Exception_OutOfRange();
			}
			return _Data[idx];
		}
		virtual const T & operator[](unsigned int idx) const
		{
			if (idx >= _Limit)
			{
				//std::cout << "Out of Range\n";
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

		static void Copy(unsigned int count, T * data_old, unsigned off_old, T * data_new, unsigned int off_new)
		{
			for (unsigned int i = 0; i < count; i++)
			{
				data_new[off_new + i] = data_old[off_old + i];
			}
		}

		void ResizeLimit_GapNew(unsigned int new_limit, unsigned int count, unsigned int gap_offset, unsigned int gap_length)
		{
			T * data = _Data;

			if (new_limit != _Limit)
			{
				data = new T[new_limit];

				unsigned int copy_end = count;
				if (gap_offset < copy_end) { copy_end = gap_offset; }
				Copy(copy_end, _Data, 0, data, 0);
			}

			if (gap_offset < count)
			{
				Copy(count - gap_offset, _Data, gap_offset, data, gap_offset + gap_length);
			}

			if (data != _Data)
			{
				delete[] _Data;
				_Data =  data;
				_Limit = new_limit;
			}
		}

		void ResizeLimit_GapOld(unsigned int new_limit, unsigned int count, unsigned int gap_offset, unsigned int gap_length)
		{
			T * data = _Data;

			if (new_limit != _Limit)
			{
				data = new T[new_limit];

				unsigned int copy_end = count;
				if (gap_offset < copy_end) { copy_end = gap_offset; }
				Copy(copy_end, _Data, 0, data, 0);
			}

			if (gap_offset < count)
			{
				Copy(count - gap_offset, _Data, gap_offset + gap_length, data, gap_offset);
			}

			if (data != _Data)
			{
				delete[] _Data;
				_Data =  data;
				_Limit = new_limit;
			}
		}
};

};

#endif