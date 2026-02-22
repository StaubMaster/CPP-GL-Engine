#ifndef  TRANS_2D_HPP
# define TRANS_2D_HPP

# include "Point2D.hpp"
# include "Angle2D.hpp"

struct Ray2D;
struct Line2D;

//	Make Scaling a part of Transformation ?
//	I dont use it most of the time.
//	also, at that point a Matrix4x4 would be more compact
//	but then the internal Values become inaccessible
//	should probably have a way of turning Trans2D directly into a Matrix4x4 anyway ?

//	that might improve Rendering ?
//	the Objects can store whatever they want (no EntryContainer stuff)
//	and then there is a function that turns that into BufferData
//	but then that would need to be recalculated every Frame

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

	public:
	Point2D	Transform0(Point2D pos) const;
	Angle2D	Transform0(Angle2D rot) const;
	Trans2D	Transform0(Trans2D trans) const;
	Ray2D	Transform0(Ray2D ray) const;

	public:
	Point2D	Transform1(Point2D pos) const;
	Angle2D	Transform1(Angle2D rot) const;
	Trans2D	Transform1(Trans2D trans) const;
	Ray2D	Transform1(Ray2D ray) const;
};

#endif
