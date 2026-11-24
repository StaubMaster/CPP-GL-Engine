#include "FileParsing/TextCommand/Args.hpp"



bool			TextCommand::Args::Empty() const
{
	return Segments.IsNull();
}
std::string		TextCommand::Args::Name() const
{
	if (Segments.Length() == 0)
	{
		return "";
	}
	return Segments[0];
}
unsigned int	TextCommand::Args::Count() const
{
	if (Segments.Length() == 0)
	{
		return 0;
	}
	return Segments.Length() - 1;
}



std::string		TextCommand::Args::ToString(unsigned int idx) const
{
	if (idx >= Count()) { return ""; }
	return Segments[idx + 1];
}
unsigned int	TextCommand::Args::ToUInt32(unsigned int idx) const
{
	if (idx >= Count()) { return 0; }
	return std::stoul(Segments[idx + 1]);
}
int				TextCommand::Args::ToInt32(unsigned int idx) const
{
	if (idx >= Count()) { return 0; }
	return std::stoi(Segments[idx + 1]);
}
float			TextCommand::Args::ToFloat(unsigned int idx) const
{
	if (idx >= Count()) { return 0.0f; }
	std::string str = Segments[idx + 1];
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == ',') { str[i] = '.'; }
	}
	return std::stof(str);
}



#include "FileParsing/StringHelp/CharPallet.hpp"
void TextCommand::Args::Split(const std::string & str)
{
	CharPallet whitespace(" \t\r\n");
	Segments = whitespace.EraseSplit(str);
}
TextCommand::Args TextCommand::Args::Split(unsigned int idx) const
{
	Args args;
	if (idx < Count())
	{
		args.Segments.NewLength(Count() - idx);
		for (unsigned int i = 0; i < args.Segments.Length(); i++)
		{
			args.Segments[i] = Segments[idx + i + 1];
		}
	}
	return args;
}





#include <iostream>
std::ostream & operator<<(std::ostream & o, const TextCommand::Args & obj)
{
	o << '(';
	o << obj.Name() << ':';
	for (unsigned int i = 0; i < obj.Count(); i++)
	{
		o << ' ' << obj.ToString(i);
	}
	o << ')';
	return o;
}
