#ifndef  TRIANGLE_F3_HPP
# define TRIANGLE_F3_HPP

# include "Vector/F3.hpp"

struct TriangleF3
{
	VectorF3	A;
	VectorF3	B;
	VectorF3	C;

	~TriangleF3() = default;
	TriangleF3() = default;
	TriangleF3(const TriangleF3 & other) = default;
	TriangleF3 & operator=(const TriangleF3 & other) = default;

	TriangleF3(const VectorF3 & a, const VectorF3 & b, const VectorF3 & c);
};

#endif