#ifndef  BUFFER_ARRAY_MAIN_INST_HPP
# define BUFFER_ARRAY_MAIN_INST_HPP

# include "Graphics/Buffer/ArrayBase.hpp"
# include "Graphics/Buffer/Attribute.hpp"

# include "Miscellaneous/Container/Binary.hpp"

namespace Buffer { class Base; };
namespace Texture { class Base; };

namespace BufferArray
{
class MainInst : public BufferArray::Base
{
	public:
	GL::DrawMode	Mode;
	Buffer::Attribute *	MainPtr;
	Buffer::Attribute *	InstPtr;

	public:
	Container::Binary<Texture::Base *>	Textures;

	public:
	virtual ~MainInst();
	MainInst(GL::DrawMode mode);

	public:
	void Draw();
};
};

#endif