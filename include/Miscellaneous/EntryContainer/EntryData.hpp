#ifndef  ENTRY_CONTAINER_ENTRY_DATA_HPP
# define ENTRY_CONTAINER_ENTRY_DATA_HPP

# include "DebugDefines.hpp"

# include "Miscellaneous/Container/Entry.hpp"

namespace EntryContainer
{

template<typename T> class Base;

template<typename T>
class EntryData : public Container::Entry
{
	public:
		Base<T> * Container;

	public:
		virtual void DebugInfo() override
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::Tabs << ">>>> EntryContainer::EntryData.Info()\n";
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << this << '\n';

			Debug::Console << Debug::Tabs << "Offset" << ' ' << (this -> Offset) << '\n';
			Debug::Console << Debug::Tabs << "Length" << ' ' << (this -> Length) << '\n';
			Debug::Console << Debug::Tabs << "Container" << ' ' << (Container) << '\n';

			Debug::Console << Debug::TabDec;
			Debug::Console << Debug::Tabs << "<<<< EntryContainer::EntryData.Info()\n";
#endif
		}

	public:
		EntryData() : Container::Entry()
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::EntryData" << "  ++++  " << "EntryData()\n";
#endif
			Container = NULL;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		EntryData(const EntryData & other) : Container::Entry(other)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::EntryData" << "  ====  " << "EntryData(other)\n";
#endif
			Container = other.Container;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		EntryData(Base<T> * container, unsigned int off, unsigned int len) : Container::Entry(off, len)
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::EntryData" << "  ++++  " << "EntryData(container, off, len)\n";
#endif
			Container = container;
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}
		virtual ~EntryData()
		{
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "EntryContainer::EntryData" << "  ----  " << "~EntryData()\n";
#endif
			if (Container != NULL)
			{
				Container -> Free(this);
			}
#ifdef ENTRY_CONTAINER_DEBUG
			Debug::Console << Debug::TabDec;
#endif
		}

	private:
		void CheckContainer() const
		{
			if (Container == NULL)
			{
				const char * msg = "EntryContainer::EntryData Entry Container Invalid.";
				//std::cout << msg << "\n";
				throw msg;
			}
		}
		void CheckIndex(unsigned int idx) const
		{
			if (idx >= this -> Length)
			{
#ifdef ENTRY_CONTAINER_DEBUG
				Debug::Console << Debug::TabInc;
				Debug::Console << Debug::Tabs << __FILE__ << ':' << __LINE__ << '\n';
				Debug::Console << Debug::Tabs << idx << " >= " << (this -> Length) << "\n";
#endif
				const char * msg = "EntryContainer::EntryData Index invalid.";
				//std::cout << msg << "\n";
#ifdef ENTRY_CONTAINER_DEBUG
				Debug::Console << Debug::TabDec;
#endif
				throw msg;
			}
		}
	public:
		T * Data() const
		{
			CheckContainer();
			return &((*Container)[Offset]);
		}
	public:
		const T & operator[](unsigned int idx) const
		{
			CheckContainer();
			CheckIndex(idx);
			return (*Container)[Offset + idx];
		}
		const T & operator*() const
		{
			CheckContainer();
			return (*Container)[Offset];
		}
		T & operator[](unsigned int idx)
		{
			CheckContainer();
			CheckIndex(idx);
			Container -> Changed = true;
			return (*Container)[Offset + idx];
		}
		T & operator*()
		{
			CheckContainer();
			Container -> Changed = true;
			return (*Container)[Offset];
		}

	public:
		/*void ShowEntry() const
		{
			std::cout << "{" << Offset << " " << Length << "}";
			std::cout << " ";
			std::cout << "[" << Min() << " " << Max() << "]";
			//for (unsigned int i = 0; i < Length; i++)
			//{
			//	std::cout << " ";
			//	std::cout << (*this)[i];
			//}
			std::cout << "\n";
		}*/

	public:
		void Move(unsigned int offset)
		{
			for (unsigned int i = 0; i < this -> Length; i++)
			{
				(*Container)[offset + i] = (*Container)[this -> Offset + i];
			}
			this -> Offset = offset;
		}
};

};

#endif