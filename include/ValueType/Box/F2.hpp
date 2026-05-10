#ifndef  BOX_F_2_HPP
# define BOX_F_2_HPP

# include "ValueType/Vector/F2.hpp"
# include "ValueType/Box/_2.hpp"

struct BoxF2 : public Box_2<VectorF2, BoxF2>
{
	~BoxF2();

	BoxF2();
	BoxF2(VectorF2 min, VectorF2 max);

	BoxF2(const BoxF2 & other);
	BoxF2 & operator=(const BoxF2 & other);
};

#endif