#ifndef  TRANS_2D_HPP
# define TRANS_2D_HPP

# include "Point2D.hpp"
# include "Angle2D.hpp"

struct Trans2D
{
	public:
	Point2D	Pos;
	Angle2D	Rot;

	public:
	Trans2D();
	Trans2D(Point2D pos, Angle2D rot);
	~Trans2D();

	Trans2D(const Trans2D & other);
	Trans2D & operator=(const Trans2D & other);

	public:
	void Move(Point2D move);
	void Spin(Angle2D spin);
	void Transform(Point2D move, Angle2D spin);
};

#endif
