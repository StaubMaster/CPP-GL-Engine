#ifndef  UNDEX_RANGE_3D_HPP
# define UNDEX_RANGE_3D_HPP

# include "Undex3D.hpp"
# include "Bool3D.hpp"

struct UndexRange3D
{
	public:
	Undex3D	Min;
	Undex3D	Max;

	public:
	UndexRange3D();
	UndexRange3D(Undex3D min, Undex3D max);
	~UndexRange3D();

	UndexRange3D(const UndexRange3D & other);
	UndexRange3D & operator=(const UndexRange3D & other);

	public:
	Bool3D CheckIn(Undex3D udx) const;
	Bool3D CheckEx(Undex3D udx) const;
	Bool3D CheckEdge(Undex3D udx) const;
};

#endif