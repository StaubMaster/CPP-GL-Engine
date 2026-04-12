#ifndef  BOX_F_1_HPP
# define BOX_F_1_HPP

# include "Box_1.hpp"

struct BoxF1 : public Box_1<float>
{
	~BoxF1();

	BoxF1();
	BoxF1(float min, float max);

	BoxF1(const BoxF1 & other);
	BoxF1 & operator=(const BoxF1 & other);
};

#endif