#ifndef  ENTRY_CONTAINER_BASE_HPP
# define ENTRY_CONTAINER_BASE_HPP

# include "Entry.hpp"
# include "Miscellaneous/Container/Base.hpp"
# include "Miscellaneous/Container/Dynamic.hpp"

namespace EntryContainer
{

template<typename T>
class Base : public Container::Base<T>
{
	protected:
		Container::Dynamic<EntryData<T>*> Entrys;

	public:
		bool Changed;

	public:
		Base() : Container::Base<T>(),
			Entrys(Container::IncreaseBehaviour::Binary, Container::DecreaseBehaviour::Binary)
		{
			//_Limit = 0;
			//_Data = new T[_Limit];
			Changed = false;
		}
		Base(unsigned int limit) : Container::Base<T>(limit),
			Entrys(Container::IncreaseBehaviour::Binary, Container::DecreaseBehaviour::Binary)
		{
			//_Limit = limit;
			//_Data = new T[_Limit];
			Changed = false;
		}
		virtual ~Base()
		{
			//delete[] _Data;
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				Entrys[i] -> Container = NULL;
				delete Entrys[i];
			}
		}

	public:
		void ShowEntrys() const
		{
			std::cout << "Entrys " << Entrys.Count() << "\n";
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				std::cout << "[" << i << "]";
				std::cout << " ";
				Entrys[i] -> ShowEntry();
			}
		}

	protected:
		unsigned int FindEntryIndex(EntryData<T> * entry) const
		{
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				if (Entrys[i] == entry) { return i; }
			}
			return 0xFFFFFFFF;
		}
		EntryData<T> * FindEntryByData(unsigned int data_index) const
		{
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				if (data_index >= Entrys[i] -> Min() && data_index < Entrys[i] -> Max())
				{
					return Entrys[i];
				}
			}
			return NULL;
		}
		unsigned int FindNextEntry(unsigned int data_index) const
		{
			unsigned int entry_idx = 0xFFFFFFFF;
			unsigned int entry_dist = 0xFFFFFFFF;
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				if (data_index <= Entrys[i] -> Offset)
				{
					unsigned int dist = Entrys[i] -> Offset - data_index;
					if (dist < entry_dist)
					{
						entry_dist = dist;
						entry_idx = i;
					}
				}
			}
			return entry_idx;
		}

		unsigned int FindNextEntryDuplicate(EntryData<T> * entry, unsigned int entry_idx) const
		{
			for (unsigned int i = entry_idx; i < Entrys.Count(); i++)
			{
				if (Entrys[i] -> Offset == entry -> Offset &&
					Entrys[i] -> Length == entry -> Length)
				{
					return i;
				}
			}
			return 0xFFFFFFFF;
		}

	public:
		virtual EntryData<T> * Alloc(unsigned int count) = 0;
		virtual void Free(EntryData<T> * entry) = 0;
		virtual EntryData<T> * Copy(EntryData<T> * entry) = 0;
};

};

#endif
