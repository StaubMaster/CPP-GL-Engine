#include "PolyHedra/Flesh.hpp"



PolyHedraFlesh::Corner::Corner(VectorF3 pos)
	: Position(pos)
{ }
PolyHedraFlesh::Corner::Corner(float x, float y, float z)
	: Position(x, y, z)
{ }



bool PolyHedraFlesh::Face::Check(unsigned int count) const
{
	return (idx[0] < count &&
			idx[1] < count &&
			idx[2] < count);
}
PolyHedraFlesh::Face::Face(unsigned int idx0, unsigned int idx1, unsigned int idx2)
	: idx{ idx0, idx1, idx2 }
	, Normal()
{ }
PolyHedraFlesh::Face::Face(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int normal_group)
	: idx{ idx0, idx1, idx2 }
	, NormalGroup(normal_group)
	, Normal()
{ }



bool PolyHedraFlesh::Edge::Check(unsigned int count) const
{
	return (idx[0] < count &&
			idx[1] < count);
}
PolyHedraFlesh::Edge::Edge(unsigned int idx0, unsigned int idx1)
	: idx{ idx0, idx1 }
{ }



void PolyHedraFlesh::Insert_Corn(float x, float y, float z)
{
	Corners.Insert(PolyHedraFlesh::Corner(x, y, z));
}
void PolyHedraFlesh::Insert_Corn(VectorF3 vec)
{
	Corners.Insert(PolyHedraFlesh::Corner(vec));
}

void PolyHedraFlesh::Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2)
{
	Faces.Insert(PolyHedraFlesh::Face(corn0, corn1, corn2));

	Edges.Insert(PolyHedraFlesh::Edge(corn0, corn1));
	Edges.Insert(PolyHedraFlesh::Edge(corn1, corn2));
	Edges.Insert(PolyHedraFlesh::Edge(corn2, corn0));
}
void PolyHedraFlesh::Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int normal_group)
{
	Faces.Insert(PolyHedraFlesh::Face(corn0, corn1, corn2, normal_group));

	Edges.Insert(PolyHedraFlesh::Edge(corn0, corn1));
	Edges.Insert(PolyHedraFlesh::Edge(corn1, corn2));
	Edges.Insert(PolyHedraFlesh::Edge(corn2, corn0));
}
void PolyHedraFlesh::Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3)
{
	Faces.Insert(PolyHedraFlesh::Face(corn0, corn1, corn2));
	Faces.Insert(PolyHedraFlesh::Face(corn2, corn1, corn3));

	Edges.Insert(PolyHedraFlesh::Edge(corn0, corn1));
	Edges.Insert(PolyHedraFlesh::Edge(corn1, corn3));
	Edges.Insert(PolyHedraFlesh::Edge(corn3, corn2));
	Edges.Insert(PolyHedraFlesh::Edge(corn2, corn0));
}
void PolyHedraFlesh::Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3, unsigned int normal_group)
{
	Faces.Insert(PolyHedraFlesh::Face(corn0, corn1, corn2, normal_group));
	Faces.Insert(PolyHedraFlesh::Face(corn2, corn1, corn3, normal_group));

	Edges.Insert(PolyHedraFlesh::Edge(corn0, corn1));
	Edges.Insert(PolyHedraFlesh::Edge(corn1, corn3));
	Edges.Insert(PolyHedraFlesh::Edge(corn3, corn2));
	Edges.Insert(PolyHedraFlesh::Edge(corn2, corn0));
}

void PolyHedraFlesh::Belt_Face(unsigned int temp[4], bool f_direction, unsigned int normal_group)
{
	if (!f_direction)
	{
		Insert_Face4(temp[0], temp[1], temp[2], temp[3], normal_group);
	}
	else
	{
		//Insert_Face4(temp[3], temp[2], temp[1], temp[0], normal_group);
		Insert_Face4(temp[0], temp[2], temp[1], temp[3], normal_group);
	}
}
void PolyHedraFlesh::Belt(unsigned int len, unsigned int list0[], unsigned int list1[], bool f_direction, bool f_closed, unsigned int normal_group)
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
		Belt_Face(temp, f_direction, normal_group);
	}

	if (f_closed)
	{
		unsigned int temp[4] = {
			list0[n],
			list0[0],
			list1[n],
			list1[0],
		};
		Belt_Face(temp, f_direction, normal_group);
	}
}

void PolyHedraFlesh::Fan_Face(unsigned int middle, unsigned int blade[2], bool f_direction, bool f_middle, unsigned int normal_group)
{
	if (!f_direction)
	{
		if (!f_middle)
		{
			Insert_Face3(blade[0], middle, blade[1], normal_group);
		}
		else
		{
			Insert_Face3(blade[1], middle, blade[0], normal_group);
		}
	}
	else
	{
		if (!f_middle)
		{
			Insert_Face3(blade[1], middle, blade[0], normal_group);
		}
		else
		{
			Insert_Face3(blade[0], middle, blade[1], normal_group);
		}
	}
}
void PolyHedraFlesh::Fan(unsigned int len, unsigned int middle, unsigned int blade[], bool f_direction, bool f_middle, bool f_closed, unsigned int normal_group)
{
	unsigned int n = len - 1;

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int temp[2] = {
			blade[i + 0],
			blade[i + 1],
		};
		Fan_Face(middle, temp, f_direction, f_middle, normal_group);
	}

	if (f_closed)
	{
		unsigned int temp[2] = {
			blade[n],
			blade[0],
		};
		Fan_Face(middle, temp, f_direction, f_middle, normal_group);
	}
}

void PolyHedraFlesh::TrimData()
{
	Corners.Trim();
	Edges.Trim();
	Faces.Trim();

	// Face Normals
	// calculate when Faces are made ?
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
		}
		else
		{
			face.Normal = VectorF3();
		}
	}
}



#include "ValueType/Trans/3D.hpp"
void PolyHedraFlesh::Combine(const PolyHedraFlesh & other, const Trans3D & trans)
{
	unsigned int corner_offset = Corners.Count();
	unsigned int face_offset = Faces.Count();

	for (unsigned int i = 0; i < other.Corners.Count(); i++)
	{
		PolyHedraFlesh::Corner corner = other.Corners[i];
		corner.Position = trans.forward(corner.Position);
		Corners.Insert(corner);
	}

	for (unsigned int i = 0; i < other.Edges.Count(); i++)
	{
		PolyHedraFlesh::Edge edge = other.Edges[i];
		for (unsigned int j = 0; j < 2; j++)
		{
			if (edge.idx[j] != 0xFFFFFFFF)
			{
				edge.idx[j] += corner_offset;
			}
		}
		Edges.Insert(edge);
	}

	for (unsigned int i = 0; i < other.Faces.Count(); i++)
	{
		PolyHedraFlesh::Face face = other.Faces[i];
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



#include "ValueType/Box/F3.hpp"
BoxF3 PolyHedraFlesh::LimitBox() const
{
	BoxF3 box = BoxF3::InverseLimit();
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		box.Consider(Corners[i].Position);
	}
	return box;
}
