#include "FileParsing/StringHelp/CharPallet.hpp"



CharPallet::CharPallet(char pallet)
	: Pallet(1, pallet)
{ }
CharPallet::CharPallet(const char * pallet)
	: Pallet(pallet)
{ }
CharPallet::CharPallet(const std::string & pallet)
	: Pallet(pallet)
{ }

bool CharPallet::Check(char c) const
{
	for (size_t i = 0; i < Pallet.length(); i++)
	{
		if (Pallet[i] == c) { return true; }
	}
	return false;
}

size_t CharPallet::FindNext(const std::string & str, size_t idx) const
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
size_t CharPallet::FindPrev(const std::string & str) const
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

size_t CharPallet::FindNextNot(const std::string & str, size_t idx) const
{
	while (idx < str.length())
	{
		if (!Check(str[idx]))
		{
			return idx;
		}
		idx++;
	}
	return std::string::npos;
}
size_t CharPallet::FindPrevNot(const std::string & str) const
{
	size_t idx = str.length() - 1;
	while (idx < str.length())
	{
		if (!Check(str[idx]))
		{
			return idx;
		}
		idx--;
	}
	return std::string::npos;
}

#include "FileParsing/StringHelp/StringRange.hpp"
std::string CharPallet::Leave(const std::string & str) const
{
	StringRange range;
	range.Index0 = FindNext(str, 0);
	range.Index1 = FindNextNot(str, range.Index0);
	std::string s = range.LeaveInEx(str);
	while (range.Index1 != std::string::npos)
	{
		range.Index0 = FindNext(str, range.Index1);
		range.Index1 = FindNextNot(str, range.Index0);
		s += range.LeaveInEx(str);
	}
	return s;
}
std::string CharPallet::Erase(const std::string & str) const
{
	StringRange range;
	range.Index0 = FindNextNot(str, 0);
	range.Index1 = FindNext(str, range.Index0);
	std::string s = range.LeaveInEx(str);
	while (range.Index1 != std::string::npos)
	{
		range.Index0 = FindNextNot(str, range.Index1);
		range.Index1 = FindNext(str, range.Index0);
		s += range.LeaveInEx(str);
	}
	return s;
}

#include "Generics/Container/Binary.hpp"
Container::Array<std::string> CharPallet::EraseSplit(const std::string & str) const
{
	Container::Binary<std::string> segments;
	StringRange range;
	range.Index0 = FindNextNot(str, 0);
	range.Index1 = FindNext(str, range.Index0);
	while (range.Index1 != std::string::npos)
	{
		segments.Insert(range.LeaveInEx(str));
		range.Index0 = FindNextNot(str, range.Index1);
		range.Index1 = FindNext(str, range.Index0);
	}
	if (range.Index0 != std::string::npos)
	{
		segments.Insert(range.LeaveInEx(str));
	}
	return segments.ToArray();
}
