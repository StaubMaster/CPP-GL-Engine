#ifndef  POLYHEDRA_PARSING_HPP
# define POLYHEDRA_PARSING_HPP

# include "PolyHedra/PolyHedra.hpp"

# include "FileInfo.hpp"
# include "FileParsing/Variables/Float.hpp"

# include "FileParsing/Text/TextCommandFunc.hpp"

# include "Generics/Container/Binary.hpp"
# include "Generics/Function/Pointer.hpp"
# include "Generics/Function/Object.hpp"

# include "ValueType/Trans/3D.hpp"

# include <string>

class TextCommandArgs;

struct PolyHedra::ParsingData
{
	FileInfo				File;
	PolyHedra &				Object;
	const ParsingData *		Parent = nullptr;

	Trans3D					Trans;
	const PolyHedra *		Other = nullptr;

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
	ParsingData(const FileInfo & file, PolyHedra & object);



	void	Parse(const TextCommandArgs & cmd_args);

	void	Check_Type(const TextCommandArgs & cmd_args);
	void	Change_Format(const TextCommandArgs & cmd_args);

	void	Check_Parameter(const TextCommandArgs & cmd_args);

//	void	Change_Name(const TextCommandArgs & cmd_args);
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

	void	Place_Belt(const TextCommandArgs & cmd_args, const CommandFlags & flags);
	void	Place_Belt(const TextCommandArgs & cmd_args);

	void	Place_Band(const TextCommandArgs & cmd_args, const CommandFlags & flags);
	void	Place_Band(const TextCommandArgs & cmd_args);

	void	Place_Fan(const TextCommandArgs & cmd_args, const CommandFlags & flags);
	void	Place_Fan(const TextCommandArgs & cmd_args);

	void	Trans_Zero(const TextCommandArgs & cmd_args);
	void	Trans_ChangePos(const TextCommandArgs & cmd_args);
	void	Trans_ChangeRot(const TextCommandArgs & cmd_args);

	void	Other_File(const TextCommandArgs & cmd_args);
	void	Other_Static(const TextCommandArgs & cmd_args);

	public:
	static PolyHedra * Load(const FileInfo & file, const ParsingData * parent);
};

#endif
