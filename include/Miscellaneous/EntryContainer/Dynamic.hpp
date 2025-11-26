#ifndef  ENTRY_CONTAINER_DYNAMIC_HPP
# define ENTRY_CONTAINER_DYNAMIC_HPP

# include "Base.hpp"

/*	Behaviour
borrow from regular Containers
more:
	bool Compact_immediately
	void Compact_Entrys()
		removes any gaps between Data
		when would this have to be done immediately ?
		allways only do it on command ?
	bool IsCompact() const
		to maybe save time ?
		or just remember via Variable
		change it when Gaps apprear ?

	bool AttemptReorganizing;
	bool ReorganizeToFit(size)
		attempts to move around data without reallocating
		to make space for size
		false if it cant
*/

/*	Base vs Dynamic
everything is handled dynamically
so it could all be put in the Base ?
*/

/*	what do I need here ?

Compact Buffers
for a draw call, the Data needs to be Compact
so for MainBuffers and InstBuffers, all the data needs to be together

nonCompact
Surface Chunks. the version in C# now puts a lot of Surface into 1 Buffer
and then draws different sections of that Buffer
these also are Fixed size
not fully sure how much this saves on performance
also it could maybe used in other places ?

*/

namespace EntryContainer
{

template<typename T>
class Dynamic : public Base<T>
{
	public:
		unsigned int Count;

	public:
		Dynamic() : Base<T>(0)
		{
			Count = 0;
		}
		~Dynamic()
		{ }

	private:
		void CopyNewLimit(unsigned int limit)
		{
			T * data = new T[limit];

			unsigned int l = Count;
			if (limit < l) { l = limit; }

			for (unsigned int i = 0; i < l; i++)
			{
				data[i] = this -> Data[i];
			}

			this -> Limit = limit;
			delete[] (this -> Data);
			this -> Data = data;
		}
		void Grow(unsigned int count)
		{
			if (Count + count > (this -> Limit))
			{
				CopyNewLimit(Count + count);
			}
		}

	public:
		bool IsCompact() const
		{
			unsigned int data_idx = 0;
			for (unsigned int i = 0; i < this -> Entrys.Count(); i++)
			{
				EntryData<T> * entry = this -> FindEntryByData(data_idx);
				if (entry == NULL) { return false; }
				if (entry -> Offset != data_idx) { return false; }
				data_idx += entry -> Length;
			}
			if (Count != data_idx) { return false; }
			return true;
		}
		void MakeCompact()
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

			delete[] this -> Data;
			this -> Data = data;
			this -> Limit = limit;
		}

	public:
		EntryData<T> * Alloc(unsigned int count) override
		{
			Grow(count);

			EntryData<T> * entry = new EntryData<T>(this, Count, count);
			this -> Entrys.Insert(entry);
			this -> Changed = true;

			Count += count;
			return entry;
		}
		void Free(EntryData<T> * entry) override
		{
			this -> Changed = true;

			unsigned int entry_idx = this -> FindEntryIndex(entry);
			if (entry_idx == 0xFFFFFFFF)
			{
				std::cout << "EntryContainer::Dynamic Entry not found." << "\n";
				throw "EntryContainer::Dynamic Entry not found.";
			}

			this -> Entrys.Remove(entry_idx);
			entry -> Container = NULL;
			Count -= entry -> Length;
		}
};

};

#endif
