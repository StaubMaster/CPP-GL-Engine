#ifndef  ENTRY_CONTAINER_BASE_HPP
# define ENTRY_CONTAINER_BASE_HPP

# include "Entry.hpp"

# include "Miscellaneous/Container/Dynamic.hpp"

/*
what should it do ?
different Sizing options like with basic Containers

not sure why I would need Fit ?

also for Fixed I want to delay Compacting/Reordering for when it is needed

and with Binary it whould maybe only do that when Update is called ?
or just have a function for Compacting

Fixed would be better with a Function that reorders the minimum amount of data
to make space for another chunk of data

right now the basic Container have their behaviour hardcoded based on inheritance
instead do it with flags ?

when creating it you need to specify flags, and the default is Binary/None ? maybe Fit ?
for the gaps, make a simple struct that has Offset and Length, then use that in Entrys ?
Container::Area ?
Container::Entry ? might get confusing
	althought they kind of are the same
	and they are in different namespaces

*/

namespace EntryContainer
{

template<typename T>
class Base
{
	protected:
		Container::Dynamic<EntryData<T>*> Entrys;

	protected:
		unsigned int Limit;
		T * Data;

	public:
		bool Changed;

	public:
		Base() :
			Entrys(Container::IncreaseBehaviour::Binary, Container::DecreaseBehaviour::Binary)
		{
			Limit = 0;
			Data = new T[Limit];
			Changed = false;
		}
		Base(unsigned int size) :
			Entrys(Container::IncreaseBehaviour::Binary, Container::DecreaseBehaviour::Binary)
		{
			Limit = size;
			Data = new T[Limit];
			Changed = false;
		}
		virtual ~Base()
		{
			delete[] Data;
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				Entrys[i] -> Container = NULL;
				delete Entrys[i];
			}
		}

	public:
		void ShowData() const
		{
			std::cout << "Container Data: " << Limit << "\n";
			for (unsigned int i = 0; i < Limit; i++)
			{
				//if ((i % 8) == 0) { if (i != 0) { std::cout << "\n"; } }
				//else { std::cout << " "; }
				if (i != 0) { std::cout << " "; }
				std::cout << Data[i];
			}
			if (Limit != 0) { std::cout << "\n"; }
		}
		void ShowEntrys() const
		{
			std::cout << "Entrys " << Entrys.Count() << "\n";
			for (unsigned int i = 0; i < Entrys.Count(); i++)
			{
				std::cout << "[" << i << "]";
				Entrys[i] -> ShowEntry();
			}
		}

	public:
		T * DataPointer(unsigned int offset)
		{
			return &(Data[offset]);
		}
		const T * ToPointer(unsigned int & limit)
		{
			limit = Limit;
			return Data;
		}

	public:
		virtual void Free(EntryData<T> * entry) = 0;
		virtual EntryData<T> * Alloc(unsigned int count) = 0;
};

};

#endif
