#include "DataShow.hpp"
#include "DataInclude.hpp"
#include <iostream>



std::ostream & operator <<(std::ostream & o, const Point2D & obj)
{
	o << "( " << obj.X << " | " << obj.Y << " )";
	return o;
}
std::ostream & operator <<(std::ostream & o, const Point3D & obj)
{
	o << "( " << obj.X << " | " << obj.Y << " | " << obj.Z << " )";
	return o;
}
std::ostream & operator <<(std::ostream & o, const Point4D & obj)
{
	o << "( " << obj.X << " | " << obj.Y << " | " << obj.Z << " | " << obj.W << " )";
	return o;
}



std::ostream & operator <<(std::ostream & o, const Angle & obj)
{
	//o << obj.ToRadians();
	o << obj.ToDegrees() << "°";
	return o;
}
std::ostream & operator <<(std::ostream & o, const Angle3D & obj)
{
	o << "( " << obj.X << " | " << obj.Y << " | " << obj.Z << " )";
	//o << "#( " << obj.sin_x << " | " << obj.sin_y << " | " << obj.sin_z << " )";
	//o << "#( " << obj.cos_x << " | " << obj.cos_y << " | " << obj.cos_z << " )";
	return o;
}



std::ostream & operator <<(std::ostream & o, const Trans3D & obj)
{
	o << "{ " << obj.Pos << " | " << obj.Rot << " }";
	return o;
}



std::ostream & operator <<(std::ostream & o, const AxisBox1D & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}
std::ostream & operator <<(std::ostream & o, const AxisBox2D & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}
std::ostream & operator <<(std::ostream & o, const AxisBox3D & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}



std::ostream & operator <<(std::ostream & o, const Undex3D & obj)
{
	o << "[" << obj.X << ":" << obj.Y << ":" << obj.Z << "]";
	return o;
}
std::ostream & operator <<(std::ostream & o, const UndexBox3D & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}



std::ostream & operator <<(std::ostream & o, const Bool3D & obj)
{
	o << "( ";
	if (obj.GetX()) { o << "true"; } else { o << "false"; }
	o << " : ";
	if (obj.GetY()) { o << "true"; } else { o << "false"; }
	o << " : ";
	if (obj.GetZ()) { o << "true"; } else { o << "false"; }
	o << " )";
	
	return o;
}



std::ostream & operator <<(std::ostream & o, const ColorF4 & obj)
{
	o << "(" << " R:" << obj.R << " G:" << obj.G << " B:" << obj.B << " A:" << obj.A << " )";
	return o;
}
