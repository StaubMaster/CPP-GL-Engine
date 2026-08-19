#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Data.hpp"

#include "PolyHedra/Skin/Skin.hpp"
#include "PolyHedra/Skin/Data.hpp"

#include "ValueType/Box/F3.hpp"

#include "Graphics/Texture/Generate.hpp"
#include "Image.hpp"

#include "Generics/Container/Array.hpp"

#include "FileParsing/Variables/Float.hpp"

//#include "FileInfo.hpp"

#include <sstream>
#include <iostream>
#include "ValueType/_Show.hpp"



BoxF3 PolyHedra::CalcBound() const
{
	BoxF3 box;
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		box.Consider(Corners[i].Position);
	}
	return box;
}



std::string PolyHedra::ToInfo() const
{
	std::stringstream ss;

	ss << "File: " << File.Path << '\n';
	ss << "IsAutomatic: " << IsAutomatic << '\n';

	ss << "PolyHedra Count Vertex: " << Corners.Count() << '\n';
	ss << "PolyHedra Count Face: " << Faces.Count() << '\n';
	
	BoxF3 bound = CalcBound();
	ss << "PolyHedra Bound Limit: " << bound << '\n';
	ss << "PolyHedra Bound Size: " << bound.Size() << '\n';

	if (Parameters != nullptr)
	{
		const Container::Binary<ParsingVariable::Float> & vars = Parameters -> Variables;
		ss << "Parameters[" << vars.Count() << "]\n";
		ss << "[\n";
		for (unsigned int i = 0; i < vars.Count(); i++)
		{
			const ParsingVariable::Float & var = vars[i];
			ss << "  " << var.Name << ": " << var.Value << '\n';
		}
		ss << "]\n";
	}

	return ss.str();
}



PolyHedra::~PolyHedra()
{
	delete Skin;
}
PolyHedra::PolyHedra()
	: Corners()
	, Edges()
	, Faces()
	, Skin(nullptr)
	, File()
	, UseCornerNormals(false)
{ }



void PolyHedra::Done()
{
	Corners.Trim();
	Edges.Trim();
	Faces.Trim();
	//CalcNormals(); ?
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
			Corner & corner0 = Corners[face.idx[0]];
			Corner & corner1 = Corners[face.idx[1]];
			Corner & corner2 = Corners[face.idx[2]];
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
	Faces.Insert(Face(corn0, corn1, corn2));
	Faces.Insert(Face(corn2, corn1, corn3));

	Edges.Insert(Edge(corn0, corn1));
	Edges.Insert(Edge(corn1, corn3));
	Edges.Insert(Edge(corn3, corn2));
	Edges.Insert(Edge(corn2, corn0));
}

void PolyHedra::Belt_Face(unsigned int temp[4], bool f_direction)
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
void PolyHedra::Belt(unsigned int len, unsigned int list0[], unsigned int list1[], bool f_direction, bool f_closed)
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

void PolyHedra::Fan_Face(unsigned int middle, unsigned int blade[2], bool f_direction, bool f_middle)
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
void PolyHedra::Fan(unsigned int len, unsigned int middle, unsigned int blade[], bool f_direction, bool f_middle, bool f_closed)
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
