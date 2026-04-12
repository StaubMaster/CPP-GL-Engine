#include "ValueType/VectorU2.hpp"

#include "ValueType/VectorF2.hpp"
#include "ValueType/VectorI2.hpp"



VectorU2::~VectorU2() { }

VectorU2::VectorU2() : Vector_2() { }
VectorU2::VectorU2(unsigned int value) : Vector_2(value) { }
VectorU2::VectorU2(unsigned int x, unsigned int y) : Vector_2(x, y) { }

VectorU2::VectorU2(const VectorF2 & other) : Vector_2(other) { }
VectorU2::VectorU2(const VectorU2 & other) : Vector_2(other) { }
VectorU2::VectorU2(const VectorI2 & other) : Vector_2(other) { }

VectorU2 & VectorU2::operator=(const VectorF2 & other) { Vector_2::operator=(other); return *this; }
VectorU2 & VectorU2::operator=(const VectorU2 & other) { Vector_2::operator=(other); return *this; }
VectorU2 & VectorU2::operator=(const VectorI2 & other) { Vector_2::operator=(other); return *this; }



VectorU2 VectorU2::operator%(const VectorU2 & other) const { return VectorU2(X % other.X, Y % other.Y); }

VectorU2 VectorU2::operator~() const { return VectorU2(~X, ~Y); }
VectorU2 VectorU2::operator&(const VectorU2 & other) const { return VectorU2(X & other.X, Y & other.Y); }
VectorU2 VectorU2::operator|(const VectorU2 & other) const { return VectorU2(X | other.X, Y | other.Y); }
VectorU2 VectorU2::operator^(const VectorU2 & other) const { return VectorU2(X ^ other.X, Y ^ other.Y); }
VectorU2 VectorU2::operator<<(const VectorU2 & other) const { return VectorU2(X << other.X, Y << other.Y); }
VectorU2 VectorU2::operator>>(const VectorU2 & other) const { return VectorU2(X >> other.X, Y >> other.Y); }



unsigned int VectorU2::Product() const { return X * Y; }

unsigned int VectorU2::Convert(VectorU2 udx) const
{
	return (udx.X) + (udx.Y * X);
}
VectorU2 VectorU2::Convert(unsigned int udx) const
{
	VectorU2 vec;
	vec.X = udx % X; udx = udx / X;
//	vec.Y = udx % Y;
	vec.Y = udx;
	return vec;
}

unsigned int VectorU2::Convert(unsigned int size, VectorU2 udx)
{
	return (udx.X) + (udx.Y * size);
}
VectorU2 VectorU2::Convert(unsigned int size, unsigned int udx)
{
	VectorU2 vec;
	vec.X = udx % size; udx = udx / size;
//	vec.Y = udx % size;
	vec.Y = udx;
	return vec;
}



/*
bool	VectorU2::Box_inclusive(VectorU2 idx, VectorU2 min, VectorU2 max)
{
	return	(idx.X >= min.X && idx.X <= max.X) &&
			(idx.Y >= min.Y && idx.Y <= max.Y);
}
bool	VectorU2::Box_exclusive(VectorU2 idx, VectorU2 min, VectorU2 max)
{
	return	(idx.X > min.X && idx.X < max.X) &&
			(idx.Y > min.Y && idx.Y < max.Y);
}

bool VectorU2::loop_inclusive(VectorU2 & idx, VectorU2 min, VectorU2 max)
{
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
	return (true);
}
bool VectorU2::loop_exclusive(VectorU2 & idx, VectorU2 min, VectorU2 max)
{
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
	return (true);
}
bool VectorU2::loop_inclusive(VectorU2 & idx, unsigned int min, unsigned int max)
{
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
	return (true);
}
bool VectorU2::loop_exclusive(VectorU2 & idx, unsigned int min, unsigned int max)
{
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
	return (true);
}
*/