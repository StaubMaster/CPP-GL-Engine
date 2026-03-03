#ifndef  UNI_ASPECT_RATIO_HPP
# define UNI_ASPECT_RATIO_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Point2D.hpp"

struct AspectRatio;

namespace Uniform
{
class AspectRatio : public Uniform::GBase<::AspectRatio>
{
	private:
	Uniform::Point2D Value;

	public:
	AspectRatio(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::AspectRatio & obj) override;
};
};

#endif