#ifndef  UNI_LIGHT_POINT_HPP
# define UNI_LIGHT_POINT_HPP

# include "Graphics/Uniform/General/GBase.hpp"
# include "Graphics/Uniform/Light/Base.hpp"
# include "Graphics/Uniform/TypeDefs/VectorF3.hpp"

struct LightPoint;

namespace Uniform
{
class LightPoint : public Uniform::GBase<::LightPoint>
{
	private:
	Uniform::LightBase	Base;
	Uniform::VectorF3	Pos;

	public:
	LightPoint(Uniform::Layout & layout, std::string name);

	public:
	void Put(const ::LightPoint & obj) override;
};
};

#endif