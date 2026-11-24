#include "FileParsing/StringHelp/StringRange.hpp"



StringRange::StringRange(const size_t & idx0, const size_t & idx1)
	: Index0(idx0)
	, Index1(idx1)
{ }

//Section StringRange::Inclusive() const { return Section(Index0, (Index1 - Index0) + 1); }
//Section StringRange::Exclusive() const { return Section(Index0 + 1, (Index1 - Index0) - 1); }

std::string StringRange::LeaveInIn(const std::string & str) const
{
	if (Index0 == std::string::npos) { return std::string(); }
	if (Index1 == std::string::npos) { return str.substr(Index0); }
	return str.substr(Index0, (Index1 - Index0) + 1);
}
std::string StringRange::LeaveInEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return std::string(); }
	if (Index1 == std::string::npos) { return str.substr(Index0); }
	return str.substr(Index0, (Index1 - Index0));
}
std::string StringRange::LeaveExEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return std::string(); }
	if (Index1 == std::string::npos) { return str.substr(Index0 + 1); }
	return str.substr(Index0 + 1, (Index1 - Index0) - 1);
}

std::string StringRange::EraseInIn(const std::string & str) const
{
	if (Index0 == std::string::npos) { return str; }
	std::string str_copy = str;
	if (Index1 == std::string::npos) { return str_copy.erase(Index0); }
	return str_copy.erase(Index0, (Index1 - Index0) + 1);
}
std::string StringRange::EraseInEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return str; }
	std::string str_copy = str;
	if (Index1 == std::string::npos) { return str_copy.erase(Index0); }
	return str_copy.erase(Index0, (Index1 - Index0));
}
std::string StringRange::EraseExEx(const std::string & str) const
{
	if (Index0 == std::string::npos) { return str; }
	std::string str_copy = str;
	if (Index1 == std::string::npos) { return str_copy.erase(Index0 + 1); }
	return str_copy.erase(Index0 + 1, (Index1 - Index0) - 1);
}
