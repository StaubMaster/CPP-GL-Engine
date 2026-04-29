#ifndef  UNI_COLOR_F4_HPP
# define UNI_COLOR_F4_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct ColorF4;

namespace Uniform
{
class ColorF4 : public Uniform::FloatN
{
	public:
	ColorF4(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::ColorF4 & val);
};
};

#endif