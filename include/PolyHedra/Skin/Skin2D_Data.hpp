#ifndef  SKIN_2D_DATA_HPP
# define SKIN_2D_DATA_HPP

# include "ValueType/Vector/F3.hpp"
# include "ValueType/Vector/F2.hpp"

struct Skin2DCorner
{

};

struct Skin2DFaceCorner
{
	VectorF3	Tex;

	Skin2DFaceCorner();
	Skin2DFaceCorner(VectorF3 tex);
	Skin2DFaceCorner(float tex_x, float tex_y, float tex_z);
};

struct Skin2DFace
{
	Skin2DFaceCorner	Corner0;
	Skin2DFaceCorner	Corner1;
	Skin2DFaceCorner	Corner2;

	Skin2DFace();
	Skin2DFace(Skin2DFaceCorner corn0, Skin2DFaceCorner corn1, Skin2DFaceCorner corn2);
};

#endif
