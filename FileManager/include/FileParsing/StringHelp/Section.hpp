#ifndef  STRING_HELP_SECTION_HPP
# define STRING_HELP_SECTION_HPP

#include <string>

namespace StringHelp
{
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
};

#endif
