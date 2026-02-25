#ifndef  MULTIFORM_TRANS_3D_HPP
# define MULTIFORM_TRANS_3D_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/Trans3D.hpp"
# include "ValueType/Trans3D.hpp"

namespace Multiform
{
typedef GBase<Uniform::Trans3D, ::Trans3D> Trans3D;
/*class Trans3D : public GBase<Uniform::Trans3D, ::Trans3D>
{
	public:
		Trans3D(std::string name);
};*/
};

#endif