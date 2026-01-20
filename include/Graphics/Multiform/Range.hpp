
#ifndef  MULTI_RANGE_HPP
# define MULTI_RANGE_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/Range.hpp"
# include "ValueType/Range.hpp"

namespace Multiform
{
class Range : public GBase<Uniform::Range, ::Range>
{
	public:
		Range(std::string name);
};
};

#endif
