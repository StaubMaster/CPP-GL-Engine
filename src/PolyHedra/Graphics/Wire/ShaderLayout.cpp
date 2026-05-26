#include "PolyHedra/Graphics/Wire/ShaderLayout.hpp"



PolyHedraWire::ShaderLayout::~ShaderLayout()
{ }
PolyHedraWire::ShaderLayout::ShaderLayout()
	: ::Uniform::Layout()
	, DisplaySize(*this, "DisplaySize")
	, View(*this, "View")
	, Depth(*this, "Depth")
	, FOV(*this, "FOV")
{ }
