#include "PolyHedra/Data.hpp"

PolyHedra::Corner::Corner() { }
PolyHedra::Corner::Corner(Point3D pos) : Position(pos) { }

PolyHedra::FaceCorner::FaceCorner() { }
PolyHedra::FaceCorner::FaceCorner(unsigned int udx) : Udx(udx) { }

PolyHedra::Face::Face() { }
PolyHedra::Face::Face(FaceCorner c0, FaceCorner c1, FaceCorner c2) : Corner0(c0), Corner1(c1), Corner2(c2) { }
