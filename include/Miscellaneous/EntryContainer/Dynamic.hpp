#ifndef  ENTRY_CONTAINER_DYNAMIC_HPP
# define ENTRY_CONTAINER_DYNAMIC_HPP

# include "DebugDefines.hpp"

# include "Base.hpp"
# include "Miscellaneous/Container/Dynamic.hpp"
# include "Miscellaneous/Container/Behaviour.hpp"

namespace EntryContainer
{

template<typename T>
class Dynamic : public Base<T>
{
	protected:
		unsigned int _Count;



	public:
		unsigned int Count() const { return _Count; }



	public:
		virtual void DebugInfo() override
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << ">>>> EntryContainer::Dynamic.Info()\n";
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << this << '\n';

			Debug::Console << "Data" << ' ' << (this -> _Data) << '\n';
			Debug::Console << "Limit" << ' ' << (this -> _Limit) << '\n';
			Debug::Console << "Count" << ' ' << (this -> _Count) << '\n';

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

			Debug::Console << Debug::TabDec;
			Debug::Console << Debug::Tabs << "<<<< EntryContainer::Dynamic.Info()\n";
#endif
		}

	public:
		Dynamic() : Base<T>(0)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Dynamic" << "  ++++  " << "Dynamic()" << "\n";
#endif
			_Count = 0;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		~Dynamic()
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Dynamic" << "  ----  " << "~Dynamic()" << "\n";
			Debug::Console << Debug::TabDec;
#endif
		}

	public:
		/*void ShowData() const override
		{
			std::cout << "Container Data: " << _Count << " " << this -> _Limit << "\n";
			for (unsigned int i = 0; i < this -> _Limit; i++)
			{
				//if ((i % 8) == 0) { if (i != 0) { std::cout << "\n"; } }
				//else { std::cout << " "; }
				if (i != 0) { std::cout << " "; }
				std::cout << this -> _Data[i];
			}
			if (this -> _Limit != 0) { std::cout << "\n"; }
		}*/

	public:
		bool IsCompact() const
		{
			unsigned int data_idx = 0;
			for (unsigned int i = 0; i < this -> Entrys.Count(); i++)
			{
				EntryData<T> * entry = this -> FindEntryContaining(data_idx).Ptr;
				if (entry == NULL) { return false; }
				if (entry -> Offset != data_idx) { return false; }
				data_idx += entry -> Length;
			}
			if (_Count != data_idx) { return false; }
			return true;
		}
		//	dosent handle duplicate entrys
		/*void CompactLimit()
		{
			unsigned int limit = 0;
			for (unsigned int i = 0; i < this -> Entrys.Count(); i++)
			{
				limit += this -> Entrys[i] -> Length;
			}
			T * data = new T[limit];

			unsigned int data_idx;
			for (unsigned int i = 0; i < this -> Entrys.Count(); i++)
			{
				for (unsigned int j = 0; j < this -> Entrys[i] -> Length; j++)
				{
					data[data_idx + j] = (*this -> Entrys[i])[j];
				}
				this -> Entrys[i] -> Offset = data_idx;
				data_idx += this -> Entrys[i] -> Length;
			}

			delete[] this -> _Data;
			this -> _Data = data;
			this -> _Limit = limit;
		}*/
		void CompactHere()
		{
			unsigned int data_idx = 0;
			unsigned int entry_idx = this -> FindNextEntry(data_idx).Idx;
			_Count = 0;
			while (entry_idx != 0xFFFFFFFF)
			{
				EntryData<T> * entry = this -> Entrys[entry_idx];
				if (entry -> Limit() > _Count) { _Count = entry -> Limit(); }
				unsigned int dupe_idx = this -> FindNextEntryDuplicate(entry, entry_idx + 1).Idx;
				entry -> Move(data_idx);
				if (dupe_idx == 0xFFFFFFFF)
				{
					data_idx = entry -> Limit();
					entry_idx = this -> FindNextEntry(data_idx).Idx;
				}
				else
				{
					entry_idx = dupe_idx;
				}
			}
		}

	public:
		EntryData<T> * Alloc(unsigned int size) override
		{
			if (this -> _IsLocked) { return NULL; }
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Dynamic" << "  ++++  " << "Alloc()" << '\n';
#endif
			unsigned int newCount = _Count + size;
			unsigned int newLimit = Container::BinarySize(newCount);

			this -> ResizeLimit(newLimit);

			EntryData<T> * entry = new EntryData<T>(this, _Count, size);
			this -> Entrys.Insert(entry);
			this -> Changed = true;
			_Count = newCount;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
			return entry;
		}
		void Free(EntryData<T> * entry) override
		{
			if (this -> _IsLocked) { return; }
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Dynamic" << "  ----  " << "Free()" << '\n';
#endif
			this -> Changed = true;
			unsigned int entry_idx = this -> FindEntry(entry).Idx;
			if (entry_idx == 0xFFFFFFFF)
			{
				//std::cout << "EntryContainer::Dynamic Entry not found." << "\n";
				throw "EntryContainer::Dynamic Entry not found.";
			}
			this -> Entrys.Remove(entry_idx);
			entry -> Container = NULL;
			/*if (this -> FindNextEntryDuplicate(entry, 0).Idx == 0xFFFFFFFF)
			{
				_Count -= entry -> Length;
			}*/
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		EntryData<T> * Copy(EntryData<T> * entry) override
		{
			if (this -> _IsLocked) { return NULL; }
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Dynamic" << "  ====  " << "Copy()" << '\n';
#endif
			if (entry == NULL)
			{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
				return NULL;
			}
			EntryData<T> * other = new EntryData<T>(*entry);
			this -> Entrys.Insert(other);
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
			return other;
		}
};

};

#endif
