#include "PolyHedra/Parsing.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Generate.hpp"

// Skin
#include "PolyHedra/Skin/Skin.hpp"
#include "Graphics/Texture/Generate.hpp"

// File
#include "FileInfo.hpp"
//#include "FilePath.hpp"
//#include "FileParsing/LineCommand.hpp"
#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"
#include "FileParsing/Text/Exceptions.hpp"

// ValueType
#include "ValueType/Vector/F3.hpp"
#include "ValueType/Angle.hpp"
#include "ValueType/EulerAngle3D.hpp"
#include "ValueType/Box/F3.hpp"
#include "ValueType/_Show.hpp"

// Debug
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



unsigned int PolyHedra::ParsingData::ToVertexIndex(const TextCommandArgs & cmd_args, unsigned int arg_idx) const
{
	std::string str = cmd_args.ToString(arg_idx);
	// check for len == 0 ?
	if (str[0] == '+' || str[0] == '-')
	{
		return VertexOffset + cmd_args.ToInt32(arg_idx);
	}
	else
	{
		return cmd_args.ToUInt32(arg_idx);
	}
}



void PolyHedra::ParsingData::CommandsClear()
{
	for (unsigned int i = 0; i < Commands.Count(); i++)
	{
		delete Commands[i];
	}
	Commands.Clear();
}
void PolyHedra::ParsingData::CommandsDefault()
{
	Commands.Insert(new TextCommandFunc("Type",		this, &ParsingData::Check_Type));
	Commands.Insert(new TextCommandFunc("Format",	this, &ParsingData::Change_Format));

	Commands.Insert(new TextCommandFunc("Name",		this, &ParsingData::Change_Name));
	Commands.Insert(new TextCommandFunc("Skin",		this, &ParsingData::New_Skin));

	Commands.Insert(new TextCommandFunc("varFloat",		&VariableFloats, &ParsingVariable::FloatMemory::Put));
}
void PolyHedra::ParsingData::CommandsLegacy()
{
	Commands.Insert(new TextCommandFunc("p",	this, &ParsingData::Place_Vertex));
	Commands.Insert(new TextCommandFunc("d",	this, &ParsingData::Legacy_Face3));
	Commands.Insert(new TextCommandFunc("o",	this, &ParsingData::Legacy_Face4));
	Commands.Insert(new TextCommandFunc("v",	this, &ParsingData::Legacy_Offset2));

	Commands.Insert(new TextCommandFunc("c",	this, &ParsingData::Place_Vertex));
	Commands.Insert(new TextCommandFunc("f",	this, &ParsingData::Legacy_Face34));
}
void PolyHedra::ParsingData::CommandsNormal()
{
	Commands.Insert(new TextCommandFunc("default",		this, &ParsingData::Change_Default));
	Commands.Insert(new TextCommandFunc("offset",		this, &ParsingData::Change_Offset));
	Commands.Insert(new TextCommandFunc("index",		this, &ParsingData::Legacy_Offset2)); // this is kind of Lecagy ?

	Commands.Insert(new TextCommandFunc("vertex",		this, &ParsingData::Place_Vertex));
	Commands.Insert(new TextCommandFunc("circle",		this, &ParsingData::Place_Circle));

	Commands.Insert(new TextCommandFunc("face",			this, &ParsingData::Place_Face));
	Commands.Insert(new TextCommandFunc("belt",			this, &ParsingData::Place_Belt));
	Commands.Insert(new TextCommandFunc("fan",			this, &ParsingData::Place_Fan));
}



PolyHedra::ParsingData::~ParsingData()
{
	CommandsClear();
}
PolyHedra::ParsingData::ParsingData(const FileInfo & file, ::PolyHedra & polyhedra)
	: File(file)
	, PolyHedra(polyhedra)
	, DefaultDirection(false)
	, DefaultClosed(true)
	, DefaultMiddle(false)
	, VertexOffset(0)
{
	PolyHedra.File = File;
	CommandsDefault();
	CommandsLegacy();
}



void PolyHedra::ParsingData::Parse(const TextCommandArgs & cmd_args)
{
	try
	{
		std::string name_args = cmd_args.Name();
		if (name_args == "")
		{
			return;
		}
		for (unsigned int i = 0; i < Commands.Count(); i++)
		{
			const TextCommandFunc & cmd_func = *Commands[i];
			const std::string & name_func = cmd_func.Name;

			// could be optimized with a "starts_with" check
			if (name_args == name_func)
			{
				cmd_func.Func(cmd_args);
				return;
			}
			else
			{
				unsigned int len;
				bool found = false;
				for (len = 0; len < name_args.size(); len++)
				{
					switch (name_args[len])
					{
						case '{': found = true; break;
						case '}': found = true; break;
						case '0': found = true; break;
						case '1': found = true; break;
						case '<': found = true; break;
						case '>': found = true; break;
						default: break;
					}
					if (found) { break; }
				}

				if (found && len == name_func.size())
				{
					name_args = name_args.substr(0, len);
					if (name_args == name_func)
					{
						cmd_func.Func(cmd_args);
						return;
					}
				}
			}
		}
		std::cout << "unknown: " << cmd_args << '\n';
	}
	catch (std::exception & ex)
	{
		std::cout << "Exception while Parsing PolyHedra: " << ex.what() << '\n';
		std::cout << "Exception on TextCommand: " << cmd_args << '\n';
	}
}

void PolyHedra::ParsingData::Check_Type(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }
	if (cmd_args.ToString(0) != "PolyHedra")
	{
		throw InvalidCommandArgument(cmd_args, 0);
	}
}
void PolyHedra::ParsingData::Change_Format(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }

	CommandsClear();
	CommandsDefault();

	std::string format = cmd_args.ToString(0);
	if (format == "All")
	{
		CommandsNormal();
		CommandsLegacy();
	}
	else if (format == "Legacy")
	{
		CommandsLegacy();
	}
	else if (format == "Normal")
	{
		CommandsNormal();
	}
	else
	{
		throw InvalidCommandArgument(cmd_args, 0);
	}
}

void PolyHedra::ParsingData::Change_Name(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }
	PolyHedra.Name = cmd_args.ToString(0);
}
void PolyHedra::ParsingData::New_Skin(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }
	//Debug::Log << cmd << Debug::Done;
	
	if (PolyHedra.Skin != nullptr) { throw CommandInvalidState(cmd_args, "PolyHedra already has Skin"); }

	FileInfo file((File.DirectoryString() + "/" + cmd_args.ToString(0)).c_str());
	if (!file.Exists()) { std::cout << cmd_args.Name() << ": " << "Bad Skin File" << "\n"; return; }
	PolyHedra.Skin = Skin::Load(file);
}

void PolyHedra::ParsingData::Change_Default(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 0 || cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 0 || n == 1"); }

	if (cmd_args.Count() == 0)
	{
		DefaultDirection = false;
		DefaultClosed = true;
		DefaultMiddle = false;
		return;
	}

	std::string str = cmd_args.ToString(0);
	if (str.size() == 0)
	{
		throw InvalidCommandArgument(cmd_args, 0); // optional description
	}

	// loop
	char c = str[0];
	switch (c)
	{
		case '{': DefaultDirection = false; break;
		case '}': DefaultDirection = true; break;
		case '0': DefaultClosed = false; break;
		case '1': DefaultClosed = true; break;
		case '<': DefaultMiddle = false; break;
		case '>': DefaultMiddle = true; break;
		default: break;

		// turn these into a struct that perses automatically
		// belt does not need middle, different struct or just ignore
		// '<' '>' would make more sense for indicating middle
		// '<' has the middle on the left
		// '>' has the middle on the right
		// what to use for direction instead ?
		// this would require changing a lot of files
		// '<' '>' direction has been chagned, so they will all need to be changed anyway
		// default dir>
		// default dir<
		// should direction be specified in the command at all ?
		// '<' '>' for middle makes sense
		// '0' '1' makes sense
		// face direciton should be the same
	}
}
void PolyHedra::ParsingData::Change_Offset(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw InvalidCommandArgumentCount(cmd_args, "n == 1"); }

	VertexOffset = ToVertexIndex(cmd_args, 0);
}

void PolyHedra::ParsingData::Legacy_Face3(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 3)) { throw InvalidCommandArgumentCount(cmd_args, "n == 3"); }

	unsigned int idx[3];
	for (unsigned int i = 0; i < 3; i++)
	{
		std::string idx_str = cmd_args.ToString(i);
		if (idx_str[0] == '+' || idx_str[0] == '-')
		{ idx[i] = VertexOffset + cmd_args.ToInt32(i); }
		else
		{ idx[i] = cmd_args.ToUInt32(i); }
	}

	if (DefaultDirection)
	{
		PolyHedra.Insert_Face3(idx[0], idx[1], idx[2]);
	}
	else
	{
		PolyHedra.Insert_Face3(idx[2], idx[1], idx[0]);
	}
}
void PolyHedra::ParsingData::Legacy_Face4(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw InvalidCommandArgumentCount(cmd_args, "n == 4"); }

	unsigned int idx[4];
	for (unsigned int i = 0; i < 4; i++)
	{
		std::string idx_str = cmd_args.ToString(i);
		if (idx_str[0] == '+' || idx_str[0] == '-')
		{ idx[i] = VertexOffset + cmd_args.ToInt32(i); }
		else
		{ idx[i] = cmd_args.ToUInt32(i); }
	}

	if (DefaultDirection)
	{
		PolyHedra.Insert_Face4(idx[0], idx[1], idx[2], idx[3]);
	}
	else
	{
		PolyHedra.Insert_Face4(idx[0], idx[2], idx[1], idx[3]);
	}
}
void PolyHedra::ParsingData::Legacy_Face34(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 3 || cmd_args.Count() == 4)) { throw InvalidCommandArgumentCount(cmd_args, "n == 3 || n == 4"); }

	unsigned int len = cmd_args.Count();
	unsigned int idx[len];
	for (unsigned int i = 0; i < len; i++)
	{
		std::string idx_str = cmd_args.ToString(i);
		if (idx_str[0] == '+' || idx_str[0] == '-')
		{ idx[i] = VertexOffset + cmd_args.ToInt32(i); }
		else
		{ idx[i] = cmd_args.ToUInt32(i); }
	}

	if (len == 3)
	{
		if (DefaultDirection)
		{
			PolyHedra.Insert_Face3(idx[0], idx[1], idx[2]);
		}
		else
		{
			PolyHedra.Insert_Face3(idx[2], idx[1], idx[0]);
		}
	}
	else if (len == 4)
	{
		if (DefaultDirection)
		{
			PolyHedra.Insert_Face4(idx[0], idx[1], idx[2], idx[3]);
		}
		else
		{
			PolyHedra.Insert_Face4(idx[0], idx[2], idx[1], idx[3]);
		}
	}
}
void PolyHedra::ParsingData::Legacy_Offset2(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw InvalidCommandArgumentCount(cmd_args, "n == 2"); }

	std::string str = cmd_args.ToString(0);
	if (str[0] == '+' || str[0] == '-')
	{
		VertexOffset += cmd_args.ToInt32(0);
	}
	else
	{
		VertexOffset = cmd_args.ToUInt32(0);
	}
}

void PolyHedra::ParsingData::Place_Vertex(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 3)) { throw InvalidCommandArgumentCount(cmd_args, "n == 3"); }
	//Debug::Log << cmd << Debug::Done;

	VectorF3 c(
		VariableFloats.To(cmd_args, 0),
		VariableFloats.To(cmd_args, 1),
		VariableFloats.To(cmd_args, 2)
	);
	//std::cout << "c: " << c << "\n";
	PolyHedra.Insert_Corn(Corner(c));
}

void PolyHedra::ParsingData::Place_Circle(const TextCommandArgs & cmd_args, bool direction)
{
	if (!(cmd_args.Count() == 11)) { throw InvalidCommandArgumentCount(cmd_args, "n == 11"); }

	Angle step = Angle::Section(cmd_args.ToInt32(0));
	int step_num = cmd_args.ToInt32(1);
	int step_off = cmd_args.ToInt32(2);

	VectorF3 center(
		VariableFloats.To(cmd_args, 3),
		VariableFloats.To(cmd_args, 4),
		VariableFloats.To(cmd_args, 5)
	);
	VectorF3 radius(VariableFloats.To(cmd_args, 6), 0, 0);

	EulerAngle3D angle = EulerAngle3D::PointToZ(VectorF3(
		cmd_args.ToFloat(7),
		cmd_args.ToFloat(8),
		cmd_args.ToFloat(9)
	));
	Angle offset = Angle::Degrees(cmd_args.ToFloat(10));

	for (int i = 0; i < step_num; i++)
	{
		if (!direction)
		{
			angle.Z0 = (step * (i + step_off)) + offset;
		}
		else
		{
			//angle.Z = ((i + step_off) * step) + offset;
		}
		//angle.CalcMatrix();
		VectorF3 p;
		//p = angle.rotateBack(radius) + center;
		p = angle.forward(radius) + center;
		PolyHedra.Insert_Corn(Corner(p));
		//std::cout << p << "\n";
	}
}
void PolyHedra::ParsingData::Place_Circle(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 11)) { throw InvalidCommandArgumentCount(cmd_args, "n == 11"); }

	bool direction = DefaultDirection;

	std::string name = cmd_args.Name();
	for (unsigned int i = 3; i < name.size(); i++)
	{
		char c = name[i];
		switch (c)
		{
			case '>': direction = false; break;
			case '<': direction = true; break;
		}
	}

	Place_Circle(cmd_args, direction);
}

void PolyHedra::ParsingData::Place_Face(const TextCommandArgs & cmd_args, bool direction)
{
	if (!(cmd_args.Count() == 3 || cmd_args.Count() == 4)) { throw InvalidCommandArgumentCount(cmd_args, "n == 3 || n == 4"); }

	unsigned int len = cmd_args.Count();

	unsigned int idx[len];

	for (unsigned int i = 0; i < len; i++)
	{
		idx[i] = ToVertexIndex(cmd_args, i);
	}

	if (len == 3)
	{
		if (!direction)
		{
			std::cout << "Face123: " << idx[0] << ' ' << idx[1] << ' ' << idx[2] << '\n';
			PolyHedra.Insert_Face3(idx[0], idx[1], idx[2]);
		}
		else
		{
			PolyHedra.Insert_Face3(idx[2], idx[1], idx[0]);
		}
	}
	else if (len == 4)
	{
		if (!direction)
		{
			PolyHedra.Insert_Face4(idx[0], idx[1], idx[2], idx[3]);
		}
		else
		{
			PolyHedra.Insert_Face4(idx[0], idx[2], idx[1], idx[3]);
		}
	}
}
void PolyHedra::ParsingData::Place_Face(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 3 || cmd_args.Count() == 4)) { throw InvalidCommandArgumentCount(cmd_args, "n == 3 || n == 4"); }

	bool direction = DefaultDirection;

	std::string name = cmd_args.Name();
	for (unsigned int i = 3; i < name.size(); i++)
	{
		char c = name[i];
		switch (c)
		{
			case '>': direction = false; break;
			case '<': direction = true; break;
		}
	}

	Place_Face(cmd_args, direction);
}

static void Belt_Face(PolyHedra & polyhedra, unsigned int temp[4], bool dir)
{
	if (!dir)
	{
		polyhedra.Insert_Face3(temp[0], temp[2], temp[1]);
		polyhedra.Insert_Face3(temp[3], temp[1], temp[2]);
	}
	else
	{
		polyhedra.Insert_Face3(temp[1], temp[2], temp[0]);
		polyhedra.Insert_Face3(temp[2], temp[1], temp[3]);
	}
}
void PolyHedra::ParsingData::Place_Belt(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure)
{
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

	unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int temp[4] = {
			list0[i + 0],
			list0[i + 1],
			list1[i + 0],
			list1[i + 1],
		};
		Belt_Face(PolyHedra, temp, f_direction);
	}

	if (f_closure)
	{
		unsigned int temp[4] = {
			list0[n],
			list0[0],
			list1[n],
			list1[0],
		};
		Belt_Face(PolyHedra, temp, f_direction);
	}
}
void PolyHedra::ParsingData::Place_Belt(const TextCommandArgs & cmd_args)
{
	if (!((cmd_args.Count() % 2) == 0 && cmd_args.Count() >= 4 && cmd_args.Count() <= 255)) { throw InvalidCommandArgumentCount(cmd_args, "(n % 2) == 0 && n >= 4 && n <= 255"); }

	bool direction = DefaultDirection;
	bool closure = DefaultClosed;

	std::string name = cmd_args.Name();
	for (unsigned int i = 3; i < name.size(); i++)
	{
		char c = name[i];
		switch (c)
		{
			case '{': direction = false; break;
			case '}': direction = true; break;
			case '0': closure = false; break;
			case '1': closure = true; break;
		}
	}

	Place_Belt(cmd_args, direction, closure);
}

void PolyHedra::ParsingData::Place_Band(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure)
{
	throw CommandNotImplemented(cmd_args);
	(void)cmd_args;
	(void)f_direction;
	(void)f_closure;
}
void PolyHedra::ParsingData::Place_Band(const TextCommandArgs & cmd_args)
{
	throw CommandNotImplemented(cmd_args);
	(void)cmd_args;
}

static void Fan_Face(PolyHedra & polyhedra, unsigned int middle, unsigned int blade[2], bool dir, bool mid)
{
	if (!dir)
	{
		if (!mid)
		{
			polyhedra.Insert_Face3(blade[1], middle, blade[0]);
		}
		else
		{
			polyhedra.Insert_Face3(blade[0], middle, blade[1]);
		}
	}
	else
	{
		if (!mid)
		{
			polyhedra.Insert_Face3(blade[0], middle, blade[1]);
		}
		else
		{
			polyhedra.Insert_Face3(blade[1], middle, blade[0]);
		}
	}
}
/*static void Fan_Faces(PolyHedra & polyhedra, unsigned int middle, unsigned int blade[], unsigned int len, bool close, bool dir, bool mid) { }*/
void PolyHedra::ParsingData::Place_Fan(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure, bool f_middle)
{
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

	unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int temp[2] = {
			blade[i + 0],
			blade[i + 1],
		};
		Fan_Face(PolyHedra, middle, temp, f_direction, f_middle);
	}

	if (f_closure)
	{
		unsigned int temp[2] = {
			blade[n],
			blade[0],
		};
		Fan_Face(PolyHedra, middle, temp, f_direction, f_middle);
	}
}
void PolyHedra::ParsingData::Place_Fan(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() >= 3 && cmd_args.Count() <= 255)) { throw InvalidCommandArgumentCount(cmd_args, "n >= 3 && n <= 255"); }

	bool direction = DefaultDirection;
	bool closure = DefaultClosed;
	bool middle = DefaultMiddle;

	std::string name = cmd_args.Name();
	for (unsigned int i = 3; i < name.size(); i++)
	{
		char c = name[i];
		switch (c)
		{
			case '{': direction = false; break;
			case '}': direction = true; break;
			case '0': closure = false; break;
			case '1': closure = true; break;
			case '<': middle = false; break;
			case '>': middle = true; break;
		}
	}

	Place_Fan(cmd_args, direction, closure, middle);
}



PolyHedra * PolyHedra::Load(const FileInfo & file)
{
	//Debug::Log << "Loading PolyHedra File " << '"' << file.Name() << '"' << " ..." << Debug::Done;
	std::cout << "Loading PolyHedra File " << '"' << file.Path << '"' << " ..." << '\n';

	PolyHedra * polyhedra = new PolyHedra();
	ParsingData data(file, *polyhedra);

	TextCommandStream stream(file.LoadText());
	TextCommandArgs cmd_args;
	while (stream.Continue(cmd_args))
	{
		data.Parse(cmd_args);
	}

	polyhedra -> Done();

	//Debug::Log << "Loading PolyHedra File " << '"' << file.Name() << '"' << " done" << '\n';
	//Debug::Log << ((*polyhedra).ToInfo());
	//Debug::Log << Debug::Done;
	std::cout << "Loading PolyHedra File " << '"' << file.Path << '"' << " done" << '\n';

	return polyhedra;
}
