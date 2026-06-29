#include "PolyHedra/Skin/Parsing.hpp"

#include "PolyHedra/Skin/Data.hpp"
#include "Graphics/Texture/Array2D.hpp"
#include "Image.hpp"

#include "FileInfo.hpp"
#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"
#include "FileParsing/Text/Exceptions.hpp"

#include "ValueType/Vector/F2.hpp"

#include <iostream>
#include "ValueType/_Show.hpp"



Skin::ParsingData::~ParsingData()
{ }
Skin::ParsingData::ParsingData(const FileInfo & file, ::Skin & skin)
	: File(file)
	, Skin(skin)
	, TextureIndex(0)
	, TextureVertexes()
	, TextureVertexIndex(0)
{
	Skin.File = File;
}



/* Belt
	< and > change vertex order
	so TexIQ is bad
	take a list of Indexes
	how should it take Texture Coordinates ?
	X and Y Versions
	X versions takes a Min and Max for X
	and Y takes a individual Texture Coordinate per Y
*/

/*
store Texture Vectors in a List
	seperate List per Image ?

belt command takes Indexes to the List

*/

void Skin::ParsingData::Parse(const TextCommand & cmd)
{
//	std::cout << "Skin::Parsing: " << cmd << '\n';
	try
	{
		std::string name = cmd.Name();
		if (name == "")				{ /*std::cout << "Skin: " << "Empty\n";*/ }
		else if (name == "Type")	{ Parse_Type(cmd); }
		else if (name == "Format")	{ Parse_Format(cmd); }

		else if (name == "Name")	{ Parse_Name(cmd); }
		else if (name == "Size")	{ Parse_Size(cmd); }
		else if (name == "Img")		{ Parse_Image(cmd); }

		else if (name == "t")		{ Parse_t(cmd); }
		else if (name == "TexI")	{ Parse_TextureIndex(cmd); }
		else if (name == "TexI4")	{ Parse_TextureIndexFace4(cmd); }
		else if (name == "TexIQ")	{ Parse_TextureIndexQuad(cmd); }

		else if (name == "vertex")	{ Parse_Vertex(cmd); }
		else if (name == "vIndex")	{ Parse_VertexIndex(cmd); }
		else if (name == "vFace<")	{ Parse_VertexFace3(cmd, false); }
		else if (name == "VFace>")	{ Parse_VertexFace3(cmd, true); }

		else						{ std::cout << "unknown: " << cmd << "\n"; }
	}
	catch(std::exception & ex)
	{
		std::cout << "Exception while Parsing Skin: " << ex.what() << '\n';
		std::cout << "Exception TextCommand: " << cmd << '\n';
	}
}
void Skin::ParsingData::Parse_Type(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }
	if (cmd.ToString(0) == "Skin")
	{
		return;
	}
	throw InvalidCommandArgument(cmd, 0);
}
void Skin::ParsingData::Parse_Format(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }
	if (cmd.ToString(0) != "S_2025_10_27") { throw InvalidCommandArgument(cmd, 0); }
}

void Skin::ParsingData::Parse_Name(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }

	Skin.Name = cmd.ToString(0);
}
void Skin::ParsingData::Parse_Size(const TextCommand & cmd)
{
	if (!(cmd.Count() == 2)) { throw InvalidCommandArgumentCount(cmd, "n == 2"); }

	Skin.Size.X = cmd.ToUInt32(0);
	Skin.Size.Y = cmd.ToUInt32(1);
}
void Skin::ParsingData::Parse_Image(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }

	FileInfo file((File.DirectoryString() + "/" + cmd.ToString(0)).c_str());
	Skin.Images.Insert(file.LoadImage());
}

void Skin::ParsingData::Parse_t(const TextCommand & cmd)
{
	if (!((cmd.Count() % 2) == 0)) { throw InvalidCommandArgumentCount(cmd, "(n % 2) == 0"); }
	//if (!cmd.CheckCount(CountCheckModulo(2, 0)) || len < 3 || len > 4) { throw TextCommand::ExceptionInvalidCount(cmd, CountCheckModulo(2, 0)); }
	unsigned int len = cmd.Count() / 2;
	
	VectorF3 t[len];
	for (size_t i = 0; i < len; i++)
	{
		t[i].X = cmd.ToFloat(i * 2 + 0);
		t[i].Y = cmd.ToFloat(i * 2 + 1);
		t[i].Z = TextureIndex;
	}

	if (len == 3)
	{
		Skin.Insert_Face3(t[0], t[1], t[2]);
	}
	else if (len == 4)
	{
		Skin.Insert_Face4(t[0], t[1], t[2], t[3]);
	}
}

void Skin::ParsingData::Parse_TextureIndex(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }
	TextureIndex = cmd.ToUInt32(0);
}
void Skin::ParsingData::Parse_TextureIndexFace4(const TextCommand & cmd)
{
	if (!(cmd.Count() == 8)) { throw InvalidCommandArgumentCount(cmd, "n == 8"); }

	VectorF3 t[4];
	for (unsigned int i = 0; i < 4; i++)
	{
		t[i].X = cmd.ToFloat(i * 2 + 0);
		t[i].Y = cmd.ToFloat(i * 2 + 1);
		t[i].Z = TextureIndex;
	}

	Skin.Insert_Face4(VectorF3(t[0]), VectorF3(t[1]), VectorF3(t[2]), VectorF3(t[3]));
}
void Skin::ParsingData::Parse_TextureIndexQuad(const TextCommand & cmd)
{
	if (!(cmd.Count() == 4)) { throw InvalidCommandArgumentCount(cmd, "n == 4"); }

	VectorF2	min;
	min.X = cmd.ToFloat(0);
	min.Y = cmd.ToFloat(1);

	VectorF2	max;
	max.X = cmd.ToFloat(2);
	max.Y = cmd.ToFloat(3);

	VectorF3 t[4];

	t[0].X = min.X;
	t[0].Y = min.Y;
	t[0].Z = TextureIndex;

	t[1].X = min.X;
	t[1].Y = max.Y;
	t[1].Z = TextureIndex;

	t[2].X = max.X;
	t[2].Y = min.Y;
	t[2].Z = TextureIndex;

	t[3].X = max.X;
	t[3].Y = max.Y;
	t[3].Z = TextureIndex;

	//std::cout << "[0]" << t[0] << '\n';
	//std::cout << "[1]" << t[1] << '\n';
	//std::cout << "[2]" << t[2] << '\n';
	//std::cout << "[3]" << t[3] << '\n';

	Skin.Insert_Face4(VectorF3(t[0]), VectorF3(t[1]), VectorF3(t[2]), VectorF3(t[3]));
}

void Skin::ParsingData::Parse_Vertex(const TextCommand & cmd)
{
	if (!(cmd.Count() == 2)) { throw InvalidCommandArgumentCount(cmd, "n == 2"); }

	VectorF2 v;
	v.X = cmd.ToFloat(0);
	v.Y = cmd.ToFloat(1);

	TextureVertexes.Insert(v);
}
void Skin::ParsingData::Parse_VertexIndex(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }

	std::string str = cmd.ToString(0);
	char c = str[0];

	if (c == '+' || c == '-')
	{ TextureVertexIndex += cmd.ToInt32(0); }
	else
	{ TextureVertexIndex = cmd.ToUInt32(0); }
}
void Skin::ParsingData::Parse_VertexFace3(const TextCommand & cmd, bool direction)
{
	if (!(cmd.Count() == 3)) { throw InvalidCommandArgumentCount(cmd, "n == 3"); }

	VectorF3 t[3];
	for (unsigned int i = 0; i < 3; i++)
	{
		VectorF2 v = TextureVertexes[TextureVertexIndex + cmd.ToUInt32(i)];
		t[i].X = v.X;
		t[i].Y = v.Y;
		t[i].Z = TextureIndex;
	}

	if (!direction)
	{
		Skin.Insert_Face3(t[0], t[1], t[2]);
	}
	else
	{
		Skin.Insert_Face3(t[2], t[1], t[0]);
	}
}
void Skin::ParsingData::Parse_VertexBelt(const TextCommand & cmd, bool direction, bool closure)
{
	throw CommandNotImplemented(cmd);
	(void)cmd;
	(void)direction;
	(void)closure;
}
void Skin::ParsingData::Parse_VertexBand(const TextCommand & cmd, bool direction, bool closure)
{
	throw CommandNotImplemented(cmd);
	(void)cmd;
	(void)direction;
	(void)closure;
}
void Skin::ParsingData::Parse_VertexFan(const TextCommand & cmd, bool direction, bool closure)
{
	throw CommandNotImplemented(cmd);
	(void)cmd;
	(void)direction;
	(void)closure;
}

Skin * Skin::Load(const FileInfo & file)
{
//	std::cout << "Skin::Load: " << file.Path << "\n";

	::Skin * skin = new Skin();
	ParsingData data(file, *skin);

	TextCommandStream stream(file.LoadText());
	TextCommand cmd;
	while (stream.Continue(cmd))
	{
		data.Parse(cmd);
	}

	skin -> Done();
	return skin;
}
