#ifndef  SKIN_PARSING_HPP
# define SKIN_PARSING_HPP

# include "Skin.hpp"

class TextCommandArgs;

struct Skin::ParsingData
{
	const FileInfo &	File;
	::Skin &			Skin;

	unsigned int	TextureIndex;
	unsigned int	TextureVertexIndex;

	unsigned int	ToVertexIndex(const TextCommandArgs & cmd_args, unsigned int arg_idx) const;

	~ParsingData();
	ParsingData(const FileInfo & file, ::Skin & skin);



	void	Parse(const TextCommandArgs & cmd_args);
	void	Parse_Type(const TextCommandArgs & cmd_args);
	void	Parse_Format(const TextCommandArgs & cmd_args);

	void	Parse_Name(const TextCommandArgs & cmd_args);
	void	Parse_Size(const TextCommandArgs & cmd_args);
	void	Parse_Image(const TextCommandArgs & cmd_args);

	void	Parse_t(const TextCommandArgs & cmd_args);

	void	Parse_TextureIndex(const TextCommandArgs & cmd_args);
	void	Parse_TextureIndexFace4(const TextCommandArgs & cmd_args);
	void	Parse_TextureIndexQuad(const TextCommandArgs & cmd_args);

	void	Parse_Vertex(const TextCommandArgs & cmd_args);			// VertexCoord()
	void	Parse_VertexIndex(const TextCommandArgs & cmd_args);	// VertexOffset()

	void	Parse_VertexFace3(const TextCommandArgs & cmd_args, bool f_direction);
	void	Parse_VertexBelt(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure);
	void	Parse_VertexBand(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure);
	void	Parse_VertexFan(const TextCommandArgs & cmd_args, bool f_direction, bool f_closure, bool f_middle);

	void	Parse_VertexRay(const TextCommandArgs & cmd_args, bool f_accumulate);

	void	Parse_ColorF_Default(const TextCommandArgs & cmd_args);
	void	Parse_ColorF(const TextCommandArgs & cmd_args);

	void	Parse_ColorD_Default(const TextCommandArgs & cmd_args);
	void	Parse_ColorD(const TextCommandArgs & cmd_args);

	void	Parse_Multi(const TextCommandArgs & cmd_args);
};

#endif
