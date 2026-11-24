#ifndef  STRING_HELP_CHAR_PALLET_HPP
# define STRING_HELP_CHAR_PALLET_HPP

#include <string>

namespace Container
{
template<typename TypeItem> struct Array;
};

struct CharPallet
{
	std::string		Pallet;

	~CharPallet() = default;
	CharPallet() = default;
	CharPallet(const CharPallet & other) = default;
	CharPallet & operator=(const CharPallet & other) = default;

	CharPallet(char pallet);
	CharPallet(const char * pallet);
	CharPallet(const std::string & pallet);

	bool	Check(char c) const;

	size_t	FindNext(const std::string & str, size_t idx) const;
	size_t	FindPrev(const std::string & str) const;

	size_t	FindNextNot(const std::string & str, size_t idx) const;
	size_t	FindPrevNot(const std::string & str) const;

	std::string		Leave(const std::string & str) const;
	std::string		Erase(const std::string & str) const;

	Container::Array<std::string>	EraseSplit(const std::string & str) const;
};

#endif
