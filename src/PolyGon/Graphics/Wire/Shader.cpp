#include "PolyGon/Graphics/Wire/Shader.hpp"



PolyGonWire::Shader::~Shader()
{ }
PolyGonWire::Shader::Shader()
	: ::Shader::Base()
{ }



PolyGonWire::Layout::~Layout()
{ }
PolyGonWire::Layout::Layout()
	: ::Uniform::Layout()
	, DisplaySize(*this,"DisplaySize")
	, View(*this,"View")
	, Scale(*this,"Scale")
{ }
