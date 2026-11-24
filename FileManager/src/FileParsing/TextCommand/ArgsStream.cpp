#include "FileParsing/TextCommand/ArgsStream.hpp"
#include "FileParsing/StringHelp/.hpp"
#include "FileParsing/StringHelp/CharPallet.hpp"
#include <string>



TextCommand::ArgsStream::ArgsStream(const std::string & text)
	: _Stream(text)
{ }



//#include <iostream>
bool TextCommand::ArgsStream::Continue(Args & cmd_args)
{
	if (!(Index < Segments.Length()))
	{
		std::string line;
		if (_Stream.Continue(line))
		{
			//std::cout << "line: " <<'"'<< line <<'"'<< '\n';
			line = StringHelp::CutAllPairsInEx(line, CharPallet("#"), CharPallet("\n"));
			Segments = CharPallet(";").EraseSplit(line);
			Index = 0;
		}
		else
		{
			return false;
		}
	}

	if (Index < Segments.Length())
	{
		//std::cout << "seg:  " <<'"'<< Segments[Index] <<'"'<< '\n';
		cmd_args.Split(Segments[Index]);
		Index++;
		return true;
	}

	cmd_args = Args();
	return true;
}
