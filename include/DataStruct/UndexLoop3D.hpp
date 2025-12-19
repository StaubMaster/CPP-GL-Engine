#ifndef  UNDEX_LOOP_3D_HPP
# define UNDEX_LOOP_3D_HPP

# include "Undex3D.hpp"
# include "UndexRange3D.hpp"

/*	Intention

UndexLoop3D loop = UndexLoop3D(min, max);
for (Undex3D udx = loop.Min(); loop.Check(udx); loop.Next(udx))
{
	udx
}

UndexLoop3D loop = UndexLoop3D(min, max);
for (Undex3D udx = loop.Max(); loop.Check(udx); loop.Prev(udx))
{
	udx
}

*/

struct UndexLoop3D
{
	public:
	UndexRange3D	Range;

	public:
	UndexLoop3D();
	UndexLoop3D(Undex3D min, Undex3D max);
	~UndexLoop3D();

	UndexLoop3D(const UndexLoop3D & other);
	UndexLoop3D & operator=(const UndexLoop3D & other);

	public:
	Undex3D Min() const;
	Undex3D Max() const;

	public:
	Bool3D CheckIn(Undex3D udx) const;
	Bool3D CheckEx(Undex3D udx) const;

	public:
	void Next(Undex3D & udx) const;
	void Prev(Undex3D & udx) const;
};

#endif