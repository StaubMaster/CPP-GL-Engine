#include "PolyHedra/Graphics/Wire/Main/Layout.hpp"
#include "PolyHedra/Graphics/Wire/Main/Data.hpp"



PolyHedraWire::Main::Layout::~Layout() { }
PolyHedraWire::Main::Layout::Layout()
	: ::Attribute::Layout(0, sizeof(PolyHedraWire::Main::Data))
	, Pos(*this)
	, Col(*this)
{ }
PolyHedraWire::Main::Layout::Layout(const Layout & other)
	: ::Attribute::Layout(other)
	, Pos(*this, other.Pos)
	, Col(*this, other.Col)
{ }
