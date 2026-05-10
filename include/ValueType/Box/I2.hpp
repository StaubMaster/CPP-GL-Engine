#ifndef  BOX_I_2_HPP
# define BOX_I_2_HPP

# include "ValueType/Vector/I2.hpp"
# include "ValueType/Box/_2.hpp"

struct BoxI2 : public Box_2<VectorI2, BoxI2>
{
	~BoxI2();

	BoxI2();
	BoxI2(VectorI2 min, VectorI2 max);

	BoxI2(const BoxI2 & other);
	BoxI2 & operator=(const BoxI2 & other);
};

#endif