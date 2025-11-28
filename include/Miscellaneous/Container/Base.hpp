#ifndef  CONTAINER_BASE_HPP
# define CONTAINER_BASE_HPP

# include <exception>
# include <iostream>

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
		bool IsConstant;

	public:
		Base()
		{
			//std::cout << "  ++++  " << "Base()" << "\n";
			_Limit = 0;
			_Data = NULL;
			//std::cout << this << ' ' << _Limit << ' ' << _Data << " Data\n";
			IsConstant = false;
		}
		Base(unsigned int limit)
		{
			//std::cout << "  ++++  " << "Base(limit)" << "\n";
			_Limit = limit;
			_Data = new T[_Limit];
			IsConstant = false;
		}

		Base(unsigned int limit, const T * data)
		{
			//std::cout << "  ++++  " << "Base(limit, data)" << "\n";
			_Limit = limit;
			_Data = (T *)data;
			IsConstant = true;
		}
		~Base()
		{
			//std::cout << "  ----  " << "~Base()" << "\n";
			if (IsConstant)
			{
				delete[] _Data;
			}
		}

		Base(const Base<T> & other)
		{
			//std::cout << "  ====  " << "Base(other)" << "\n";
			_Limit = other._Limit;
			_Data = new T[_Limit];
			for (unsigned int i = 0; i < _Limit; i++)
			{
				_Data[i] = other._Data[i];
			}
			IsConstant = false;
		}
		Base & operator=(const Base<T> & other)
		{
			//std::cout << "  ====  " << "Base operator=(other)" << "\n";
			_Limit = other._Limit;
			_Data = new T[_Limit];
			for (unsigned int i = 0; i < _Limit; i++)
			{
				_Data[i] = other._Data[i];
			}
			IsConstant = false;
			return *this;
		}

	public:
		void Dispose()
		{
			if (!IsConstant)
			{
				delete[] _Data;
			}
			_Data = NULL;
			_Limit = 0;
		}
		void Allocate(unsigned int limit)
		{
			Dispose();
			_Limit = limit;
			_Data = new T[_Limit];
			IsConstant = false;
		}
		void Bind(unsigned int limit, const T * data)
		{
			Dispose();
			_Limit = limit;
			_Data = (T *)data;
			IsConstant = true;
		}
		void ReleaseTo(Base<T> & other)
		{
			other.Dispose();
			other._Limit = _Limit;
			other._Data = _Data;
			_Data = NULL;
			_Limit = 0;
		}
		Base<T> Release()
		{
			Base<T> other;
			ReleaseTo(other);
			return other;
		}

	public:
		unsigned int Limit() const { return _Limit; }
		const T * Data() const { return _Data; }

	public:
		/*virtual void ShowData() const
		{
			std::cout << "Container Data: " << _Limit << "\n";
			for (unsigned int i = 0; i < _Limit; i++)
			{
				if (i != 0) { std::cout << " "; }
				std::cout << _Data[i];
			}
			if (_Limit != 0) { std::cout << "\n"; }
		}*/

	public:
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
		unsigned int CopyFromOther(Base<T> & other, unsigned int count)
		{
			if (count > _Limit) { count = _Limit; }
			if (count > other._Limit) { count = other._Limit; }
			for (unsigned int i = 0; i < count; i++)
			{
				_Data[i] = other._Data[i];
			}
			return count;
		}

	protected:
		void ResizeLimit(unsigned int & count, unsigned int limit)
		{
			Base<T> other(limit);
			count = other.CopyFromOther(*this, count);
			other.ReleaseTo(*this);
		}

		static void Copy(unsigned int count, T * data_old, unsigned off_old, T * data_new, unsigned int off_new)
		{
			for (unsigned int i = 0; i < count; i++)
			{
				data_new[off_new + i] = data_old[off_old + i];
			}
		}
		static void Copy(unsigned int count, Base<T> & old_cont, unsigned off_old, Base<T> & new_cont, unsigned int off_new)
		{
			for (unsigned int i = 0; i < count; i++)
			{
				new_cont._Data[off_new + i] = old_cont._Data[off_old + i];
			}
		}

	private:
		/*	optimized for copying with gaps in both input and output
			gaps are the opposite of Entrys
			invert for copying Entrys ?
			gaps should be in order ?
		*/
		static void CopyOrderedGaps(unsigned int count,
			Base<T> & inn_container, Base<Entry> inn_gaps,
			Base<T> & out_container, Base<Entry> out_gaps)
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
						inn_off = inn_gaps[inn_gap_idx].Max();
					}
				}
				if (out_gap_idx < out_gaps.Limit() && out_off >= out_gaps[out_gap_idx].Offset)
				{
					out_gap_idx++;
					if (out_gap_idx < out_gaps.Limit())
					{
						out_off = out_gaps[out_gap_idx].Max();
					}
				}
				out_container[out_off] = inn_container[inn_off];
				inn_off++;
				out_off++;
			}
		}

	protected:
		void ResizeLimit_GapNew(unsigned int limit, unsigned int count, Entry gap)
		{
			Base<T> other;
			
			if (limit == _Limit)
			{
				other._Data = _Data;
				other._Limit = _Limit;
			}
			else
			{
				other.Allocate(limit);
				Copy(gap.Offset, *this, 0, other, 0);
			}
			
			if (gap.Offset < count)
			{
				Copy(count - gap.Offset, *this, gap.Min(), other, gap.Max());
			}

			if (other._Data != _Data) { other.ReleaseTo(*this); }
		}
		void ResizeLimit_GapOld(unsigned int limit, unsigned int count, Entry gap)
		{
			Base<T> other;

			if (limit == _Limit)
			{
				other._Data = _Data;
				other._Limit = _Limit;
			}
			else
			{
				other.Allocate(limit);
				Copy(gap.Offset, *this, 0, other, 0);
			}

			if (gap.Offset < count)
			{
				Copy(count - gap.Offset, *this, gap.Max(), other, gap.Min());
			}

			if (other._Data != _Data) { other.ReleaseTo(*this); }
		}
};

};

#endif