#ifndef  UNI_LIGHT_BASE_HPP
# define UNI_LIGHT_BASE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Float.hpp"
# include "Graphics/Uniform/ColorF4.hpp"

struct LightBase;

namespace Uniform
{
class LightBase : public Uniform::GBase<::LightBase>
{
	private:
	Uniform::Float Intensity;
	Uniform::ColorF4 Color;

	public:
	LightBase(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::LightBase & obj) override;
};
};

#endif