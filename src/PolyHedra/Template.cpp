#include "PolyHedra/Template.hpp"
#include "PolyHedra/Data.hpp"

#include "ValueType/Point3D.hpp"



PolyHedra::Template::Template(PolyHedra & referance) :
	Referance(referance)
{ }



void PolyHedra::Template::Done()
{
	Referance.Corners.Trim();
	Referance.Faces.Trim();

	Calc_Face_Normals();
	Calc_Corn_Normals();
}



void PolyHedra::Template::Calc_Face_Normals()
{
	for (unsigned int i = 0; i < Referance.Faces.Count(); i++)
	{
		Face & face = Referance.Faces[i];
		if (face.Check(Referance.Corners.Count()))
		{
			const Point3D & cornerX = Referance.Corners[face.udx[0]].Position;
			const Point3D & cornerY = Referance.Corners[face.udx[1]].Position;
			const Point3D & cornerZ = Referance.Corners[face.udx[2]].Position;
			face.Normal = Point3D::cross(cornerY - cornerX, cornerZ - cornerX).normalize();
		}
		else
		{
			face.Normal = Point3D();
		}
	}
}
void PolyHedra::Template::Calc_Corn_Normals()
{
	for (unsigned int i = 0; i < Referance.Corners.Count(); i++)
	{
		Point3D normal_sum(0, 0, 0);
		for (unsigned int j = 0; j < Referance.Faces.Count(); j++)
		{
			const Face & face = Referance.Faces[j];
			if (face.udx[0] == i ||
				face.udx[1] == i ||
				face.udx[2] == i
			)
			{
				normal_sum = normal_sum + face.Normal;
			}
		}
		Referance.Corners[i].Normal = normal_sum.normalize();
	}
}



void PolyHedra::Template::Insert_Corn(Corner corn)
{
	Referance.Corners.Insert(corn);
}
void PolyHedra::Template::Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2)
{
	Referance.Faces.Insert(Face(corn0, corn1, corn2));
}
void PolyHedra::Template::Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3)
{
	Insert_Face3(corn0, corn1, corn2);
	Insert_Face3(corn2, corn1, corn3);
}





void PolyHedra::Template::Belt(unsigned int idx0[], unsigned int idx1[], unsigned int len, bool direction, bool closure)
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
//void PolyHedra::Template::Band(unsigned int idx0[], unsigned int idx1[], unsigned int len, bool direction, bool closure)
void PolyHedra::Template::Fan(unsigned int middle, unsigned int blade[], unsigned int len, bool direction, bool closure)
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
