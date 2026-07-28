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



void PolyHedra::ParsingData::CommandFlags::MakeDefault()
{
	Direction = false;
	Closed = true;
	Middle = false;
}
bool PolyHedra::ParsingData::CommandFlags::Parse(char c)
{
	switch (c)
	{
		case '{': Direction = false; break;
		case '}': Direction = true; break;
		case '0': Closed = false; break;
		case '1': Closed = true; break;
		case '<': Middle = false; break;
		case '>': Middle = true; break;
		default: return false;
	}
	return true;
}
unsigned int PolyHedra::ParsingData::CommandFlags::Parse(const std::string & name)
{
	if (Parse(name[0]))
	{
		throw "Name cannot start with Flag Character.";
	}

	unsigned int len = name.size();
	for (unsigned int i = 0; i < name.size(); i++)
	{
		if (Parse(name[i]))
		{
			len = i;
			break;
		}
	}

	for (unsigned int i = len + 1; i < name.size(); i++)
	{
		if (!Parse(name[i]))
		{
			std::cerr << "Non Flag Character '" << name[i] << "' in '" << name << "' at [" << i << "] of [" << name.size() << "]\n";
			throw "Error";
		}
	}
	return len;
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
	, VertexOffset(0)
	, DefaultFlags()
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
				CommandFlags flags = DefaultFlags;
				unsigned int len = flags.Parse(name_args);
				if (len == name_func.size())
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
		throw UnknownCommandName(cmd_args);
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
		DefaultFlags.MakeDefault();
		return;
	}

	std::string str = cmd_args.ToString(0);
	if (str.size() == 0)
	{
		throw InvalidCommandArgument(cmd_args, 0); // optional description
	}

	// loop
	if (!DefaultFlags.Parse(str[0]))
	{
		// not Flag Character
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

	if (DefaultFlags.Direction)
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

	if (DefaultFlags.Direction)
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
		if (DefaultFlags.Direction)
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
		if (DefaultFlags.Direction)
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

void PolyHedra::ParsingData::Place_Circle(const TextCommandArgs & cmd_args, const CommandFlags & flags)
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
	VectorF3 radius(
		VariableFloats.To(cmd_args, 6),
		0,
		0
	);

	VectorF3 normal(
		cmd_args.ToFloat(7),
		cmd_args.ToFloat(8),
		cmd_args.ToFloat(9)
	);
	//std::cout << "Circle: Direction: " << flags.Direction << '\n';
	/*if (flags.Direction)
	{
		normal = -normal;
	}*/

	EulerAngle3D angle = EulerAngle3D::PointToZ(normal);
	Angle offset = Angle::Degrees(cmd_args.ToFloat(10));

	for (int i = 0; i < step_num; i++)
	{
		if (!flags.Direction)
		{
			angle.Z0 = (step * (step_off + i)) + offset;
		}
		else
		{
			angle.Z0 = (step * (step_off - i)) + offset;
		}
		PolyHedra.Insert_Corn(Corner(angle.forward(radius) + center));
	}
}
void PolyHedra::ParsingData::Place_Circle(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() == 11)) { throw InvalidCommandArgumentCount(cmd_args, "n == 11"); }

	CommandFlags flags = DefaultFlags;
	flags.Parse(cmd_args.Name());

	Place_Circle(cmd_args, flags);
}

void PolyHedra::ParsingData::Place_Face(const TextCommandArgs & cmd_args, const CommandFlags & flags)
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
		if (!flags.Direction)
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
		if (!flags.Direction)
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

	CommandFlags flags = DefaultFlags;
	flags.Parse(cmd_args.Name());

	Place_Face(cmd_args, flags);
}

void PolyHedra::ParsingData::Place_Belt_Face(const CommandFlags & flags, unsigned int temp[4])
{
	if (!flags.Direction)
	{
		PolyHedra.Insert_Face3(temp[0], temp[2], temp[1]);
		PolyHedra.Insert_Face3(temp[3], temp[1], temp[2]);
	}
	else
	{
		PolyHedra.Insert_Face3(temp[1], temp[2], temp[0]);
		PolyHedra.Insert_Face3(temp[2], temp[1], temp[3]);
	}
}
void PolyHedra::ParsingData::Place_Belt(const TextCommandArgs & cmd_args, const CommandFlags & flags)
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
		Place_Belt_Face(flags, temp);
	}

	if (flags.Closed)
	{
		unsigned int temp[4] = {
			list0[n],
			list0[0],
			list1[n],
			list1[0],
		};
		Place_Belt_Face(flags, temp);
	}
}
void PolyHedra::ParsingData::Place_Belt(const TextCommandArgs & cmd_args)
{
	if (!((cmd_args.Count() % 2) == 0 && cmd_args.Count() >= 4 && cmd_args.Count() <= 255)) { throw InvalidCommandArgumentCount(cmd_args, "(n % 2) == 0 && n >= 4 && n <= 255"); }

	CommandFlags flags = DefaultFlags;
	flags.Parse(cmd_args.Name());

	Place_Belt(cmd_args, flags);
}

void PolyHedra::ParsingData::Place_Band(const TextCommandArgs & cmd_args, const CommandFlags & flags)
{
	throw CommandNotImplemented(cmd_args);
	(void)cmd_args;
	(void)flags;
}
void PolyHedra::ParsingData::Place_Band(const TextCommandArgs & cmd_args)
{
	throw CommandNotImplemented(cmd_args);
	(void)cmd_args;
}

void PolyHedra::ParsingData::Place_Fan_Face(const CommandFlags & flags, unsigned int middle, unsigned int blade[2])
{
	if (!flags.Direction)
	{
		if (!flags.Middle)
		{
			PolyHedra.Insert_Face3(blade[1], middle, blade[0]);
		}
		else
		{
			PolyHedra.Insert_Face3(blade[0], middle, blade[1]);
		}
	}
	else
	{
		if (!flags.Middle)
		{
			PolyHedra.Insert_Face3(blade[0], middle, blade[1]);
		}
		else
		{
			PolyHedra.Insert_Face3(blade[1], middle, blade[0]);
		}
	}
}
void PolyHedra::ParsingData::Place_Fan(const TextCommandArgs & cmd_args, const CommandFlags & flags)
{
	unsigned int len = cmd_args.Count() - 1;

	unsigned int middle;
	unsigned int blade[len];

	if (!flags.Middle)
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
		Place_Fan_Face(flags, middle, temp);
	}

	if (flags.Closed)
	{
		unsigned int temp[2] = {
			blade[n],
			blade[0],
		};
		Place_Fan_Face(flags, middle, temp);
	}
}
void PolyHedra::ParsingData::Place_Fan(const TextCommandArgs & cmd_args)
{
	if (!(cmd_args.Count() >= 3 && cmd_args.Count() <= 255)) { throw InvalidCommandArgumentCount(cmd_args, "n >= 3 && n <= 255"); }

	CommandFlags flags = DefaultFlags;
	flags.Parse(cmd_args.Name());

	Place_Fan(cmd_args, flags);
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
