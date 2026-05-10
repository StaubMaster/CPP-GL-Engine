#include "ValueType/Vector/U3.hpp"



VectorU3::VectorU3() :
	X(0),
	Y(0),
	Z(0)
{ }
VectorU3::VectorU3(unsigned int x, unsigned int y, unsigned int z) :
	X(x),
	Y(y),
	Z(z)
{ }
VectorU3::~VectorU3()
{ }



VectorU3::VectorU3(const VectorU3 & other) :
	X(other.X),
	Y(other.Y),
	Z(other.Z)
{ }
VectorU3 & VectorU3::operator=(const VectorU3 & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return (*this);
}



VectorU3 VectorU3::operator+(const VectorU3 & other) const
{
	return VectorU3(
		X + other.X,
		Y + other.Y,
		Z + other.Z
	);
}
VectorU3 VectorU3::operator-(const VectorU3 & other) const
{
	return VectorU3(
		X - other.X,
		Y - other.Y,
		Z - other.Z
	);
}



VectorU3 VectorU3::operator%(const VectorU3 & other) const
{
	return VectorU3(
		X % other.X,
		Y % other.Y,
		Z % other.Z
	);
}



Bool3 VectorU3::operator==(const VectorU3 & other) const
{
	return Bool3(
		X == other.X,
		Y == other.Y,
		Z == other.Z
	);
}
Bool3 VectorU3::operator<=(const VectorU3 & other) const
{
	return Bool3(
		X <= other.X,
		Y <= other.Y,
		Z <= other.Z
	);
}
Bool3 VectorU3::operator>=(const VectorU3 & other) const
{
	return Bool3(
		X >= other.X,
		Y >= other.Y,
		Z >= other.Z
	);
}
Bool3 VectorU3::operator!=(const VectorU3 & other) const
{
	return Bool3(
		X != other.X,
		Y != other.Y,
		Z != other.Z
	);
}
Bool3 VectorU3::operator<(const VectorU3 & other) const
{
	return Bool3(
		X < other.X,
		Y < other.Y,
		Z < other.Z
	);
}
Bool3 VectorU3::operator>(const VectorU3 & other) const
{
	return Bool3(
		X > other.X,
		Y > other.Y,
		Z > other.Z
	);
}



bool	VectorU3::Box_inclusive(VectorU3 idx, VectorU3 min, VectorU3 max)
{
	return	(idx.X >= min.X && idx.X <= max.X) &&
			(idx.Y >= min.Y && idx.Y <= max.Y) &&
			(idx.Z >= min.Z && idx.Z <= max.Z);
}
bool	VectorU3::Box_exclusive(VectorU3 idx, VectorU3 min, VectorU3 max)
{
	return	(idx.X > min.X && idx.X < max.X) &&
			(idx.Y > min.Y && idx.Y < max.Y) &&
			(idx.Z > min.Z && idx.Z < max.Z);
}



bool VectorU3::loop_inclusive(VectorU3 & idx, VectorU3 min, VectorU3 max)
{
	idx.Z++;
	if (idx.Z > max.Z)
	{
		idx.Z = min.Z;
		idx.Y++;
		if (idx.Y > max.Y)
		{
			idx.Y = min.Y;
			idx.X++;
			if (idx.X > max.X)
			{
				idx.X = min.X;
				return (false);
			}
		}
	}
	return (true);
}
bool VectorU3::loop_exclusive(VectorU3 & idx, VectorU3 min, VectorU3 max)
{
	idx.Z++;
	if (idx.Z >= max.Z)
	{
		idx.Z = min.Z;
		idx.Y++;
		if (idx.Y >= max.Y)
		{
			idx.Y = min.Y;
			idx.X++;
			if (idx.X >= max.X)
			{
				idx.X = min.X;
				return (false);
			}
		}
	}
	return (true);
}
bool VectorU3::loop_inclusive(VectorU3 & idx, unsigned int min, unsigned int max)
{
	idx.Z++;
	if (idx.Z > max)
	{
		idx.Z = min;
		idx.Y++;
		if (idx.Y > max)
		{
			idx.Y = min;
			idx.X++;
			if (idx.X > max)
			{
				idx.X = min;
				return (false);
			}
		}
	}
	return (true);
}
bool VectorU3::loop_exclusive(VectorU3 & idx, unsigned int min, unsigned int max)
{
	idx.Z++;
	if (idx.Z >= max)
	{
		idx.Z = min;
		idx.Y++;
		if (idx.Y >= max)
		{
			idx.Y = min;
			idx.X++;
			if (idx.X >= max)
			{
				idx.X = min;
				return (false);
			}
		}
	}
	return (true);
}





/*std::ostream & operator <<(std::ostream & o, const VectorU3 & u)
{
	o << "[" << u.X << ":" << u.Y << ":" << u.Z << "]";
	return o;
}*/
