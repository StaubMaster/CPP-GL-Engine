#ifndef  SKIN_BASE_HPP
# define SKIN_BASE_HPP

# include "Miscellaneous/Container/Binary.hpp"

# include "Image.hpp"
# include "FileInfo.hpp"

class TextCommand;

namespace Texture
{
	class Base;
};

class SkinBase
{
	public:
	Container::Binary<Image> Images;
	FileInfo File;

	public:
	SkinBase();
	virtual ~SkinBase();

	public:
	virtual void Done() = 0;

	virtual Texture::Base * ToTexture() const = 0;

	protected:
	virtual void Parse(const TextCommand & cmd) = 0;
	struct ParserData
	{
		FileInfo	File;
		SkinBase *	Skin;
		void Parse(const TextCommand & cmd);
		void Parse_Type(const TextCommand & cmd);
		void Parse_Format(const TextCommand & cmd);
	};
	public:
	static SkinBase * Load(const FileInfo & file);
};

#endif
