#ifndef  SKIN_BASE_HPP
# define SKIN_BASE_HPP

# include "Miscellaneous/Container/Binary.hpp"

# include "FileParsing/ParsingCommand.hpp"

# include "Image.hpp"

namespace YMT
{
	class PolyHedra;
};

namespace Texture
{
	class Base;
};

class FileInfo;
class LineCommand;

class SkinBase
{
	public:
		Container::Binary<Image> Images;
		const FileInfo * File;

	public:
		SkinBase();
		virtual ~SkinBase();

	public:
		virtual void Done() = 0;

		virtual Texture::Base * ToTexture() const = 0;

	public:
		struct ParsingEnvironmentData : public ParsingCommand::EnvironmentData
		{
			SkinBase * Skin;
			ParsingEnvironmentData(const FileInfo & file);
			void Parse(const ParsingCommand & cmd) override;

			void Parse_Type(const ParsingCommand & cmd);
			void Parse_Format(const ParsingCommand & cmd);
		};
	public:
		virtual void Parse(const ParsingCommand & cmd) = 0;
	public:
		static SkinBase * Load(const FileInfo & file);
};

#endif
