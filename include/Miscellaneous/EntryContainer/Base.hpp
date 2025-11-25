#ifndef  ENTRY_CONTAINER_BASE_HPP
# define ENTRY_CONTAINER_BASE_HPP

# include "Entry.hpp"

# include "Miscellaneous/Container/Binary.hpp"

namespace EntryContainer
{

template<typename T>
class Base
{
	protected:
		unsigned int Limit;
		T * Data;

	protected:
		Container::Binary<Entry<T>*> Entrys;
	public:
		bool Changed;

	public:
		Base()
		{
			Limit = 0;
			Data = new T[Limit];
			Changed = false;
		}
		Base(unsigned int size)
		{
			Limit = size;
			Data = new T[Limit];
			Changed = false;
		}
		virtual ~Base()
		{
			delete[] Data;
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				delete Entrys[i];
			}
		}

	public:
		void ShowData() const
		{
			std::cout << "Container Data: " << Limit << "\n";
			for (unsigned int i = 0; i < Limit; i++)
			{
				//if ((i % 8) == 0) { if (i != 0) { std::cout << "\n"; } }
				//else { std::cout << " "; }
				if (i != 0) { std::cout << " "; }
				std::cout << Data[i];
			}
			if (Limit != 0) { std::cout << "\n"; }
		}
		void ShowEntrys() const
		{
			std::cout << "Entrys " << Entrys.Count() << "\n";
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				std::cout << "[" << i << "]";
				Entrys[i] -> ShowEntry();
			}
		}

	public:
		T * DataPointer(unsigned int offset)
		{
			return &(Data[offset]);
		}
		const T * ToPointer(unsigned int & limit)
		{
			limit = Limit;
			return Data;
		}

	public:
		virtual void Free(Entry<T> * entry) = 0;
		virtual Entry<T> * Alloc(unsigned int count) = 0;
};

};

#endif
