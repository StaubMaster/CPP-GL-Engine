#ifndef  POLYHEDRA_SIMPLE3D_SHADER_HPP
# define POLYHEDRA_SIMPLE3D_SHADER_HPP

# include "Graphics/Shader/Base.hpp"
# include "Graphics/UniformsInclude.hpp"

class DirectoryContext;

namespace PolyHedra_Simple3D
{
class Shader : public ::Shader::Base
{
	public:
	Uniform::WindowBufferSize2D	WindowSize;
	Uniform::Trans3D			View;
	Uniform::Depth				Depth;

	public:
	Shader();
	Shader(const DirectoryContext & dir);
	~Shader();
};
};

#endif