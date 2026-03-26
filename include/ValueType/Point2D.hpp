#ifndef  POINT_2D_HPP
# define POINT_2D_HPP

struct Point2D
{
	public:
	float	X;
	float	Y;

	//	Synonyms
	//public:
	//	float &	W;
	//	float &	H;
	//	Referances take Space

	public:
	~Point2D();

	Point2D();
	Point2D(float x, float y);

	Point2D(const Point2D & other);
	Point2D & operator=(const Point2D & other);

	public:
	float length2() const;
	float length() const;

	Point2D normalize() const;
	Point2D normalize(float & len) const;

	Point2D operator+() const; // dosent do anything
	Point2D operator-() const; // reverses floats
	Point2D operator!() const; // normalize

	Point2D & operator+=(float f);
	Point2D & operator-=(float f);
	Point2D & operator*=(float f);
	Point2D & operator/=(float f);

	Point2D operator+(const Point2D & other) const;
	Point2D operator-(const Point2D & other) const;
	Point2D operator*(const Point2D & other) const;
	Point2D operator/(const Point2D & other) const;

	Point2D & operator+=(const Point2D & other);
	Point2D & operator-=(const Point2D & other);
	Point2D & operator*=(const Point2D & other);
	Point2D & operator/=(const Point2D & other);

			float dot(const Point2D & other) const;
	static	float dot(const Point2D & p0, const Point2D & p1);

			float cross(const Point2D & other) const;
	static	float cross(const Point2D & p0, const Point2D & p1);

			Point2D cross(float f) const;
	static	Point2D cross(float f, const Point2D & p);
	static	Point2D cross(const Point2D & p, float f);

	// operator % as dot
	// operator ^ as cross
};

Point2D operator+(Point2D p, float f);
Point2D operator-(Point2D p, float f);
Point2D operator*(Point2D p, float f);
Point2D operator/(Point2D p, float f);

Point2D operator+(float f, Point2D p);
Point2D operator-(float f, Point2D p);
Point2D operator*(float f, Point2D p);
Point2D operator/(float f, Point2D p);

#endif