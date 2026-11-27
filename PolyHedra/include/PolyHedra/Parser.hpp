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
	// Format: Verbose		full function name

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
	//void	PolyHedra_Put(const TextCommand::Args & cmd_args);



	void	CommandsSkin();

	unsigned int	TextureIndex;
	unsigned int	TextureVertexIndex;

	unsigned int	ToTextureVertexIndex(const TextCommand::Args & cmd_args, unsigned int arg_idx) const;

	void	Skin_Parse(const TextCommand::Args & cmd_args);
	void	Skin_Parse_Type(const TextCommand::Args & cmd_args);
	void	Skin_Parse_Format(const TextCommand::Args & cmd_args);

	//void	Skin_Parse_Name(const TextCommand::Args & cmd_args);
	void	Skin_Parse_Size(const TextCommand::Args & cmd_args);
	void	Skin_Parse_Image(const TextCommand::Args & cmd_args);

	void	Skin_Parse_t(const TextCommand::Args & cmd_args);

	void	Skin_Parse_TextureIndex(const TextCommand::Args & cmd_args);
	void	Skin_Parse_TextureIndexFace4(const TextCommand::Args & cmd_args);
	void	Skin_Parse_TextureIndexQuad(const TextCommand::Args & cmd_args);

	void	Skin_Parse_Vertex(const TextCommand::Args & cmd_args);			// VertexCoord()
	void	Skin_Parse_VertexIndex(const TextCommand::Args & cmd_args);	// VertexOffset()

	void	Skin_Parse_VertexFace3_F(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFace3_T(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFace3(const TextCommand::Args & cmd_args, bool f_direction);

	void	Skin_Parse_VertexBelt_FF(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexBelt_TF(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexBelt_FT(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexBelt_TT(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexBelt(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure);

	void	Skin_Parse_VertexBand_FF(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexBand_TF(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexBand_FT(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexBand_TT(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexBand(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure);

	void	Skin_Parse_VertexFan_FFF(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFan_TFF(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFan_FTF(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFan_TTF(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFan_FFT(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFan_TFT(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFan_FTT(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFan_TTT(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexFan(const TextCommand::Args & cmd_args, bool f_direction, bool f_closure, bool f_middle);

	void	Skin_Parse_VertexRay_F(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexRay_T(const TextCommand::Args & cmd_args);
	void	Skin_Parse_VertexRay(const TextCommand::Args & cmd_args, bool f_accumulate);

	void	Skin_Parse_ColorF_Default(const TextCommand::Args & cmd_args);
	void	Skin_Parse_ColorF(const TextCommand::Args & cmd_args);

	void	Skin_Parse_ColorD_Default(const TextCommand::Args & cmd_args);
	void	Skin_Parse_ColorD(const TextCommand::Args & cmd_args);

	void	Skin_Parse_Multi(const TextCommand::Args & cmd_args);

	void	Skin_Parse_AxisAlign(const TextCommand::Args & cmd_args);



	void	Done();

	static PolyHedra *	Load(const FileInfo & file, PolyHedraManager * manager);
};

#endif
