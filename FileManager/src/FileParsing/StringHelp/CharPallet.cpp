#include "FileParsing/StringHelp/CharPallet.hpp"



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
