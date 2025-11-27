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

	private:
		void CheckContainer() const
		{
			if (Container == NULL)
			{
				const char * msg = "EntryContainer::EntryData Entry Container Invalid.";
				std::cout << msg << "\n";
				throw msg;
			}
		}
		void CheckIndex(unsigned int idx) const
		{
			if (idx >= Length)
			{
				const char * msg = "EntryContainer::EntryData Index invalid.";
				std::cout << msg << "\n";
				throw msg;
			}
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
		void ShowEntry() const
		{
			std::cout << "{" << Offset << " " << Length << "}";
			std::cout << " ";
			std::cout << "[" << Min() << " " << Max() << "]";
			for (unsigned int i = 0; i < Length; i++)
			{
				std::cout << " ";
				std::cout << (*this)[i];
			}
			std::cout << "\n";
		}

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

	private:
		//	these are a lot so extra function
		//	once everything works again, turn these into excpetions
		void CheckData() const
		{
			if (Data == NULL)
			{
				const char * msg = "EntryContainer::Entry Entry Invalid.";
				std::cout << msg << "\n";
				throw msg;
			}
		}
		void CheckDataContainer() const
		{
			if (Data -> Container == NULL)
			{
				const char * msg = "EntryContainer::Entry Entry Invalid.";
				std::cout << msg << "\n";
				throw msg;
			}
		}
		void CheckIndex(unsigned int idx) const
		{
			if (idx >= Data -> Length)
			{
				const char * msg = "EntryContainer::Entry Index invalid.";
				std::cout << msg << "\n";
				throw msg;
			}
		}
	public:
		const T & operator[](unsigned int idx) const
		{
			CheckData();
			CheckDataContainer();
			CheckIndex(idx);
			//Data -> Container -> Changed = true;
			//return (Data -> Container -> DataPointer(Data -> Offset))[idx];
			return (*Data)[idx];
		}
		const T & operator*() const
		{
			CheckData();
			CheckDataContainer();
			//return *(Data -> Container -> DataPointer(Data -> Offset));
			return *(*Data);
		}
		T & operator[](unsigned int idx)
		{
			CheckData();
			CheckDataContainer();
			CheckIndex(idx);
			//return (*Data)[idx];
			return (*Data)[idx];
		}
		T & operator*()
		{
			CheckData();
			CheckDataContainer();
			//return *(*Data);
			return *(*Data);
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