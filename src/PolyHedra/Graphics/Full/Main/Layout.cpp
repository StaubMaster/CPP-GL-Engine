#include "PolyHedra/Graphics/Full/Main/Layout.hpp"
#include "PolyHedra/Graphics/Full/Main/Data.hpp"



PolyHedraFull::Main::Layout::~Layout() { }
PolyHedraFull::Main::Layout::Layout()
	: ::Attribute::Layout(0, sizeof(PolyHedraFull::Main::Data))
	, Position(*this)
	, Normal(*this)
	, Texture(*this)
{ }
PolyHedraFull::Main::Layout::Layout(const Layout & other)
	: ::Attribute::Layout(other)
	, Position(*this, other.Position)
	, Normal(*this, other.Normal)
	, Texture(*this, other.Texture)
{ }
