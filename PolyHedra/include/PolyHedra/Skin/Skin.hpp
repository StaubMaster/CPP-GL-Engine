#ifndef  SKIN_HPP
# define SKIN_HPP

# include "ValueType/Vector/U2.hpp"
# include "ValueType/Vector/F2.hpp"
# include "ValueType/Color/F4.hpp"
# include "Image.hpp"

# include "Generics/Container/Binary.hpp"

namespace Texture { class Array2D; };

class PolyHedra;

class Skin
{
	public:
	struct Corner
	{
		VectorF2		Coord;
		unsigned int	Index = 0xFFFFFFFF; // in Face
		ColorF4			Color; // in Face ?

		~Corner() = default;
		Corner() = default;
		Corner(const Corner & other) = default;
		Corner & operator=(const Corner & other) = default;

		Corner(VectorF2 coord, unsigned int index);
		Corner(float coord_x, float coord_y, unsigned int index);
		Corner(ColorF4 color);
	};
	struct Face
	{
		unsigned int	idx[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

		~Face() = default;
		Face() = default;
		Face(const Face & other) = default;
		Face & operator=(const Face & other) = default;

		Face(unsigned int idx0, unsigned int idx1, unsigned int idx2);
	};

	public:
	Container::Binary<Corner>	Corners;
	Container::Binary<Face>		Faces;

	public:
	VectorU2					Size;
	Container::Binary<Image>	Images;
	ColorF4						Color;

	public:
	~Skin() = default;
	//Skin() = default;
	Skin(); // only needed for Color
	Skin(const Skin & other) = delete;
	Skin & operator=(const Skin & other) = delete;

	public:
	Texture::Array2D	ToTexture() const;

	public:
	void	Combine(const Skin & other);



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

	public:
	struct ParsingData;
};

#endif
