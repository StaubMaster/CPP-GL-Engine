#ifndef  STRING_HELP_GENERAL_HPP
# define STRING_HELP_GENERAL_HPP

#include <string>

namespace StringHelp
{
	struct CharPallet;
	struct Range;

	Range		FindNextPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1, size_t idx = 0);
	Range		FindPrevPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1);

	// remove every instance of these characters
	std::string		CutAll(const std::string & str, const CharPallet & pallet);

	std::string		CutAllPairsInEx(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1);
};

#endif
