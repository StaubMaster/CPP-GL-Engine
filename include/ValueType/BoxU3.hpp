#ifndef  BOX_U_3_HPP
# define BOX_U_3_HPP

# include "VectorU3.hpp"
# include "Box_3.hpp"

struct BoxU3 : public Box_3<VectorU3>
{
	~BoxU3();

	BoxU3();
	BoxU3(VectorU3 min, VectorU3 max);

	BoxU3(const BoxU3 & other);
	BoxU3 & operator=(const BoxU3 & other);



	Bool3 CheckIn(VectorU3 udx) const;
	Bool3 CheckEx(VectorU3 udx) const;
	Bool3 CheckEdge(VectorU3 udx) const;
};

#endif