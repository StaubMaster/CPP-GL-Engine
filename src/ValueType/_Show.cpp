#include "ValueType/_Show.hpp"
#include "ValueType/_Include.hpp"

#include <iostream>


static const char * ToString(bool val) { if (val) { return "true"; } else { return "false"; } }

/*
"( "	" )"
"{ "	" }"
"[ "	" ]"
" | "	" : "
*/

std::ostream & operator<<(std::ostream & o, const Bool2 & obj) { return o << "( " << ToString(obj.GetX()) << " : " << ToString(obj.GetY()) << " )"; }
std::ostream & operator<<(std::ostream & o, const Bool3 & obj) { return o << "( " << ToString(obj.GetX()) << " : " << ToString(obj.GetY()) << " : " << ToString(obj.GetZ()) << " )"; }
std::ostream & operator<<(std::ostream & o, const Bool4 & obj) { return o << "( " << ToString(obj.GetX()) << " : " << ToString(obj.GetY()) << " : " << ToString(obj.GetZ()) << " : " << ToString(obj.GetW()) << " )"; }



std::ostream & operator<<(std::ostream & o, const VectorF2 & obj) { return o << "( " << obj.X << " | " << obj.Y << " )"; }
std::ostream & operator<<(std::ostream & o, const VectorF3 & obj) { return o << "( " << obj.X << " | " << obj.Y << " | " << obj.Z << " )"; }
std::ostream & operator<<(std::ostream & o, const VectorF4 & obj) { return o << "( " << obj.X << " | " << obj.Y << " | " << obj.Z << " | " << obj.W << " )"; }

std::ostream & operator<<(std::ostream & o, const BoxF1 & obj) { return o << "{ " << obj.Min << " : " << obj.Max << " }"; }
std::ostream & operator<<(std::ostream & o, const BoxF2 & obj) { return o << "{ " << obj.Min << " : " << obj.Max << " }"; }
std::ostream & operator<<(std::ostream & o, const BoxF3 & obj) { return o << "{ " << obj.Min << " : " << obj.Max << " }"; }



std::ostream & operator<<(std::ostream & o, const VectorU2 & obj) { return o << "[ " << obj.X << " | " << obj.Y << " ]"; }
std::ostream & operator<<(std::ostream & o, const VectorU3 & obj) { return o << "[ " << obj.X << " | " << obj.Y << " | " << obj.Z << " ]"; }

std::ostream & operator<<(std::ostream & o, const BoxU2 & obj) { return o << "{ " << obj.Min << " : " << obj.Max << " }"; }
std::ostream & operator<<(std::ostream & o, const BoxU3 & obj) { return o << "{ " << obj.Min << " : " << obj.Max << " }"; }



std::ostream & operator<<(std::ostream & o, const VectorI2 & obj) { return o << "[ " << obj.X << " | " << obj.Y << " ]"; }
std::ostream & operator<<(std::ostream & o, const VectorI3 & obj) { return o << "[ " << obj.X << " | " << obj.Y << " | " << obj.Z << " ]"; }

std::ostream & operator<<(std::ostream & o, const BoxI2 & obj) { return o << "{ " << obj.Min << " : " << obj.Max << " }"; }
std::ostream & operator<<(std::ostream & o, const BoxI3 & obj) { return o << "{ " << obj.Min << " : " << obj.Max << " }"; }



/*std::ostream & operator<<(std::ostream & o, const VectorF2 & obj)
{
	o << "( " << obj.X << " | " << obj.Y << " )";
	return o;
}*/
/*std::ostream & operator<<(std::ostream & o, const VectorF3 & obj)
{
	o << "( " << obj.X << " | " << obj.Y << " | " << obj.Z << " )";
	return o;
}*/
/*std::ostream & operator<<(std::ostream & o, const VectorF4 & obj)
{
	o << "( " << obj.X << " | " << obj.Y << " | " << obj.Z << " | " << obj.W << " )";
	return o;
}*/

/*std::ostream & operator<<(std::ostream & o, const BoxF1 & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}*/
/*std::ostream & operator<<(std::ostream & o, const BoxF2 & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}*/
/*std::ostream & operator<<(std::ostream & o, const BoxF3 & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}*/

//std::ostream & operator<<(std::ostream & o, const Line2D & obj) { return o; }
//std::ostream & operator<<(std::ostream & o, const Line3D & obj) { return o; }

//std::ostream & operator<<(std::ostream & o, const Ray2D & obj) { return o; }
//std::ostream & operator<<(std::ostream & o, const Ray3D & obj) { return o; }

std::ostream & operator<<(std::ostream & o, const Angle & obj)
{
	//o << obj.ToRadians();
	o << obj.ToDegrees() << "°";
	return o;
}
std::ostream & operator<<(std::ostream & o, const EulerAngle3D & obj)
{
	o << "( Z: " << obj.Z0 << " | X: " << obj.X1 << " | Y: " << obj.Y2 << " )";
	return o;
}

std::ostream & operator<<(std::ostream & o, const Trans2D & obj)
{
	o << "{ " << obj.Pos << " | " << obj.Rot << " }";
	return o;
}
std::ostream & operator<<(std::ostream & o, const Trans3D & obj)
{
	o << "{ " << obj.Position << " | " << obj.Rotation << " }";
	return o;
}



std::ostream & operator<<(std::ostream & o, const ColorF4 & obj)
{
	o << "(" << " R:" << obj.R << " G:" << obj.G << " B:" << obj.B << " A:" << obj.A << " )";
	return o;
}



/*std::ostream & operator<<(std::ostream & o, const Bool2 & obj)
{
	o << "( ";
	if (obj.GetX()) { o << "true"; } else { o << "false"; }
	o << " : ";
	if (obj.GetY()) { o << "true"; } else { o << "false"; }
	o << " )";
	return o;
}*/
/*std::ostream & operator<<(std::ostream & o, const Bool3 & obj)
{
	o << "( ";
	if (obj.GetX()) { o << "true"; } else { o << "false"; }
	o << " : ";
	if (obj.GetY()) { o << "true"; } else { o << "false"; }
	o << " : ";
	if (obj.GetZ()) { o << "true"; } else { o << "false"; }
	o << " )";
	return o;
}*/

std::ostream & operator<<(std::ostream & o, const Undex & obj)
{
	if (obj.IsValid())
	{
		o << "[" << obj.Value << "]";
	}
	else
	{
		o << "[!]";
	}
	return o;
}

/*std::ostream & operator<<(std::ostream & o, const VectorU2 & obj)
{
	o << "[" << obj.X << ":" << obj.Y << "]";
	return o;
}*/
/*std::ostream & operator<<(std::ostream & o, const UndexBox2D & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}*/

/*std::ostream & operator<<(std::ostream & o, const VectorU3 & obj)
{
	o << "[" << obj.X << ":" << obj.Y << ":" << obj.Z << "]";
	return o;
}*/
/*std::ostream & operator<<(std::ostream & o, const UndexBox3D & obj)
{
	o << "{ " << obj.Min << " : " << obj.Max << " }";
	return o;
}*/
