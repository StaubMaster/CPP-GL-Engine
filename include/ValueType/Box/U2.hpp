#ifndef  BOX_U_2_HPP
# define BOX_U_2_HPP

# include "ValueType/Vector/U2.hpp"
# include "ValueType/Box/_2.hpp"

struct BoxU2 : public Box_2<VectorU2, BoxU2>
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