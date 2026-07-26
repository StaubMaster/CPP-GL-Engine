#ifndef  POLYHEDRA_PARSING_HPP
# define POLYHEDRA_PARSING_HPP

# include "FileInfo.hpp"
# include "FileParsing/Variables/Float.hpp"

# include "PolyHedra/PolyHedra.hpp"
//# include "FileParsing/ParsingCommand.hpp"
//# include "FileParsing/Text/TextCommand.hpp"

# include "Generics/Container/Binary.hpp"
# include "Generics/Function/Pointer.hpp"
# include "Generics/Function/Object.hpp"

# include <string>
# include <exception>

class TextCommand;
typedef TextCommand TextCommandArgs;

struct TextCommandFunc
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
};

struct PolyHedra::ParsingData
{
	FileInfo		File;
	::PolyHedra &	PolyHedra;

	bool	DefaultDirection; // IsNormalToClockWise
	bool	DefaultClosed; // open : closed // default should be closed // IsClosed
	bool	DefaultMiddle; // first : last // IsMiddleLast

	unsigned int	VertexOffset;
	unsigned int	ToVertexIndex(const TextCommandArgs & cmd_args, unsigned int arg_idx) const;

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

	void	Place_Circle(const TextCommandArgs & cmd_args, bool direction);
	void	Place_Circle(const TextCommandArgs & cmd_args);

	void	Place_Face(const TextCommandArgs & cmd_args, bool direction);
	void	Place_Face(const TextCommandArgs & cmd_args);

	/* belt
		'0'		open
		'1'		closed
	*/
	void	Place_Belt(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure);
	void	Place_Belt(const TextCommandArgs & cmd_args);

	void	Place_Band(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure);
	void	Place_Band(const TextCommandArgs & cmd_args);

	/* fan
		'<'		Middle is first
		'>'		Middle is last
		'0'		open
		'1'		closed
	*/
	void	Place_Fan(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure, bool f_middle);
	void	Place_Fan(const TextCommandArgs & cmd_args);

/*
[0]		[			0			]
		[	       /|\       	]
		[	     // | \\     	]
		[	   / /  |  \ \   	]
		[	 /  /   |   \  \ 	]
[1]		[	0---1---2---3---4	]
		[	|	|	|	|	|	]
		[	|	|	|	|	|	]
		[	|	|	|	|	|	]
[2]		[	0---1---2---3---4	]
		[	 \  \   |   /  / 	]
		[	   \ \  |  / /   	]
		[	     \\ | //     	]
		[	       \|/       	]
[3]		[			0			]

fanF   [0][0]           [1][0;1;2;3;4]
belt   [1][0;1;2;3;4]   [2][0;1;2;3;4]
fanR   [2][0;1;2;3;4]   [3][0]

Counter Clockwise

fanF
        [1][1]   [0][0]   [1][0]
belt
        [1][0]   [2][0]   [1][1]
        [2][1]   [1][1]   [2][0]
fanR
        [2][0]   [3][0]   [2][1]
*/
};

#endif
