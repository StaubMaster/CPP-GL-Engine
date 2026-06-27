#ifndef  UNI_LIGHT_DIRECTION_HPP
# define UNI_LIGHT_DIRECTION_HPP

# include "Graphics/Uniform/General/GBase.hpp"
# include "Graphics/Uniform/Light/Base.hpp"
# include "Graphics/Uniform/TypeDefs/VectorF3.hpp"

struct LightDirection;

namespace Uniform
{
class LightDirection : public Uniform::GBase<::LightDirection>
{
	private:
	Uniform::LightBase	Base;
	Uniform::VectorF3	Dir;

	public:
	LightDirection(Uniform::Layout & layout, std::string name);

	public:
	void Put(const ::LightDirection & obj) override;
};
};

#endif