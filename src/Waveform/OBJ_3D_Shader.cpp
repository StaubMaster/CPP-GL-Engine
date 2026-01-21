#include "Waveform/OBJ_3D_Shader.hpp"
#include "Graphics/Shader/Code.hpp"

#include "DirectoryInfo.hpp"
#include "FileInfo.hpp"

#include <iostream>

#include "Miscellaneous/Container/Pointer.hpp"



/*OBJ_3D_Shader::OBJ_3D_Shader(const DirectoryInfo & dir)
	: Shader::Base(
		Container::Pointer<Shader::Code>(2, (Shader::Code[])
		{
			Shader::Code(dir.File("OBJ_S3D.vert")),
			Shader::Code(dir.File("OBJ.frag")),
		})
	),
	ViewPortSizeRatio(Uniform::NameShader("ViewPortSizeRatio", *this)),
	View(Uniform::NameShader("View", *this)),
	Depth(Uniform::NameShader("Depth", *this)),
	ColorToTex(Uniform::NameShader("ColorToTex", *this)),
	ShowLightFactor(Uniform::NameShader("ShowLightFactor", *this))
{
	//std::cout << "################################################################\n";
	//std::cout << dir.File("OBJ_S3D.vert").LoadText();
	//std::cout << "################################################################\n";
	//std::cout << dir.File("OBJ.frag").LoadText();
	//std::cout << "################################################################\n";
	(void)dir;
}*/
OBJ_3D_Shader::~OBJ_3D_Shader()
{ }
