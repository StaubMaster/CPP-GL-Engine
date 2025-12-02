#ifndef  ENTRY_CONTAINER_BASE_HPP
# define ENTRY_CONTAINER_BASE_HPP

# include "DebugDefines.hpp"

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
	protected:
		bool _IsLocked;

	public:
		bool Changed;
	


	public:
		bool IsLocked() const { return _IsLocked; }
		void Lock() { _IsLocked = true; }
		void UnLock() { _IsLocked = false; }



	public:
		virtual void DebugInfo() override
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << ">>>> EntryContainer::Base.Info()\n";
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << this << '\n';

			Debug::Console << "Data" << ' ' << (this -> _Data) << '\n';
			Debug::Console << "Limit" << ' ' << (this -> _Limit) << '\n';

			Debug::Console << "IsConstant" << ' ';
			if (this -> IsConstant) { Debug::Console << "true"; } else { Debug::Console << "false"; }
			Debug::Console << '\n';

			Debug::Console << "IsLocked" << ' ';
			if (this -> _IsLocked) { Debug::Console << "true"; } else { Debug::Console << "false"; }
			Debug::Console << '\n';

			Debug::Console << "Changed" << ' ';
			if (this -> Changed) { Debug::Console << "true"; } else { Debug::Console << "false"; }
			Debug::Console << '\n';
		
			Debug::Console << "Entrys" << ' ' << (this -> Entrys.Count()) << ' ' << (this -> Entrys.Limit()) << '\n';
			Debug::Console << Debug::Tabs << "<<<< EntryContainer::Base.Info()\n";
			Debug::Console << Debug::TabDec;
#endif
		}

	public:
		Base() : Container::Base<T>(),
			Entrys(Container::IncreaseBehaviour::Binary, Container::DecreaseBehaviour::Binary)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Base" << "  ++++  " << "Base()" << "\n";
#endif
			//_Limit = 0;
			//_Data = new T[_Limit];
			_IsLocked = false;
			Changed = false;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		Base(unsigned int limit) : Container::Base<T>(limit),
			Entrys(Container::IncreaseBehaviour::Binary, Container::DecreaseBehaviour::Binary)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Base" << "  ++++  " << "Base(limit)" << "\n";
#endif
			//_Limit = limit;
			//_Data = new T[_Limit];
			_IsLocked = false;
			Changed = false;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		virtual ~Base()
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
#endif
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Base" << "  ----  " << "~Base()" << "\n";
#endif
			//delete[] _Data;
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				Entrys[i] -> Container = NULL;
				delete Entrys[i];
			}
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
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
