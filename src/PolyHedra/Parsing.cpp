#include "PolyHedra/Parsing.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Template.hpp"
#include "PolyHedra/Generate.hpp"

#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Graphics/Texture/Generate.hpp"

#include "FileInfo.hpp"
//#include "FilePath.hpp"
//#include "FileParsing/LineCommand.hpp"
#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"
#include "FileParsing/Text/Exceptions.hpp"

#include "ValueType/Point3D.hpp"
#include "ValueType/Angle.hpp"
#include "ValueType/Angle3D.hpp"
#include "ValueType/AxisBox3D.hpp"
#include "DataShow.hpp"

#include "Debug.hpp"
#include <sstream>
#include <iostream>



/*
	Parse each line
	for errors / Debug stuff
		console out should be normalized
		also use errors for certain things
		like args number
		Unknown / Invalid
	Exceptions
		right now I use exceptions that create and store a String internally
		make a BaseException for that
		have FileExceptions and LineExceptions ?
			LineExceptions skip the line but continue in the File ?
			dont know of any case where that applies right now
			also could just give the BaseException an extra info ?
			so Bits that say what type of exception it is
*/



PolyHedra::ParsingData::ParsingData(const FileInfo & file) :
	File(file),
	PH(NULL),
	Data(NULL),
	CornerOffset(0),
	FaceOffset(0)
{ }
PolyHedra::ParsingData::~ParsingData()
{
	delete Data;
}

void PolyHedra::ParsingData::Parse(const TextCommand & cmd)
{
	try
	{
		std::string name = cmd.Name();
		if (name == "")				{ /*std::cout << "empty\n";*/ }
		else if (name == "Type")	{ Parse_Type(cmd); }
		else if (name == "Format")	{ Parse_Format(cmd); }

		else if (name == "Skin")	{ Parse_Skin(cmd); }

		else if (name == "c")		{ Parse_Corner(cmd); }
		else if (name == "f")		{ Parse_Face(cmd); }

		else if (name == "p")		{ Parse_Corner(cmd); }
		else if (name == "d")		{ Parse_Face(cmd); }
		else if (name == "o")		{ Parse_Face(cmd); }

		else if (name == "v")		{ Parse_Offset(cmd); }
		else if (name == "circle")	{ Parse_CircleOLD(cmd); }
		else if (name == "belt0")	{ Parse_Belt(cmd, false, false); }
		else if (name == "belt1")	{ Parse_Belt(cmd, false, true); }
		else if (name == "fan0")	{ Parse_Fan(cmd, false, true); }
		else if (name == "fan1")	{ Parse_Fan(cmd, true, true); }

		else if (name == "circle>")	{ Parse_Circle(cmd, false); }
		else if (name == "circle<")	{ Parse_Circle(cmd, true); }

		else if (name == "belt>0")	{ Parse_Belt(cmd, false, false); }
		else if (name == "belt<0")	{ Parse_Belt(cmd, true, false); }
		else if (name == "belt>1")	{ Parse_Belt(cmd, false, true); }
		else if (name == "belt<1")	{ Parse_Belt(cmd, true, true); }

		else if (name == "fan>0")	{ Parse_Fan(cmd, false, false); }
		else if (name == "fan<0")	{ Parse_Fan(cmd, true, false); }
		else if (name == "fan>1")	{ Parse_Fan(cmd, false, true); }
		else if (name == "fan<1")	{ Parse_Fan(cmd, true, true); }

		else						{ Debug::Log << "unknown: " << cmd << Debug::Done; }
	}
	catch (std::exception & ex)
	{
		Debug::Log << "Exception while Parsing PolyHedra: " << ex.what() << '\n';
		Debug::Log << "Exception on TextCommand: " << cmd << Debug::Done;
	}
}
void PolyHedra::ParsingData::Parse_Type(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }
	if (cmd.ToString(0) != "PolyHedra") { throw InvalidCommandArgument(cmd, 0); }
}
void PolyHedra::ParsingData::Parse_Format(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }
	if (cmd.ToString(0) != "PH_2025_10_27") { throw InvalidCommandArgument(cmd, 0); }
}
void PolyHedra::ParsingData::Parse_Skin(const TextCommand & cmd)
{
	if (!(cmd.Count() == 1)) { throw InvalidCommandArgumentCount(cmd, "n == 1"); }
	//Debug::Log << cmd << Debug::Done;

	FileInfo file((File.DirectoryString() + "/" + cmd.ToString(0)).c_str());
	if (PH -> Skin != NULL)
	{
		std::cout << cmd.Name() << ": " << "Skin already given" << "\n";
		std::cout << "Prev: Skin: " << PH -> Skin << "\n";
		delete PH -> Skin;
		PH -> Skin = NULL;
	}
	if (!file.Exists()) { std::cout << cmd.Name() << ": " << "Bad Skin File" << "\n"; return; }
	PH -> Skin = SkinBase::Load(file);
}

void PolyHedra::ParsingData::Parse_Corner(const TextCommand & cmd)
{
	if (!(cmd.Count() == 3)) { throw InvalidCommandArgumentCount(cmd, "n == 3"); }
	//Debug::Log << cmd << Debug::Done;

	Point3D c;
	c.X = cmd.ToFloat(0);
	c.Y = cmd.ToFloat(1);
	c.Z = cmd.ToFloat(2);
	//std::cout << "c: " << c << "\n";
	Data -> Insert_Corn(Corner(c));
}
void PolyHedra::ParsingData::Parse_Face(const TextCommand & cmd)
{
	if (!(cmd.Count() >= 3 && cmd.Count() <= 4)) { throw InvalidCommandArgumentCount(cmd, "n >= 3 && n <= 4"); }
	//Debug::Log << cmd << Debug::Done;
	//std::cout << "COff: " << CornerOffset << "\n";

	unsigned int idx[cmd.Count()];
	for (unsigned int i = 0; i < cmd.Count(); i++)
	{
		std::string idx_str = cmd.ToString(i);
		if (idx_str[0] == '+' || idx_str[0] == '-')
		{ idx[i] = CornerOffset + cmd.ToInt32(i); }
		else
		{ idx[i] = cmd.ToUInt32(i); }
		//std::cout << "[" << idx[i] << "]" << Data -> Corners[idx[i]].Position << "\n";
	}

	if (cmd.Count() == 3)
	{
		Data -> Insert_Face3(FaceCorner(idx[0]), FaceCorner(idx[1]), FaceCorner(idx[2]));
	}
	else if (cmd.Count() == 4)
	{
		Data -> Insert_Face4(FaceCorner(idx[0]), FaceCorner(idx[1]), FaceCorner(idx[2]), FaceCorner(idx[3]));
	}
}

void PolyHedra::ParsingData::Parse_Offset(const TextCommand & cmd)
{
	if (!(cmd.Count() == 2)) { throw InvalidCommandArgumentCount(cmd, "n == 2"); }
	//Debug::Log << cmd << Debug::Done;

	{
		std::string corner = cmd.ToString(0);
		if (corner[0] == '+' || corner[0] == '-')
		{ CornerOffset += cmd.ToInt32(0); }
		else
		{ CornerOffset = cmd.ToUInt32(0); }
	}

	{
		std::string corner = cmd.ToString(1);
		if (corner[0] == '+' || corner[0] == '-')
		{ FaceOffset += cmd.ToInt32(1); }
		else
		{ FaceOffset = cmd.ToUInt32(1); }
	}
}
void PolyHedra::ParsingData::Parse_Belt(const TextCommand & cmd, bool direction, bool closure)
{
	unsigned int len = cmd.Count() / 2;
	if (!((cmd.Count() % 2) == 0)) { throw InvalidCommandArgumentCount(cmd, "(n % 2) == 2"); }
	//Debug::Log << cmd << Debug::Done;

	unsigned int idx0[len];
	unsigned int idx1[len];
	for (unsigned int i = 0; i < len; i++)
	{
		unsigned int i0 = i;
		unsigned int i1 = i + len;

		std::string idx0_str = cmd.ToString(i0);
		if (idx0_str[0] == '+' || idx0_str[0] == '-')
		{ idx0[i] = CornerOffset + cmd.ToInt32(i0); }
		else
		{ idx0[i] = cmd.ToUInt32(i0); }

		std::string idx1_str = cmd.ToString(i1);
		if (idx1_str[0] == '+' || idx1_str[0] == '-')
		{ idx1[i] = CornerOffset + cmd.ToInt32(i1); }
		else
		{ idx1[i] = cmd.ToUInt32(i1); }
	}

	for (unsigned int i = 1; i < len; i++)
	{
		if (!direction)
		{
			//Data -> Insert_Face4(idx0[i - 1], idx0[i - 0], idx1[i - 1], idx1[i - 0]);
			Data -> Insert_Face3(idx0[i - 1], idx0[i - 0], idx1[i - 1]);
			Data -> Insert_Face3(idx1[i - 1], idx0[i - 0], idx1[i - 0]);
		}
		else
		{
			//Data -> Insert_Face4(idx1[i - 1], idx0[i - 0], idx1[i - 1], idx1[i - 0]);
			Data -> Insert_Face3(idx1[i - 1], idx0[i - 0], idx0[i - 1]);
			Data -> Insert_Face3(idx1[i - 0], idx0[i - 0], idx1[i - 1]);
		}
	}

	if (closure)
	{
		if (!direction)
		{
			Data -> Insert_Face3(idx0[len - 1], idx0[0], idx1[len - 1]);
			Data -> Insert_Face3(idx1[len - 1], idx0[0], idx1[0]);
		}
		else
		{
			Data -> Insert_Face3(idx0[0], idx0[len -1], idx1[len - 1]);
			Data -> Insert_Face3(idx0[0], idx1[len -1], idx1[0]);
		}
	}
}
void PolyHedra::ParsingData::Parse_Band(const TextCommand & cmd, bool direction, bool closure)
{
	(void)cmd;
	(void)direction;
	(void)closure;
}
void PolyHedra::ParsingData::Parse_Fan(const TextCommand & cmd, bool direction, bool closure)
{
	unsigned int len = cmd.Count() - 1;
	if (!(cmd.Count() >= 2 && cmd.Count() <= 255)) { throw InvalidCommandArgumentCount(cmd, "n >= 2 && n <= 255"); }
	//Debug::Log << cmd << Debug::Done;

	unsigned int middle;
	{
		std::string idx0_str = cmd.ToString(0);
		if (idx0_str[0] == '+' || idx0_str[0] == '-')
		{ middle = CornerOffset + cmd.ToInt32(0); }
		else
		{ middle = cmd.ToUInt32(0); }
	}

	unsigned int blade[len];
	for (unsigned int i = 0; i < len; i++)
	{
		std::string idx1_str = cmd.ToString(i + 1);
		if (idx1_str[0] == '+' || idx1_str[0] == '-')
		{ blade[i] = CornerOffset + cmd.ToInt32(i + 1); }
		else
		{ blade[i] = cmd.ToUInt32(i + 1); }
	}

	for (unsigned int i = 1; i < len; i++)
	{
		if (!direction)
		{
			Data -> Insert_Face3(middle, blade[i - 1], blade[i - 0]);
		}
		else
		{
			Data -> Insert_Face3(middle, blade[i - 0], blade[i - 1]);
		}
	}

	if (closure)
	{
		if (!direction)
		{
			Data -> Insert_Face3(middle, blade[len - 1], blade[0]);
		}
		else
		{
			Data -> Insert_Face3(middle, blade[0], blade[len - 1]);
		}
	}
}
void PolyHedra::ParsingData::Parse_CircleOLD(const TextCommand & cmd)
{
	if (!(cmd.Count() == 10)) { throw InvalidCommandArgumentCount(cmd, "n == 10"); }
	//Debug::Log << cmd << Debug::Done;

	int step_num = cmd.ToInt32(0);
	int step_off = cmd.ToInt32(1);

	Point3D center(
		cmd.ToFloat(2),
		cmd.ToFloat(3),
		cmd.ToFloat(4)
	);
	float radius = cmd.ToFloat(5);

	Angle3D angle = Angle3D::FromPoint3D(Point3D(
		cmd.ToFloat(6),
		cmd.ToFloat(7),
		cmd.ToFloat(8)
	));
	Angle offset = Angle::Degrees(cmd.ToFloat(9));

	int step_abs = 0;
	if (step_num > 0) { step_abs = +step_num; offset += Angle::Degrees(000); }
	if (step_num < 0) { step_abs = -step_num; offset += Angle::Degrees(180); }

	Point3D rad_p(radius, 0, 0);
	for (int i = 0; i < step_abs; i++)
	{
		angle.Z = (Angle::Section(step_num) * (i + step_off)) + offset;
		angle.CalcMatrix();
		Point3D p;
		p = angle.rotateBack(rad_p);
		p = p + center;
		Data -> Insert_Corn(Corner(p));
		//std::cout << p << "\n";
	}
}
void PolyHedra::ParsingData::Parse_Circle(const TextCommand & cmd, bool direction)
{
	if (!(cmd.Count() == 11)) { throw InvalidCommandArgumentCount(cmd, "n == 11"); }
	//Debug::Log << cmd << Debug::Done;

	Angle step = Angle::Section(cmd.ToInt32(0));
	int step_num = cmd.ToInt32(1);
	int step_off = cmd.ToInt32(2);

	Point3D center(
		cmd.ToFloat(3),
		cmd.ToFloat(4),
		cmd.ToFloat(5)
	);
	Point3D radius(cmd.ToFloat(6), 0, 0);

	Angle3D angle = Angle3D::FromPoint3D(Point3D(
		cmd.ToFloat(7),
		cmd.ToFloat(8),
		cmd.ToFloat(9)
	));
	Angle offset = Angle::Degrees(cmd.ToFloat(10));

	for (int i = 0; i < step_num; i++)
	{
		if (!direction)
		{
			angle.Z = (step * (i + step_off)) + offset;
		}
		else
		{
			//angle.Z = ((i + step_off) * step) + offset;
		}
		angle.CalcMatrix();
		Point3D p;
		p = angle.rotateBack(radius) + center;
		Data -> Insert_Corn(Corner(p));
		//std::cout << p << "\n";
	}
}

PolyHedra * PolyHedra::Load(const FileInfo & file)
{
	Debug::Log << "Loading PolyHedra File " << file.Name() << " ..." << Debug::Done;
	ParsingData data(file);
	data.PH = new PolyHedra();
	data.Data = new PolyHedra::Template(*data.PH);

	TextCommandStream stream(file.LoadText());
	TextCommand cmd;
	while (stream.Continue(cmd))
	{
		data.Parse(cmd);
	}
	//ParsingCommand::SplitFileIntoCommands(data);

	if (data.Data != NULL)
	{
		if (data.PH -> Skin == NULL)
		{
			Skin2DA * skin = new Skin2DA();
			skin -> W = 1;
			skin -> H = 1;
			skin -> Images.Insert(Texture::Generate::NoSkin());
			data.PH -> Skin = skin;
		}
		data.Data -> Done();
	}
	else
	{
		data.PH = Generate::HexaHedron();
	}
	Debug::Log << "Loading PolyHedra File " << file.Name() << " done" << Debug::Done;
	Debug::Log << "Count:" << " V:" << data.PH -> Corners.Count() << Debug::Done;
	Debug::Log << "Count:" << " F:" << data.PH -> Faces.Count() << Debug::Done;
	AxisBox3D bound = data.PH -> CalcBound();
	Debug::Log << "Bound:" << "Limit:" << bound << Debug::Done;
	Debug::Log << "Bound:" << "Size:" << bound.Size() << Debug::Done;

	/*	Unit Converter
		Length:	to make Data more cohereent
		Area:	not sure where I would need this
		Volume:	might be interesting ?
		Angle:	Deg to Rad & Rad to Deg
		Time:	?
		once a base is made it shouldnt be very difficult to add new Units
	*/

	return data.PH;
}
