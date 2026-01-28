#ifndef  VIEW_HPP
# define VIEW_HPP

# include "ValueType/Trans3D.hpp"
# include "ValueType/Depth.hpp"

struct View
{
	Trans3D	Trans;
	::Depth	Depth;
	float	FOV;	//make a Point2D for different X and Y angle ?

	View();
	~View();

	View(const View & other);
	View & operator=(const View & other);

	void TransformFlatX(Trans3D trans, float timeDelta);
};

#endif