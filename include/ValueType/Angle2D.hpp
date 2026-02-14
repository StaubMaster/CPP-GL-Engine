#ifndef  ANGLE_2D_HPP
# define ANGLE_2D_HPP

# include "Angle.hpp"
# include "Matrix2x2.hpp"

struct Point2D;

struct Angle2D
{
	public:
	Angle	Ang;

	public:
	Matrix2x2	Mat;

	public:
	Angle2D();
	Angle2D(Angle ang);
	~Angle2D();

	Angle2D(const Angle2D & other);
	const Angle2D & operator=(const Angle2D & other);

	static Angle2D FromPoint2D(const Point2D & dir);

	public:
	void	CalcMatrix();

	public:
	Point2D rotateFore(Point2D p) const;
	Point2D rotateBack(Point2D p) const;
	Angle2D	rotateFore(Angle2D a) const;
	Angle2D	rotateBack(Angle2D a) const;

	public:
	Angle2D		operator+(const Angle2D & other) const;
	Angle2D		operator-(const Angle2D & other) const;
	Angle2D &	operator+=(const Angle2D & other);
	Angle2D &	operator-=(const Angle2D & other);

	Angle2D		operator*(const float & flt) const;
	Angle2D		operator/(const float & flt) const;
	Angle2D &	operator*=(const float & flt);
	Angle2D &	operator/=(const float & flt);
};

#endif
