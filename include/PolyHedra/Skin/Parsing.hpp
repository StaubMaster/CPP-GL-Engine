#ifndef  SKIN_PARSING_HPP
# define SKIN_PARSING_HPP

# include "Skin.hpp"

class TextCommand;

struct Skin::ParsingData
{
	const FileInfo &	File;
	::Skin &			Skin;

	unsigned int		TextureIndex;

	~ParsingData();
	ParsingData(const FileInfo & file, ::Skin & skin);



	void	Parse(const TextCommand & cmd);
	void	Parse_Type(const TextCommand & cmd);
	void	Parse_Format(const TextCommand & cmd);

	void	Parse_Size(const TextCommand & cmd);
	void	Parse_Image(const TextCommand & cmd);

	void	Parse_t(const TextCommand & cmd);

	void	Parse_TextureIndex(const TextCommand & cmd);
	void	Parse_TextureIndexFace4(const TextCommand & cmd);
	void	Parse_TextureIndexQuad(const TextCommand & cmd);
};

#endif
