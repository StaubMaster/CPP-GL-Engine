#ifndef  INTERSECT_HPP
# define INTERSECT_HPP

# include "ValueType/_Declare.hpp"

namespace Intersect { };

bool IsIntersecting(
	const Ray2D & ray,
	const Line2D & line
);

bool IsIntersecting(
	const Line2D & line0,
	const Line2D & line1
);

bool Intersection(
	const Line2D & line0,
	const Line2D & line1,
	VectorF2 & ret
);

#endif