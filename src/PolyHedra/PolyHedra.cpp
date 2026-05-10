#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Data.hpp"

#include "PolyHedra/Skin/Skin2DA.hpp"

#include "PolyHedra/Graphics/Full/Main/Data.hpp"

#include "ValueType/Box/F3.hpp"

#include "Graphics/Texture/Generate.hpp"
#include "Image.hpp"

#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"

#include "Miscellaneous/Container/Fixed.hpp"

//#include "FileInfo.hpp"

#include <sstream>
#include <iostream>
#include "ValueType/_Show.hpp"



PolyHedra::PolyHedra()
	: Corners()
	, Edges()
	, Faces()
	, File()
	, Skin(nullptr)
	, UseCornerNormals(false)
{ }
PolyHedra::~PolyHedra()
{
	delete Skin;
}

void PolyHedra::Done()
{
	Corners.Trim();
	Edges.Trim();
	Faces.Trim();

	if (Skin == nullptr)
	{
		Skin2DA * skin = new Skin2DA();
		skin -> W = 1;
		skin -> H = 1;
		skin -> Images.Insert(Texture::Generate::NoSkin());
		Skin = skin;
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



void PolyHedra::Calc_Face_Normals()
{
	for (unsigned int i = 0; i < Faces.Count(); i++)
	{
		Face & face = Faces[i];
		if (face.Check(Corners.Count()))
		{
			const VectorF3 & cornerX = Corners[face.udx[0]].Position;
			const VectorF3 & cornerY = Corners[face.udx[1]].Position;
			const VectorF3 & cornerZ = Corners[face.udx[2]].Position;
			face.Normal = VectorF3::cross(cornerY - cornerX, cornerZ - cornerX).normalize();
		}
		else
		{
			face.Normal = VectorF3();
		}
	}
}
void PolyHedra::Calc_Corn_Normals()
{
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		VectorF3 normal_sum(0, 0, 0);
		for (unsigned int j = 0; j < Faces.Count(); j++)
		{
			const Face & face = Faces[j];
			if (face.udx[0] == i ||
				face.udx[1] == i ||
				face.udx[2] == i
			)
			{
				normal_sum = normal_sum + face.Normal;
			}
		}
		Corners[i].Normal = normal_sum.normalize();
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



Container::Pointer<PolyHedraFull::Main::Data> PolyHedra::ToMainData()
{
	Container::Pointer<PolyHedraFull::Main::Data> data(Faces.Count() * 3);

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

	if (Skin == NULL)
	{
		for (unsigned int i = 0; i < data.Count(); i++)
		{
			data[i].Texture = VectorF3();
		}
	}
	else
	{
		const Skin2DA * skin = (const Skin2DA *)Skin;
		for (unsigned int f = 0; f < skin -> Faces.Count(); f++)
		{
			int c = f * 3;
			const Skin2DFace & face = ((Skin2DA*)Skin) -> Faces[f];
			data[c + 0].Texture = face.Corner0.Tex;
			data[c + 1].Texture = face.Corner1.Tex;
			data[c + 2].Texture = face.Corner2.Tex;
		}
	}

	return data;
}
