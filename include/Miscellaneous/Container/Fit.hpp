#ifndef  CONTAINER_FIT_HPP
# define CONTAINER_FIT_HPP

# include "Dynamic.hpp"

namespace Container
{
template<typename T>
class Fit : public Dynamic<T>
{
	public:
		Fit() : Dynamic<T>()
		{ }
		~Fit()
		{ }

	protected:
		unsigned int NewLimit(unsigned int wanted_count) override
		{
			return wanted_count;
		}
};

};

#endif