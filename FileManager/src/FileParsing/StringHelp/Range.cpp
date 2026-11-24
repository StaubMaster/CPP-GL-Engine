#include "FileParsing/StringHelp/Range.hpp"



StringHelp::Range::Range(const size_t & idx0, const size_t & idx1)
	: Index0(idx0)
	, Index1(idx1)
{ }

//StringHelp::Section StringHelp::Range::Inclusive() const { return Section(Index0, (Index1 - Index0) + 1); }
//StringHelp::Section StringHelp::Range::Exclusive() const { return Section(Index0 + 1, (Index1 - Index0) - 1); }

std::string StringHelp::Range::CutInIn(const std::string & str) const
{
	if (Index0 == std::string::npos) { return std::string(); }
	if (Index1 == std::string::npos) { return str.substr(Index0); }
	return str.substr(Index0, (Index1 - Index0) + 1);
}
std::string StringHelp::Range::CutInEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return std::string(); }
	if (Index1 == std::string::npos) { return str.substr(Index0); }
	return str.substr(Index0, (Index1 - Index0));
}
std::string StringHelp::Range::CutExEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return std::string(); }
	if (Index1 == std::string::npos) { return str.substr(Index0 + 1); }
	return str.substr(Index0 + 1, (Index1 - Index0) - 1);
}

std::string StringHelp::Range::EraseInIn(const std::string & str) const
{
	if (Index0 == std::string::npos) { return str; }
	std::string str_copy = str;
	if (Index1 == std::string::npos) { return str_copy.erase(Index0); }
	return str_copy.erase(Index0, (Index1 - Index0) + 1);
}
std::string StringHelp::Range::EraseInEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return str; }
	std::string str_copy = str;
	if (Index1 == std::string::npos) { return str_copy.erase(Index0); }
	return str_copy.erase(Index0, (Index1 - Index0));
}
std::string StringHelp::Range::EraseExEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return str; }
	std::string str_copy = str;
	if (Index1 == std::string::npos) { return str_copy.erase(Index0 + 1); }
	return str_copy.erase(Index0 + 1, (Index1 - Index0) - 1);
}
