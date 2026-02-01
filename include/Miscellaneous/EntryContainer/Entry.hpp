#ifndef  ENTRY_CONTAINER_ENTRY_HPP
# define ENTRY_CONTAINER_ENTRY_HPP

# include "EntryData.hpp"

# include <iostream>

namespace EntryContainer
{

template<typename T>
class Entry
{
	private:
	public:
	EntryData<T> * Data;

	public:
	virtual void DebugInfo() { }

	public:
	Entry()
	{
		Data = NULL;
	}
	Entry(Base<T> & container, unsigned int count)
	{
		Data = container.Alloc(count);
	}
	~Entry()
	{
		delete Data;
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
		if (other.Data != NULL)
		{
			Data = other.Data -> Container -> Copy(other.Data);
		}
		else
		{
			Data = NULL;
		}
	}
	Entry<T> & operator =(const Entry<T> & other)
	{
		Dispose();
		if (other.Data != NULL)
		{
			Data = other.Data -> Container -> Copy(other.Data);
		}
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
			const char * msg = "EntryContainer::Entry Index invalid.";
			//std::cout << msg << "\n";
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