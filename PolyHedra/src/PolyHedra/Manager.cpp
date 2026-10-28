#include "PolyHedra/Manager.hpp"
#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Parser.hpp"



PolyHedra * PolyHedraManager::Find(const FileInfo & file) const
{
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		const PolyHedraEntry & entry = Entrys[i];
		if (std::string(entry.File.Path.ToString()) == std::string(file.Path.ToString())) // File Path Comparison
		{
			return entry.Object;
		}
	}
	return nullptr;
}



PolyHedra * PolyHedraManager::Make(const FileInfo & file)
{
	PolyHedraEntry entry;
	PolyHedra * object = PolyHedraParser::Load(file, nullptr, this, &entry);
	if (object == nullptr) { return nullptr; }
	if (entry.Parameters == nullptr)
	{
		Entrys.Insert(entry);
	}
	return object;
}
PolyHedra * PolyHedraManager::Make(const FileInfo & file, const PolyHedraParser & parser)
{
	PolyHedraEntry entry;
	PolyHedra * object = PolyHedraParser::Load(file, &parser, this, &entry);
	if (object == nullptr) { return nullptr; }
	if (entry.Parameters == nullptr)
	{
		Entrys.Insert(entry);
	}
	return object;
}



PolyHedra * PolyHedraManager::Take(const FileInfo & file)
{
	PolyHedra * object = Find(file);
	if (object != nullptr)
	{
		return object;
	}
	return Make(file);
}
PolyHedra * PolyHedraManager::Take(const FileInfo & file, const PolyHedraParser & parser)
{
	PolyHedra * object = Find(file);
	if (object == nullptr)
	{
		return object;
	}
	return Make(file, parser);
}



#include <iostream>
void PolyHedraManager::ToInfo(std::ostream & s) const
{
	s << "PolyHedraManager: " << Entrys.Count() << '\n';
	s << "[\n";
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		const PolyHedraEntry & entry = Entrys[i];
		s << "  " << entry.File << '\n';
	}
	s << "]\n";
}
