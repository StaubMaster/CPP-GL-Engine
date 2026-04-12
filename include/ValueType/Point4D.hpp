#ifndef  POINT_4D_HPP
# define POINT_4D_HPP

# include "VectorF4.hpp"

typedef VectorF4 Point4D;

/*
struct Point4D
{
	public:
	float	X;
	float	Y;
	float	Z;
	float	W;



	public:
	Point4D();
	Point4D(float x, float y, float z, float w);
	~Point4D();

	Point4D(const Point4D & other);
	Point4D & operator=(const Point4D & other);



	public:
	float		length2() const;
	float		length() const;

	Point4D		normalize() const;
	Point4D		normalize(float & len) const;

	Point4D		round() const;
	Point4D		roundC() const;
	Point4D		roundF() const;

	Point4D		round(float size) const;
	Point4D		roundC(float size) const;
	Point4D		roundF(float size) const;



	public:
	Point4D operator+() const;
	Point4D operator-() const;
	Point4D operator!() const;

	Point4D operator+(const float & flt) const;
	Point4D operator-(const float & flt) const;
	Point4D operator*(const float & flt) const;
	Point4D operator/(const float & flt) const;

	Point4D & operator+=(const float & flt);
	Point4D & operator-=(const float & flt);
	Point4D & operator*=(const float & flt);
	Point4D & operator/=(const float & flt);

	Point4D operator+(const Point4D & other) const;
	Point4D operator-(const Point4D & other) const;
	Point4D operator*(const Point4D & other) const;
	Point4D operator/(const Point4D & other) const;

	Point4D & operator+=(const Point4D & other);
	Point4D & operator-=(const Point4D & other);
	Point4D & operator*=(const Point4D & other);
	Point4D & operator/=(const Point4D & other);



	float static dot(const Point4D & p0, const Point4D & p1);
};
*/
#endif