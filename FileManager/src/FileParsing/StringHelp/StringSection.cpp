#include "FileParsing/StringHelp/StringSection.hpp"



StringSection::StringSection(const size_t & off, const size_t & len)
	: Offset(off)
	, Length(len)
{ }

std::string StringSection::SubString(const std::string & str) const
{
	return str.substr(Offset, Length);
}
std::string StringSection::Erase(const std::string & str) const
{
	std::string str_copy(str);
	return str_copy.erase(Offset, Length);
}
