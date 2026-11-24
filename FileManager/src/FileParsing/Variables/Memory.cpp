#include "FileParsing/Variables/Memory.hpp"
#include "FileParsing/StringHelp/General.hpp"
#include "FileParsing/StringHelp/CharPallet.hpp"
#include "FileParsing/StringHelp/Range.hpp"



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

bool VariableMemory::CheckIndex(std::string & name, unsigned int & idx)
{
	StringHelp::Range range = StringHelp::FindPrevPair(name, StringHelp::CharPallet("["), StringHelp::CharPallet("]"));

	if (range.Index0 == std::string::npos || range.Index1 == std::string::npos)
	{
		return false;
	}
	if (range.Index0 >= range.Index1)
	{
		// throw error if not normal ?
		return false;
	}

	std::string idx_str = range.CutExEx(name);
	name = range.EraseInIn(name);
	idx = std::stoul(idx_str);

	return true;
}
