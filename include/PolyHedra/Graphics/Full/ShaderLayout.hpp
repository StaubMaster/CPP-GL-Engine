#ifndef  POLYHEDRA_FULL_SHADER_HPP
# define POLYHEDRA_FULL_SHADER_HPP

# include "Graphics/Uniform/General/Layout.hpp"
# include "Graphics/Uniform/_Include.hpp"

namespace PolyHedraFull
{
class ShaderLayout : public Uniform::Layout
{
	public:
	Uniform::DisplaySize		DisplaySize;
	Uniform::Matrix4x4			View;
	Uniform::Depth				Depth;
	Uniform::Angle				FOV;
	public:
	~ShaderLayout();
	ShaderLayout();
};
};

#endif