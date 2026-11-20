#include "PolyHedra/Manager.hpp"
#include "PolyHedra/Entry.hpp"
#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Parser.hpp"



void PolyHedraManager::Clear()
{
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		delete Entrys[i] -> Data;
		delete Entrys[i];
	}
	Entrys.Clear();
}

PolyHedraEntry * PolyHedraManager::Make(const FileInfo & file)
{
	PolyHedraEntry * entry = new PolyHedraEntry();
	entry -> File = file;
	entry -> Load(*this);
	//PolyHedra * object = PolyHedraParser::Load(file, nullptr, this, entry); // do Loading in Entry ?. have Manager Pointer in Entry
	//if (object == nullptr)
	if (entry -> Data == nullptr)
	{
		delete entry;
		return nullptr;
	}
	Entrys.Insert(entry);
	return entry;
}
PolyHedraEntry * PolyHedraManager::Find(const FileInfo & file) const
{
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		const PolyHedraEntry & entry = *Entrys[i];
		if (std::string(entry.File.Path.ToString()) == std::string(file.Path.ToString())) // File Path Comparison
		{
			return Entrys[i];
		}
	}
	return nullptr;
}
PolyHedraEntry * PolyHedraManager::Take(const FileInfo & file)
{
	PolyHedraEntry * entry = Find(file);
	if (entry != nullptr)
	{
		return entry;
	}
	return Make(file);
}

PolyHedraEntry * PolyHedraManager::Find(const PolyHedra * polyhedra) const
{
	if (polyhedra == nullptr) { return nullptr; }
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		if (Entrys[i] -> Data == polyhedra)
		{
			return Entrys[i];
		}
	}
	return nullptr;
}

PolyHedra * PolyHedraManager::Find_Data(const FileInfo & file) const
{
	PolyHedraEntry * entry = Find(file);
	if (entry != nullptr) { return entry -> Data; }
	return nullptr;
}
PolyHedra * PolyHedraManager::Take_Data(const FileInfo & file)
{
	PolyHedraEntry * entry = Take(file);
	if (entry != nullptr) { return entry -> Data; }
	return nullptr;
}

#include <iostream>
void PolyHedraManager::ToInfo(std::ostream & s) const
{
	s << "PolyHedraManager: " << Entrys.Count() << '\n';
	s << "[\n";
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		const PolyHedraEntry & entry = *Entrys[i];
		s << "  " << entry.File << '\n';
	}
	s << "]\n";
}



PolyHedraManager * PolyHedraManager::Current_ = nullptr;
PolyHedraManager & PolyHedraManager::Current() { return *Current_; }
bool PolyHedraManager::CheckCurrent() { return (Current_ != nullptr); }
void PolyHedraManager::ClearCurrent() { Current_ = nullptr; }
bool PolyHedraManager::IsCurrent() const { return (Current_ == this); }
void PolyHedraManager::MakeCurrent() { Current_ = this; }

PolyHedraEntry * PolyHedraManager::sFind(const FileInfo & file) { if (CheckCurrent()) { return Current().Find(file); } return nullptr; }
PolyHedraEntry * PolyHedraManager::sTake(const FileInfo & file) { if (CheckCurrent()) { return Current().Take(file); } return nullptr; }

PolyHedraEntry * PolyHedraManager::sFind(const PolyHedra * polyhedra) { if (CheckCurrent()) { return Current().Find(polyhedra); } return nullptr; }

PolyHedra * PolyHedraManager::sFind_Data(const FileInfo & file) { if (CheckCurrent()) { return Current().Find_Data(file); } return nullptr; }
PolyHedra * PolyHedraManager::sTake_Data(const FileInfo & file) { if (CheckCurrent()) { return Current().Take_Data(file); } return nullptr; }
