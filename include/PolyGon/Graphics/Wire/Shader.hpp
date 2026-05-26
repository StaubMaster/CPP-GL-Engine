#ifndef  POLYGON_GRAPHICS_WIRE_SHADER_HPP
# define POLYGON_GRAPHICS_WIRE_SHADER_HPP

# include "Graphics/Shader/Base.hpp"
# include "Graphics/Uniform/Layout.hpp"
# include "Graphics/Uniform/_Include.hpp"

namespace PolyGonWire
{
class Shader : public ::Shader::Base
{
	public:
	~Shader();
	Shader();
};
class Layout : public Uniform::Layout
{
	public:
	Uniform::DisplaySize		DisplaySize;
//	Uniform::Trans2D			View;
	Uniform::Matrix3x3			View;
	Uniform::Float				Scale;
	public:
	~Layout();
	Layout();
};
};

#endif