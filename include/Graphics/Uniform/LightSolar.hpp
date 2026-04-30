#ifndef  UNI_LIGHT_SOLAR_HPP
# define UNI_LIGHT_SOLAR_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/LightBase.hpp"
# include "Graphics/Uniform/TypeDefs/VectorF3.hpp"

struct LightSolar;

namespace Uniform
{
class LightSolar : public Uniform::GBase<::LightSolar>
{
	private:
	Uniform::LightBase	Base;
	Uniform::VectorF3	Dir;

	public:
	LightSolar(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::LightSolar & obj) override;
};
};

#endif