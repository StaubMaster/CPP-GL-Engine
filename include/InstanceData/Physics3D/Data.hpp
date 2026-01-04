#ifndef  PHYSICS3D_DATA_HPP
# define PHYSICS3D_DATA_HPP

# include "DataStruct/Trans3D.hpp"

namespace Physics3D
{
struct Data
{
	Trans3D Trans;
	Trans3D Vel;

	public:
	Data();
	Data(const Trans3D & trans);
};
};

#endif
