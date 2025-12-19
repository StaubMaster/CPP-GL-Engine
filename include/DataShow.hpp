#ifndef  DATA_SHOW_HPP
# define DATA_SHOW_HPP

# include "DataDeclare.hpp"

# include <iosfwd>

std::ostream & operator <<(std::ostream & o, const Point2D & val);
std::ostream & operator <<(std::ostream & o, const Point3D & val);
std::ostream & operator <<(std::ostream & o, const Point4D & val);

std::ostream & operator <<(std::ostream & o, const Angle3D & val);

std::ostream & operator <<(std::ostream & o, const AxisBox1D & val);
std::ostream & operator <<(std::ostream & o, const AxisBox2D & val);
std::ostream & operator <<(std::ostream & o, const AxisBox3D & val);

std::ostream & operator <<(std::ostream & o, const Undex3D & val);
std::ostream & operator <<(std::ostream & o, const UndexBox3D & val);

std::ostream & operator <<(std::ostream & o, const Bool3D & val);

std::ostream & operator <<(std::ostream & o, const Color & val);

#endif
