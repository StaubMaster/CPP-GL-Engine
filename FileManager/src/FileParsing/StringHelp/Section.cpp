#include "FileParsing/StringHelp/Section.hpp"



StringHelp::Section::Section(const size_t & off, const size_t & len)
	: Offset(off)
	, Length(len)
{ }

std::string StringHelp::Section::SubString(const std::string & str) const
{
	return str.substr(Offset, Length);
}
std::string StringHelp::Section::Erase(const std::string & str) const
{
	std::string str_copy(str);
	return str_copy.erase(Offset, Length);
}
