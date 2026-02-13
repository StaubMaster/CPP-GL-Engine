#ifndef  UNI_LIGHT_BASE_HPP
# define UNI_LIGHT_BASE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"
# include "Graphics/Uniform/ColorF4.hpp"

struct LightBase;

namespace Uniform
{
class LightBase : public Uniform::GBase<::LightBase>
{
	private:
	Uniform::Float1 Intensity;
	Uniform::ColorF4 Color;

	public:
	LightBase(Uniform::NameShader name_shader);

	public:
	void Put(const ::LightBase & obj) override;
};
};

#endif