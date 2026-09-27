#include "PolyHedra/Skin/Skin.hpp"
#include "PolyHedra/Skin/Data.hpp"
#include "Graphics/Texture/Array2D.hpp"
#include "Image.hpp"

#include "FileInfo.hpp"

#include "ValueType/Vector/F2.hpp"

#include <iostream>
#include "ValueType/_Show.hpp"



Skin::Skin()
	: Size()
	, Color(1.0f, 1.0f, 1.0f, 1.0f)
	, Images()
	, Faces()
	, File()
	, Name()
{ }
Skin::~Skin()
{ }



Texture::Array2D Skin::ToTexture() const
{
	Texture::Array2D tex;
	tex.Create();
	tex.Assign(Size, Images.ToArray());
	return tex;
}



/*void Skin::Insert_Face3(unsigned int idx0, unsigned int idx1, unsigned int idx2)
{
	Faces.Insert(Face(idx0, idx1, idx2));
}*/
/*void Skin::Insert_Face4(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int idx3)
{
	Faces.Insert(Face(idx0, idx1, idx2));
	Faces.Insert(Face(idx2, idx1, idx3));
}*/



void Skin::Insert_Corn(float x, float y, unsigned int texture_idx)
{
	Corners.Insert(Skin::Corner(x, y, texture_idx));
}
void Skin::Insert_Corn(VectorF2 vec, unsigned int texture_idx)
{
	Corners.Insert(Skin::Corner(vec, texture_idx));
}

void Skin::Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2)
{
	Faces.Insert(Skin::Face(corn0, corn1, corn2));
}
void Skin::Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3)
{
	Faces.Insert(Skin::Face(corn0, corn1, corn2));
	Faces.Insert(Skin::Face(corn2, corn1, corn3));
}

void Skin::Belt_Face(unsigned int temp[4], bool f_direction)
{
	if (!f_direction)
	{
		Insert_Face3(temp[0], temp[2], temp[1]);
		Insert_Face3(temp[3], temp[1], temp[2]);
	}
	else
	{
		Insert_Face3(temp[1], temp[2], temp[0]);
		Insert_Face3(temp[2], temp[1], temp[3]);
	}
}
void Skin::Belt(unsigned int len, unsigned int list0[], unsigned int list1[], bool f_direction, bool f_closed)
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

void Skin::Fan_Face(unsigned int middle, unsigned int blade[2], bool f_direction, bool f_middle)
{
	if (!f_direction)
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
	else
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
}
void Skin::Fan(unsigned int len, unsigned int middle, unsigned int blade[], bool f_direction, bool f_middle, bool f_closed)
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

void Skin::Done()
{
	Images.Trim();
	Corners.Trim();
	Faces.Trim();
}
