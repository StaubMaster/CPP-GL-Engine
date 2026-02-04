#include "Wavefront/Simple3D/Shader.hpp"



Wavefront::Simple3D::Shader::Shader()
	: ::Shader::Base(),
	WindowSize(Uniform::NameShader("WindowSize", *this)),
	View(Uniform::NameShader("View", *this)),
	Depth(Uniform::NameShader("Depth", *this)),
	ColorToTex(Uniform::NameShader("ColorToTex", *this)),
	ShowLightFactor(Uniform::NameShader("ShowLightFactor", *this))
{ }
Wavefront::Simple3D::Shader::~Shader()
{ }
