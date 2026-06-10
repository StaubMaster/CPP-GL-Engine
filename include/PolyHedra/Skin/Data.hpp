#ifndef  SKIN_DATA_HPP
# define SKIN_DATA_HPP

# include "Skin.hpp"

# include "ValueType/Vector/F3.hpp"

struct Skin::Face
{
	VectorF3	Corner[3];
	Face();
	Face(VectorF3 corn0, VectorF3 corn1, VectorF3 corn2);
};

#endif
