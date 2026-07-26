#include "PolyHedra/Skin/Parsing.hpp"

#include "PolyHedra/Skin/Data.hpp"
#include "Graphics/Texture/Array2D.hpp"
#include "Image.hpp"

#include "FileInfo.hpp"
#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"
#include "FileParsing/Text/Exceptions.hpp"

#include "ValueType/Vector/F2.hpp"
#include "ValueType/Ray/F2.hpp"

#include <iostream>
#include "ValueType/_Show.hpp"




unsigned int Skin::ParsingData::ToVertexIndex(const TextCommandArgs & cmd_args, unsigned int arg_idx) const
{
	std::string str = cmd_args.ToString(arg_idx);
	if (str[0] == '+' || str[0] == '-')
	{
		return TextureVertexIndex + cmd_args.ToInt32(arg_idx);
	}
	else
	{
		return cmd_args.ToUInt32(arg_idx);
	}
}
VectorF3 Skin::ParsingData::ToVertex(const TextCommandArgs & cmd_args, unsigned int arg_idx) const
{
	VectorF2 temp;
	temp = TextureVertexes[cmd_args.ToUInt32(arg_idx) + TextureVertexIndex];
	return VectorF3(
		temp.X,
		temp.Y,
		TextureIndex
	);
}



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



void Skin::ParsingData::Parse(const TextCommandArgs & cmd_args)
{
//	std::cout << "Skin::Parsing: " << cmd << '\n';
	try
	{
		std::string name = cmd_args.Name();
		if (name == "")				{ /*std::cout << "Skin: " << "Empty\n";*/ }
		else if (name == "Type")	{ Parse_Type(cmd_args); }
		else if (name == "Format")	{ Parse_Format(cmd_args); }

		else if (name == "Name")	{ Parse_Name(cmd_args); }
		else if (name == "Size")	{ Parse_Size(cmd_args); }
		else if (name == "Img")		{ Parse_Image(cmd_args); }

		else if (name == "t")		{ Parse_t(cmd_args); }
		else if (name == "TexI")	{ Parse_TextureIndex(cmd_args); }
		else if (name == "TexI4")	{ Parse_TextureIndexFace4(cmd_args); }
		else if (name == "TexIQ")	{ Parse_TextureIndexQuad(cmd_args); }

		else if (name == "vertex")	{ Parse_Vertex(cmd_args); }
		else if (name == "vIndex")	{ Parse_VertexIndex(cmd_args); }
		else if (name == "vFace<")	{ Parse_VertexFace3(cmd_args, false); }
		else if (name == "VFace>")	{ Parse_VertexFace3(cmd_args, true); }

		else if (name == "belt{0")	{ Parse_VertexBelt(cmd_args, false, false); }
		else if (name == "belt}0")	{ Parse_VertexBelt(cmd_args, true, false); }
		else if (name == "belt{1")	{ Parse_VertexBelt(cmd_args, false, true); }
		else if (name == "belt}1")	{ Parse_VertexBelt(cmd_args, true, true); }

		else if (name == "band{0")	{ Parse_VertexBand(cmd_args, false, false); }
		else if (name == "band}0")	{ Parse_VertexBand(cmd_args, true, false); }
		else if (name == "band{1")	{ Parse_VertexBand(cmd_args, false, true); }
		else if (name == "band}1")	{ Parse_VertexBand(cmd_args, true, true); }

		else if (name == "fan<{0")	{ Parse_VertexFan(cmd_args, false, false, false); }
		else if (name == "fan<}0")	{ Parse_VertexFan(cmd_args, true, false, false); }
		else if (name == "fan<{1")	{ Parse_VertexFan(cmd_args, false, true, false); }
		else if (name == "fan<}1")	{ Parse_VertexFan(cmd_args, true, true, false); }
		else if (name == "fan>{0")	{ Parse_VertexFan(cmd_args, false, false, true); }
		else if (name == "fan>}0")	{ Parse_VertexFan(cmd_args, true, false, true); }
		else if (name == "fan>{1")	{ Parse_VertexFan(cmd_args, false, true, true); }
		else if (name == "fan>}1")	{ Parse_VertexFan(cmd_args, true, true, true); }

		else if (name == "rayT")	{ Parse_VertexRay(cmd_args, false); }
		else if (name == "rayA")	{ Parse_VertexRay(cmd_args, true); }

		else						{ std::cout << "unknown: " << cmd_args << "\n"; }
	}
	catch(std::exception & ex)
	{
		std::cout << "Exception while Parsing Skin: " << ex.what() << '\n';
		std::cout << "Exception TextCommand: " << cmd_args << '\n';
	}
}

void Skin::ParsingData::Parse_Type(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }
	if (cmd_args.ToString(0) == "Skin")
	{
		return;
	}
	throw InvalidCommandArgument(cmd_args, 0);
}
void Skin::ParsingData::Parse_Format(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }

	if (cmd_args.ToString(0) != "S_2025_10_27") { throw InvalidCommandArgument(cmd_args, 0); }
}

void Skin::ParsingData::Parse_Name(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }

	Skin.Name = cmd_args.ToString(0);
}
void Skin::ParsingData::Parse_Size(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw InvalidCommandArgumentCount(cmd_args, "n == 2"); }

	Skin.Size.X = cmd_args.ToUInt32(0);
	Skin.Size.Y = cmd_args.ToUInt32(1);
}
void Skin::ParsingData::Parse_Image(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }
	std::cout << cmd_args << '\n';

	FileInfo file((File.DirectoryString() + "/" + cmd_args.ToString(0)).c_str());
	std::cout << "Path: " << file.Path << '\n';
	std::cout << "Exists: " << file.Exists() << '\n';

	//Skin.Images.Insert(file.LoadImage());

	// Stick.png is Empty(). why ?
	Image img = file.LoadImage(true);
	std::cout << "Size: " << img.Size() << '\n';
	std::cout << "Empty: " << img.Empty() << '\n';
	/*if (img.W() == 16 && img.H() == 16)
	{
		for (unsigned int i = 0; i < img.Size().Product(); i++)
		{
			std::cout << img.Pixel(i) << '\n';
		}
		std::cout << '\n';
	}*/
	Skin.Images.Insert(img);
}

void Skin::ParsingData::Parse_t(const TextCommandArgs & cmd_args)
{
	if (!((cmd_args.Count() % 2) == 0)) { throw InvalidCommandArgumentCount(cmd_args, "(n % 2) == 0"); }

	unsigned int len = cmd_args.Count() / 2;
	
	VectorF3 t[len];
	for (size_t i = 0; i < len; i++)
	{
		t[i].X = cmd_args.ToFloat(i * 2 + 0);
		t[i].Y = cmd_args.ToFloat(i * 2 + 1);
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

void Skin::ParsingData::Parse_TextureIndex(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }
	TextureIndex = cmd_args.ToUInt32(0);
}
void Skin::ParsingData::Parse_TextureIndexFace4(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 8)) { throw InvalidCommandArgumentCount(cmd_args, "n == 8"); }

	VectorF3 t[4];
	for (unsigned int i = 0; i < 4; i++)
	{
		t[i].X = cmd_args.ToFloat(i * 2 + 0);
		t[i].Y = cmd_args.ToFloat(i * 2 + 1);
		t[i].Z = TextureIndex;
	}

	Skin.Insert_Face4(VectorF3(t[0]), VectorF3(t[1]), VectorF3(t[2]), VectorF3(t[3]));
}
void Skin::ParsingData::Parse_TextureIndexQuad(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw InvalidCommandArgumentCount(cmd_args, "n == 4"); }

	VectorF2	min;
	min.X = cmd_args.ToFloat(0);
	min.Y = cmd_args.ToFloat(1);

	VectorF2	max;
	max.X = cmd_args.ToFloat(2);
	max.Y = cmd_args.ToFloat(3);

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

void Skin::ParsingData::Parse_Vertex(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw InvalidCommandArgumentCount(cmd_args, "n == 2"); }

	VectorF2 v;
	v.X = cmd_args.ToFloat(0);
	v.Y = cmd_args.ToFloat(1);

	TextureVertexes.Insert(v);
}
void Skin::ParsingData::Parse_VertexIndex(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }

	std::string str = cmd_args.ToString(0);
	if (str == "here")
	{
		TextureVertexIndex = TextureVertexes.Count();
	}
	else
	{
		TextureVertexIndex = ToVertexIndex(cmd_args, 0);
	}
}
void Skin::ParsingData::Parse_VertexFace3(const TextCommandArgs & cmd_args, bool f_direction)
{
	if (!(cmd_args.Count() == 3)) { throw InvalidCommandArgumentCount(cmd_args, "n == 3"); }

	VectorF3 t[3];
	for (unsigned int i = 0; i < 3; i++)
	{
		VectorF2 v = TextureVertexes[cmd_args.ToUInt32(i) + TextureVertexIndex];
		t[i].X = v.X;
		t[i].Y = v.Y;
		t[i].Z = TextureIndex;
	}

	if (!f_direction)
	{
		Skin.Insert_Face3(t[0], t[1], t[2]);
	}
	else
	{
		Skin.Insert_Face3(t[2], t[1], t[0]);
	}
}

static void Belt_Face(Skin & skin, VectorF3 temp[4], bool dir)
{
	if (!dir)
	{
		skin.Insert_Face3(temp[0], temp[2], temp[1]);
		skin.Insert_Face3(temp[3], temp[1], temp[2]);
	}
	else
	{
		skin.Insert_Face3(temp[1], temp[2], temp[0]);
		skin.Insert_Face3(temp[2], temp[1], temp[3]);
	}
}
void Skin::ParsingData::Parse_VertexBelt(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure)
{
	if (!((cmd_args.Count() % 2) == 0 && cmd_args.Count() >= 4 && cmd_args.Count() <= 255)) { throw InvalidCommandArgumentCount(cmd_args, "(n % 2) == 0 && n >= 4 && n <= 255"); }

	unsigned int len = cmd_args.Count() / 2;

	VectorF3 list0[len];
	VectorF3 list1[len];

	for (unsigned int i = 0; i < len; i++)
	{
		unsigned int i0 = i;
		unsigned int i1 = i + len;

		list0[i] = ToVertex(cmd_args, i0);
		list1[i] = ToVertex(cmd_args, i1);
	}

	unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		VectorF3 temp[4] = {
			list0[i + 0],
			list0[i + 1],
			list1[i + 0],
			list1[i + 1],
		};
		Belt_Face(Skin, temp, f_direction);
	}

	if (f_closure)
	{
		VectorF3 temp[4] = {
			list0[n],
			list0[0],
			list1[n],
			list1[0],
		};
		Belt_Face(Skin, temp, f_direction);
	}
}

void Skin::ParsingData::Parse_VertexBand(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure)
{
	throw CommandNotImplemented(cmd_args);
	(void)cmd_args;
	(void)f_direction;
	(void)f_closure;
}

static void Fan_Face(Skin & skin, VectorF3 middle, VectorF3 blade[2], bool dir, bool mid)
{
	if (!dir)
	{
		if (!mid)
		{
			skin.Insert_Face3(blade[1], middle, blade[0]);
		}
		else
		{
			skin.Insert_Face3(blade[0], middle, blade[1]);
		}
	}
	else
	{
		if (!mid)
		{
			skin.Insert_Face3(blade[0], middle, blade[1]);
		}
		else
		{
			skin.Insert_Face3(blade[1], middle, blade[0]);
		}
	}
}
void Skin::ParsingData::Parse_VertexFan(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure, bool f_middle)
{
	if (!(cmd_args.Count() >= 3 && cmd_args.Count() <= 255)) { throw InvalidCommandArgumentCount(cmd_args, "n >= 3 && n <= 255"); }

	unsigned int len = cmd_args.Count() - 1;

	VectorF3 middle;
	VectorF3 blade[len];

	if (!f_middle)
	{
		middle = ToVertex(cmd_args, 0);
		for (unsigned int i = 0; i < len; i++)
		{
			blade[i] = ToVertex(cmd_args, i + 1);
		}
	}
	else
	{
		for (unsigned int i = 0; i < len; i++)
		{
			blade[i] = ToVertex(cmd_args, i);
		}
		middle = ToVertex(cmd_args, len);
	}

	unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		VectorF3 temp[2] = {
			blade[i + 0],
			blade[i + 1],
		};
		Fan_Face(Skin, middle, temp, f_direction, f_middle);
	}

	if (f_closure)
	{
		VectorF3 temp[2] = {
			blade[n],
			blade[0],
		};
		Fan_Face(Skin, middle, temp, f_direction, f_middle);
	}
}
void Skin::ParsingData::Parse_VertexRay(const TextCommandArgs & cmd_args, bool f_accumulate)
{
	if (!(cmd_args.Count() >= 4 && cmd_args.Count() <= 255)) { throw InvalidCommandArgumentCount(cmd_args, "n >= 4 && n <= 255"); }

	unsigned int len = cmd_args.Count() - 4;

	RayF2 ray;
	ray.Pos.X = cmd_args.ToFloat(0);
	ray.Pos.Y = cmd_args.ToFloat(1);
	ray.Dir.X = cmd_args.ToFloat(2);
	ray.Dir.Y = cmd_args.ToFloat(3);

	float intervals[len];
	if (!f_accumulate)
	{
		for (unsigned int i = 0; i < len; i++)
		{
			intervals[i] = cmd_args.ToFloat(i + 4);
		}
	}
	else
	{
		float sum = 0.0f;
		for (unsigned int i = 0; i < len; i++)
		{
			sum += cmd_args.ToFloat(i + 4);
			intervals[i] = sum;
		}
	}

	for (unsigned int i = 0; i < len; i++)
	{
		TextureVertexes.Insert(ray.ToPoint(intervals[i]));
	}
}



Skin * Skin::Load(const FileInfo & file)
{
	std::cout << "Loading Skin File " << '"' << file.Path << '"' << " ..." << '\n';

	::Skin * skin = new Skin();
	ParsingData data(file, *skin);

	TextCommandStream stream(file.LoadText());
	TextCommand cmd;
	while (stream.Continue(cmd))
	{
		data.Parse(cmd);
	}

	skin -> Done();

	std::cout << "Loading Skin File " << '"' << file.Path << '"' << " done" << '\n';

	return skin;
}
