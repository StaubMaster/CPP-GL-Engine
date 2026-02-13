#include "ValueType/Undex2D.hpp"



Undex2D::Undex2D() :
	X(0),
	Y(0)
{ }
Undex2D::Undex2D(unsigned int x, unsigned int y) :
	X(x),
	Y(y)
{ }
Undex2D::~Undex2D()
{ }



Undex2D::Undex2D(const Undex2D & other) :
	X(other.X),
	Y(other.Y)
{ }
Undex2D & Undex2D::operator=(const Undex2D & other)
{
	X = other.X;
	Y = other.Y;
	return (*this);
}



Undex2D Undex2D::operator+(const Undex2D & other) const
{
	return Undex2D(
		X + other.X,
		Y + other.Y
	);
}
Undex2D Undex2D::operator-(const Undex2D & other) const
{
	return Undex2D(
		X - other.X,
		Y - other.Y
	);
}



Undex2D Undex2D::operator%(const Undex2D & other) const
{
	return Undex2D(
		X % other.X,
		Y % other.Y
	);
}



Bool2D Undex2D::operator==(const Undex2D & other) const
{
	return Bool2D(
		X == other.X,
		Y == other.Y
	);
}
Bool2D Undex2D::operator<=(const Undex2D & other) const
{
	return Bool2D(
		X <= other.X,
		Y <= other.Y
	);
}
Bool2D Undex2D::operator>=(const Undex2D & other) const
{
	return Bool2D(
		X >= other.X,
		Y >= other.Y
	);
}
Bool2D Undex2D::operator!=(const Undex2D & other) const
{
	return Bool2D(
		X != other.X,
		Y != other.Y
	);
}
Bool2D Undex2D::operator<(const Undex2D & other) const
{
	return Bool2D(
		X < other.X,
		Y < other.Y
	);
}
Bool2D Undex2D::operator>(const Undex2D & other) const
{
	return Bool2D(
		X > other.X,
		Y > other.Y
	);
}



bool	Undex2D::Box_inclusive(Undex2D idx, Undex2D min, Undex2D max)
{
	return	(idx.X >= min.X && idx.X <= max.X) &&
			(idx.Y >= min.Y && idx.Y <= max.Y);
}
bool	Undex2D::Box_exclusive(Undex2D idx, Undex2D min, Undex2D max)
{
	return	(idx.X > min.X && idx.X < max.X) &&
			(idx.Y > min.Y && idx.Y < max.Y);
}



bool Undex2D::loop_inclusive(Undex2D & idx, Undex2D min, Undex2D max)
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
bool Undex2D::loop_exclusive(Undex2D & idx, Undex2D min, Undex2D max)
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
bool Undex2D::loop_inclusive(Undex2D & idx, unsigned int min, unsigned int max)
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
bool Undex2D::loop_exclusive(Undex2D & idx, unsigned int min, unsigned int max)
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





/*std::ostream & operator <<(std::ostream & o, const Undex2D & u)
{
	o << "[" << u.X << ":" << u.Y << ":" << u.Z << "]";
	return o;
}*/
