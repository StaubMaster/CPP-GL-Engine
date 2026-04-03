#ifndef  TRANS_2D_HPP
# define TRANS_2D_HPP

# include "Point2D.hpp"
# include "Angle2D.hpp"

struct Ray2D;
struct Line2D;

struct Trans2D
{
	Point2D		Pos; // Position
	Angle2D		Rot; // Rotation



	~Trans2D();

	Trans2D();
	Trans2D(Point2D pos);
	Trans2D(Point2D pos, Angle2D rot);

	Trans2D(const Trans2D & other);
	Trans2D & operator=(const Trans2D & other);



	Point2D		forward(Point2D p) const;
	Point2D		reverse(Point2D p) const;

	Ray2D		forward(Ray2D ray) const;
	Ray2D		reverse(Ray2D ray) const;
};

#endif
