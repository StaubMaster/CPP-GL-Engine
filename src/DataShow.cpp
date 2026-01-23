#include "DataShow.hpp"
#include "DataInclude.hpp"
#include <iostream>



std::ostream & operator <<(std::ostream & o, const Point2D & val)
{
	o << "( " << val.X << " | " << val.Y << " )";
	return o;
}
std::ostream & operator <<(std::ostream & o, const Point3D & val)
{
	o << "( " << val.X << " | " << val.Y << " | " << val.Z << " )";
	return o;
}
std::ostream & operator <<(std::ostream & o, const Point4D & val)
{
	o << "( " << val.X << " | " << val.Y << " | " << val.Z << " | " << val.W << " )";
	return o;
}



std::ostream & operator <<(std::ostream & o, const Angle3D & val)
{
	o << "( " << val.X << " | " << val.Y << " | " << val.Z << " )";
	//o << "#( " << val.sin_x << " | " << val.sin_y << " | " << val.sin_z << " )";
	//o << "#( " << val.cos_x << " | " << val.cos_y << " | " << val.cos_z << " )";
	return o;
}



std::ostream & operator <<(std::ostream & o, const Trans3D & val)
{
	o << "{ " << val.Pos << " | " << val.Rot << " }";
	return o;
}



std::ostream & operator <<(std::ostream & o, const AxisBox1D & val)
{
	o << "{ " << val.Min << " : " << val.Max << " }";
	return o;
}
std::ostream & operator <<(std::ostream & o, const AxisBox2D & val)
{
	o << "{ " << val.Min << " : " << val.Max << " }";
	return o;
}
std::ostream & operator <<(std::ostream & o, const AxisBox3D & val)
{
	o << "{ " << val.Min << " : " << val.Max << " }";
	return o;
}



std::ostream & operator <<(std::ostream & o, const Undex3D & val)
{
	o << "[" << val.X << ":" << val.Y << ":" << val.Z << "]";
	return o;
}
std::ostream & operator <<(std::ostream & o, const UndexBox3D & val)
{
	o << "{ " << val.Min << " : " << val.Max << " }";
	return o;
}



std::ostream & operator <<(std::ostream & o, const Bool3D & val)
{
	o << "( ";
	if (val.GetX()) { o << "true"; } else { o << "false"; }
	o << " : ";
	if (val.GetY()) { o << "true"; } else { o << "false"; }
	o << " : ";
	if (val.GetZ()) { o << "true"; } else { o << "false"; }
	o << " )";
	
	return o;
}



std::ostream & operator <<(std::ostream & o, const ColorF4 & val)
{
	o << "(" << " R:" << val.R << " G:" << val.G << " B:" << val.B << " A:" << val.A << " )";
	return o;
}
