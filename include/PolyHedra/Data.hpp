#ifndef  POLYHEDRA_DATA_HPP
# define POLYHEDRA_DATA_HPP

# include "PolyHedra.hpp"

# include "ValueType/Vector/F3.hpp"

struct PolyHedra::Corner
{
	VectorF3 Position;
	VectorF3 Normal;
	Corner();
	Corner(VectorF3 pos);
};
struct PolyHedra::Face
{
	unsigned int udx[3];
	VectorF3 Normal;
	Face();
	Face(unsigned int u0, unsigned int u1, unsigned int u2);
	bool Check(unsigned int count) const;
};
struct PolyHedra::Edge
{
	unsigned int udx[2];
	Edge();
	Edge(unsigned int u0, unsigned int u1);
	bool Check(unsigned int count) const;
};

#endif