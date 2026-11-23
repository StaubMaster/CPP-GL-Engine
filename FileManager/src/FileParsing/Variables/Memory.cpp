#include "FileParsing/Variables/Memory.hpp"
#include "FileParsing/StringHelp.hpp"



VariableMemory::~VariableMemory()
{
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		delete Entrys[i];
	}
}

VariableEntryBase * VariableMemory::Find(const std::string & name) const
{
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		if (Entrys[i] -> Name == name)
		{
			return Entrys[i];
		}
	}
	return nullptr;
}

static std::string	SubStringFromTo(const std::string & str, size_t idx0, size_t idx1)
{
	return str.substr(idx0, (idx1 - idx0) + 1);
}
static std::string	EraseFromTo(const std::string & str, size_t idx0, size_t idx1)
{
	std::string str_copy(str);
	return str_copy.erase(idx0, (idx1 - idx0) + 1);
}

struct CharPair
{
	size_t	Index0 = std::string::npos;
	size_t	Index1 = std::string::npos;

	bool	IsValid() const		{ return (Index0 != std::string::npos && Index1 != std::string::npos); }
	bool	IsNormal() const	{ return (Index0 < Index1); }

	std::string		Content(const std::string & str) const		{ return SubStringFromTo(str, Index0 + 1, Index1 - 1); }
	std::string		Remove(const std::string & str) const		{ return EraseFromTo(str, Index0, Index1); }
};

bool VariableMemory::CheckIndex(std::string & name, unsigned int & idx)
{
	CharPair pair;
	pair.Index0 = name.find_last_of('[');
	pair.Index1 = name.find_last_of(']');

	if (!pair.IsValid() || !pair.IsNormal())
	{
		// throw error if not normal ?
		return false;
	}

	std::string idx_str = pair.Content(name);
	name = pair.Remove(name);

	idx = std::stoul(idx_str);
	return true;
}
