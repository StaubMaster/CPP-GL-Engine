#include "PolyHedra/Simple3D/Shader.hpp"
#include "Graphics/Shader/Code.hpp"

#include "DirectoryContext.hpp"
#include "FileContext.hpp"

#include "Miscellaneous/Container/Pointer.hpp"



PolyHedra_Simple3D::Shader::Shader()
	: ::Shader::Base(),
	WindowSize(Uniform::NameShader("WindowSize", *this)),
	View(Uniform::NameShader("View", *this)),
	Depth(Uniform::NameShader("Depth", *this))
{ }
PolyHedra_Simple3D::Shader::Shader(const DirectoryContext & dir)
	: ::Shader::Base(
		Container::Pointer<::Shader::Code>(2, (::Shader::Code[])
		{
			::Shader::Code(dir.File("PH_S3D.vert")),
			//Shader::Code::FromFile(dir.File("PH_solar.frag")),
			//Shader::Code::FromFile(dir.File("PH_ULight.frag")),
			::Shader::Code(dir.File("PH_Full.frag")),
		})
	),
	WindowSize(Uniform::NameShader("WindowSize", *this)),
	View(Uniform::NameShader("View", *this)),
	Depth(Uniform::NameShader("Depth", *this))
{ }
PolyHedra_Simple3D::Shader::~Shader()
{ }
