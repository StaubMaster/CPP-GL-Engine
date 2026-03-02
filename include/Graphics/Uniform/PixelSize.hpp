#ifndef  UNI_PIXEL_SIZE_HPP
# define UNI_PIXEL_SIZE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Point2D.hpp"

struct PixelSize;

namespace Uniform
{
class PixelSize : public Uniform::GBase<::PixelSize>
{
	private:
	Uniform::Point2D Full;
	Uniform::Point2D Half;

	public:
	PixelSize(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::PixelSize & obj) override;
};
};

#endif