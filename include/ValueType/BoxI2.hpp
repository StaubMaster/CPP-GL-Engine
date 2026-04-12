#ifndef  BOX_I_2_HPP
# define BOX_I_2_HPP

# include "VectorI2.hpp"
# include "Box_2.hpp"

struct BoxI2 : public Box_2<VectorI2>
{
	~BoxI2();

	BoxI2();
	BoxI2(VectorI2 min, VectorI2 max);

	BoxI2(const BoxI2 & other);
	BoxI2 & operator=(const BoxI2 & other);
};

#endif