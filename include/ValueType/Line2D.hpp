#ifndef  LINE_2D_HPP
# define LINE_2D_HPP

# include "ValueType/Point2D.hpp"

struct Line2D
{
	public:
	Point2D Pos0;
	Point2D Pos1;

	public:
	~Line2D();

	Line2D();
	Line2D(Point2D pos0, Point2D pos1);

	Line2D(const Line2D & other);
	Line2D & operator=(const Line2D & other);
};

#endif