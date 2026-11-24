#ifndef  STRING_HELP_STRING_SECTION_HPP
# define STRING_HELP_STRING_SECTION_HPP

#include <string>

struct StringSection
{
	size_t	Offset = 0;
	size_t	Length = std::string::npos;

	~StringSection() = default;
	StringSection() = default;
	StringSection(const StringSection & other) = default;
	StringSection & operator=(const StringSection & other) = default;

	StringSection(const size_t & off, const size_t & len);

	std::string		SubString(const std::string & str) const;
	std::string		Erase(const std::string & str) const;
};

#endif
