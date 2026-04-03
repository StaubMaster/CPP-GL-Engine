#ifndef  ANGLE_HPP
# define ANGLE_HPP

# define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
# define TAU 6.28318530717958647692528676655900576839433879875021164194988918461563281257241799725606965068423413

struct Point2D;

struct Angle
{
	private:
	float	Value;

	public:
	~Angle();
	Angle();
	Angle(const Angle & other);
	Angle & operator=(const Angle & other);

	private:
	Angle(float val);

	private:
	static float	DegreesToRadians(float val);
	static float	RadiansToDegrees(float val);

	public:
	void	FromRadians(float val);
	void	FromDegrees(float val);

	float	ToRadians() const;
	float	ToDegrees() const;

	static Angle	Radians(float val);
	static Angle	Degrees(float val);
	static Angle	Section(float val);

	// PointToX()
	// PointToY()

	public:
	void	Clamp();

	public:
	float	Sin() const;
	float	Cos() const;
	float	Tan() const;

	void	aSin(float val);
	void	aCos(float val);
	void	aTan2(float y, float x);

	static Angle	SaSin(float val);
	static Angle	SaCos(float val);
	static Angle	SaTan2(float y, float x);

	public:
	void	Forward(float & x, float & y) const;
	void	Reverse(float & x, float & y) const;
	Point2D	Forward(Point2D p) const;
	Point2D	Reverse(Point2D p) const;

	public:
	Angle		operator+() const;
	Angle		operator-() const;

	Angle		operator+(const Angle & other) const;
	Angle		operator-(const Angle & other) const;
	Angle		operator*(const Angle & other) const;
	Angle		operator/(const Angle & other) const;

	Angle &		operator+=(const Angle & other);
	Angle &		operator-=(const Angle & other);
	Angle &		operator*=(const Angle & other);
	Angle &		operator/=(const Angle & other);

	Angle		operator*(const float & flt) const;
	Angle		operator/(const float & flt) const;

	Angle &		operator*=(const float & flt);
	Angle &		operator/=(const float & flt);
};

#endif