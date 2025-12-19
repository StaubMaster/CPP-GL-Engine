#include "DataStruct/Main/Waveform/OBJ_3D_Shader.hpp"
#include "Graphics/Shader/Code.hpp"

#include "DirectoryContext.hpp"
#include "FileContext.hpp"

#include <iostream>



OBJ_3D_Shader::OBJ_3D_Shader(const DirectoryContext & dir)
	: Shader::Base((const Shader::Code []) {
		Shader::Code::FromFile(dir.File("OBJ_S3D.vert")),
		Shader::Code::FromFile(dir.File("OBJ.frag")),
	}, 2),
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
}
OBJ_3D_Shader::~OBJ_3D_Shader()
{ }
