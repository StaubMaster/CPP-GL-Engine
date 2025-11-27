#ifndef  ENTRY_CONTAINER_DYNAMIC_HPP
# define ENTRY_CONTAINER_DYNAMIC_HPP

# include "Base.hpp"
# include "Miscellaneous/Container/Dynamic.hpp"

namespace EntryContainer
{

template<typename T>
class Dynamic : public Base<T>
{
	protected:
		unsigned int _Count;

	public:
		Dynamic() : Base<T>(0)
		{
			_Count = 0;
		}
		~Dynamic()
		{ }

	public:
		unsigned int Count() const { return _Count; }

	public:
		void ShowData() const override
		{
			std::cout << "Container Data: " << _Count << " " << this -> _Limit << "\n";
			for (unsigned int i = 0; i < this -> _Limit; i++)
			{
				//if ((i % 8) == 0) { if (i != 0) { std::cout << "\n"; } }
				//else { std::cout << " "; }
				if (i != 0) { std::cout << " "; }
				std::cout << this -> _Data[i];
			}
			if (this -> _Limit != 0) { std::cout << "\n"; }
		}

	private:
		/*	this is the old system or changing Size
			change this to use new Container Behaviour
			first fix Container::Base and Container::Dynamic being the same
		*/
		void CopyNewLimit(unsigned int limit)
		{
			T * data = new T[limit];

			unsigned int l = _Count;
			if (limit < l) { l = limit; }

			for (unsigned int i = 0; i < l; i++)
			{
				data[i] = this -> _Data[i];
			}

			this -> _Limit = limit;
			delete[] (this -> _Data);
			this -> _Data = data;
		}
		void Grow(unsigned int count)
		{
			if (_Count + count > (this -> _Limit))
			{
				CopyNewLimit(_Count + count);
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
			if (_Count != data_idx) { return false; }
			return true;
		}
		void CompactLimit()
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

			delete[] this -> _Data;
			this -> _Data = data;
			this -> _Limit = limit;
		}
		void CompactHere()
		{
			unsigned int data_idx = 0;
			EntryData<T> * entry = this -> FindNextEntry(data_idx);
			while (entry != NULL)
			{
				entry -> Move(data_idx);
				data_idx = entry -> Max();
				entry = this -> FindNextEntry(data_idx);
			}
		}

	public:
		EntryData<T> * Alloc(unsigned int count) override
		{
			Grow(count);

			EntryData<T> * entry = new EntryData<T>(this, _Count, count);
			this -> Entrys.Insert(entry);
			this -> Changed = true;

			_Count += count;
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
			_Count -= entry -> Length;
		}
};

};

#endif
