#include "PolyHedra/Simple3D/Shader.hpp"
#include "Graphics/Shader/Code.hpp"

#include "DirectoryInfo.hpp"
#include "FileInfo.hpp"

#include "Miscellaneous/Container/Pointer.hpp"



PolyHedra_Simple3D::Shader::Shader()
	: ::Shader::Base()
	, DisplaySize(*this, "DisplaySize")
	, View(*this, "View")
	, Depth(*this, "Depth")
	, FOV(*this, "FOV")
{ }
PolyHedra_Simple3D::Shader::~Shader()
{ }
