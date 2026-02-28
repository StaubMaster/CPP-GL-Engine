#ifndef  DATA_SHOW_HPP
# define DATA_SHOW_HPP

# include "DataDeclare.hpp"

# include <iosfwd>

std::ostream & operator<<(std::ostream & o, const Point2D & obj);
std::ostream & operator<<(std::ostream & o, const Point3D & obj);
std::ostream & operator<<(std::ostream & o, const Point4D & obj);

std::ostream & operator<<(std::ostream & o, const Angle & obj);
std::ostream & operator<<(std::ostream & o, const Angle2D & obj);
std::ostream & operator<<(std::ostream & o, const Angle3D & obj);

std::ostream & operator<<(std::ostream & o, const Trans2D & obj);
std::ostream & operator<<(std::ostream & o, const Trans3D & obj);

std::ostream & operator<<(std::ostream & o, const AxisBox1D & obj);
std::ostream & operator<<(std::ostream & o, const AxisBox2D & obj);
std::ostream & operator<<(std::ostream & o, const AxisBox3D & obj);

std::ostream & operator<<(std::ostream & o, const Undex & obj);

std::ostream & operator<<(std::ostream & o, const Undex2D & obj);
std::ostream & operator<<(std::ostream & o, const UndexBox2D & obj);

std::ostream & operator<<(std::ostream & o, const Undex3D & obj);
std::ostream & operator<<(std::ostream & o, const UndexBox3D & obj);

std::ostream & operator<<(std::ostream & o, const Bool3D & obj);

std::ostream & operator<<(std::ostream & o, const ColorF4 & obj);

#endif
