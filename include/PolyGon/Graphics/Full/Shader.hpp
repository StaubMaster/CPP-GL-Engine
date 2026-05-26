#ifndef  POLYGON_GRAPHICS_FULL_SHADER_HPP
# define POLYGON_GRAPHICS_FULL_SHADER_HPP

# include "Graphics/Shader/Base.hpp"
# include "Graphics/Uniform/Layout.hpp"
# include "Graphics/Uniform/_Include.hpp"

namespace PolyGonFull
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
	Uniform::Matrix3x3			View;
	Uniform::Float				Scale;
	public:
	~Layout();
	Layout();
};
};

#endif