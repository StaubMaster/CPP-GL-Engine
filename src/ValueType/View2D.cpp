#include "View2D.hpp"



View2D::View2D()
	: Pos()
	, Rot()
	, Scale(0.0f)
{ }
View2D::~View2D()
{ }

View2D::View2D(const View2D & other)
	: Pos(other.Pos)
	, Rot(other.Rot)
	, Scale(other.Scale)
{ }
View2D & View2D::operator=(const View2D & other)
{
	Pos = other.Pos;
	Rot = other.Rot;
	Scale = other.Scale;
	return *this;
}



View2D View2D::Default()
{
	View2D view;
	view.Scale = 10.0f;
	return view;
}



void View2D::Transform(Point2D move, Angle2D spin, float timeDelta)
{
	move = Rot.rotateBack(move);
	Pos += move * timeDelta;
	Rot.Ang += spin.Ang * timeDelta;
	Rot.CalcMatrix();
}
