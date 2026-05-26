#ifndef  POLYHEDRA_GRAPHICS_WIRE_MAIN_LAYOUT_HPP
# define POLYHEDRA_GRAPHICS_WIRE_MAIN_LAYOUT_HPP

# include "Graphics/Attribute/Layout.hpp"
# include "Graphics/Attribute/TypeDefs/VectorF3.hpp"
# include "Graphics/Attribute/TypeDefs/ColorF4.hpp"

namespace PolyHedraWire
{
namespace Main
{
class Layout : public ::Attribute::Layout
{
	public:
	::Attribute::VectorF3	Pos;
	::Attribute::ColorF4	Col;
	public:
	~Layout();
	Layout();
	Layout(const Layout & other);
};
};
};

#endif