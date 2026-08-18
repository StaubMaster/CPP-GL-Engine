#ifndef  POLYHEDRA_PARSING_HPP
# define POLYHEDRA_PARSING_HPP

# include "FileInfo.hpp"
# include "FileParsing/Variables/Float.hpp"

# include "PolyHedra/PolyHedra.hpp"
//# include "FileParsing/ParsingCommand.hpp"
//# include "FileParsing/Text/TextCommand.hpp"
# include "FileParsing/Text/TextCommandFunc.hpp"

# include "Generics/Container/Binary.hpp"
# include "Generics/Function/Pointer.hpp"
# include "Generics/Function/Object.hpp"

# include <string>
//# include <exception>

class TextCommandArgs;
//typedef TextCommand TextCommandArgs;

/*struct TextCommandFunc
{
	std::string		Name;
	FunctionPointer<const TextCommandArgs &>	Func;



	~TextCommandFunc()
	{ }
	TextCommandFunc(std::string name)
		: Name(name)
		, Func()
	{ }

	template<typename ObjectType> TextCommandFunc(
		std::string name,
		ObjectType * obj,
		void (ObjectType::*func)(const TextCommandArgs &)
	)
		: Name(name)
		, Func(obj, func)
	{ }
};*/

struct PolyHedra::ParsingData
{
	FileInfo		File;
	::PolyHedra &	PolyHedra;

	unsigned int	VertexOffset;
	unsigned int	ToVertexIndex(const TextCommandArgs & cmd_args, unsigned int arg_idx) const;

	struct CommandFlags
	{
		bool	Direction = false;
		bool	Closed = true;
		bool	Middle = false;
		void	MakeDefault();

		~CommandFlags() = default;
		CommandFlags() = default;
		CommandFlags(const CommandFlags & other) = default;
		CommandFlags & operator=(const CommandFlags & other) = default;

		bool			Parse(char c);
		unsigned int	Parse(const std::string & name);
	};
	CommandFlags	DefaultFlags;
	// each Command takes different Flags

	ParsingVariable::FloatMemory	VariableFloats;

	Container::Binary<TextCommandFunc*>		Commands;
	void	CommandsClear();
	void	CommandsDefault();
	void	CommandsNormal();
	void	CommandsLegacy();

	~ParsingData();
	ParsingData(const FileInfo & file, ::PolyHedra & polyhedra);



	void	Parse(const TextCommandArgs & cmd_args);

	void	Check_Type(const TextCommandArgs & cmd_args);
	void	Change_Format(const TextCommandArgs & cmd_args);

	void	Change_Name(const TextCommandArgs & cmd_args);
	void	New_Skin(const TextCommandArgs & cmd_args);

	void	Change_Default(const TextCommandArgs & cmd_args);
	void	Change_Offset(const TextCommandArgs & cmd_args);

	void	Legacy_Face3(const TextCommandArgs & cmd_args);
	void	Legacy_Face4(const TextCommandArgs & cmd_args);
	void	Legacy_Face34(const TextCommandArgs & cmd_args);
	void	Legacy_Offset2(const TextCommandArgs & cmd_args);
 
	void	Place_Vertex(const TextCommandArgs & cmd_args);

	void	Place_Circle(const TextCommandArgs & cmd_args, const CommandFlags & flags);
	void	Place_Circle(const TextCommandArgs & cmd_args);

	void	Place_Face(const TextCommandArgs & cmd_args, const CommandFlags & flags);
	void	Place_Face(const TextCommandArgs & cmd_args);

	void	Place_Belt_Face(const CommandFlags & flags, unsigned int temp[4]);
	void	Place_Belt(const TextCommandArgs & cmd_args, const CommandFlags & flags);
	void	Place_Belt(const TextCommandArgs & cmd_args);

	void	Place_Band(const TextCommandArgs & cmd_args, const CommandFlags & flags);
	void	Place_Band(const TextCommandArgs & cmd_args);

	void	Place_Fan_Face(const CommandFlags & flags, unsigned int middle, unsigned int blade[2]);
	void	Place_Fan(const TextCommandArgs & cmd_args, const CommandFlags & flags);
	void	Place_Fan(const TextCommandArgs & cmd_args);
};

#endif
