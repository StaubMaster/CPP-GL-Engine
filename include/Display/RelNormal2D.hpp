#ifndef  DISPLAY_RELNORMAL2D_HPP
# define DISPLAY_RELNORMAL2D_HPP

# include "ValueType/Point2D.hpp"

struct AbsNormal2D;

struct RelNormal2D : public Point2D
{
	RelNormal2D();
	RelNormal2D(const Point2D & other);

//	RelNormal2D(const RelNormal2D & other);
//	RelNormal2D(const AbsNormal2D & other);
//	RelNormal2D & operator=(const RelNormal2D & other);
//	RelNormal2D & operator=(const AbsNormal2D & other);

	AbsNormal2D ToAbsolute() const;
};

#endif