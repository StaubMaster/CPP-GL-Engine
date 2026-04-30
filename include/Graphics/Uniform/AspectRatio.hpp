#ifndef  UNI_ASPECT_RATIO_HPP
# define UNI_ASPECT_RATIO_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/TypeDefs/VectorF2.hpp"

struct AspectRatio;

namespace Uniform
{
class AspectRatio : public Uniform::GBase<::AspectRatio>
{
	private:
	Uniform::VectorF2 Value;

	public:
	AspectRatio(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::AspectRatio & obj) override;
};
};

#endif