#ifndef  POLYHEDRA_PARSING_HPP
# define POLYHEDRA_PARSING_HPP

# include "FileInfo.hpp"
# include "PolyHedra/PolyHedra.hpp"
//# include "FileParsing/ParsingCommand.hpp"
//# include "FileParsing/Text/TextCommand.hpp"

# include <string>
# include <exception>

class TextCommand;

struct PolyHedra::ParsingData
{
	FileInfo				File;
	PolyHedra *				PH;		//rename to Data
	PolyHedra::Template *	Data;	//rename to Temp
	unsigned int	CornerOffset;
	unsigned int	FaceOffset;

	ParsingData(const FileInfo & file);
	~ParsingData();

	void Parse(const TextCommand & cmd);

	void Parse_Type(const TextCommand & cmd);
	void Parse_Format(const TextCommand & cmd);
	void Parse_Skin(const TextCommand & cmd);

	void Parse_Corner(const TextCommand & cmd);
	void Parse_Face(const TextCommand & cmd);

	void Parse_Offset(const TextCommand & cmd);
	void Parse_Belt(const TextCommand & cmd, bool direction, bool closure);
	void Parse_Band(const TextCommand & cmd, bool direction, bool closure);
	void Parse_Fan(const TextCommand & cmd, bool direction, bool closure);
	void Parse_CircleOLD(const TextCommand & cmd);
	void Parse_Circle(const TextCommand & cmd, bool direction);
};

#endif
