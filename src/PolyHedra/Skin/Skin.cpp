#include "PolyHedra/Skin/Skin.hpp"
#include "PolyHedra/Skin/Data.hpp"
#include "Graphics/Texture/Array2D.hpp"
#include "Image.hpp"

#include "FileInfo.hpp"
#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"
#include "FileParsing/Text/Exceptions.hpp"

#include "ValueType/Vector/F2.hpp"

#include <iostream>
#include "ValueType/_Show.hpp"



Skin::Skin()
	: Size()
	, Images()
	, Faces()
	, File()
{ }
Skin::~Skin()
{ }



void Skin::Done()
{
	Faces.Trim();
}
Texture::Array2D Skin::ToTexture() const
{
	Texture::Array2D tex;
	tex.Create();
	tex.Assign(Size, Images.ToArray());
	return tex;
}



void Skin::Insert_Face3(VectorF3 corn0, VectorF3 corn1, VectorF3 corn2)
{
	Faces.Insert(Face(corn0, corn1, corn2));
}
void Skin::Insert_Face4(VectorF3 corn0, VectorF3 corn1, VectorF3 corn2, VectorF3 corn3)
{
	Insert_Face3(corn0, corn1, corn2);
	Insert_Face3(corn2, corn1, corn3);
}
