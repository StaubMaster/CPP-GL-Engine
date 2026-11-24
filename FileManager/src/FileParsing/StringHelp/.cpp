#include "FileParsing/StringHelp/.hpp"
#include "FileParsing/StringHelp/CharPallet.hpp"
#include "FileParsing/StringHelp/StringRange.hpp"



StringRange StringHelp::FindNextPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1, size_t idx)
{
	StringRange range;
	for (; idx < str.length(); idx++)
	{
		if (range.Index0 != std::string::npos) { if (pallet0.Check(str[idx])) { range.Index0 = idx; } }
		if (range.Index1 != std::string::npos) { if (pallet1.Check(str[idx])) { range.Index1 = idx; } }
		if (range.Index0 != std::string::npos && range.Index1 != std::string::npos) { break; }
	}
	return range;
}
StringRange StringHelp::FindPrevPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1)
{
	StringRange range;
	for (size_t i = str.length() - 1; i < str.length(); i--)
	{
		if (range.Index0 == std::string::npos) { if (pallet0.Check(str[i])) { range.Index0 = i; } }
		if (range.Index1 == std::string::npos) { if (pallet1.Check(str[i])) { range.Index1 = i; } }
		if (range.Index0 != std::string::npos && range.Index1 != std::string::npos) { break; }
	}
	return range;
}



std::string StringHelp::CutAllPairsInEx(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1)
{
	StringRange range;
	range.Index0 = 0;
	range.Index1 = pallet0.FindNext(str, range.Index0);

	std::string s;
	while (range.Index1 != std::string::npos)
	{
		s += range.LeaveInEx(str);
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
	s += range.LeaveInEx(str);
	return s;
}



#include <iostream>
/*static void TestPallet(const CharPallet & pallet, const std::string & str)
{
	std::cout << "     : " << str << '\n';
	std::cout << "Leave: " << pallet.Leave(str) << '\n';
	std::cout << "Erase: " << pallet.Erase(str) << '\n';
}*/
/*#include "Generics/Container/Array.hpp"
static void TestPalletEraseSplit(const CharPallet & pallet, const std::string & str)
{
	std::cout << '"' << str << '"' << '\n';
	Container::Array<std::string> sections = pallet.EraseSplit(str);
	std::cout << "[\n";
	for (unsigned int i = 0; i < sections.Length(); i++)
	{
		std::cout << "  " << '"' << sections[i] << '"' << '\n';
	}
	std::cout << "]\n";
}*/
void StringHelp::Test()
{
	std::cout << "StringHelp::Test() ....\n";
	/*{
		TestPallet(CharPallet("456"), "123[456]789");
		TestPallet(CharPallet("456"), "456[789]123");
		TestPallet(CharPallet("456"), "789[123]456");
		TestPallet(CharPallet("456"), "123[]789");
		TestPallet(CharPallet("456"), "456");
	}*/
	/*{
		TestPalletEraseSplit(CharPallet(" \t\r\n"), "   circle>   12 12 0   0,0 0,05 0,0   0,10   0,0 -1,0 0,0   0,0   ");
	}*/
	std::cout << "StringHelp::Test() done\n";
}
