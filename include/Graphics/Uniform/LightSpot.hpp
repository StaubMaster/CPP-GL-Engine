#ifndef  UNI_LIGHT_SPOT_HPP
# define UNI_LIGHT_SPOT_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/LightBase.hpp"
# include "Graphics/Uniform/Point3D.hpp"
# include "Graphics/Uniform/Range.hpp"
struct LightSpot;

namespace Uniform
{
class LightSpot : public Uniform::GBase<::LightSpot>
{
	private:
	Uniform::LightBase	Base;
	Uniform::Point3D	Pos;
	Uniform::Point3D	Dir;
	Uniform::Range		Range;

	public:
	LightSpot(Uniform::NameShader name_shader);

	public:
	void Put(const ::LightSpot & obj) override;
};
};

#endif