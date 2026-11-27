#include "PolyHedra/Skin.hpp"



PolyHedraSkin::Corner::Corner(VectorF2 coord, unsigned int index)
	: Coord(coord)
	, Index(index)
{ }
PolyHedraSkin::Corner::Corner(float coord_x, float coord_y, unsigned int index)
	: Coord(coord_x, coord_y)
	, Index(index)
{ }
PolyHedraSkin::Corner::Corner(ColorF4 color)
	: Color(color)
{ }



PolyHedraSkin::Face::Face(unsigned int idx0, unsigned int idx1, unsigned int idx2)
	: idx{ idx0, idx1, idx2 }
{ }



/*void PolyHedraSkin::Insert_Face3(unsigned int idx0, unsigned int idx1, unsigned int idx2)
{
	Faces.Insert(Face(idx0, idx1, idx2));
}*/
/*void PolyHedraSkin::Insert_Face4(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int idx3)
{
	Faces.Insert(Face(idx0, idx1, idx2));
	Faces.Insert(Face(idx2, idx1, idx3));
}*/

void PolyHedraSkin::Insert_Corn(float x, float y, unsigned int texture_idx)
{
	Corners.Insert(PolyHedraSkin::Corner(x, y, texture_idx));
}
void PolyHedraSkin::Insert_Corn(VectorF2 vec, unsigned int texture_idx)
{
	Corners.Insert(PolyHedraSkin::Corner(vec, texture_idx));
}

void PolyHedraSkin::Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2)
{
	Faces.Insert(PolyHedraSkin::Face(corn0, corn1, corn2));
}
void PolyHedraSkin::Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3)
{
	Faces.Insert(PolyHedraSkin::Face(corn0, corn1, corn2));
	Faces.Insert(PolyHedraSkin::Face(corn2, corn1, corn3));
}

void PolyHedraSkin::Belt_Face(unsigned int temp[4], bool f_direction)
{
	if (!f_direction)
	{
		Insert_Face4(temp[0], temp[1], temp[2], temp[3]);
	}
	else
	{
		Insert_Face4(temp[3], temp[2], temp[1], temp[0]);
	}
}
void PolyHedraSkin::Belt(unsigned int len, unsigned int list0[], unsigned int list1[], bool f_direction, bool f_closed)
{
	unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int temp[4] = {
			list0[i + 0],
			list0[i + 1],
			list1[i + 0],
			list1[i + 1],
		};
		Belt_Face(temp, f_direction);
	}

	if (f_closed)
	{
		unsigned int temp[4] = {
			list0[n],
			list0[0],
			list1[n],
			list1[0],
		};
		Belt_Face(temp, f_direction);
	}
}

void PolyHedraSkin::Fan_Face(unsigned int middle, unsigned int blade[2], bool f_direction, bool f_middle)
{
	if (!f_direction)
	{
		if (!f_middle)
		{
			Insert_Face3(blade[0], middle, blade[1]);
		}
		else
		{
			Insert_Face3(blade[1], middle, blade[0]);
		}
	}
	else
	{
		if (!f_middle)
		{
			Insert_Face3(blade[1], middle, blade[0]);
		}
		else
		{
			Insert_Face3(blade[0], middle, blade[1]);
		}
	}
}
void PolyHedraSkin::Fan(unsigned int len, unsigned int middle, unsigned int blade[], bool f_direction, bool f_middle, bool f_closed)
{
	unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int temp[2] = {
			blade[i + 0],
			blade[i + 1],
		};
		Fan_Face(middle, temp, f_direction, f_middle);
	}

	if (f_closed)
	{
		unsigned int temp[2] = {
			blade[n],
			blade[0],
		};
		Fan_Face(middle, temp, f_direction, f_middle);
	}
}

void PolyHedraSkin::TrimData()
{
	Images.Trim();
	Corners.Trim();
	Faces.Trim();
}



void PolyHedraSkin::Combine(const PolyHedraSkin & other)
{
	unsigned int image_offset = Images.Count();
	unsigned int corner_offset = Corners.Count();
	unsigned int face_offset = Faces.Count();

	for (unsigned int i = 0; i < other.Images.Count(); i++)
	{
		Images.Insert(other.Images[i]);
	}

	for (unsigned int i = 0; i < other.Corners.Count(); i++)
	{
		PolyHedraSkin::Corner corner = other.Corners[i];
		if (corner.Index != 0xFFFFFFFF)
		{
			corner.Index += image_offset;
		}
		Corners.Insert(corner);
	}

	for (unsigned int i = 0; i < other.Faces.Count(); i++)
	{
		PolyHedraSkin::Face face = other.Faces[i];
		for (unsigned int j = 0; j < 3; j++)
		{
			if (face.idx[j] != 0xFFFFFFFF)
			{
				face.idx[j] += corner_offset;
			}
		}
		Faces.Insert(face);
	}

	(void)face_offset;
}



PolyHedraSkin::PolyHedraSkin()
	: Color(1.0f, 1.0f, 1.0f, 1.0f)
{ }



#include "Graphics/Texture/Array2D.hpp"
Texture::Array2D PolyHedraSkin::ToTexture() const
{
	Texture::Array2D tex;
	tex.Create();
	tex.Assign(Size, Images.ToArray());
	return tex;
}
