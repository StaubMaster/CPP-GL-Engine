#ifndef  ENTRY_CONTAINER_ENTRY_HPP
# define ENTRY_CONTAINER_ENTRY_HPP

# define INVALID_INDEX 0xFFFFFFFF

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
class Entry
{
	private:
		Base<T> * Container;
		unsigned int Index;

	public:
		unsigned int Offset;
		unsigned int Length;

	public:
		Entry()
		{
			Container = NULL,
			Index = INVALID_INDEX;
			Offset = 0;
			Length = 0;
		}
		Entry(const Entry & other)
		{
			Container = other.Container;
			Index = other.Index;
			Offset = other.Offset;
			Length = other.Length;
		}
		Entry(Base<T> * container, unsigned int idx, unsigned int off, unsigned int len)
		{
			Container = container;
			Index = idx;
			Offset = off;
			Length = len;
		}
		virtual ~Entry()
		{
			Container = NULL;
			Index = 0;
			Offset = 0;
			Length = 0;
			//	should only be deleted by Container
			//	so dont need to handle removing it from container ?
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

	public:
		void ChangeContainer(Base<T> * container)
		{
			//std::cout << "change Index from " << Container << " to " << container << "\n";
			Container = container;
		}
		Base<T> * ChangeContainer()
		{
			return Container;
		}
		void ChangeIndex(unsigned int index)
		{
			/*
			if (index == INVALID_INDEX)
			{ std::cout << "change Index from " << Index << " to " << "Invalid" << "\n"; }
			else
			{ std::cout << "change Index from " << Index << " to " << index << "\n"; }
			*/
			Index = index;
		}
		unsigned int ChangeIndex()
		{
			return Index;
		}

	public:
		void Dispose()
		{
			if (Container != NULL)
			{
				Container -> Free(this);
				ChangeContainer(NULL);
				ChangeIndex(INVALID_INDEX);
			}
		}
};

};

#endif