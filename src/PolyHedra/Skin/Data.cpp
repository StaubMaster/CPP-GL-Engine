#include "PolyHedra/Skin/Data.hpp"



Skin::Face::Face()
{ }
Skin::Face::Face(VectorF3 corn0, VectorF3 corn1, VectorF3 corn2)
	: Corner{
		corn0,
		corn1,
		corn2,
	}
{ }
