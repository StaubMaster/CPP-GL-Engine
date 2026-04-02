#include "ValueType/View3D.hpp"



View3D::View3D() :
	Trans(),
	Depth(
		DepthFactors(0.1f, 1000.0f),
		Range(0.8f, 1.0f),
		ColorF4(0.5f, 0.5f, 0.5f)
	),
	FOV(Angle::Degrees(90))
{ }
View3D::~View3D()
{ }

View3D::View3D(const View3D & other) :
	Trans(other.Trans),
	Depth(other.Depth),
	FOV(other.FOV)
{ }
View3D & View3D::operator=(const View3D & other)
{
	Trans = other.Trans;
	Depth = other.Depth;
	FOV = other.FOV;
	return *this;
}



void View3D::TransformFlatX(Trans3D trans, float timeDelta)
{
	trans.Position *= timeDelta;
	trans.Rotation *= timeDelta;
	{
		EulerAngle3D e(Trans.Rotation.Y2, Angle(), Angle());
		Trans.Position += e.Reverse(trans.Position);
		Trans.Rotation += trans.Rotation;
	}
	Trans.Rotation.Y2.Clamp();
}
