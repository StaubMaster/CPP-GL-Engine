#ifndef  ENTRY_CONTAINER_ENTRY_HPP
# define ENTRY_CONTAINER_ENTRY_HPP

# include "DebugDefines.hpp"

# include "EntryData.hpp"

namespace EntryContainer
{

template<typename T>
class Entry
{
	private:
		EntryData<T> * Data;

	public:
		virtual void DebugInfo()
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << ">>>> EntryContainer::Entry.Info()\n";
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << this << '\n';

			Debug::Console << Debug::Tabs << "Data" << ' ' << (Data) << '\n';
			if (Data != NULL)
			{
				Data -> DebugInfo();
			}

			Debug::Console << Debug::TabDec;
			Debug::Console << Debug::Tabs << "<<<< EntryContainer::Entry.Info()\n";
#endif
		}

	public:
		Entry()
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ++++  " << "Entry()\n";
#endif
			Data = NULL;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << " Data " << Data << "\n";
			Debug::Console << Debug::TabDec;
#endif
		}
		Entry(Base<T> & container, unsigned int count)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ++++  " << "Entry(container, count)\n";
#endif
			Data = container.Alloc(count);
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << " Data " << Data << "\n";
			Debug::Console << Debug::TabDec;
#endif
		}
		~Entry()
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ----  " << "~Entry()\n";
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << " Data " << Data << "\n";
#endif
			delete Data;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}

		/*	Copying
			I need it
			problem:
				when I copy from e0 to e1
				when I then delete e0 it removes the entry
				at which point e1 becomes invalid
			problem:
				i cant delete Data from e0 because it is constant
			solution: ?
				allow a Entry container to have duplicates of a Entry
				the area is only freed once the last duplicate of that Entry is removed
			question:
				allow Entrys to overlap ?
				to know the Count (how much Data is used) would require going over each bit of data
				this would also mean that looking for space is inefficient ?
			no it dosent ?
				just start at 0,
				then look for the first enty beginning
					then go to the end
					then check if it inside another enty
					then go to the end of that
					repeat until end is outside of entrys
				this is now an area
					remember those in entrys too ?
					maybe save this for another time
			looking for space:
				go to the end of a entry
				put offset of new enty there
				check if it overlaps any other
				repeat until space is found
				else reallocate new space

			the whole reason why I split this into EntryData and Entry is because of copying
			if this works. merge them back together

			no ???
				I did it so I can use Entrys withour Pointer syntax
		*/
		Entry(const Entry<T> & other)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ====  " << "Entry(other) ...\n";
#endif
			if (other.Data != NULL)
			{
				Data = other.Data -> Container -> Copy(other.Data);
			}
			else
			{
				Data = NULL;
			}
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << " Data " << Data << "\n";
#endif
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ====  " << "Entry(other) done\n";
			Debug::Console << Debug::TabDec;
#endif
		}
		Entry<T> & operator =(const Entry<T> & other)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ====  " << "operator =(other) ...\n";
#endif
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs<< "EntryContainer::Entry" << " Data " << Data << "\n";
#endif
			Dispose();
			if (other.Data != NULL)
			{
				Data = other.Data -> Container -> Copy(other.Data);
			}
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << " Data " << Data << "\n";
#endif
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ====  " << "operator =(other) done\n";
			Debug::Console << Debug::TabDec;
#endif
			return *this;
		}

	public:
		unsigned int Length() const { return Data -> Length; }

	private:
		//	these are a lot so extra function
		//	once everything works again, turn these into excpetions
		void CheckData() const
		{
			if (Data == NULL)
			{
				const char * msg = "EntryContainer::Entry Entry Invalid.";
				//std::cout << msg << "\n";
				throw msg;
			}
		}
		/*void CheckDataContainer() const
		{
			if (Data -> Container == NULL)
			{
				const char * msg = "EntryContainer::Entry Entry Invalid.";
				//std::cout << msg << "\n";
				throw msg;
			}
		}*/
		void CheckIndex(unsigned int idx) const
		{
			if (idx >= Data -> Length)
			{
#ifdef ENTRY_CONTAINER_DEBUG
				Debug::Console << Debug::TabInc;
				Debug::Console << Debug::Tabs << __FILE__ << ':' << __LINE__ << '\n';
				Debug::Console << Debug::Tabs << idx << " >= " << (Data -> Length) << "\n";
#endif
				const char * msg = "EntryContainer::Entry Index invalid.";
				//std::cout << msg << "\n";
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
				throw msg;
			}
		}
	public:
		const T & operator[](unsigned int idx) const
		{
			CheckData();
			//CheckDataContainer();
			CheckIndex(idx);
			//Data -> Container -> Changed = true;
			//return (Data -> Container -> DataPointer(Data -> Offset))[idx];
			//return (*Data)[idx];
			//return (Data -> Data())[idx];
			return (*Data)[idx];
		}
		const T & operator*() const
		{
			CheckData();
			//CheckDataContainer();
			//return *(Data -> Container -> DataPointer(Data -> Offset));
			//return *(*Data);
			//return *(Data -> Data());
			return *(*Data);
		}
		T & operator[](unsigned int idx)
		{
			CheckData();
			//CheckDataContainer();
			CheckIndex(idx);
			//return (*Data)[idx];
			//return (*Data)[idx];
			//return (Data -> Data())[idx];
			return (*Data)[idx];
		}
		T & operator*()
		{
			CheckData();
			//CheckDataContainer();
			//return *(*Data);
			//return *(*Data);
			//return *(Data -> Data());
			return *(*Data);
		}

	public:
		bool Is() const
		{
			return (Data != NULL);
		}
		void Allocate(Base<T> & container, unsigned int count)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ++++  " << "Allocate()\n";
#endif
			Dispose();
			Data = container.Alloc(count);
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << " Data " << Data << "\n";
			Debug::Console << Debug::TabDec;
#endif
		}
		void Dispose()
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::Entry" << "  ----  " << "Dispose()\n";
			Debug::Console << Debug::Tabs<< "EntryContainer::Entry" << " Data " << Data << "\n";
#endif
			if (Data != NULL)
			{
				delete Data;
				Data = NULL;
			}
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
};

};

#endif