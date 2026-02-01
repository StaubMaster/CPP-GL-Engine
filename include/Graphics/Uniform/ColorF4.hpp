#ifndef  UNI_COLOR_F4_HPP
# define UNI_COLOR_F4_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float4.hpp"
struct ColorF4;

namespace Uniform
{
class ColorF4 : public Uniform::Float4
{
	public:
	ColorF4(Uniform::NameShader name_shader);

	public:
	void Put(const ::ColorF4 & val);
};
};

#endif