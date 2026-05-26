#include "PolyGon/Graphics/Full/Shader.hpp"



PolyGonFull::Shader::~Shader()
{ }
PolyGonFull::Shader::Shader()
	: ::Shader::Base()
{ }



PolyGonFull::Layout::~Layout()
{ }
PolyGonFull::Layout::Layout()
	: Uniform::Layout()
	, DisplaySize(*this, "DisplaySize")
	, View(*this, "View")
	, Scale(*this, "Scale")
{ }
