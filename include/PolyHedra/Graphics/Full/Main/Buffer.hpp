#ifndef  POLYHEDRA_GRAPHICS_FULL_MAIN_BUFFER_HPP
# define POLYHEDRA_GRAPHICS_FULL_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/Layout.hpp"
# include "Graphics/Attribute/TypeDefs/VectorF3.hpp"

namespace PolyHedraFull
{
namespace Main
{
class Layout : public ::Attribute::Layout
{
	public:
	::Attribute::VectorF3	Position;
	::Attribute::VectorF3	Normal;
	::Attribute::VectorF3	Texture;
	public:
	~Layout();
	Layout();
	Layout(const Layout & other);
};
};
};

#endif