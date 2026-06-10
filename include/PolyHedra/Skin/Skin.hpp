#ifndef  SKIN_HPP
# define SKIN_HPP

# include "Miscellaneous/Container/Binary.hpp"

# include "FileInfo.hpp"
# include "ValueType/Vector/U2.hpp"
# include "ValueType/Vector/F3.hpp"
# include "Image.hpp"

# include <string>

namespace Texture { class Array2D; };

class Skin
{
	public:
	struct Face;

	public:
	VectorU2	Size;
	Container::Binary<Image>	Images;
	Container::Binary<Face>		Faces;

	public: // Information stuff
	FileInfo	File;
	std::string	Name;

	public:
	~Skin();
	Skin();
	Skin(const Skin & other) = delete;
	Skin & operator=(const Skin & other) = delete;

	public:
	void				Done();
	Texture::Array2D	ToTexture() const; // To Texture Data ?



	public:
	void	Insert_Face3(VectorF3 corn0, VectorF3 corn1, VectorF3 corn2);
	void	Insert_Face4(VectorF3 corn0, VectorF3 corn1, VectorF3 corn2, VectorF3 corn3);



	private:
	struct ParsingData;
	public:
	static Skin *	Load(const FileInfo & file);
};

#endif
