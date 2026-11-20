#include "PolyHedra/Entry.hpp"
#include "PolyHedra/Parser.hpp"



void PolyHedraEntry::Load(PolyHedraManager & manager)
{
	if (Data != nullptr)
	{
		delete Data;
	}

	Data = PolyHedraParser::Load(File, nullptr, &manager, this);
}
