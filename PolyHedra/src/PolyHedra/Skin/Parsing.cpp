#include "PolyHedra/Skin/Parsing.hpp"

#include "PolyHedra/Skin/Data.hpp"
#include "Graphics/Texture/Array2D.hpp"
#include "Image.hpp"

#include "FileInfo.hpp"
#include "FileParsing/TextCommand/Args.hpp"
#include "FileParsing/TextCommand/ArgsStream.hpp"
#include "FileParsing/TextCommand/Exceptions.hpp"
#include "DirectoryInfo.hpp"

#include "ValueType/Vector/F2.hpp"
#include "ValueType/Ray/F2.hpp"

#include <iostream>
#include "ValueType/_Show.hpp"



unsigned int Skin::ParsingData::ToVertexIndex(const TextCommand::Args & cmd_args, unsigned int arg_idx) const
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



Skin::ParsingData::~ParsingData()
{ }
Skin::ParsingData::ParsingData(const FileInfo & file, ::Skin & object, ::PolyHedra * polyHedra)
	: File(file)
	, Object(object)
	, PolyHedra(polyHedra)
	, TextureIndex(0)
	, TextureVertexIndex(0)
{
	Object.File = File;
}



void Skin::ParsingData::Parse(const TextCommand::Args & cmd_args)
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

		else if (name == "colFdefault")		{ Parse_ColorF_Default(cmd_args); }
		else if (name == "colF")			{ Parse_ColorF(cmd_args); }

		else if (name == "colDdefault")		{ Parse_ColorD_Default(cmd_args); }
		else if (name == "colD")			{ Parse_ColorD(cmd_args); }

		else if (name == "multi")			{ Parse_Multi(cmd_args); }

		else if (name == "axisAlign")	{ Parse_AxisAlign(cmd_args); }

		else						{ std::cout << "unknown: " << cmd_args << "\n"; }
	}
	catch(std::exception & ex)
	{
		std::cout << "Exception while Parsing Skin: " << ex.what() << '\n';
		std::cout << "Exception TextCommand: " << cmd_args << '\n';
	}
}

void Skin::ParsingData::Parse_Type(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }
	if (cmd_args.ToString(0) == "Skin")
	{
		return;
	}
	throw TextCommand::Exception::InvalidArgument(cmd_args, 0);
}
void Skin::ParsingData::Parse_Format(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	if (cmd_args.ToString(0) != "S_2025_10_27") { throw TextCommand::Exception::InvalidArgument(cmd_args, 0); }
}

void Skin::ParsingData::Parse_Name(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	Object.Name = cmd_args.ToString(0);
}
void Skin::ParsingData::Parse_Size(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	Object.Size.X = cmd_args.ToUInt32(0);
	Object.Size.Y = cmd_args.ToUInt32(1);
}
void Skin::ParsingData::Parse_Image(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	FileInfo file(File.Directory().File(cmd_args.ToString(0)));
	Object.Images.Insert(file.LoadImage());
}

void Skin::ParsingData::Parse_t(const TextCommand::Args & cmd_args)
{
	if (!((cmd_args.Count() % 2) == 0)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "(n % 2) == 0"); }

	unsigned int len = cmd_args.Count() / 2;
	
	Skin::Corner t[len];
	unsigned int idx = Object.Corners.Count();

	for (size_t i = 0; i < len; i++)
	{
		t[i].Coord.X = cmd_args.ToFloat(i * 2 + 0);
		t[i].Coord.Y = cmd_args.ToFloat(i * 2 + 1);
		t[i].Index = TextureIndex;
		Object.Corners.Insert(t[i]);
	}

	if (len == 3)
	{
		//Skin.Insert_Face3(t[0], t[1], t[2]);
		Object.Insert_Face3(idx + 0, idx + 1, idx + 2);
	}
	else if (len == 4)
	{
		//Skin.Insert_Face4(t[0], t[1], t[2], t[3]);
		Object.Insert_Face4(idx + 0, idx + 1, idx + 2, idx + 3);
	}
}

void Skin::ParsingData::Parse_TextureIndex(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }
	TextureIndex = cmd_args.ToUInt32(0);
}
void Skin::ParsingData::Parse_TextureIndexFace4(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 8)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 8"); }

	Skin::Corner t[4];
	unsigned int idx = Object.Corners.Count();

	for (unsigned int i = 0; i < 4; i++)
	{
		t[i].Coord.X = cmd_args.ToFloat(i * 2 + 0);
		t[i].Coord.Y = cmd_args.ToFloat(i * 2 + 1);
		t[i].Index = TextureIndex;
		Object.Corners.Insert(t[i]);
	}

	Object.Insert_Face4(idx + 0, idx + 1, idx + 2, idx + 3);
}
void Skin::ParsingData::Parse_TextureIndexQuad(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	VectorF2	min;
	min.X = cmd_args.ToFloat(0);
	min.Y = cmd_args.ToFloat(1);

	VectorF2	max;
	max.X = cmd_args.ToFloat(2);
	max.Y = cmd_args.ToFloat(3);

	Skin::Corner t[4];
	unsigned int idx = Object.Corners.Count();

	t[0].Coord.X = min.X;
	t[0].Coord.Y = min.Y;
	t[0].Index = TextureIndex;
	Object.Corners.Insert(t[0]);

	t[1].Coord.X = min.X;
	t[1].Coord.Y = max.Y;
	t[1].Index = TextureIndex;
	Object.Corners.Insert(t[1]);

	t[2].Coord.X = max.X;
	t[2].Coord.Y = min.Y;
	t[2].Index = TextureIndex;
	Object.Corners.Insert(t[2]);

	t[3].Coord.X = max.X;
	t[3].Coord.Y = max.Y;
	t[3].Index = TextureIndex;
	Object.Corners.Insert(t[3]);

	Object.Insert_Face4(idx + 0, idx + 1, idx + 2, idx + 3);
}

void Skin::ParsingData::Parse_Vertex(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	VectorF2 v;
	v.X = cmd_args.ToFloat(0);
	v.Y = cmd_args.ToFloat(1);

	Object.Corners.Insert(Skin::Corner(v, TextureIndex));
}
void Skin::ParsingData::Parse_VertexIndex(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	std::string str = cmd_args.ToString(0);
	if (str == "here")
	{
		TextureVertexIndex = Object.Corners.Count();
	}
	else
	{
		TextureVertexIndex = ToVertexIndex(cmd_args, 0);
	}
}
void Skin::ParsingData::Parse_VertexFace3(const TextCommand::Args & cmd_args, bool f_direction)
{
	if (!(cmd_args.Count() == 3)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 3"); }

	unsigned int t[3];
	for (unsigned int i = 0; i < 3; i++)
	{
		t[i] = ToVertexIndex(cmd_args, i);
	}

	if (!f_direction)
	{
		Object.Insert_Face3(t[0], t[1], t[2]);
	}
	else
	{
		Object.Insert_Face3(t[2], t[1], t[0]);
	}
}

/*static void Belt_Face(Skin & skin, unsigned int temp[4], bool dir)
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
}*/
void Skin::ParsingData::Parse_VertexBelt(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure)
{
	if (!((cmd_args.Count() % 2) == 0 && cmd_args.Count() >= 4 && cmd_args.Count() <= 255)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "(n % 2) == 0 && n >= 4 && n <= 255"); }

	unsigned int len = cmd_args.Count() / 2;

	unsigned int list0[len];
	unsigned int list1[len];

	for (unsigned int i = 0; i < len; i++)
	{
		unsigned int i0 = i;
		unsigned int i1 = i + len;

		list0[i] = ToVertexIndex(cmd_args, i0);
		list1[i] = ToVertexIndex(cmd_args, i1);
	}

	Object.Belt(len, list0, list1, f_direction, f_closure);

	/*unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int temp[4] = {
			list0[i + 0],
			list0[i + 1],
			list1[i + 0],
			list1[i + 1],
		};
		Belt_Face(Skin, temp, f_direction);
	}

	if (f_closure)
	{
		unsigned int temp[4] = {
			list0[n],
			list0[0],
			list1[n],
			list1[0],
		};
		Belt_Face(Skin, temp, f_direction);
	}*/
}

void Skin::ParsingData::Parse_VertexBand(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure)
{
	throw TextCommand::Exception::NotImplemented(cmd_args);
	(void)cmd_args;
	(void)f_direction;
	(void)f_closure;
}

/*static void Fan_Face(Skin & skin, unsigned int middle, unsigned int blade[2], bool dir, bool mid)
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
}*/
void Skin::ParsingData::Parse_VertexFan(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure, bool f_middle)
{
	if (!(cmd_args.Count() >= 3 && cmd_args.Count() <= 255)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n >= 3 && n <= 255"); }

	unsigned int len = cmd_args.Count() - 1;

	unsigned int middle;
	unsigned int blade[len];

	if (!f_middle)
	{
		middle = ToVertexIndex(cmd_args, 0);
		for (unsigned int i = 0; i < len; i++)
		{
			blade[i] = ToVertexIndex(cmd_args, i + 1);
		}
	}
	else
	{
		for (unsigned int i = 0; i < len; i++)
		{
			blade[i] = ToVertexIndex(cmd_args, i);
		}
		middle = ToVertexIndex(cmd_args, len);
	}

	Object.Fan(len, middle, blade, f_direction, f_middle, f_closure);

/*
	unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int temp[2] = {
			blade[i + 0],
			blade[i + 1],
		};
		Fan_Face(Skin, middle, temp, f_direction, f_middle);
	}

	if (f_closure)
	{
		unsigned int temp[2] = {
			blade[n],
			blade[0],
		};
		Fan_Face(Skin, middle, temp, f_direction, f_middle);
	}
*/
}
void Skin::ParsingData::Parse_VertexRay(const TextCommand::Args & cmd_args, bool f_accumulate)
{
	if (!(cmd_args.Count() >= 4 && cmd_args.Count() <= 255)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n >= 4 && n <= 255"); }

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
		Object.Corners.Insert(Skin::Corner(ray.ToPoint(intervals[i]), TextureIndex));
	}
}

void Skin::ParsingData::Parse_ColorF_Default(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	ColorF4 col;
	col.R = cmd_args.ToFloat(0);
	col.G = cmd_args.ToFloat(1);
	col.B = cmd_args.ToFloat(2);
	col.A = cmd_args.ToFloat(3);

	Object.Color = col;
}
void Skin::ParsingData::Parse_ColorF(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	ColorF4 col;
	col.R = cmd_args.ToFloat(0);
	col.G = cmd_args.ToFloat(1);
	col.B = cmd_args.ToFloat(2);
	col.A = cmd_args.ToFloat(3);

	Object.Corners.Insert(Skin::Corner(col));
}

#include "ValueType/Color/U4.hpp"
void Skin::ParsingData::Parse_ColorD_Default(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	ColorU4 col;
	col.R = cmd_args.ToUInt32(0);
	col.G = cmd_args.ToUInt32(1);
	col.B = cmd_args.ToUInt32(2);
	col.A = cmd_args.ToUInt32(3);

	Object.Color = col.ToColorF4();
}
void Skin::ParsingData::Parse_ColorD(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	ColorU4 col;
	col.R = cmd_args.ToUInt32(0);
	col.G = cmd_args.ToUInt32(1);
	col.B = cmd_args.ToUInt32(2);
	col.A = cmd_args.ToUInt32(3);

	Object.Corners.Insert(Skin::Corner(col.ToColorF4()));
}

/* this is a terrible name
*/
void Skin::ParsingData::Parse_Multi(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	unsigned int idx = ToVertexIndex(cmd_args, 0);
	unsigned int n = cmd_args.ToUInt32(1);
	for (unsigned int i = 0; i < n; i++)
	{
		Object.Faces.Insert(Skin::Face(idx, idx, idx));
	}
}



#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Data.hpp"
/* take a position and an axis from that position
align texture to that axis

needs PolyHedra corners
*/
/* axis_align
	origin x y z
	axis0 x y z scale
	axis1 x y z scale
	number of faces
*/
void Skin::ParsingData::Parse_AxisAlign(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 12)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 12"); }

	if (PolyHedra == nullptr) { throw TextCommand::Exception::InvalidState(cmd_args, "Missing PolyHedra"); }

	VectorF3 origin(
		cmd_args.ToFloat(0),
		cmd_args.ToFloat(1),
		cmd_args.ToFloat(2)
	);

	VectorF3 axis0(
		cmd_args.ToFloat(3),
		cmd_args.ToFloat(4),
		cmd_args.ToFloat(5)
	);
	float scale0 = cmd_args.ToFloat(6);

	VectorF3 axis1(
		cmd_args.ToFloat(7),
		cmd_args.ToFloat(8),
		cmd_args.ToFloat(9)
	);
	float scale1 = cmd_args.ToFloat(10);

	unsigned int n = cmd_args.ToUInt32(11);

	axis0 = axis0.normalize();
	axis1 = axis1.normalize();

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int corners_index = Object.Corners.Count();
		unsigned int face_index = Object.Faces.Count();

		const PolyHedra::Face & face = PolyHedra -> Faces[face_index];
		const PolyHedra::Corner & corner0 = PolyHedra -> Corners[face.idx[0]];
		const PolyHedra::Corner & corner1 = PolyHedra -> Corners[face.idx[1]];
		const PolyHedra::Corner & corner2 = PolyHedra -> Corners[face.idx[2]];

		VectorF2 vec;

		vec.X = axis0.dot(corner0.Position) / scale0;
		vec.Y = axis1.dot(corner0.Position) / scale1;
		Object.Insert_Corn(vec, TextureIndex);

		vec.X = axis0.dot(corner1.Position) / scale0;
		vec.Y = axis1.dot(corner1.Position) / scale1;
		Object.Insert_Corn(vec, TextureIndex);

		vec.X = axis0.dot(corner2.Position) / scale0;
		vec.Y = axis1.dot(corner2.Position) / scale1;
		Object.Insert_Corn(vec, TextureIndex);

		Object.Insert_Face3(corners_index + 0, corners_index + 1, corners_index + 2);
	}
}



Skin * Skin::Load(const FileInfo & file, ::PolyHedra * polyHedra)
{
//	std::cout << "Loading Skin File " << '"' << file.Path << '"' << " ..." << '\n';

	::Skin * object = new Skin();
	ParsingData data(file, *object, polyHedra);

	TextCommand::ArgsStream stream(file.LoadText());
	TextCommand::Args cmd_args;
	while (stream.Continue(cmd_args))
	{
		data.Parse(cmd_args);
	}

	object -> Done();

//	std::cout << "Loading Skin File " << '"' << file.Path << '"' << " done" << '\n';

	return object;
}
Skin * Skin::Load(const FileInfo & file)
{
	return Load(file, nullptr);
}
