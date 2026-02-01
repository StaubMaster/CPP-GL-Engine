#include "ValueType/View.hpp"



View::View() :
	Trans(),
	Depth(
		DepthFactors(0.1f, 1000.0f),
		Range(0.8f, 1.0f),
		ColorF4(0.5f, 0.5f, 0.5f)
	),
	FOV(Angle::Degrees(90))
{ }
View::~View()
{ }

View::View(const View & other) :
	Trans(other.Trans),
	Depth(other.Depth),
	FOV(other.FOV)
{ }
View & View::operator=(const View & other)
{
	Trans = other.Trans;
	Depth = other.Depth;
	FOV = other.FOV;
	return *this;
}



void View::TransformFlatX(Trans3D trans, float timeDelta)
{
	trans.Pos *= timeDelta;
	trans.Rot.X *= timeDelta;
	trans.Rot.Y *= timeDelta;
	trans.Rot.Z *= timeDelta;
	Trans.TransformFlatX(trans.Pos, trans.Rot);
	Trans.Rot.Y.Clamp();
	Trans.Rot.CalcMatrix();
}
