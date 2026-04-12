#include "ValueType/VectorI2.hpp"



VectorI2::~VectorI2() { }

VectorI2::VectorI2()
	: Vector_2()
{ }
VectorI2::VectorI2(int value)
	: Vector_2(value)
{ }
VectorI2::VectorI2(int x, int y)
	: Vector_2(x, y)
{ }

VectorI2::VectorI2(const VectorI2 & other)
	: Vector_2(other)
{ }
VectorI2 & VectorI2::operator=(const VectorI2 & other)
{
	Vector_2::operator=(other);
	return *this;
}



VectorI2 VectorI2::operator%(const VectorI2 & other) const { return VectorI2(X % other.X, Y % other.Y); }

VectorI2 VectorI2::operator~() const { return VectorI2(~X, ~Y); }
VectorI2 VectorI2::operator&(const VectorI2 & other) const { return VectorI2(X & other.X, Y & other.Y); }
VectorI2 VectorI2::operator|(const VectorI2 & other) const { return VectorI2(X | other.X, Y | other.Y); }
VectorI2 VectorI2::operator^(const VectorI2 & other) const { return VectorI2(X ^ other.X, Y ^ other.Y); }
VectorI2 VectorI2::operator<<(const VectorI2 & other) const { return VectorI2(X << other.X, Y << other.Y); }
VectorI2 VectorI2::operator>>(const VectorI2 & other) const { return VectorI2(X >> other.X, Y >> other.Y); }



int VectorI2::Product() const { return X * Y; }

int VectorI2::Convert(VectorI2 idx) const
{
	return (idx.X) + (idx.Y * X);
}
VectorI2 VectorI2::Convert(int idx) const
{
	VectorI2 vec;
	vec.X = idx % X; idx = idx / X;
//	vec.Y = idx % Y;
	vec.Y = idx;
	return vec;
}

int VectorI2::Convert(int size, VectorI2 idx)
{
	return (idx.X) + (idx.Y * size);
}
VectorI2 VectorI2::Convert(int size, int idx)
{
	VectorI2 vec;
	vec.X = idx % size; idx = idx / size;
//	vec.Y = idx % size;
	vec.Y = idx;
	return vec;
}



/*
bool	VectorI2::Box_inclusive(VectorI2 idx, VectorI2 min, VectorI2 max)
{
	return	(idx.X >= min.X && idx.X <= max.X) &&
			(idx.Y >= min.Y && idx.Y <= max.Y);
}
bool	VectorI2::Box_exclusive(VectorI2 idx, VectorI2 min, VectorI2 max)
{
	return	(idx.X > min.X && idx.X < max.X) &&
			(idx.Y > min.Y && idx.Y < max.Y);
}

bool VectorI2::loop_inclusive(VectorI2 & idx, VectorI2 min, VectorI2 max)
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
bool VectorI2::loop_exclusive(VectorI2 & idx, VectorI2 min, VectorI2 max)
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
bool VectorI2::loop_inclusive(VectorI2 & idx, int min, int max)
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
bool VectorI2::loop_exclusive(VectorI2 & idx, int min, int max)
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