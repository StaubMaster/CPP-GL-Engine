#include "PolyHedra/Skin/Skin2D_Data.hpp"



Skin2DFaceCorner::Skin2DFaceCorner() { }
Skin2DFaceCorner::Skin2DFaceCorner(Point2D tex) : Tex(tex.X, tex.Y, 0) { }
Skin2DFaceCorner::Skin2DFaceCorner(Point3D tex) : Tex(tex) { }
Skin2DFaceCorner::Skin2DFaceCorner(float tex_x, float tex_y, float tex_z) : Tex(tex_x, tex_y, tex_z) { }

Skin2DFace::Skin2DFace() { }
Skin2DFace::Skin2DFace(Skin2DFaceCorner corn0, Skin2DFaceCorner corn1, Skin2DFaceCorner corn2) : Corner0(corn0), Corner1(corn1), Corner2(corn2) { }
