#include "FileParsing/Variables/Exception.hpp"

#include <sstream>



VariableNotFound::VariableNotFound(const std::string & name)
{
	std::stringstream ss;
	ss << "Variable: ";
	ss << '"' << name << '"';
	ss << " not found";
	ss << '.';
	Text = ss.str();
}



VariableIncorrentType::VariableIncorrentType(const std::string & name)
{
	std::stringstream ss;
	ss << "Variable: ";
	ss << '"' << name << '"';
	ss << " has incorrect Type";
	ss << '.';
	Text = ss.str();
}