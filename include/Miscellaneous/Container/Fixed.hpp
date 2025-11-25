#ifndef  CONTAINER_FIXED_HPP
# define CONTAINER_FIXED_HPP

# include "Dynamic.hpp"

namespace Container
{
template<typename T>
class Fixed : public Dynamic<T>
{
	public:
		Fixed(unsigned int limit) : Dynamic<T>(limit)
		{ }
		~Fixed()
		{ }

	protected:
		unsigned int NewLimit(unsigned int wanted_count) override
		{
			return this -> _Limit;
			(void)wanted_count;
		}
};

};

#endif