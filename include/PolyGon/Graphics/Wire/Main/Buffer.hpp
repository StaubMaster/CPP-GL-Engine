#ifndef  POLYGON_GRAPHICS_WIRE_MAIN_BUFFER_HPP
# define POLYGON_GRAPHICS_WIRE_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"
# include "Graphics/Attribute/Layout.hpp"
# include "Graphics/Attribute/TypeDefs/VectorF2.hpp"
# include "Graphics/Attribute/TypeDefs/ColorF4.hpp"

namespace PolyGonWire
{
namespace Main
{
class Layout : public ::Attribute::Layout
{
	public:
	::Attribute::VectorF2	Pos;
	::Attribute::ColorF4	Col;
	public:
	~Layout();
	Layout();
	Layout(const Layout & other);
};
};
};

#endif