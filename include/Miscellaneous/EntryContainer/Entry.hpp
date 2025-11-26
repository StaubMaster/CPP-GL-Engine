#ifndef  ENTRY_CONTAINER_ENTRY_HPP
# define ENTRY_CONTAINER_ENTRY_HPP

# define INVALID_INDEX 0xFFFFFFFF

# include "Miscellaneous/Container/Entry.hpp"

/*	nonPointer Entry

it needs to use Pointers because they need to be syncronized
for both Container and User

make a Wrappar that has a Pointer to the Entry internally
but can be used as a non Pointer ?

what needs to be stored in the internal one ?
	Index
	Offset
	Length
Container dosent need to be internal
since it is basically constant ?
it is set to NULL when the Entry is invalid but this can be done in other ways
but maybe just keep it since that would be easier

*/

namespace EntryContainer
{

template<typename T> class Base;

template<typename T>
class EntryData : public Container::Entry
{
	public:
		Base<T> * Container;
		unsigned int Index;

	public:
		EntryData() : Container::Entry()
		{
			Container = NULL,
			Index = INVALID_INDEX;
		}
		EntryData(const EntryData & other) : Container::Entry(other)
		{
			Container = other.Container;
			Index = other.Index;
		}
		EntryData(Base<T> * container, unsigned int idx, unsigned int off, unsigned int len) : Container::Entry(off, len)
		{
			Container = container;
			Index = idx;
		}
		virtual ~EntryData()
		{
			if (Container != NULL)
			{
				Container -> Free(this);
			}
		}

	public:
		T & operator[](unsigned int idx)
		{
			if (Container == NULL)
			{
				std::cout << "EntryContainer::Entry Entry Invalid." << "\n";
				throw "EntryContainer::Entry Entry Invalid.";
			}
			if (idx >= Length)
			{
				std::cout << "EntryContainer::Entry Index out of Range." << "\n";
				throw "EntryContainer::Entry Index out of Range.";
			}
			Container -> Changed = true;
			return (Container -> DataPointer(Offset))[idx];
		}
		T & operator*()
		{
			if (Container == NULL)
			{
				std::cout << "EntryContainer::Entry Entry Invalid." << "\n";
				throw "EntryContainer::Entry Entry Invalid.";
			}
			Container -> Changed = true;
			return *(Container -> DataPointer(Offset));
		}

	public:
		void ShowEntry() const
		{
			std::cout << "Entry";
			std::cout << "(" << this << ")";
			std::cout << " [" << Index << "] ";
			std::cout << Container;
			std::cout << "\n";
		}
};

/*	Problem with Copying
if the Entry E0 gets returned from the Alloc function
it gets put into outside variable E1
then E0 gets deleted, since it is temporary
now E1 has undefined Data

get rid of Copy ?
much like Dispose, give the Alloc function to Entry ?
give it an Container, Size constructor as well


*/

template<typename T>
class Entry
{
	private:
		EntryData<T> * Data;

	public:
		Entry()
		{
			std::cout << "  ++++ Entry()\n";
			Data = NULL;
		}
		Entry(Base<T> & container, unsigned int count)
		{
			std::cout << "  ++++ Entry(container, count)\n";
			Data = container.Alloc(count);
		}
		~Entry()
		{
			std::cout << "  ---- ~Entry()\n";
			delete Data;
		}

		Entry(const Entry<T> & other) = delete;
		Entry<T> & operator =(const Entry<T> & other) = delete;

	public:
		unsigned int Length() const { return Data -> Length; }

	public:
		const T & operator[](unsigned int idx) const
		{
			if (Data -> Container == NULL)
			{
				std::cout << "EntryContainer::Entry Entry Invalid." << "\n";
				throw "EntryContainer::Entry Entry Invalid.";
			}
			if (idx >= Data -> Length)
			{
				std::cout << "EntryContainer::Entry Index out of Range." << "\n";
				throw "EntryContainer::Entry Index out of Range.";
			}
			Data -> Container -> Changed = true;
			return (Data -> Container -> DataPointer(Data -> Offset))[idx];
		}
		const T & operator*() const
		{
			if (Data -> Container == NULL)
			{
				std::cout << "EntryContainer::Entry Entry Invalid." << "\n";
				throw "EntryContainer::Entry Entry Invalid.";
			}
			return *(Data -> Container -> DataPointer(Data -> Offset));
		}
		T & operator[](unsigned int idx)
		{
			if (Data -> Container == NULL)
			{
				std::cout << "EntryContainer::Entry Entry Invalid." << "\n";
				throw "EntryContainer::Entry Entry Invalid.";
			}
			if (idx >= Data -> Length)
			{
				std::cout << "EntryContainer::Entry Index out of Range." << "\n";
				throw "EntryContainer::Entry Index out of Range.";
			}
			return (Data -> Container -> DataPointer(Data -> Offset))[idx];
		}
		T & operator*()
		{
			if (Data -> Container == NULL)
			{
				std::cout << "EntryContainer::Entry Entry Invalid." << "\n";
				throw "EntryContainer::Entry Entry Invalid.";
			}
			Data -> Container -> Changed = true;
			return *(Data -> Container -> DataPointer(Data -> Offset));
		}

	public:
		void Allocate(Base<T> & container, unsigned int count)
		{
			Dispose();
			Data = container.Alloc(count);
		}
		void Dispose()
		{
			if (Data != NULL)
			{
				delete Data;
				Data = NULL;
			}
		}
};

};

#endif