#ifndef  VALUE_TYPE_SHOW_HPP
# define VALUE_TYPE_SHOW_HPP

# include "ValueTypeDeclare.hpp"

# include <iosfwd>

//std::ostream & operator<<(std::ostream & o, const Matrix2x2 & obj);
//std::ostream & operator<<(std::ostream & o, const Matrix3x3 & obj);
//std::ostream & operator<<(std::ostream & o, const Matrix4x4 & obj);

std::ostream & operator<<(std::ostream & o, const Point2D & obj);
std::ostream & operator<<(std::ostream & o, const Point3D & obj);
std::ostream & operator<<(std::ostream & o, const Point4D & obj);

std::ostream & operator<<(std::ostream & o, const AxisBox1D & obj);
std::ostream & operator<<(std::ostream & o, const AxisBox2D & obj);
std::ostream & operator<<(std::ostream & o, const AxisBox3D & obj);

std::ostream & operator<<(std::ostream & o, const Line2D & obj);
std::ostream & operator<<(std::ostream & o, const Line3D & obj);

std::ostream & operator<<(std::ostream & o, const Ray2D & obj);
std::ostream & operator<<(std::ostream & o, const Ray3D & obj);

std::ostream & operator<<(std::ostream & o, const Angle & obj);
std::ostream & operator<<(std::ostream & o, const EulerAngle3D & obj);

std::ostream & operator<<(std::ostream & o, const Trans2D & obj);
std::ostream & operator<<(std::ostream & o, const Trans3D & obj);

//std::ostream & operator<<(std::ostream & o, const DepthFactors & obj);
//std::ostream & operator<<(std::ostream & o, const Depth & obj);

//std::ostream & operator<<(std::ostream & o, const Range & obj);
//std::ostream & operator<<(std::ostream & o, const LInter & obj);

std::ostream & operator<<(std::ostream & o, const ColorF4 & obj);

//std::ostream & operator<<(std::ostream & o, const View2D & obj);
//std::ostream & operator<<(std::ostream & o, const View3D & obj);

std::ostream & operator<<(std::ostream & o, const Bool2D & obj);
std::ostream & operator<<(std::ostream & o, const Bool3D & obj);

std::ostream & operator<<(std::ostream & o, const Undex & obj);

std::ostream & operator<<(std::ostream & o, const Undex2D & obj);
std::ostream & operator<<(std::ostream & o, const UndexBox2D & obj);
//std::ostream & operator<<(std::ostream & o, const UndexLoop2D & obj);

std::ostream & operator<<(std::ostream & o, const Undex3D & obj);
std::ostream & operator<<(std::ostream & o, const UndexBox3D & obj);
//std::ostream & operator<<(std::ostream & o, const UndexLoop3D & obj);

#endif
