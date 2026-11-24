#include "FileParsing/TextCommand/LineStream.hpp"
#include "FileParsing/StringHelp/.hpp"
#include "FileParsing/StringHelp/CharPallet.hpp"
#include <string>

#include <iostream>



LineStream::LineStream(const std::string & text) :
	_Stream(text)
{ }



bool LineStream::Continue(std::string & line)
{
	if (_Stream.good())
	{
		std::getline(_Stream, line, '\n');
		line = CharPallet("\n\r").Erase(line); // maybe replace with ' ' ?
		return true;
	}
	return false;
}
