#ifndef  VIEW_3D_HPP
# define VIEW_3D_HPP

# include "ValueType/Trans3D.hpp"
# include "ValueType/Depth.hpp"

struct View3D
{
	Trans3D	Trans;
	::Depth	Depth;
	Angle	FOV;	//make a Point2D for different X and Y angle ?

	View3D();
	~View3D();

	View3D(const View3D & other);
	View3D & operator=(const View3D & other);

	static View3D Default();

	void TransformFlatX(Trans3D trans, float timeDelta);
};

#endif