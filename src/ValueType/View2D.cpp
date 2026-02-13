#include "ValueType/View2D.hpp"



View2D::View2D()
	: Trans()
	, Scale(0.0f)
{ }
View2D::~View2D()
{ }

View2D::View2D(const View2D & other)
	: Trans(other.Trans)
	, Scale(other.Scale)
{ }
View2D & View2D::operator=(const View2D & other)
{
	Trans = other.Trans;
	Scale = other.Scale;
	return *this;
}



View2D View2D::Default()
{
	View2D view;
	view.Scale = 10.0f;
	return view;
}



void View2D::Transform(Trans2D trans, float timeDelta)
{
	trans.Pos *= timeDelta;
	trans.Rot.Ang *= timeDelta;
	Trans.Transform(trans.Pos, trans.Rot);
	Trans.Rot.CalcMatrix();
}
