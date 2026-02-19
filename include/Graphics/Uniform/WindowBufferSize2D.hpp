#ifndef  UNI_DISPLAY_SIZE_HPP
# define UNI_DISPLAY_SIZE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Point2D.hpp"

struct WindowBufferSize2D;

namespace Uniform
{
class WindowBufferSize2D : public Uniform::GBase<::WindowBufferSize2D>
{
	private:
	Uniform::Point2D WindowSize;
	Uniform::Point2D BufferSize;
	Uniform::Point2D Ratio;

	public:
	WindowBufferSize2D(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::WindowBufferSize2D & obj) override;
};
};

#endif