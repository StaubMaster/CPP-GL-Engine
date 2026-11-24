#include "FileParsing/StringHelp/General.hpp"
#include "FileParsing/StringHelp/CharPallet.hpp"
#include "FileParsing/StringHelp/Range.hpp"



StringHelp::Range StringHelp::FindNextPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1, size_t idx)
{
	Range range;
	for (; idx < str.length(); idx++)
	{
		if (range.Index0 != std::string::npos) { if (pallet0.Check(str[idx])) { range.Index0 = idx; } }
		if (range.Index1 != std::string::npos) { if (pallet1.Check(str[idx])) { range.Index1 = idx; } }
		if (range.Index0 != std::string::npos && range.Index1 != std::string::npos) { break; }
	}
	return range;
}
StringHelp::Range StringHelp::FindPrevPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1)
{
	Range range;
	for (size_t i = str.length() - 1; i < str.length(); i--)
	{
		if (range.Index0 == std::string::npos) { if (pallet0.Check(str[i])) { range.Index0 = i; } }
		if (range.Index1 == std::string::npos) { if (pallet1.Check(str[i])) { range.Index1 = i; } }
		if (range.Index0 != std::string::npos && range.Index1 != std::string::npos) { break; }
	}
	return range;
}



std::string StringHelp::CutAll(const std::string & str, const CharPallet & pallet)
{
	Range range;
	range.Index0 = 0;
	range.Index1 = pallet.FindNext(str, range.Index0);

	std::string s = "";
	while (range.Index1 != std::string::npos)
	{
		s += range.CutInEx(str);
		range.Index0 = range.Index1 + 1;
		range.Index1 = pallet.FindNext(str, range.Index0);
	}
	s += range.CutInEx(str);
	return s;
}

std::string StringHelp::CutAllPairsInEx(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1)
{
	Range range;
	range.Index0 = 0;
	range.Index1 = pallet0.FindNext(str, range.Index0);

	std::string s;
	while (range.Index1 != std::string::npos)
	{
		s += range.CutInEx(str);
		range.Index0 = pallet1.FindNext(str, range.Index1);
		if (range.Index0 == std::string::npos)
		{
			break;
		}
		range.Index0++;
		range.Index1 = pallet0.FindNext(str, range.Index0);
		if (range.Index1 == std::string::npos)
		{
			break;
		}
	}
	s += range.CutInEx(str);
	return s;
}
