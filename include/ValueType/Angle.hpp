#ifndef  ANGLE_HPP
# define ANGLE_HPP

# define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
# define TAU 6.28318530717958647692528676655900576839433879875021164194988918461563281257241799725606965068423413

/*
	stores the angle and how to interpret it ?
	{
		if these are used in Angle3D
		I would have to skip the values for the Buffers
		
		{
			maybe figure out how to get the angles back from the matrix ?
			but that would require knowing if it was calculates foreward or backward
			but the differance between those is that they are transposed
			so just allways calculate one way
			and when the other is needed just multiply transposedly
		}
			
		but calculating the inital angles everytime they are changed might be slow ?
		just uncalculate all of them into a Point3D (used as Float3)
		then change them, then calculate back ?
		
		and have behaviour to add/sub by a Point3D (Float3) and then do this stuff internally
		maybe optimize it
		but that would have to be differentiated from rotating a Point
		maybe use + - for one and * / for the other idk
	}

	the differant angle types are:
	Radiant		0 to 2 Pi (1 Tau) for a full Circle
	Degrees		0 to 360 for a full Circle
	Normal		0 to 1
	maybe some other ?
	or just store the multiplyer ?

	or only store one but have it be a struct
	so functions can be used to add/sub Degrees ?
	that might be the simplest
*/

struct Angle
{
	private:
	float	Value;

	public:
	Angle();
	~Angle();
	Angle(const Angle & other);
	Angle & operator=(const Angle & other);

	private:
	Angle(float val);

	public:
	void	Clamp();

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

	public:
	float	Sin() const;
	float	Cos() const;
	float	Tan() const;

	void	aSin(float val);
	void	aCos(float val);
	void	aTan2(float x, float y);

	static Angle	SaSin(float val);
	static Angle	SaCos(float val);
	static Angle	SaTan2(float x, float y);



	public:
	Angle	operator+(const Angle & other) const;
	Angle	operator-(const Angle & other) const;
	Angle	operator*(const Angle & other) const;
	Angle	operator/(const Angle & other) const;

	Angle	operator*(const float & flt) const;
	Angle	operator/(const float & flt) const;

	Angle &	operator+=(const Angle & other);
	Angle &	operator-=(const Angle & other);
	Angle &	operator*=(const Angle & other);
	Angle &	operator/=(const Angle & other);

	Angle &	operator*=(const float & flt);
	Angle &	operator/=(const float & flt);
};

#endif