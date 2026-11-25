#ifndef  POLYHEDRA_PARSING_HPP
# define POLYHEDRA_PARSING_HPP

# include "PolyHedra/PolyHedra.hpp"

# include "FileInfo.hpp"
# include "FileParsing/Variables/Memory.hpp"

# include "FileParsing/TextCommand/Func.hpp"
# include "FileParsing/TextCommand/Loop.hpp"
namespace TextCommand { class Args; };

# include "Generics/Container/Binary.hpp"
# include "Generics/Function/Pointer.hpp"
# include "Generics/Function/Object.hpp"

# include "ValueType/Trans/3D.hpp"

# include <string>

# include "TextExceptionBase.hpp"

class PolyHedraManager;

struct PolyHedraParser : public TextCommand::Loop
{
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

	struct CommandFlagsFunc : public TextCommand::Func
	{
		Function::Pointer<const TextCommand::Args &, const CommandFlags &>		Function;

		~CommandFlagsFunc();
		template<typename ObjectType> CommandFlagsFunc(
			std::string name,
			ObjectType * obj,
			void (ObjectType::*func)(const TextCommand::Args &, const CommandFlags &)
		)
			: Func(name)
			, Function(obj, func)
		{ }
	
		bool	TryInvoke(const TextCommand::Args & cmd_args) const override;
	};
	/* Flag Combinations
		1 Flags: 6
			< >
			{ }
			0 1
		2 Flags: 12
			<{ >{
			<} >}
			<0 >0
			<1 >1
			{0 }0
			{1 }1
		3 Flags: 8
			<{0 >{0
			<}0 >}0
			<{1 >{1
			<}1 >}1
		Total Flags: 26
	*/
	// each Command takes different Flags

	void	CommandsDefault();
	void	CommandsLegacy();
	void	CommandsNormal();
	//		CommandsParameter();



	VariableMemory		Variables;

	// store these in a variable called "return" ?
	unsigned int					VariableIndexReturn;
	Container::Array<unsigned int>	VariableIndexArrayReturn;

	void	Change_Variable(const TextCommand::Args & cmd_args);

	unsigned int	VertexOffset = 0;
	template<typename Type> void	ToVariable(const TextCommand::Args & cmd_args, unsigned int idx, Type & data) const;
	template<typename Type> Type	ToVariable(const TextCommand::Args & cmd_args, unsigned int idx) const
	{
		Type data;
		ToVariable(cmd_args, idx, data);
		return data;
	}



	PolyHedra *					Object = nullptr;
	const PolyHedraParser *		Parser = nullptr; // only need Variables
	PolyHedraManager *			Manager = nullptr;



	~PolyHedraParser();
	PolyHedraParser();



	void	Check_Type(const TextCommand::Args & cmd_args);
	void	Change_Format(const TextCommand::Args & cmd_args);

	void	New_Skin(const TextCommand::Args & cmd_args);

	void	Change_Default(const TextCommand::Args & cmd_args);
	void	Change_Offset(const TextCommand::Args & cmd_args);

	void	Legacy_Face3(const TextCommand::Args & cmd_args);
	void	Legacy_Face4(const TextCommand::Args & cmd_args);
	void	Legacy_Face34(const TextCommand::Args & cmd_args);
	void	Legacy_Offset2(const TextCommand::Args & cmd_args);

	void	Place_Vertex(const TextCommand::Args & cmd_args);
	void	Place_Circle(const TextCommand::Args & cmd_args, const CommandFlags & flags);

	void	Place_Face(const TextCommand::Args & cmd_args, const CommandFlags & flags);
	void	Place_Belt(const TextCommand::Args & cmd_args, const CommandFlags & flags);
	void	Place_Band(const TextCommand::Args & cmd_args, const CommandFlags & flags);
	void	Place_Fan(const TextCommand::Args & cmd_args, const CommandFlags & flags);

	//void	Place_IndexArray_Face(const TextCommand::Args & cmd_args, const CommandFlags & flags);
	void	Place_IndexArray_Belt(const TextCommand::Args & cmd_args, const CommandFlags & flags);
	void	Place_IndexArray_Band(const TextCommand::Args & cmd_args, const CommandFlags & flags);
	void	Place_IndexArray_Fan(const TextCommand::Args & cmd_args, const CommandFlags & flags);

	unsigned int	NormalGroup = 0xFFFFFFFF;
	void	Normal_Change(const TextCommand::Args & cmd_args);

	// Parameters should check Type
	void	Parameter_Check(const TextCommand::Args & cmd_args);
	void	Parameter_File(const TextCommand::Args & cmd_args);

	void	PolyHedra_Combine(const TextCommand::Args & cmd_args);
	void	PolyHedra_Put(const TextCommand::Args & cmd_args);

	void	Done();

	static PolyHedra *	Load(const FileInfo & file, PolyHedraManager * manager);
};

#endif
