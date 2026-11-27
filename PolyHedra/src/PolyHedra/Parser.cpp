#include "PolyHedra/Parser.hpp"
#include "PolyHedra/Generate.hpp"
#include "PolyHedra/Entry.hpp"
#include "PolyHedra/Manager.hpp"

// FileParsing
#include "FileInfo.hpp"
#include "DirectoryInfo.hpp"
#include "FileParsing/TextCommand/Args.hpp"
#include "FileParsing/TextCommand/ArgsStream.hpp"
#include "FileParsing/TextCommand/Exceptions.hpp"
#include "FileParsing/TextCommand/FuncNormal.hpp"
#include "FileParsing/Variables/Float.hpp"

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



void PolyHedraParser::CommandFlags::MakeDefault()
{
	Direction = false;
	Closed = true;
	Middle = false;
}
bool PolyHedraParser::CommandFlags::Parse(char c)
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
unsigned int PolyHedraParser::CommandFlags::Parse(const std::string & name)
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

PolyHedraParser::CommandFlagsFunc::~CommandFlagsFunc()
{ }
bool PolyHedraParser::CommandFlagsFunc::TryInvoke(const TextCommand::Args & cmd_args) const
{
	std::string name_args = cmd_args.Name();
	std::string name_func = Name;
	//CommandFlags flags = DefaultFlags;
	CommandFlags flags;
	flags.Direction = false;
	flags.Middle = false;
	flags.Closed = true;
	unsigned int len = flags.Parse(name_args);
	if (len == name_func.size())
	{
		name_args = name_args.substr(0, len);
		if (name_args == name_func)
		{
			Function(cmd_args, flags);
			return true;
		}
	}
	return false;
}

/*void PolyHedraParser::CommandsClear()
{
	for (unsigned int i = 0; i < Commands.Count(); i++)
	{
		delete Commands[i];
	}
	Commands.Clear();
}*/
void PolyHedraParser::CommandsDefault()
{
	Commands.Insert(new TextCommand::FuncNormal("Type",		this, &PolyHedraParser::Check_Type));
	Commands.Insert(new TextCommand::FuncNormal("Format",	this, &PolyHedraParser::Change_Format));

//	Commands.Insert(new TextCommand::FuncNormal("Name",		this, &PolyHedraParser::Change_Name));
	Commands.Insert(new TextCommand::FuncNormal("Skin",		this, &PolyHedraParser::New_Skin));
}
void PolyHedraParser::CommandsLegacy()
{
	Commands.Insert(new TextCommand::FuncNormal("p",	this, &PolyHedraParser::Place_Vertex));
	Commands.Insert(new TextCommand::FuncNormal("d",	this, &PolyHedraParser::Legacy_Face3));
	Commands.Insert(new TextCommand::FuncNormal("o",	this, &PolyHedraParser::Legacy_Face4));
	Commands.Insert(new TextCommand::FuncNormal("v",	this, &PolyHedraParser::Legacy_Offset2));

	Commands.Insert(new TextCommand::FuncNormal("c",	this, &PolyHedraParser::Place_Vertex));
	Commands.Insert(new TextCommand::FuncNormal("f",	this, &PolyHedraParser::Legacy_Face34));
}
void PolyHedraParser::CommandsNormal()
{
	Commands.Insert(new TextCommand::FuncNormal("default",		this, &PolyHedraParser::Change_Default));
	Commands.Insert(new TextCommand::FuncNormal("offset",		this, &PolyHedraParser::Change_Offset));

	Commands.Insert(new TextCommand::FuncNormal("var",			this, &PolyHedraParser::Change_Variable));

	Commands.Insert(new TextCommand::FuncNormal("vertex",		this, &PolyHedraParser::Place_Vertex));
	Commands.Insert(new CommandFlagsFunc(		"circle",		this, &PolyHedraParser::Place_Circle));

	Commands.Insert(new CommandFlagsFunc("face",	this, &PolyHedraParser::Place_Face));
	Commands.Insert(new CommandFlagsFunc("belt",	this, &PolyHedraParser::Place_Belt));
	Commands.Insert(new CommandFlagsFunc("band",	this, &PolyHedraParser::Place_Band));
	Commands.Insert(new CommandFlagsFunc("fan",		this, &PolyHedraParser::Place_Fan));

	Commands.Insert(new CommandFlagsFunc("beltI",	this, &PolyHedraParser::Place_IndexArray_Belt));
	Commands.Insert(new CommandFlagsFunc("bandI",	this, &PolyHedraParser::Place_IndexArray_Band));
	Commands.Insert(new CommandFlagsFunc("fanI",	this, &PolyHedraParser::Place_IndexArray_Fan));

	Commands.Insert(new TextCommand::FuncNormal("normal",		this, &PolyHedraParser::Normal_Change));

	Commands.Insert(new TextCommand::FuncNormal("param",		this, &PolyHedraParser::Parameter_Check));
	Commands.Insert(new TextCommand::FuncNormal("paramFile",	this, &PolyHedraParser::Parameter_File));

	Commands.Insert(new TextCommand::FuncNormal("PolyHedraCombine",		this, &PolyHedraParser::PolyHedra_Combine));
	//Commands.Insert(new TextCommand::FuncNormal("PolyHedraPut",			this, &PolyHedraParser::PolyHedra_Put));
}



static void CheckThrow(const TextCommand::Args & cmd_args, bool check, const char * str)
{
	if (!check)
	{
		throw TextCommand::Exception::InvalidArgumentCount(cmd_args, str);
	}
}

void PolyHedraParser::Change_Variable(const TextCommand::Args & cmd_args)
{
	CheckThrow(cmd_args, cmd_args.Count() >= 2, "n >= 2");
	//std::cout << "var:: " << cmd_args.Split(0) << '\n';
	std::string type = cmd_args.ToString(0);
	std::string name = cmd_args.ToString(1);
	// split type check into CommandDecider ?
	// also handle array as a variant of the normal type

	if (type == "~")
	{
		CheckThrow(cmd_args, cmd_args.Count() == 2, "n == 2");
		// remove Variable
	}
	else if (type == "float")
	{
		CheckThrow(cmd_args, cmd_args.Count() == 3, "n == 3");
		/*if (cmd_args.ToString(2) == "return")
		{ }
		else*/
		{
			Variables.Set(name, ToVariable<float>(cmd_args, 2));
		}
	}
	else if (type == "index")
	{
		CheckThrow(cmd_args, cmd_args.Count() == 3, "n == 3");
		if (cmd_args.ToString(2) == "return")
		{
			Variables.Set(name, VariableIndexReturn);
		}
		else
		{
			Variables.Set(name, ToVariable<unsigned int>(cmd_args, 2));
		}
	}
	else if (type == "index[]")
	{
		CheckThrow(cmd_args, cmd_args.Count() >= 3, "n >= 3");
		if (cmd_args.ToString(2) == "return")
		{
			CheckThrow(cmd_args, cmd_args.Count() == 3, "n == 3");
			Variables.Set(name, VariableIndexArrayReturn);
		}
		else
		{
			CheckThrow(cmd_args, cmd_args.Count() >= 3, "n >= 3");
			Container::Array<unsigned int> data(cmd_args.Count() - 2);
			for (unsigned int i = 0; i < data.Length(); i++)
			{
				data[i] = ToVariable<unsigned int>(cmd_args, i + 2);
			}
			Variables.Set(name, data);
		}
	}
	else if (type == "Trans3D")
	{
		CheckThrow(cmd_args, cmd_args.Count() == 8, "n == 8");
		Trans3D trans(
			VectorF3(
				ToVariable<float>(cmd_args, 2),
				ToVariable<float>(cmd_args, 3),
				ToVariable<float>(cmd_args, 4)
			),
			EulerAngle3D::Degrees(
				ToVariable<float>(cmd_args, 5),
				ToVariable<float>(cmd_args, 6),
				ToVariable<float>(cmd_args, 7)
			)
		);
		Variables.Set(name, trans);
	}
	else if (type == "PolyHedra")
	{
		CheckThrow(cmd_args, cmd_args.Count() == 3, "n == 3");
		if (Manager == nullptr) { throw TextCommand::Exception::InvalidState(cmd_args, "Manager missing for polyhedra Variable"); }

		FileInfo file = File.Directory().File(cmd_args.ToString(2).c_str());
		if (!file.Exists()) { throw TextCommand::Exception::InvalidArgument(cmd_args, 0, "Bad PolyHedra File"); } // this is not InvalidArgument. this is generic error

		PolyHedra * polyhedra  = Manager -> Take_Data(file);
		Variables.Set(name, polyhedra);
	}
}

static bool IsLiteralVertexIndex(const std::string & str)
{
	char c;

	if (str.size() == 0) { return false; }
	c = str[0];

	if (c == '+' || c == '-')
	{
		if (str.size() == 1) { return false; }
		c = str[1];
	}

	if (c >= '0' && c <= '9')
	{
		return true;
	}

	return false;
}

template<> void PolyHedraParser::ToVariable<float>(const TextCommand::Args & cmd_args, unsigned int idx, float & data) const
{
	data = ParsingVariable::Float::Parse(Variables, cmd_args.ToString(idx));
}
template<> void PolyHedraParser::ToVariable<unsigned int>(const TextCommand::Args & cmd_args, unsigned int idx, unsigned int & data) const
{
	std::string str = cmd_args.ToString(idx);
	if (IsLiteralVertexIndex(str))
	{
		// check for len == 0 ?
		if (str[0] == '+' || str[0] == '-')
		{
			data = VertexOffset + cmd_args.ToInt32(idx);
		}
		else
		{
			data = cmd_args.ToUInt32(idx);
		}
	}
	else
	{
		Variables.Get(str, data);
	}
}
template<> void PolyHedraParser::ToVariable<Trans3D>(const TextCommand::Args & cmd_args, unsigned int idx, Trans3D & data) const
{
	std::string str = cmd_args.ToString(idx);
	Variables.Get(str, data);
}
template<> void PolyHedraParser::ToVariable<PolyHedra *>(const TextCommand::Args & cmd_args, unsigned int idx, PolyHedra * & data) const
{
	std::string str = cmd_args.ToString(idx);
	Variables.Get(str, data);
}



__attribute__((unused)) static void Display_Data(const char * name, const Container::Array<unsigned int> & data)
{
	std::cout << name;
	std::cout << " [ ";
	for (unsigned int i = 0; i < data.Length(); i++)
	{
		if (i != 0) { std::cout << " , "; }
		std::cout << data[i];
	}
	std::cout << " ] ";
	std::cout << data.Length();;
	std::cout << '\n';
}



PolyHedraParser::~PolyHedraParser()
{ }
PolyHedraParser::PolyHedraParser()
	: TextCommand::Loop()
{
	CommandsDefault();
	CommandsLegacy();
}



/*void PolyHedraParser::Parse(const TextCommand::Args & cmd_args)
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
			const TextCommand::Func & cmd_func = *Commands[i];
			const std::string & name_func = cmd_func.Name;

			// could be optimized with a "starts_with" check
			if (name_args == name_func)
			{
				cmd_func.Function(cmd_args);
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
						cmd_func.Function(cmd_args);
						return;
					}
				}
			}
		}
		throw TextCommand::Exception::Unknown(cmd_args);
	}
	catch (std::exception & ex)
	{
		std::cout << "Exception while Parsing PolyHedra: " << ex.what() << '\n';
		std::cout << "Exception on TextCommand: " << cmd_args << '\n';
	}
}*/

void PolyHedraParser::Check_Type(const TextCommand::Args & cmd_args)
{
	unsigned int n = cmd_args.Count();
	if (!(n == 1 || n == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1 || n == 2"); } // fatal

	if (cmd_args.ToString(0) != "PolyHedra")
	{
		throw TextCommand::Exception::InvalidArgument(cmd_args, 0, "Invalid Type"); // fatal
	}

	if (Parser == nullptr)
	{
		if (Object != nullptr)
		{
			throw TextCommand::Exception::InvalidState(cmd_args, "Object already exists");
		}
		Object = new PolyHedra(); // check that Object exists in all that need it
		if (n == 1)
		{
			Object -> IsAutomatic = false;
		}
		else if (n == 2)
		{
			std::string type = cmd_args.ToString(1);
			if (type == "Manual")
			{
				Object -> IsAutomatic = false;
			}
			else if (type == "Automatic")
			{
				Object -> IsAutomatic = true;
			}
			else
			{
				throw TextCommand::Exception::InvalidArgument(cmd_args, 0, "Invalid Type"); // fatal ? or default to Manual ?
			}
		}
		/*else
		{
			throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1 || n == 2");
		}*/
	}
	else
	{
		if (Object == nullptr)
		{
			throw TextCommand::Exception::InvalidState(cmd_args, "missing Object");
		}
	}
}
void PolyHedraParser::Change_Format(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	Clear(); //CommandsClear();
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
	else if (format == "Skin" || format == "S_2025_10_27")
	{
		//if (Object -> Skin != nullptr) { throw TextCommand::Exception::InvalidState(cmd_args, "PolyHedra already has Skin"); }
		//Object -> Skin = new Skin();
		CommandsSkin();
	}
	else
	{
		throw TextCommand::Exception::InvalidArgument(cmd_args, 0);
	}
}

//#include "PolyHedra/Skin/Parsing.hpp"
void PolyHedraParser::New_Skin(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }
	//Debug::Log << cmd << Debug::Done;

	//if (Object -> Skin != nullptr) { throw TextCommand::Exception::InvalidState(cmd_args, "PolyHedra already has Skin"); }

	FileInfo file(File.Directory().File(cmd_args.ToString(0)));
	if (!file.Exists()) { throw TextCommand::Exception::InvalidArgument(cmd_args, 0, "Bad Skin File"); } // this is not InvalidArgument. this is generic error

	PolyHedraParser parser;
	parser.File = file;
	parser.Manager = Manager;
	parser.Object = Object;
	parser.ParseFile();

	//Skin::ParsingData::Load(file, *(Object -> Skin), Object);
}

void PolyHedraParser::Change_Default(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 0 || cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 0 || n == 1"); }

	if (cmd_args.Count() == 0)
	{
		DefaultFlags.MakeDefault();
		return;
	}

	std::string str = cmd_args.ToString(0);
	if (str.size() == 0)
	{
		throw TextCommand::Exception::InvalidArgument(cmd_args, 0, "optional description");
	}

	// loop
	if (!DefaultFlags.Parse(str[0]))
	{
		// not Flag Character
	}
}
void PolyHedraParser::Change_Offset(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	if (cmd_args.ToString(0) == "here")
	{
		VertexOffset = Object -> Flesh.Corners.Count();
	}
	else
	{
		VertexOffset = ToVariable<unsigned int>(cmd_args, 0);
	}
}



void PolyHedraParser::Legacy_Face3(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 3)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 3"); }

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
		Object -> Flesh.Insert_Face3(idx[0], idx[1], idx[2]);
	}
	else
	{
		Object -> Flesh.Insert_Face3(idx[2], idx[1], idx[0]);
	}
}
void PolyHedraParser::Legacy_Face4(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

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
		Object -> Flesh.Insert_Face4(idx[0], idx[1], idx[2], idx[3]);
	}
	else
	{
		Object -> Flesh.Insert_Face4(idx[0], idx[2], idx[1], idx[3]);
	}
}
void PolyHedraParser::Legacy_Face34(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 3 || cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 3 || n == 4"); }

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
			Object -> Flesh.Insert_Face3(idx[0], idx[1], idx[2]);
		}
		else
		{
			Object -> Flesh.Insert_Face3(idx[2], idx[1], idx[0]);
		}
	}
	else if (len == 4)
	{
		if (DefaultFlags.Direction)
		{
			Object -> Flesh.Insert_Face4(idx[0], idx[1], idx[2], idx[3]);
		}
		else
		{
			Object -> Flesh.Insert_Face4(idx[0], idx[2], idx[1], idx[3]);
		}
	}
}
void PolyHedraParser::Legacy_Offset2(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

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



void PolyHedraParser::Place_Vertex(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 3)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 3"); }

	VariableIndexReturn = Object -> Flesh.Corners.Count();
	Object -> Flesh.Insert_Corn(
		ToVariable<float>(cmd_args, 0),
		ToVariable<float>(cmd_args, 1),
		ToVariable<float>(cmd_args, 2)
	);
}
void PolyHedraParser::Place_Circle(const TextCommand::Args & cmd_args, const CommandFlags & flags)
{
	if (!(cmd_args.Count() == 11)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 11"); }

	Angle step = Angle::Section(cmd_args.ToInt32(0));
	int step_num = cmd_args.ToInt32(1);
	int step_off = cmd_args.ToInt32(2);

	VectorF3 center(
		ToVariable<float>(cmd_args, 3),
		ToVariable<float>(cmd_args, 4),
		ToVariable<float>(cmd_args, 5)
	);
	VectorF3 radius(
		ToVariable<float>(cmd_args, 6),
		0,
		0
	);

	VectorF3 normal(
		ToVariable<float>(cmd_args, 7),
		ToVariable<float>(cmd_args, 8),
		ToVariable<float>(cmd_args, 9)
	);

	/*if (flags.Direction)
	{
		normal = -normal;
	}*/

	EulerAngle3D angle = EulerAngle3D::PointToZ(normal);
	Angle offset = Angle::Degrees(ToVariable<float>(cmd_args, 10));

	VariableIndexArrayReturn.NewLength(step_num, 0xFFFFFFFF);
	unsigned int o = Object -> Flesh.Corners.Count();
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
		VariableIndexArrayReturn[i] = o + i;
		Object -> Flesh.Insert_Corn(angle.forward(radius) + center);
	}
}



void PolyHedraParser::Place_Face(const TextCommand::Args & cmd_args, const CommandFlags & flags)
{
	if (!(cmd_args.Count() == 3 || cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 3 || n == 4"); }

	unsigned int len = cmd_args.Count();

	unsigned int idx[len];

	for (unsigned int i = 0; i < len; i++)
	{
		idx[i] = ToVariable<unsigned int>(cmd_args, i);
	}

	if (len == 3)
	{
		if (!flags.Direction)
		{
			Object -> Flesh.Insert_Face3(idx[0], idx[1], idx[2], NormalGroup);
		}
		else
		{
			Object -> Flesh.Insert_Face3(idx[2], idx[1], idx[0], NormalGroup);
		}
	}
	else if (len == 4)
	{
		if (!flags.Direction)
		{
			Object -> Flesh.Insert_Face4(idx[0], idx[1], idx[2], idx[3], NormalGroup);
		}
		else
		{
			Object -> Flesh.Insert_Face4(idx[0], idx[2], idx[1], idx[3], NormalGroup);
		}
	}
}
void PolyHedraParser::Place_Belt(const TextCommand::Args & cmd_args, const CommandFlags & flags)
{
	if (!((cmd_args.Count() % 2) == 0 && cmd_args.Count() >= 4 && cmd_args.Count() <= 255)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "(n % 2) == 0 && n >= 4 && n <= 255"); }

	unsigned int len = cmd_args.Count() / 2;

	unsigned int list0[len];
	unsigned int list1[len];

	for (unsigned int i = 0; i < len; i++)
	{
		unsigned int i0 = i;
		unsigned int i1 = i + len;

		list0[i] = ToVariable<unsigned int>(cmd_args, i0);
		list1[i] = ToVariable<unsigned int>(cmd_args, i1);
	}

	Object -> Flesh.Belt(len, list0, list1, flags.Direction, flags.Closed, NormalGroup);
}
void PolyHedraParser::Place_Band(const TextCommand::Args & cmd_args, const CommandFlags & flags)
{
	throw TextCommand::Exception::NotImplemented(cmd_args);
	(void)cmd_args;
	(void)flags;
}
void PolyHedraParser::Place_Fan(const TextCommand::Args & cmd_args, const CommandFlags & flags)
{
	if (!(cmd_args.Count() >= 3 && cmd_args.Count() <= 255)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n >= 3 && n <= 255"); }

	unsigned int len = cmd_args.Count() - 1;

	unsigned int middle;
	unsigned int blade[len];

	if (!flags.Middle)
	{
		middle = ToVariable<unsigned int>(cmd_args, 0);
		for (unsigned int i = 0; i < len; i++)
		{
			blade[i] = ToVariable<unsigned int>(cmd_args, i + 1);
		}
	}
	else
	{
		for (unsigned int i = 0; i < len; i++)
		{
			blade[i] = ToVariable<unsigned int>(cmd_args, i);
		}
		middle = ToVariable<unsigned int>(cmd_args, len);
	}

	Object -> Flesh.Fan(len, middle, blade, flags.Direction, flags.Middle, flags.Closed, NormalGroup);
}

void PolyHedraParser::Place_IndexArray_Belt(const TextCommand::Args & cmd_args, const CommandFlags & flags)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	Container::Array<unsigned int> list0;
	Container::Array<unsigned int> list1;

	Variables.Get(cmd_args.ToString(0), list0);
	Variables.Get(cmd_args.ToString(1), list1);

	if (list0.IsNull()) { throw TextCommand::Exception::InvalidArgument(cmd_args, 0, "Index Array Variable is Empty"); }
	if (list1.IsNull()) { throw TextCommand::Exception::InvalidArgument(cmd_args, 1, "Index Array Variable is Empty"); }

	if (list0.Length() != list1.Length()) { throw TextCommand::Exception::InvalidState(cmd_args, "Index Variables have different length"); }
	unsigned int len = list0.Length();

	Object -> Flesh.Belt(len, list0.Memory(), list1.Memory(), flags.Direction, flags.Closed, NormalGroup);
}
void PolyHedraParser::Place_IndexArray_Band(const TextCommand::Args & cmd_args, const CommandFlags & flags)
{
	throw TextCommand::Exception::NotImplemented(cmd_args);
	(void)cmd_args;
	(void)flags;
}
void PolyHedraParser::Place_IndexArray_Fan(const TextCommand::Args & cmd_args, const CommandFlags & flags)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	unsigned int middle;
	Container::Array<unsigned int> blade;

	if (!flags.Middle)
	{
		Variables.Get(cmd_args.ToString(0), middle);
		Variables.Get(cmd_args.ToString(1), blade);
	}
	else
	{
		Variables.Get(cmd_args.ToString(0), blade);
		Variables.Get(cmd_args.ToString(1), middle);
	}

	if (blade.IsNull()) { throw TextCommand::Exception::InvalidArgument(cmd_args, 1, "Index Array Variable is Empty"); }

	unsigned int len = blade.Length();

	Object -> Flesh.Fan(len, middle, blade.Memory(), flags.Direction, flags.Middle, flags.Closed, NormalGroup);
}



void PolyHedraParser::Normal_Change(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 0 || cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 0 || n == 1"); }

	if (cmd_args.Count() == 0)
	{
		NormalGroup = 0xFFFFFFFF;
	}
	else
	{
		NormalGroup = cmd_args.ToUInt32(0);
	}
}

// Parameters should check Type
void PolyHedraParser::Parameter_Check(const TextCommand::Args & cmd_args)
{
	unsigned int n = cmd_args.Count();
	if (!(n == 1 || n == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1 || n == 2"); }

	std::string name = cmd_args.ToString(0);

	if (n == 1)
	{
		if (Parser == nullptr)
		{
			throw TextCommand::Exception::InvalidState(cmd_args, "Missing Parser for Parameters"); // fatal
		}
		const VariableEntryType<float> * var = dynamic_cast<const VariableEntryType<float> *>(Parser -> Variables.Find(name));
		if (var == nullptr)
		{
			throw TextCommand::Exception::InvalidState(cmd_args, "Missing Parameter"); // fatal
		}
		Variables.Set(var -> Name, var -> Data);
	}
	else if (n == 2)
	{
		const VariableEntryType<float> * var = dynamic_cast<const VariableEntryType<float> *>(Parser -> Variables.Find(name));
		if (var != nullptr)
		{
			Variables.Set(var -> Name, var -> Data);
		}
		else
		{
			Variables.Set(name, cmd_args.ToFloat(1));
		}
	}
}
void PolyHedraParser::Parameter_File(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	FileInfo file = File.Directory().File(cmd_args.ToString(0).c_str());
	if (!file.Exists()) { throw TextCommand::Exception::InvalidArgument(cmd_args, 0, "Bad PolyHedra File"); } // this is not InvalidArgument. this is generic error

	PolyHedraParser parser;
	parser.File = file;
	parser.Parser = this;
	parser.Object = Object;
	//	std::cout << "Loading PolyHedra File " << '"' << file.Path << '"' << " ..." << '\n';
	parser.ParseFile();
	//	std::cout << "Loading PolyHedra File " << '"' << file.Path << '"' << " done" << '\n';
	parser.Done();
}

void PolyHedraParser::PolyHedra_Combine(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	Object -> Combine(*ToVariable<PolyHedra*>(cmd_args, 0), ToVariable<Trans3D>(cmd_args, 1));
}
/*void PolyHedraParser::PolyHedra_Put(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }
	if (Manager == nullptr) { throw TextCommand::Exception::InvalidState(cmd_args, "Manager missing for Other"); }

	PolyHedra::PolyHedraOther polyhedra_other;
	polyhedra_other.Object = ToVariable<PolyHedra*>(cmd_args, 0);
	polyhedra_other.Trans = ToVariable<Trans3D>(cmd_args, 1);
	Object -> Others.Insert(polyhedra_other);
}*/



void PolyHedraParser::CommandsSkin()
{
	//Commands.Insert(new TextCommand::FuncNormal("Name",	this, &PolyHedraParser::Skin_Parse_Name));
	Commands.Insert(new TextCommand::FuncNormal("Size",	this, &PolyHedraParser::Skin_Parse_Size));
	Commands.Insert(new TextCommand::FuncNormal("Img",	this, &PolyHedraParser::Skin_Parse_Image));

	Commands.Insert(new TextCommand::FuncNormal("t",		this, &PolyHedraParser::Skin_Parse_t));
	Commands.Insert(new TextCommand::FuncNormal("TexI",		this, &PolyHedraParser::Skin_Parse_TextureIndex));
	Commands.Insert(new TextCommand::FuncNormal("TexI4",	this, &PolyHedraParser::Skin_Parse_TextureIndexFace4));
	Commands.Insert(new TextCommand::FuncNormal("TexIQ",	this, &PolyHedraParser::Skin_Parse_TextureIndexQuad));

	Commands.Insert(new TextCommand::FuncNormal("vertex",	this, &PolyHedraParser::Skin_Parse_Vertex));
	Commands.Insert(new TextCommand::FuncNormal("vIndex",	this, &PolyHedraParser::Skin_Parse_VertexIndex));
	//Commands.Insert(new TextCommand::FuncNormal("vFace<",	this, &PolyHedraParser::Skin_Parse_VertexFace3, false));
	//Commands.Insert(new TextCommand::FuncNormal("VFace>",	this, &PolyHedraParser::Skin_Parse_VertexFace3, true));
	Commands.Insert(new TextCommand::FuncNormal("vFace<",	this, &PolyHedraParser::Skin_Parse_VertexFace3_F));
	Commands.Insert(new TextCommand::FuncNormal("VFace>",	this, &PolyHedraParser::Skin_Parse_VertexFace3_T));

	//Commands.Insert(new TextCommand::FuncNormal("belt{0",	this, &PolyHedraParser::Skin_Parse_VertexBelt, false, false);)
	//Commands.Insert(new TextCommand::FuncNormal("belt}0",	this, &PolyHedraParser::Skin_Parse_VertexBelt, true, false);)
	//Commands.Insert(new TextCommand::FuncNormal("belt{1",	this, &PolyHedraParser::Skin_Parse_VertexBelt, false, true);)
	//Commands.Insert(new TextCommand::FuncNormal("belt}1",	this, &PolyHedraParser::Skin_Parse_VertexBelt, true, true);)
	Commands.Insert(new TextCommand::FuncNormal("belt{0",	this, &PolyHedraParser::Skin_Parse_VertexBelt_FF));
	Commands.Insert(new TextCommand::FuncNormal("belt}0",	this, &PolyHedraParser::Skin_Parse_VertexBelt_TF));
	Commands.Insert(new TextCommand::FuncNormal("belt{1",	this, &PolyHedraParser::Skin_Parse_VertexBelt_FT));
	Commands.Insert(new TextCommand::FuncNormal("belt}1",	this, &PolyHedraParser::Skin_Parse_VertexBelt_TT));

	//Commands.Insert(new TextCommand::FuncNormal("band{0",	this, &PolyHedraParser::Skin_Parse_VertexBand, false, false));
	//Commands.Insert(new TextCommand::FuncNormal("band}0",	this, &PolyHedraParser::Skin_Parse_VertexBand, true, false));
	//Commands.Insert(new TextCommand::FuncNormal("band{1",	this, &PolyHedraParser::Skin_Parse_VertexBand, false, true));
	//Commands.Insert(new TextCommand::FuncNormal("band}1",	this, &PolyHedraParser::Skin_Parse_VertexBand, true, true));
	Commands.Insert(new TextCommand::FuncNormal("band{0",	this, &PolyHedraParser::Skin_Parse_VertexBand_FF));
	Commands.Insert(new TextCommand::FuncNormal("band}0",	this, &PolyHedraParser::Skin_Parse_VertexBand_TF));
	Commands.Insert(new TextCommand::FuncNormal("band{1",	this, &PolyHedraParser::Skin_Parse_VertexBand_FT));
	Commands.Insert(new TextCommand::FuncNormal("band}1",	this, &PolyHedraParser::Skin_Parse_VertexBand_TT));

	//Commands.Insert(new TextCommand::FuncNormal("fan<{0",	this, &PolyHedraParser::Skin_Parse_VertexFan, false, false, false));
	//Commands.Insert(new TextCommand::FuncNormal("fan<}0",	this, &PolyHedraParser::Skin_Parse_VertexFan, true, false, false));
	//Commands.Insert(new TextCommand::FuncNormal("fan<{1",	this, &PolyHedraParser::Skin_Parse_VertexFan, false, true, false));
	//Commands.Insert(new TextCommand::FuncNormal("fan<}1",	this, &PolyHedraParser::Skin_Parse_VertexFan, true, true, false));
	//Commands.Insert(new TextCommand::FuncNormal("fan>{0",	this, &PolyHedraParser::Skin_Parse_VertexFan, false, false, true));
	//Commands.Insert(new TextCommand::FuncNormal("fan>}0",	this, &PolyHedraParser::Skin_Parse_VertexFan, true, false, true));
	//Commands.Insert(new TextCommand::FuncNormal("fan>{1",	this, &PolyHedraParser::Skin_Parse_VertexFan, false, true, true));
	//Commands.Insert(new TextCommand::FuncNormal("fan>}1",	this, &PolyHedraParser::Skin_Parse_VertexFan, true, true, true));
	Commands.Insert(new TextCommand::FuncNormal("fan<{0",	this, &PolyHedraParser::Skin_Parse_VertexFan_FFF));
	Commands.Insert(new TextCommand::FuncNormal("fan<}0",	this, &PolyHedraParser::Skin_Parse_VertexFan_TFF));
	Commands.Insert(new TextCommand::FuncNormal("fan<{1",	this, &PolyHedraParser::Skin_Parse_VertexFan_FTF));
	Commands.Insert(new TextCommand::FuncNormal("fan<}1",	this, &PolyHedraParser::Skin_Parse_VertexFan_TTF));
	Commands.Insert(new TextCommand::FuncNormal("fan>{0",	this, &PolyHedraParser::Skin_Parse_VertexFan_FFT));
	Commands.Insert(new TextCommand::FuncNormal("fan>}0",	this, &PolyHedraParser::Skin_Parse_VertexFan_TFT));
	Commands.Insert(new TextCommand::FuncNormal("fan>{1",	this, &PolyHedraParser::Skin_Parse_VertexFan_FTT));
	Commands.Insert(new TextCommand::FuncNormal("fan>}1",	this, &PolyHedraParser::Skin_Parse_VertexFan_TTT));

	//Commands.Insert(new TextCommand::FuncNormal("rayT",		this, &PolyHedraParser::Skin_Parse_VertexRay, false));
	//Commands.Insert(new TextCommand::FuncNormal("rayA",		this, &PolyHedraParser::Skin_Parse_VertexRay, true));
	Commands.Insert(new TextCommand::FuncNormal("rayT",			this, &PolyHedraParser::Skin_Parse_VertexRay_F));
	Commands.Insert(new TextCommand::FuncNormal("rayA",			this, &PolyHedraParser::Skin_Parse_VertexRay_T));

	Commands.Insert(new TextCommand::FuncNormal("colFdefault",	this, &PolyHedraParser::Skin_Parse_ColorF_Default));
	Commands.Insert(new TextCommand::FuncNormal("colF",			this, &PolyHedraParser::Skin_Parse_ColorF));

	Commands.Insert(new TextCommand::FuncNormal("colDdefault",	this, &PolyHedraParser::Skin_Parse_ColorD_Default));
	Commands.Insert(new TextCommand::FuncNormal("colD",			this, &PolyHedraParser::Skin_Parse_ColorD));

	Commands.Insert(new TextCommand::FuncNormal("multi",		this, &PolyHedraParser::Skin_Parse_Multi));

	Commands.Insert(new TextCommand::FuncNormal("axisAlign",	this, &PolyHedraParser::Skin_Parse_AxisAlign));
}

unsigned int PolyHedraParser::ToTextureVertexIndex(const TextCommand::Args & cmd_args, unsigned int arg_idx) const
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

void PolyHedraParser::Skin_Parse_Type(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }
	if (cmd_args.ToString(0) == "Skin")
	{
		return;
	}
	throw TextCommand::Exception::InvalidArgument(cmd_args, 0);
}
void PolyHedraParser::Skin_Parse_Format(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	if (cmd_args.ToString(0) != "S_2025_10_27") { throw TextCommand::Exception::InvalidArgument(cmd_args, 0); }
}

/*void PolyHedraParser::Skin_Parse_Name(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	Object -> Skin.Name = cmd_args.ToString(0);
}*/
void PolyHedraParser::Skin_Parse_Size(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	Object -> Skin.Size.X = cmd_args.ToUInt32(0);
	Object -> Skin.Size.Y = cmd_args.ToUInt32(1);
}
void PolyHedraParser::Skin_Parse_Image(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	FileInfo file(File.Directory().File(cmd_args.ToString(0)));
	Object -> Skin.Images.Insert(file.LoadImage());
}

void PolyHedraParser::Skin_Parse_t(const TextCommand::Args & cmd_args)
{
	if (!((cmd_args.Count() % 2) == 0)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "(n % 2) == 0"); }

	unsigned int len = cmd_args.Count() / 2;

	PolyHedraSkin::Corner t[len];
	unsigned int idx = Object -> Skin.Corners.Count();

	for (size_t i = 0; i < len; i++)
	{
		t[i].Coord.X = cmd_args.ToFloat(i * 2 + 0);
		t[i].Coord.Y = cmd_args.ToFloat(i * 2 + 1);
		t[i].Index = TextureIndex;
		Object -> Skin.Corners.Insert(t[i]);
	}

	if (len == 3)
	{
		//Skin.Insert_Face3(t[0], t[1], t[2]);
		Object -> Skin.Insert_Face3(idx + 0, idx + 1, idx + 2);
	}
	else if (len == 4)
	{
		//Skin.Insert_Face4(t[0], t[1], t[2], t[3]);
		Object -> Skin.Insert_Face4(idx + 0, idx + 1, idx + 2, idx + 3);
	}
}

void PolyHedraParser::Skin_Parse_TextureIndex(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }
	TextureIndex = cmd_args.ToUInt32(0);
}
void PolyHedraParser::Skin_Parse_TextureIndexFace4(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 8)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 8"); }

	PolyHedraSkin::Corner t[4];
	unsigned int idx = Object -> Skin.Corners.Count();

	for (unsigned int i = 0; i < 4; i++)
	{
		t[i].Coord.X = cmd_args.ToFloat(i * 2 + 0);
		t[i].Coord.Y = cmd_args.ToFloat(i * 2 + 1);
		t[i].Index = TextureIndex;
		Object -> Skin.Corners.Insert(t[i]);
	}

	Object -> Skin.Insert_Face4(idx + 0, idx + 1, idx + 2, idx + 3);
}
void PolyHedraParser::Skin_Parse_TextureIndexQuad(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	VectorF2	min;
	min.X = cmd_args.ToFloat(0);
	min.Y = cmd_args.ToFloat(1);

	VectorF2	max;
	max.X = cmd_args.ToFloat(2);
	max.Y = cmd_args.ToFloat(3);

	PolyHedraSkin::Corner t[4];
	unsigned int idx = Object -> Skin.Corners.Count();

	t[0].Coord.X = min.X;
	t[0].Coord.Y = min.Y;
	t[0].Index = TextureIndex;
	Object -> Skin.Corners.Insert(t[0]);

	t[1].Coord.X = min.X;
	t[1].Coord.Y = max.Y;
	t[1].Index = TextureIndex;
	Object -> Skin.Corners.Insert(t[1]);

	t[2].Coord.X = max.X;
	t[2].Coord.Y = min.Y;
	t[2].Index = TextureIndex;
	Object -> Skin.Corners.Insert(t[2]);

	t[3].Coord.X = max.X;
	t[3].Coord.Y = max.Y;
	t[3].Index = TextureIndex;
	Object -> Skin.Corners.Insert(t[3]);

	Object -> Skin.Insert_Face4(idx + 0, idx + 1, idx + 2, idx + 3);
}

void PolyHedraParser::Skin_Parse_Vertex(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	VectorF2 v;
	v.X = cmd_args.ToFloat(0);
	v.Y = cmd_args.ToFloat(1);

	Object -> Skin.Corners.Insert(PolyHedraSkin::Corner(v, TextureIndex));
}
void PolyHedraParser::Skin_Parse_VertexIndex(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 1)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 1"); }

	std::string str = cmd_args.ToString(0);
	if (str == "here")
	{
		TextureVertexIndex = Object -> Skin.Corners.Count();
	}
	else
	{
		TextureVertexIndex = ToTextureVertexIndex(cmd_args, 0);
	}
}

void PolyHedraParser::Skin_Parse_VertexFace3_F(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFace3(cmd_args, false); }
void PolyHedraParser::Skin_Parse_VertexFace3_T(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFace3(cmd_args, true); }
void PolyHedraParser::Skin_Parse_VertexFace3(const TextCommand::Args & cmd_args, bool f_direction)
{
	if (!(cmd_args.Count() == 3)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 3"); }

	unsigned int t[3];
	for (unsigned int i = 0; i < 3; i++)
	{
		t[i] = ToTextureVertexIndex(cmd_args, i);
	}

	if (!f_direction)
	{
		Object -> Skin.Insert_Face3(t[0], t[1], t[2]);
	}
	else
	{
		Object -> Skin.Insert_Face3(t[2], t[1], t[0]);
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
void PolyHedraParser::Skin_Parse_VertexBelt_FF(const TextCommand::Args & cmd_args) { Skin_Parse_VertexBelt(cmd_args, false, false); }
void PolyHedraParser::Skin_Parse_VertexBelt_TF(const TextCommand::Args & cmd_args) { Skin_Parse_VertexBelt(cmd_args, true, false); }
void PolyHedraParser::Skin_Parse_VertexBelt_FT(const TextCommand::Args & cmd_args) { Skin_Parse_VertexBelt(cmd_args, false, true); }
void PolyHedraParser::Skin_Parse_VertexBelt_TT(const TextCommand::Args & cmd_args) { Skin_Parse_VertexBelt(cmd_args, true, true); }
void PolyHedraParser::Skin_Parse_VertexBelt(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure)
{
	if (!((cmd_args.Count() % 2) == 0 && cmd_args.Count() >= 4 && cmd_args.Count() <= 255)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "(n % 2) == 0 && n >= 4 && n <= 255"); }

	unsigned int len = cmd_args.Count() / 2;

	unsigned int list0[len];
	unsigned int list1[len];

	for (unsigned int i = 0; i < len; i++)
	{
		unsigned int i0 = i;
		unsigned int i1 = i + len;

		list0[i] = ToTextureVertexIndex(cmd_args, i0);
		list1[i] = ToTextureVertexIndex(cmd_args, i1);
	}

	Object -> Skin.Belt(len, list0, list1, f_direction, f_closure);

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

void PolyHedraParser::Skin_Parse_VertexBand_FF(const TextCommand::Args & cmd_args) { Skin_Parse_VertexBand(cmd_args, false, false); }
void PolyHedraParser::Skin_Parse_VertexBand_TF(const TextCommand::Args & cmd_args) { Skin_Parse_VertexBand(cmd_args, true, false); }
void PolyHedraParser::Skin_Parse_VertexBand_FT(const TextCommand::Args & cmd_args) { Skin_Parse_VertexBand(cmd_args, false, true); }
void PolyHedraParser::Skin_Parse_VertexBand_TT(const TextCommand::Args & cmd_args) { Skin_Parse_VertexBand(cmd_args, true, true); }
void PolyHedraParser::Skin_Parse_VertexBand(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure)
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
void PolyHedraParser::Skin_Parse_VertexFan_FFF(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFan(cmd_args, false, false, false); }
void PolyHedraParser::Skin_Parse_VertexFan_TFF(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFan(cmd_args, true, false, false); }
void PolyHedraParser::Skin_Parse_VertexFan_FTF(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFan(cmd_args, false, true, false); }
void PolyHedraParser::Skin_Parse_VertexFan_TTF(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFan(cmd_args, true, true, false); }
void PolyHedraParser::Skin_Parse_VertexFan_FFT(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFan(cmd_args, false, false, true); }
void PolyHedraParser::Skin_Parse_VertexFan_TFT(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFan(cmd_args, true, false, true); }
void PolyHedraParser::Skin_Parse_VertexFan_FTT(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFan(cmd_args, false, true, true); }
void PolyHedraParser::Skin_Parse_VertexFan_TTT(const TextCommand::Args & cmd_args) { Skin_Parse_VertexFan(cmd_args, true, true, true); }
void PolyHedraParser::Skin_Parse_VertexFan(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure, bool f_middle)
{
	if (!(cmd_args.Count() >= 3 && cmd_args.Count() <= 255)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n >= 3 && n <= 255"); }

	unsigned int len = cmd_args.Count() - 1;

	unsigned int middle;
	unsigned int blade[len];

	if (!f_middle)
	{
		middle = ToTextureVertexIndex(cmd_args, 0);
		for (unsigned int i = 0; i < len; i++)
		{
			blade[i] = ToTextureVertexIndex(cmd_args, i + 1);
		}
	}
	else
	{
		for (unsigned int i = 0; i < len; i++)
		{
			blade[i] = ToTextureVertexIndex(cmd_args, i);
		}
		middle = ToTextureVertexIndex(cmd_args, len);
	}

	Object -> Skin.Fan(len, middle, blade, f_direction, f_middle, f_closure);

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

#include "ValueType/Ray/F2.hpp"
void PolyHedraParser::Skin_Parse_VertexRay_F(const TextCommand::Args & cmd_args) { Skin_Parse_VertexRay(cmd_args, false); }
void PolyHedraParser::Skin_Parse_VertexRay_T(const TextCommand::Args & cmd_args) { Skin_Parse_VertexRay(cmd_args, true); }
void PolyHedraParser::Skin_Parse_VertexRay(const TextCommand::Args & cmd_args, bool f_accumulate)
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
		Object -> Skin.Corners.Insert(PolyHedraSkin::Corner(ray.ToPoint(intervals[i]), TextureIndex));
	}
}

void PolyHedraParser::Skin_Parse_ColorF_Default(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	ColorF4 col;
	col.R = cmd_args.ToFloat(0);
	col.G = cmd_args.ToFloat(1);
	col.B = cmd_args.ToFloat(2);
	col.A = cmd_args.ToFloat(3);

	Object -> Skin.Color = col;
}
void PolyHedraParser::Skin_Parse_ColorF(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	ColorF4 col;
	col.R = cmd_args.ToFloat(0);
	col.G = cmd_args.ToFloat(1);
	col.B = cmd_args.ToFloat(2);
	col.A = cmd_args.ToFloat(3);

	Object -> Skin.Corners.Insert(PolyHedraSkin::Corner(col));
}

#include "ValueType/Color/U4.hpp"
void PolyHedraParser::Skin_Parse_ColorD_Default(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	ColorU4 col;
	col.R = cmd_args.ToUInt32(0);
	col.G = cmd_args.ToUInt32(1);
	col.B = cmd_args.ToUInt32(2);
	col.A = cmd_args.ToUInt32(3);

	Object -> Skin.Color = col.ToColorF4();
}
void PolyHedraParser::Skin_Parse_ColorD(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 4)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 4"); }

	ColorU4 col;
	col.R = cmd_args.ToUInt32(0);
	col.G = cmd_args.ToUInt32(1);
	col.B = cmd_args.ToUInt32(2);
	col.A = cmd_args.ToUInt32(3);

	Object -> Skin.Corners.Insert(PolyHedraSkin::Corner(col.ToColorF4()));
}

/* this is a terrible name
*/
void PolyHedraParser::Skin_Parse_Multi(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 2)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 2"); }

	unsigned int idx = ToTextureVertexIndex(cmd_args, 0);
	unsigned int n = cmd_args.ToUInt32(1);
	for (unsigned int i = 0; i < n; i++)
	{
		Object -> Skin.Faces.Insert(PolyHedraSkin::Face(idx, idx, idx));
	}
}

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
void PolyHedraParser::Skin_Parse_AxisAlign(const TextCommand::Args & cmd_args)
{
	if (!(cmd_args.Count() == 12)) { throw TextCommand::Exception::InvalidArgumentCount(cmd_args, "n == 12"); }

	if (Object == nullptr) { throw TextCommand::Exception::InvalidState(cmd_args, "Missing PolyHedra"); }

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
		unsigned int corners_index = Object -> Skin.Corners.Count();
		unsigned int face_index = Object -> Skin.Faces.Count();

		const PolyHedraFlesh::Face & face = Object -> Flesh.Faces[face_index];
		const PolyHedraFlesh::Corner & corner0 = Object -> Flesh.Corners[face.idx[0]];
		const PolyHedraFlesh::Corner & corner1 = Object -> Flesh.Corners[face.idx[1]];
		const PolyHedraFlesh::Corner & corner2 = Object -> Flesh.Corners[face.idx[2]];

		VectorF2 vec;

		vec.X = axis0.dot(corner0.Position) / scale0;
		vec.Y = axis1.dot(corner0.Position) / scale1;
		Object -> Skin.Insert_Corn(vec, TextureIndex);

		vec.X = axis0.dot(corner1.Position) / scale0;
		vec.Y = axis1.dot(corner1.Position) / scale1;
		Object -> Skin.Insert_Corn(vec, TextureIndex);

		vec.X = axis0.dot(corner2.Position) / scale0;
		vec.Y = axis1.dot(corner2.Position) / scale1;
		Object -> Skin.Insert_Corn(vec, TextureIndex);

		Object -> Skin.Insert_Face3(corners_index + 0, corners_index + 1, corners_index + 2);
	}
}



void PolyHedraParser::Done()
{
	if (Parser == nullptr)
	{
		if (Object != nullptr)
		{
			Object -> Flesh.TrimData();
			Object -> Skin.TrimData();
		}
	}
}



PolyHedra * PolyHedraParser::Load(const FileInfo & file, PolyHedraManager * manager)
{
	PolyHedraParser parser;
	parser.File = file;
	parser.Manager = manager;
//	std::cout << "Loading PolyHedra File " << '"' << file.Path << '"' << " ..." << '\n';
	parser.ParseFile();
//	std::cout << "Loading PolyHedra File " << '"' << file.Path << '"' << " done" << '\n';
	parser.Done();
	return parser.Object;
}
