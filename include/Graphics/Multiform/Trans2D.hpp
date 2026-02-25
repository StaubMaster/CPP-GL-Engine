#ifndef  MULTIFORM_TRANS_2D_HPP
# define MULTIFORM_TRANS_2D_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/Trans2D.hpp"
# include "ValueType/Trans2D.hpp"

namespace Multiform
{
typedef GBase<Uniform::Trans2D, ::Trans2D> Trans2D;
/*class Trans2D : public GBase<Uniform::Trans2D, ::Trans2D>
{
	public:
		Trans2D(std::string name);
};*/
};

#endif