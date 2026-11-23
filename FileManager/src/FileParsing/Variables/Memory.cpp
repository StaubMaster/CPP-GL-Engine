#include "FileParsing/Variables/Memory.hpp"



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
