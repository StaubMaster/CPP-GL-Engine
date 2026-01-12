#include "PolyHedra/Simple3D/Shader.hpp"
#include "Graphics/Shader/Code.hpp"

#include "DirectoryInfo.hpp"
#include "FileInfo.hpp"

#include "Miscellaneous/Container/Pointer.hpp"



PolyHedra_Simple3D::Shader::Shader()
	: ::Shader::Base(),
	WindowSize(Uniform::NameShader("WindowSize", *this)),
	View(Uniform::NameShader("View", *this)),
	Depth(Uniform::NameShader("Depth", *this)),
	FOV(Uniform::NameShader("FOV", *this))
{ }
PolyHedra_Simple3D::Shader::Shader(const DirectoryInfo & dir)
	: ::Shader::Base(
		Container::Pointer<::Shader::Code>(2, (::Shader::Code[])
		{
			::Shader::Code(dir.File("PH_S3D.vert")),
			::Shader::Code(dir.File("PH_Full.frag")),
		})
	),
	WindowSize(Uniform::NameShader("WindowSize", *this)),
	View(Uniform::NameShader("View", *this)),
	Depth(Uniform::NameShader("Depth", *this)),
	FOV(Uniform::NameShader("FOV", *this))
{ }
PolyHedra_Simple3D::Shader::~Shader()
{ }
