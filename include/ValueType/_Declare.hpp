#ifndef  VALUE_TYPE_DECLARE_HPP
# define VALUE_TYPE_DECLARE_HPP

struct Bool2;
struct Bool3;
struct Bool4;

struct VectorF2;
struct VectorF3;
struct VectorF4;

struct VectorU2;
struct VectorU3;

struct BoxF1;
struct BoxF2;
struct BoxF3;

struct BoxU2;
struct BoxU3;



struct Matrix2x2;
struct Matrix3x3;
struct Matrix4x4;

//struct Point2D;
typedef VectorF2 Point2D;
//struct Point3D;
typedef VectorF3 Point3D;
//struct Point3D;
typedef VectorF4 Point4D;

//struct AxisBox1D;
typedef BoxF1 AxisBox1D;
//struct AxisBox2D;
typedef BoxF2 AxisBox2D;
//struct AxisBox3D;
typedef BoxF3 AxisBox3D;

struct Line2D;
struct Line3D;

struct Ray2D;
struct Ray3D;

struct Angle;
struct EulerAngle3D;

struct Trans2D;
struct Trans3D;

struct DepthFactors;
struct Depth;

struct Range;
struct LInter;

struct ColorF4;

struct View2D;
struct View3D;

struct LightBase;
struct LightSolar;
struct LightSpot;

//struct Bool2D;
typedef Bool2 Bool2D;
//struct Bool3D;
typedef Bool3 Bool3D;

struct Undex;

//struct Undex2D;
typedef VectorU2 Undex2D;
//struct UndexBox2D;
typedef BoxU2 UndexBox2D;
struct UndexLoop2D;

//struct Undex3D;
typedef VectorU3 Undex3D;
//struct UndexBox3D;
typedef BoxU3 UndexBox3D;
struct UndexLoop3D;

#endif