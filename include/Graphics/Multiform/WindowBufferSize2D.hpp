#ifndef  MULTIFORM_DISPLAY_SIZE_HPP
# define MULTIFORM_DISPLAY_SIZE_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/WindowBufferSize2D.hpp"
# include "Display/WindowBufferSize2D.hpp"

namespace Multiform
{
typedef GBase<Uniform::WindowBufferSize2D, ::WindowBufferSize2D> WindowBufferSize2D;
/*class WindowBufferSize2D : public GBase<Uniform::WindowBufferSize2D, ::WindowBufferSize2D>
{
	public:
		WindowBufferSize2D(std::string name);
};*/
};

#endif