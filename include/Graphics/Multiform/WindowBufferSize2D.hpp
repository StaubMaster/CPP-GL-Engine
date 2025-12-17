
#ifndef  MULTI_DISPLAY_SIZE_HPP
# define MULTI_DISPLAY_SIZE_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/WindowBufferSize2D.hpp"
# include "Display/WindowBufferSize2D.hpp"

namespace Multiform
{
class WindowBufferSize2D : public GBase<Uniform::WindowBufferSize2D, ::WindowBufferSize2D>
{
	public:
		WindowBufferSize2D(std::string name);
};
};

#endif

