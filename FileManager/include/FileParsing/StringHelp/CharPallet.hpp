#ifndef  STRING_HELP_CHAR_PALLET_HPP
# define STRING_HELP_CHAR_PALLET_HPP

#include <string>

namespace StringHelp
{
	struct CharPallet
	{
		size_t			Count = 0;
		const char *	Characters = nullptr;

		~CharPallet() = default;
		CharPallet() = default;
		CharPallet(const CharPallet & other) = default;
		CharPallet & operator=(const CharPallet & other) = default;

		CharPallet(const char * pallet);

		bool	Check(char c) const;

		size_t	FindNext(const std::string & str, size_t idx) const;
		size_t	FindPrev(const std::string & str) const;
	};
};

#endif
