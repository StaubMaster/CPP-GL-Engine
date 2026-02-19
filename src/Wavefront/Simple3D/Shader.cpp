#include "Wavefront/Simple3D/Shader.hpp"



Wavefront::Simple3D::Shader::Shader()
	: ::Shader::Base()
	, WindowSize(*this, "WindowSize")
	, View(*this, "View")
	, Depth(*this, "Depth")
	, ColorToTex(*this, "ColorToTex")
	, ShowLightFactor(*this, "ShowLightFactor")
{ }
Wavefront::Simple3D::Shader::~Shader()
{ }
