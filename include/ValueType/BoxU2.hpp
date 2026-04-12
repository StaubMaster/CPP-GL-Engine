#ifndef  BOX_U_2_HPP
# define BOX_U_2_HPP

# include "VectorU2.hpp"
# include "Box_2.hpp"

struct BoxU2 : public Box_2<VectorU2>
{
	~BoxU2();

	BoxU2();
	BoxU2(VectorU2 min, VectorU2 max);

	BoxU2(const BoxU2 & other);
	BoxU2 & operator=(const BoxU2 & other);



	Bool2 CheckIn(VectorU2 udx) const;
	Bool2 CheckEx(VectorU2 udx) const;
	Bool2 CheckEdge(VectorU2 udx) const;
};

#endif