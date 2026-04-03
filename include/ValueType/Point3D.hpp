#ifndef  POINT_3D_HPP
# define POINT_3D_HPP

struct Point3D
{
	public:
	float	X;
	float	Y;
	float	Z;



	public:
	~Point3D();

	Point3D();
	Point3D(float x, float y, float z);

	Point3D(const Point3D & other);
	Point3D &	operator=(const Point3D & other);



	public:
	float		length2() const;
	float		length() const;

	Point3D		normalize() const;
	Point3D		normalize(float & len) const;



	Point3D		round() const;
	Point3D		roundC() const;
	Point3D		roundF() const;

	Point3D		round(float size) const;
	Point3D		roundC(float size) const;
	Point3D		roundF(float size) const;



	public:
	Point3D		operator+() const;
	Point3D		operator-() const;
	Point3D		operator!() const;

	Point3D		operator+(const Point3D & other) const;
	Point3D		operator-(const Point3D & other) const;
	Point3D		operator*(const Point3D & other) const;
	Point3D		operator/(const Point3D & other) const;

	Point3D &	operator+=(const Point3D & other);
	Point3D &	operator-=(const Point3D & other);
	Point3D &	operator*=(const Point3D & other);
	Point3D &	operator/=(const Point3D & other);



			float	dot(const Point3D & other) const;
	static	float	dot(const Point3D & p0, const Point3D & p1);

	static	Point3D	cross(const Point3D & p0, const Point3D & p1);
			Point3D	cross(const Point3D & other) const;



	Point3D &	operator+=(float f);
	Point3D &	operator-=(float f);
	Point3D &	operator*=(float f);
	Point3D &	operator/=(float f);
};

Point3D		operator+(Point3D p, float f);
Point3D		operator-(Point3D p, float f);
Point3D		operator*(Point3D p, float f);
Point3D		operator/(Point3D p, float f);

Point3D		operator+(float f, Point3D p);
Point3D		operator-(float f, Point3D p);
Point3D		operator*(float f, Point3D p);
Point3D		operator/(float f, Point3D p);

#endif