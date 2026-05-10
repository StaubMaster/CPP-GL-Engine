#include "ValueType/View3D.hpp"



View3D::~View3D() { }

View3D::View3D()
	: Trans()
	, Depth(
		DepthFactors(0.1f, 1000.0f),
		Range(0.8f, 1.0f),
		ColorF4(0.5f, 0.5f, 0.5f)
	)
	, FOV(Angle::Degrees(90))
{ }

View3D::View3D(const View3D & other)
	: Trans(other.Trans)
	, Depth(other.Depth)
	, FOV(other.FOV)
{ }
View3D & View3D::operator=(const View3D & other)
{
	Trans = other.Trans;
	Depth = other.Depth;
	FOV = other.FOV;
	return *this;
}

View3D View3D::Default()
{
	View3D view;
	return view;
}



void View3D::ChangeFlatX(Trans3D trans, float timeDelta)
{
	trans.Position *= timeDelta;
	trans.Rotation *= timeDelta;
	{
		EulerAngle3D e(Angle(), Angle(), Trans.Rotation.Y2);
		Trans.Position += e.forward(trans.Position);
		Trans.Rotation += trans.Rotation;
	}
	Trans.Rotation.X1.clampPI();
}



//VectorF3 View3D::forward(VectorF3 p) const { }
//VectorF3 View3D::reverse(VectorF3 p) const { }
