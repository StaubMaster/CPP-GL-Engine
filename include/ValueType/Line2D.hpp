#ifndef  LINE_2D_HPP
# define LINE_2D_HPP

# include "ValueType/Point2D.hpp"

struct Ray2D;

struct Line2D
{
	public:
	Point2D Origin;
	Point2D Target;

	public:
	~Line2D();

	Line2D();
	Line2D(Point2D origin, Point2D target);
	
	Line2D(const Line2D & other);
	Line2D & operator=(const Line2D & other);
	
	Line2D(const Ray2D & ray);



	Line2D Reverse() const;

	Point2D Differance() const;
	float Length() const;

	Point2D Middle() const;
	Point2D Normal() const;
};

#endif