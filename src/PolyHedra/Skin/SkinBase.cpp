#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Graphics/Texture/Base.hpp"
#include "Image.hpp"

#include "FileInfo.hpp"
#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"
#include "FileParsing/Text/Exceptions.hpp"

#include <iostream>



SkinBase::SkinBase() :
	Images(),
	File()
{ }
SkinBase::~SkinBase()
{
	for (unsigned int i = 0; i < Images.Count(); i++)
	{
		Images[i].Dispose();
	}
}





void SkinBase::ParserData::Parse(const TextCommand & cmd)
{
	std::cout << "SkinBase::Parsing: " << cmd << '\n';
	try
	{
		std::string name = cmd.Name();
		if (name== "")				{ /*std::cout << "Skin: " << "Empty\n";*/ }
		else if (name == "Type")	{ Parse_Type(cmd); }
		else if (name == "Format")	{ Parse_Format(cmd); }

		else if (Skin != NULL)		{ Skin -> Parse(cmd); }

		else						{ std::cout << "unknown: " << cmd << "\n"; }
	}
	catch(std::exception & ex)
	{
		std::cout << "Exception while Parsing Skin: " << ex.what() << '\n';
		std::cout << "Exception TextCommand: " << cmd << '\n';
	}
}
void SkinBase::ParserData::Parse_Type(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }
	if (cmd.ToString(0) == "Skin2DA")
	{
		Skin = new Skin2DA();
		Skin -> File = File;
		return;
	}
	throw InvalidCommandArgument(cmd, 0);
}
void SkinBase::ParserData::Parse_Format(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }
	if (cmd.ToString(0) != "S_2025_10_27") { throw InvalidCommandArgument(cmd, 0); }
}

SkinBase * SkinBase::Load(const FileInfo & file)
{
	std::cout << "SkinBase::Load: " << file.Path << "\n";

	ParserData data;
	data.File = file;
	data.Skin = NULL;

	TextCommandStream stream(file.LoadText());
	TextCommand cmd;
	while (stream.Continue(cmd))
	{
		data.Parse(cmd);
	}

	data.Skin -> Done();
	return data.Skin;
}
