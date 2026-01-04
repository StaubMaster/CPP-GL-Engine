#ifndef  SIMPLE3D_DATA_HPP
# define SIMPLE3D_DATA_HPP

# include "DataStruct/Trans3D.hpp"

namespace Simple3D
{
struct Data
{
	Trans3D Trans;

	Data();
	Data(const Trans3D & trans);
};
};

#endif