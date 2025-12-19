
#ifndef  GENERIC_UNIFORM_BASE_HPP
# define GENERIC_UNIFORM_BASE_HPP

# include "Graphics/Uniform/Base/Base.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
template <typename DataType>
class GBase : public Uniform::Base
{
	protected:
		GBase(Uniform::NameShader name_shader) :
			Uniform::Base(name_shader) { }
		virtual ~GBase() { }

	public:
		virtual void PutData(DataType data) = 0;
};
};

#endif
