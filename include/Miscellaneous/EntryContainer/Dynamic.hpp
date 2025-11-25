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
		void Free(Entry<T> * entry) override
		{
			if (entry -> ChangeIndex() >= this -> Entrys.Count())
			{
				std::cout << "EntryContainer::Dynamic Entry Index out of Range." << "\n";
				throw "EntryContainer::Dynamic Entry Index out of Range.";
			}
			if (entry != this -> Entrys[entry -> ChangeIndex()])
			{
				std::cout << "EntryContainer::Dynamic Entry Index invalid." << "\n";
				throw "EntryContainer::Dynamic Entry Index invalid.";
			}
			this -> Changed = true;

			unsigned int off0 = entry -> Offset;
			unsigned int off1 = entry -> Length + off0;

			this -> Entrys.Remove(entry -> ChangeIndex());

			{
				unsigned int offset = 0;
				for (unsigned int i = 0; i < this -> Entrys.Count(); i++)
				{
					this -> Entrys[i] -> Offset = offset;
					offset += this -> Entrys[i] -> Length;
					this -> Entrys[i] -> ChangeIndex(i);
				}
			}

			{
				while (off1 < Count)
				{
					this -> Data[off0] = this -> Data[off1];
					off0++;
					off1++;
				}
				this -> Limit = off0;
			}
		}
		Entry<T> * Alloc(unsigned int count) override
		{
			Grow(count);

			Entry<T> * entry = new Entry<T>(this, this -> Entrys.Count(), Count, count);
			this -> Entrys.Insert(entry);
			this -> Changed = true;

			Count += count;
			return entry;
		}
};

};

#endif
