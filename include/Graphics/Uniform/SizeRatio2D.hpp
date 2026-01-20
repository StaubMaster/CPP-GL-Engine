#ifndef  UNI_SIZE_RATIO_2D_HPP
# define UNI_SIZE_RATIO_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Display/SizeRatio2D.hpp"

# include "Graphics/Uniform/Point2D.hpp"

namespace Uniform
{
class SizeRatio2D : public Uniform::GBase<::SizeRatio2D>
{
	private:
	Uniform::Point2D Size;
	Uniform::Point2D Ratio;

	public:
	SizeRatio2D(Uniform::NameShader name_shader);

	public:
	void Put(const ::SizeRatio2D & obj) override;
};
};

#endif