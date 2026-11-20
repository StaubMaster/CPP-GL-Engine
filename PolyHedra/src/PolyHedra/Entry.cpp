#include "PolyHedra/Entry.hpp"
#include "PolyHedra/Parser.hpp"



PolyHedraEntry::PolyHedraEntry(PolyHedraManager & manager)
	: Manager(manager)
{ }

void PolyHedraEntry::Load()
{
	if (Data != nullptr)
	{
		delete Data;
	}

	Data = PolyHedraParser::Load(File, &Manager);
}
