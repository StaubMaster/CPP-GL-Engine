#ifndef  UNI_COLOR_HPP
# define UNI_COLOR_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float3.hpp"
# include "DataDeclare.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Color : public Uniform::Float3
{
	public:
	Color(Uniform::NameShader name_shader);

	public:
	void Put(const ::Color & val);
};
};

#endif