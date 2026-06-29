#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Data.hpp"

#include "PolyHedra/Skin/Skin.hpp"
#include "PolyHedra/Skin/Data.hpp"

#include "PolyHedra/Graphics/Full/Main/Data.hpp"

#include "ValueType/Box/F3.hpp"

#include "Graphics/Texture/Generate.hpp"
#include "Image.hpp"

#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"

#include "Miscellaneous/Container/Array.hpp"

//#include "FileInfo.hpp"

#include <sstream>
#include <iostream>
#include "ValueType/_Show.hpp"



PolyHedra::~PolyHedra()
{
	for (unsigned int i = 0; i < Skins.Count(); i++)
	{
		delete Skins[i];
	}
}
PolyHedra::PolyHedra()
	: Corners()
	, Edges()
	, Faces()
	, Skins()
	, File()
	, UseCornerNormals(false)
{ }

void PolyHedra::Done()
{
	Corners.Trim();
	Edges.Trim();
	Faces.Trim();

	// think of a better way to do this ?
	// Color override in Instance Data ?
	if (Skins.Count() == 0)
	{
		Skin * skin = new ::Skin();
		skin -> Size = VectorU2(1, 1);
		skin -> Images.Insert(Texture::Generate::NoSkin());
		Skins.Insert(skin);
	}
}



std::string PolyHedra::ToInfo() const
{
	std::stringstream ss;

	ss << "Source: " << File << '\n';

	ss << "PolyHedra Count Vertex: " << Corners.Count() << '\n';
	ss << "PolyHedra Count Face: " << Faces.Count() << '\n';
	
	BoxF3 bound = CalcBound();
	ss << "PolyHedra Bound Limit: " << bound << '\n';
	ss << "PolyHedra Bound Size: " << bound.Size() << '\n';

	return ss.str();
}

BoxF3	PolyHedra::CalcBound() const
{
	BoxF3 box;
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		box.Consider(Corners[i].Position);
	}
	return box;
}



void PolyHedra::CalcNormals()
{
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		Corners[i].Normal = VectorF3();
	}

	for (unsigned int i = 0; i < Faces.Count(); i++)
	{
		Face & face = Faces[i];
		if (face.Check(Corners.Count()))
		{
			Corner & corner0 = Corners[face.udx[0]];
			Corner & corner1 = Corners[face.udx[1]];
			Corner & corner2 = Corners[face.udx[2]];
			face.Normal = VectorF3::cross(
				corner1.Position - corner0.Position,
				corner2.Position - corner0.Position
			).normalize();
			corner0.Normal += face.Normal;
			corner1.Normal += face.Normal;
			corner2.Normal += face.Normal;
		}
		else
		{
			face.Normal = VectorF3();
		}
	}

	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		Corner & corner = Corners[i];
		corner.Normal = corner.Normal.normalize();
	}
}

void PolyHedra::Insert_Corn(Corner corn)
{
	Corners.Insert(corn);
}
void PolyHedra::Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2)
{
	Faces.Insert(Face(corn0, corn1, corn2));

	Edges.Insert(Edge(corn0, corn1));
	Edges.Insert(Edge(corn1, corn2));
	Edges.Insert(Edge(corn2, corn0));
}
void PolyHedra::Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3)
{
	Insert_Face3(corn0, corn1, corn2);
	Insert_Face3(corn2, corn1, corn3);
}

void PolyHedra::Belt(unsigned int idx0[], unsigned int idx1[], unsigned int len, bool direction, bool closure)
{
	for (unsigned int i = 1; i < len; i++)
	{
		if (!direction)
		{
			Insert_Face3(idx0[i - 1], idx0[i - 0], idx1[i - 1]);
			Insert_Face3(idx1[i - 1], idx0[i - 0], idx1[i - 0]);
		}
		else
		{
			Insert_Face3(idx1[i - 1], idx0[i - 0], idx0[i - 1]);
			Insert_Face3(idx1[i - 0], idx0[i - 0], idx1[i - 1]);
		}
	}

	if (closure)
	{
		if (!direction)
		{
			Insert_Face3(idx0[len - 1], idx0[0], idx1[len - 1]);
			Insert_Face3(idx1[len - 1], idx0[0], idx1[0]);
		}
		else
		{
			Insert_Face3(idx0[0], idx0[len -1], idx1[len - 1]);
			Insert_Face3(idx0[0], idx1[len -1], idx1[0]);
		}
	}
}
//void PolyHedra::Band(unsigned int idx0[], unsigned int idx1[], unsigned int len, bool direction, bool closure)
void PolyHedra::Fan(unsigned int middle, unsigned int blade[], unsigned int len, bool direction, bool closure)
{
	for (unsigned int i = 1; i < len; i++)
	{
		if (!direction)
		{
			Insert_Face3(middle, blade[i - 1], blade[i - 0]);
		}
		else
		{
			Insert_Face3(middle, blade[i - 0], blade[i - 1]);
		}
	}

	if (closure)
	{
		if (!direction)
		{
			Insert_Face3(middle, blade[len - 1], blade[0]);
		}
		else
		{
			Insert_Face3(middle, blade[0], blade[len - 1]);
		}
	}
}



Container::Array<PolyHedraFull::Main::Data> PolyHedra::ToMainData()
{
	Container::Array<PolyHedraFull::Main::Data> data(Faces.Count() * 3);

	for (unsigned int f = 0; f < Faces.Count(); f++)
	{
		int c = f * 3;
		const Face & face = Faces[f];
		if (face.Check(Corners.Count()))
		{
			const Corner & cornerX = Corners[face.udx[0]];
			const Corner & cornerY = Corners[face.udx[1]];
			const Corner & cornerZ = Corners[face.udx[2]];

			data[c + 0].Position = cornerX.Position;
			data[c + 1].Position = cornerY.Position;
			data[c + 2].Position = cornerZ.Position;

			if (!UseCornerNormals)
			{
				data[c + 0].Normal = face.Normal;
				data[c + 1].Normal = face.Normal;
				data[c + 2].Normal = face.Normal;
			}
			else
			{
				data[c + 0].Normal = cornerX.Normal;
				data[c + 1].Normal = cornerY.Normal;
				data[c + 2].Normal = cornerZ.Normal;
			}
		}
		else
		{
			//std::cout << "Invalid Face\n";
		}
	}

	if (Skins.Count() == 0)
	{
		for (unsigned int i = 0; i < data.Length(); i++)
		{
			data[i].Texture = VectorF3();
		}
	}
	else
	{
		const Skin * skin = Skins[0];
		for (unsigned int f = 0; f < skin -> Faces.Count(); f++)
		{
			int c = f * 3;
			const Skin::Face & face = skin -> Faces[f];
			data[c + 0].Texture = face.Corner[0];
			data[c + 1].Texture = face.Corner[1];
			data[c + 2].Texture = face.Corner[2];
		}
	}

	return data;
}
