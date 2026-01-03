#ifndef  ENTRY_CONTAINER_BASE_HPP
# define ENTRY_CONTAINER_BASE_HPP

# include "Entry.hpp"
# include "Miscellaneous/Container/Base.hpp"
# include "Miscellaneous/Container/Binary.hpp"

namespace EntryContainer
{

template<typename T>
class Base : public Container::Base<T>
{
	protected:
		Container::Binary<EntryData<T>*> Entrys;
	protected:
		bool _IsLocked;

	public:
		bool Changed;
	


	public:
		bool IsLocked() const { return _IsLocked; }
		void Lock() { _IsLocked = true; }
		void UnLock() { _IsLocked = false; }



	public:
		virtual void DebugInfo() override { }

	public:
		Base(Container::Behaviour::EIncrease incB, Container::Behaviour::EDecrease decB, Container::Behaviour::EMemory memB ) : Container::Base<T>(incB, decB, memB),
			Entrys()
		{
			//_Limit = 0;
			//_Data = new T[_Limit];
			_IsLocked = false;
			Changed = false;
		}
		/*Base(unsigned int limit) : Container::Base<T>(limit),
			Entrys(Container::Behaviour::EIncrease::Binary,Container::Behaviour::EDecrease::Binary)
		{
			//_Limit = limit;
			//_Data = new T[_Limit];
			_IsLocked = false;
			Changed = false;
		}*/
		virtual ~Base()
		{
			//delete[] _Data;
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				Entrys[i] -> Container = NULL;
				delete Entrys[i];	// remove this ?
				/*
					EntryData is pointen to in 2 places
					here and in Entry
					if this is deleted then the Entrys still exist
					Container is set to NULL
					so Entry knows that the EntryContainer no longer exists
					and so can safely delete it itself
				*/
			}
		}

	public:
		/*void ShowEntrys() const
		{
			std::cout << "Entrys " << Entrys.Count() << "\n";
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				std::cout << "[" << i << "]";
				std::cout << " ";
				Entrys[i] -> ShowEntry();
			}
		}*/

	public:
		struct FindResult
		{
			unsigned int Idx;
			EntryData<T> * Ptr;

			FindResult() :
				Idx(0xFFFFFFFF),
				Ptr(NULL)
			{ }
			FindResult(unsigned int idx, EntryData<T> * ptr) :
				Idx(idx),
				Ptr(ptr)
			{ }
		};
	protected:
		FindResult FindEntry(EntryData<T> * entry) const
		{
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				if (Entrys[i] == entry) { return FindResult(i, Entrys[i]); }
			}
			return FindResult();
		}
		FindResult FindEntryContaining(unsigned int data_index) const
		{
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				if (data_index >= Entrys[i] -> Min() && data_index <= Entrys[i] -> Max())
				{
					return FindResult(i, Entrys[i]);
				}
			}
			return FindResult();
		}

		FindResult FindNextEntry(unsigned int data_index) const
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
			if (entry_idx != 0xFFFFFFFF)
			{
				return FindResult(entry_idx, Entrys[entry_idx]);
			}
			return FindResult();
		}
		FindResult FindNextEntryDuplicate(EntryData<T> * entry, unsigned int entry_idx) const
		{
			for (unsigned int i = entry_idx; i < Entrys.Count(); i++)
			{
				if (Entrys[i] -> Offset == entry -> Offset &&
					Entrys[i] -> Length == entry -> Length)
				{
					return FindResult(i, Entrys[i]);
				}
			}
			return FindResult();
		}



	public:
		virtual EntryData<T> * Alloc(unsigned int size) = 0;
		virtual void Free(EntryData<T> * entry) = 0;
		virtual EntryData<T> * Copy(EntryData<T> * entry) = 0;
};

};

#endif
