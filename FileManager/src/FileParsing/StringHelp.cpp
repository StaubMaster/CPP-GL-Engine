#include "FileParsing/StringHelp.hpp"



StringHelp::CharPallet::CharPallet(const char * pallet)
{
	Characters = pallet;
	Count = 0; while (Characters[Count] != '\0') { Count++; }
}
bool StringHelp::CharPallet::Check(char c) const
{
	for (size_t i = 0; i < Count; i++)
	{
		if (Characters[i] == c) { return true; }
	}
	return false;
}
size_t StringHelp::CharPallet::FindNext(const std::string & str, size_t idx) const
{
	while (idx < str.length())
	{
		if (Check(str[idx]))
		{
			return idx;
		}
		idx++;
	}
	return std::string::npos;
}
size_t StringHelp::CharPallet::FindPrev(const std::string & str) const
{
	size_t idx = str.length() - 1;
	while (idx < str.length())
	{
		if (Check(str[idx]))
		{
			return idx;
		}
		idx--;
	}
	return std::string::npos;
}



StringHelp::Section::Section(const size_t & off, const size_t & len)
	: Offset(off)
	, Length(len)
{ }
std::string StringHelp::Section::SubString(const std::string & str) const
{
	return str.substr(Offset, Length);
}
std::string StringHelp::Section::Erase(const std::string & str) const
{
	std::string str_copy(str);
	return str_copy.erase(Offset, Length);
}

StringHelp::Range::Range(const size_t & idx0, const size_t & idx1)
	: Index0(idx0)
	, Index1(idx1)
{ }
StringHelp::Section StringHelp::Range::Inclusive() const
{
	return Section(Index0, (Index1 - Index0) + 1);
}
StringHelp::Section StringHelp::Range::Exclusive() const
{
	return Section(Index0 + 1, (Index1 - Index0) - 1);
}
//std::string StringHelp::Range::CutInIn(const std::string & str) const { }
std::string StringHelp::Range::CutInEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return std::string(); }
	if (Index1 == std::string::npos) { return str.substr(Index0); }
	return str.substr(Index0, Index1 - Index0);
}
//std::string StringHelp::Range::CutExEx(const std::string & str) const { }

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
		if (range.Index0 != std::string::npos) { if (pallet0.Check(str[i])) { range.Index0 = i; } }
		if (range.Index1 != std::string::npos) { if (pallet1.Check(str[i])) { range.Index1 = i; } }
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
