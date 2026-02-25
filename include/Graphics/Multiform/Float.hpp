#ifndef  MULTIFORM_FLOAT_HPP
# define MULTIFORM_FLOAT_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/Float.hpp"

namespace Multiform
{
typedef GBase<Uniform::Float, float> Float;
/*class Float : public GBase<Uniform::Float, float>
{
	public:
	Float(std::string name);
};*/
};

#endif