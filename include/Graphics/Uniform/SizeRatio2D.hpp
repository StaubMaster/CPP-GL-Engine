#ifndef  UNI_SIZE_RATIO_2D_HPP
# define UNI_SIZE_RATIO_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Point2D.hpp"

struct SizeRatio2D;

namespace Uniform
{
class SizeRatio2D : public Uniform::GBase<::SizeRatio2D>
{
	private:
	Uniform::Point2D Size;
	Uniform::Point2D Ratio;

	public:
	SizeRatio2D(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::SizeRatio2D & obj) override;
};
};

#endif