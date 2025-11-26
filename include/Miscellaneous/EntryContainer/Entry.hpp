#ifndef  ENTRY_CONTAINER_ENTRY_HPP
# define ENTRY_CONTAINER_ENTRY_HPP

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
		EntryData() : Container::Entry()
		{
			Container = NULL;
		}
		EntryData(const EntryData & other) : Container::Entry(other)
		{
			Container = other.Container;
		}
		EntryData(Base<T> * container, unsigned int off, unsigned int len) : Container::Entry(off, len)
		{
			Container = container;
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
			std::cout << "{" << Offset << " " << Length << "}";
			std::cout << " ";
			std::cout << "[" << Min() << " " << Max() << "]";
			std::cout << "\n";
		}
};

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