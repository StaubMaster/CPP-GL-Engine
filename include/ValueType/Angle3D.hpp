#ifndef ANGLE_3D_HPP
# define ANGLE_3D_HPP

# include "Angle.hpp"
# include "Matrix3x3.hpp"

struct Point3D;

struct Angle3D
{
	public:
	Angle	X;
	Angle	Y;
	Angle	Z;

	public:
	Matrix3x3	Mat;

	public:
	Angle3D();
	Angle3D(Angle x, Angle y, Angle z);
	~Angle3D();

	Angle3D(const Angle3D & other);
	const Angle3D & operator =(const Angle3D & other);

	static Angle3D FromPoint3D(const Point3D & dir);

	private:
	public:
	void	CalcFore();
	void	CalcBack();

	Point3D	rotate(Point3D p) const;
	Angle3D	rotate(Angle3D a) const;

	public:
	Angle3D		operator+(const Angle3D & other) const;
	Angle3D		operator-(const Angle3D & other) const;
	Angle3D &	operator+=(const Angle3D & other);
	Angle3D &	operator-=(const Angle3D & other);
};

#endif
