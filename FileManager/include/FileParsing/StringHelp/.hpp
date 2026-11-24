#ifndef  STRING_HELP__HPP
# define STRING_HELP__HPP

#include <string>

struct CharPallet;
struct StringRange;

namespace StringHelp
{
	StringRange		FindNextPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1, size_t idx = 0);
	StringRange		FindPrevPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1);

	std::string		CutAllPairsInEx(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1);

	void	Test();
};

#endif
