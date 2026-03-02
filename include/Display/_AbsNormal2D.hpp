#ifndef  DISPLAY_ABSNORMAL2D_HPP
# define DISPLAY_ABSNORMAL2D_HPP

# include "ValueType/Point2D.hpp"

struct RelNormal2D;

struct AbsNormal2D : public Point2D
{
	AbsNormal2D();
	AbsNormal2D(const Point2D & other);

//	AbsNormal2D(const AbsNormal2D & other);
//	AbsNormal2D(const RelNormal2D & other);
//	AbsNormal2D & operator=(const AbsNormal2D & other);
//	AbsNormal2D & operator=(const RelNormal2D & other);

	RelNormal2D ToRelative() const;
};

#endif