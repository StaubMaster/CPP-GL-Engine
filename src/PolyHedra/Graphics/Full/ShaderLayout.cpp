#include "PolyHedra/Graphics/Full/ShaderLayout.hpp"



PolyHedraFull::ShaderLayout::~ShaderLayout()
{ }
PolyHedraFull::ShaderLayout::ShaderLayout()
	: ::Uniform::Layout()
	, DisplaySize(*this, "DisplaySize")
	, View(*this, "View")
	, Depth(*this, "Depth")
	, FOV(*this, "FOV")
{ }
