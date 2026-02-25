#ifndef  MULTIFORM_LINTER_HPP
# define MULTIFORM_LINTER_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/LInter.hpp"
# include "ValueType/LInter.hpp"

namespace Multiform
{
typedef GBase<Uniform::LInter, ::LInter> LInter;
/*class LInter : public GBase<Uniform::LInter, ::LInter>
{
	public:
		LInter(std::string name);
};*/
};

#endif