#ifndef  STRING_HELP_HPP
# define STRING_HELP_HPP

#include <string>

namespace StringHelp
{
	struct CharPallet
	{
		size_t			Count;
		const char *	Characters;
		CharPallet(const char * pallet);
		bool	Check(char c) const;
		size_t	FindNext(const std::string & str, size_t idx) const;
		size_t	FindPrev(const std::string & str) const;
	};
	/*struct CharPair
	{
		CharPallet	Pallet0;
		CharPallet	Pallet1;
	};*/

	struct Section
	{
		size_t	Offset = 0;
		size_t	Length = std::string::npos;
		~Section() = default;
		Section() = default;
		Section(const Section & other) = default;
		Section & operator=(const Section & other) = default;
		Section(const size_t & off, const size_t & len);
		std::string		SubString(const std::string & str) const;
		std::string		Erase(const std::string & str) const;
	};
	struct Range
	{
		size_t	Index0 = std::string::npos;
		size_t	Index1 = std::string::npos;
		~Range() = default;
		Range() = default;
		Range(const Range & other) = default;
		Range & operator=(const Range & other) = default;
		Range(const size_t & idx0, const size_t & idx1);
		Section		Inclusive() const; // including the Boundary Characters
		Section		Exclusive() const; // excluding the Boundary Characters
		std::string	CutInIn(const std::string & str) const;
		std::string	CutInEx(const std::string & str) const;
		std::string	CutExEx(const std::string & str) const;
	};

	Range		FindNextPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1, size_t idx = 0);
	Range		FindPrevPair(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1);

	// remove every instance of these characters
	std::string		CutAll(const std::string & str, const CharPallet & pallet);

	std::string		CutAllPairsInEx(const std::string & str, const CharPallet & pallet0, const CharPallet & pallet1);
};


#endif
