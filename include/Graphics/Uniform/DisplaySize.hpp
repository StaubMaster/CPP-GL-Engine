#ifndef  UNI_DISPLAY_SIZE_HPP
# define UNI_DISPLAY_SIZE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Point2D.hpp"
# include "Graphics/Uniform/PixelSize.hpp"

struct DisplaySize;

namespace Uniform
{
class DisplaySize : public Uniform::GBase<::DisplaySize>
{
	private:
	Uniform::Point2D	Ratio;
	Uniform::PixelSize	Window;
	Uniform::PixelSize	Buffer;

	public:
	DisplaySize(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::DisplaySize & obj) override;
};
};

#endif