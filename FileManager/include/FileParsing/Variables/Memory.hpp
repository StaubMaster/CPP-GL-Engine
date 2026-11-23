#ifndef  PARSING_VARIABLE_MEMORY_HPP
# define PARSING_VARIABLE_MEMORY_HPP

# include "FileParsing/Variables/Entry.hpp"
# include "FileParsing/Variables/Exception.hpp"

# include "Generics/Container/Binary.hpp"

struct VariableEntryBase;
struct VariableMemory
{
	Container::Binary<VariableEntryBase*>		Entrys;

	~VariableMemory();

	VariableEntryBase *		Find(const std::string & name) const;

	static bool		CheckIndex(std::string & name, unsigned int & idx);

	template<typename Type> void	Set(const std::string & name, const Type & data)
	{
		std::string		array_name = name;
		unsigned int	array_index;
		if (CheckIndex(array_name, array_index))
		{
			VariableEntryBase * entry_base = Find(array_name);
			VariableEntryType<Container::Array<Type>> * entry_type = dynamic_cast<VariableEntryType<Container::Array<Type>>*>(entry_base);
			if (entry_base == nullptr)
			{
				throw VariableNotFound(name);
			}
			if (entry_type == nullptr)
			{
				throw VariableIncorrentType(name);
			}
			entry_type -> Data[array_index] = data;
			return;
		}
		VariableEntryBase * entry_base = Find(name);
		VariableEntryType<Type> * entry_type = dynamic_cast<VariableEntryType<Type>*>(entry_base);
		if (entry_base == nullptr)
		{
			entry_type = new VariableEntryType<Type>();
			entry_type -> Name = name;
			Entrys.Insert(entry_type);
		}
		if (entry_type == nullptr)
		{
			throw VariableIncorrentType(name);
		}
		entry_type -> Data = data;
	}
	template<typename Type> void	Get(const std::string & name, Type & data) const
	{
		std::string		array_name = name;
		unsigned int	array_index;
		if (CheckIndex(array_name, array_index))
		{
			const VariableEntryBase * entry_base = Find(array_name);
			const VariableEntryType<Container::Array<Type>> * entry_type = dynamic_cast<const VariableEntryType<Container::Array<Type>>*>(entry_base);
			if (entry_base == nullptr)
			{
				throw VariableNotFound(name);
			}
			if (entry_type == nullptr)
			{
				throw VariableIncorrentType(name);
			}
			data = entry_type -> Data[array_index];
			return;
		}
		const VariableEntryBase * entry_base = Find(name);
		const VariableEntryType<Type> * entry_type = dynamic_cast<const VariableEntryType<Type>*>(entry_base);
		if (entry_base == nullptr)
		{
			throw VariableNotFound(name);
		}
		if (entry_type == nullptr)
		{
			throw VariableIncorrentType(name);
		}
		data = entry_type -> Data;
	}
	template<typename Type> Type	Get(const std::string & name) const
	{
		Type data;
		Get(name, data);
		return data;
	}
};

#endif