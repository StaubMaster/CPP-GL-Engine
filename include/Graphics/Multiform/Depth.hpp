#ifndef  MULTIFORM_DEPTH_HPP
# define MULTIFORM_DEPTH_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/Depth.hpp"
# include "ValueType/Depth.hpp"

namespace Multiform
{
typedef GBase<Uniform::Depth, ::Depth> Depth;
/*class Depth : public GBase<Uniform::Depth, ::Depth>
{
	public:
		Depth(std::string name);
};*/
};

#endif