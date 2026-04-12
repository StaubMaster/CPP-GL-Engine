#ifndef  BOX_F_3_HPP
# define BOX_F_3_HPP

# include "VectorF3.hpp"
# include "Box_3.hpp"

struct BoxF3 : public Box_3<VectorF3>
{
	~BoxF3();

	BoxF3();
	BoxF3(VectorF3 min, VectorF3 max);

	BoxF3(const BoxF3 & other);
	BoxF3 & operator=(const BoxF3 & other);
};

#endif