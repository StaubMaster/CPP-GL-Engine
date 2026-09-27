#ifndef  SKIN_HPP
# define SKIN_HPP

# include "Generics/Container/Binary.hpp"

# include "FileInfo.hpp"
# include "ValueType/Vector/U2.hpp"
# include "ValueType/Vector/F3.hpp"
# include "ValueType/Color/F4.hpp"
# include "Image.hpp"

# include <string>

namespace Texture { class Array2D; };

class PolyHedra;

class Skin
{
	public:
	struct Corner;
	struct Face;

	public:
	VectorU2	Size;
	ColorF4		Color;

	public:
	Container::Binary<Image>	Images;
	Container::Binary<Corner>	Corners;
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
	Texture::Array2D	ToTexture() const; // To Texture Data ?



	public:
	void	Insert_Corn(float x, float y, unsigned int texture_idx);
	void	Insert_Corn(VectorF2 vec, unsigned int texture_idx);

	public:
	void	Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2);
	void	Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3);

	public:
	void	Belt_Face(unsigned int temp[4], bool f_direction);
	void	Belt(unsigned int len, unsigned int list0[], unsigned int list1[], bool f_direction, bool f_closed);

	public:
	void	Fan_Face(unsigned int middle, unsigned int blade[2], bool f_direction, bool f_middle);
	void	Fan(unsigned int len, unsigned int middle, unsigned int blade[], bool f_direction, bool f_middle, bool f_closed);

	public:
	void	Done();

	private:
	struct ParsingData;
	public:
	static Skin *	Load(const FileInfo & file, ::PolyHedra * polyHedra);
	static Skin *	Load(const FileInfo & file);
};

#endif
