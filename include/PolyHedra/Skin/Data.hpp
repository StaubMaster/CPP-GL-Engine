#ifndef  SKIN_DATA_HPP
# define SKIN_DATA_HPP

# include "Skin.hpp"

# include "ValueType/Vector/F3.hpp"

struct Skin::Face
{
	// Use Vec2 for Texture Coord
	// use unsigned int for Index

	// init Index as 0xFFFFFFFF
	// if there are any 0xFFFFFFFF Indexes
	//   generate an Empty Skin
	//   use that for undefined Vertexes

	VectorF3	Corner[3];
	Face();
	Face(VectorF3 corn0, VectorF3 corn1, VectorF3 corn2);
};

#endif
