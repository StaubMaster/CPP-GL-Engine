#ifndef  UNI_LIGHT_SPOT_HPP
# define UNI_LIGHT_SPOT_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/LightBase.hpp"
# include "Graphics/Uniform/TypeDefs/VectorF3.hpp"
# include "Graphics/Uniform/Range.hpp"

struct LightSpot;

namespace Uniform
{
class LightSpot : public Uniform::GBase<::LightSpot>
{
	private:
	Uniform::LightBase	Base;
	Uniform::VectorF3	Pos;
	Uniform::VectorF3	Dir;
	Uniform::Range		Range;

	public:
	LightSpot(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::LightSpot & obj) override;
};
};

#endif