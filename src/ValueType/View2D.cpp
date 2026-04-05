#include "ValueType/View2D.hpp"



View2D::~View2D() { }

View2D::View2D()
	: Trans()
	, Scale(0.0f)
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
	view.Scale = 1.0f;
	return view;
}

void View2D::Change(Trans2D change, float timeDelta)
{
	change.Pos *= timeDelta;
	change.Rot *= timeDelta;

	Trans.Pos += Trans.Rot.forward(change.Pos);
	Trans.Rot += change.Rot;
}



Point2D View2D::forward(Point2D p) const { return Trans.forward(p * Scale); }
Point2D View2D::reverse(Point2D p) const { return Trans.reverse(p) / Scale; }
