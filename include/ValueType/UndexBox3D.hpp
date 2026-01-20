#ifndef  UNDEX_BOX_3D_HPP
# define UNDEX_BOX_3D_HPP

# include "Undex3D.hpp"
# include "Bool3D.hpp"

struct UndexBox3D
{
	public:
	Undex3D	Min;
	Undex3D	Max;

	public:
	UndexBox3D();
	UndexBox3D(Undex3D min, Undex3D max);
	~UndexBox3D();

	UndexBox3D(const UndexBox3D & other);
	UndexBox3D & operator=(const UndexBox3D & other);

	public:
	Bool3D CheckIn(Undex3D udx) const;
	Bool3D CheckEx(Undex3D udx) const;
	Bool3D CheckEdge(Undex3D udx) const;
};

#endif