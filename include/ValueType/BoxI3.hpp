#ifndef  BOX_I_3_HPP
# define BOX_I_3_HPP

# include "VectorI3.hpp"
# include "Box_3.hpp"

struct BoxI3 : public Box_3<VectorI3, BoxI3>
{
	~BoxI3();

	BoxI3();
	BoxI3(VectorI3 min, VectorI3 max);

	BoxI3(const BoxI3 & other);
	BoxI3 & operator=(const BoxI3 & other);
};

#endif