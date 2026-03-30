#ifndef  SIMPLE3D_DATA_HPP
# define SIMPLE3D_DATA_HPP

# include "ValueType/Trans3D.hpp"

namespace Simple3D
{
struct Data
{
//	Trans3D Trans;
	Point3D Point;

	Data();
	Data(const Trans3D & trans);
};
};

#endif