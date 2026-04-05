#include "PolyHedra/Graphics/Wire/Shader.hpp"



PolyHedraWire::Shader::~Shader()
{ }
PolyHedraWire::Shader::Shader()
	: ::Shader::Base()
	, DisplaySize(*this, "DisplaySize")
	, View(*this, "View")
	, Depth(*this, "Depth")
	, FOV(*this, "FOV")
{ }
