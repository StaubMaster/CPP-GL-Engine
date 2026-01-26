#include "Graphics/Texture/Base.hpp"
#include "ValueType/Undex3D.hpp"
#include "OpenGL.hpp"
#include <sstream>

#include "Debug.hpp"
#include "DataShow.hpp"
#include <iostream>

GL::TextureID Texture::Base::None = 0;

void Texture::Base::LogInfo(bool self) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "Texture Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << "ID " << ID << '\n';
	Debug::Log << Debug::Tabs << "Target " << ((unsigned int)Target) << '\n';
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}



Texture::Base::Base(GL::TextureTarget target) :
	Target(target),
	ID(None)
{ }
Texture::Base::~Base()
{ }

Texture::Base::Base(const Base & other) :
	Target(other.Target),
	ID(other.ID)
{ }
Texture::Base & Texture::Base::operator=(const Base & other)
{
	ID = other.ID;
	Target = other.Target;
	return *this;
}



bool Texture::Base::Exists() const { return (ID != None); }
bool Texture::Base::IsBound() const { return (Bound(Target) == ID); }
void Texture::Base::Bind()
{
	if (Exists() && !IsBound())
	{
		GL::BindTexture(Target, ID);
	}
}

GL::TextureID Texture::Base::Bound(GL::TextureTarget target)
{
	GL::ParameterName name;
	switch (target)
	{
		case GL::TextureTarget::Texture2DArray: name = GL::ParameterName::TextureBinding2DArray; break;
		default: return None;
	};
	int ID;
	GL::GetIntegerv(name, ID);
	return ID;
}
void Texture::Base::BindNone(GL::TextureTarget target)
{
	GL::BindTexture(target, None);
}



void Texture::Base::Create()
{
	if (ID != None) { return; }

	Debug::Log << "Texture::Base Creating " << ID << " ..." << Debug::Done;
	ID = GL::CreateTexture();
	Debug::Log << "Texture::Base Creating " << ID << " done" << Debug::Done;
}
void Texture::Base::Delete()
{
	if (ID == None) { return; }

	Debug::Log << "Texture::Base Deleting " << ID << " ..." << Debug::Done;
	GL::DeleteTexture(ID);
	ID = 0;
	Debug::Log << "Texture::Base Deleting " << ID << " done" << Debug::Done;
}



/*
GL_DEPTH_STENCIL_TEXTURE_MODE

GL_TEXTURE_BASE_LEVEL

GL_TEXTURE_COMPARE_FUNC
GL_TEXTURE_COMPARE_MODE

GL_TEXTURE_MIN_FILTER
	GL_NEAREST
	GL_LINEAR
	GL_NEAREST_MIPMAP_NEAREST
	GL_LINEAR_MIPMAP_NEAREST
	GL_NEAREST_MIPMAP_LINEAR
	GL_LINEAR_MIPMAP_LINEAR
GL_TEXTURE_MAG_FILTER
	GL_NEAREST
	GL_LINEAR

GL_TEXTURE_LOD_BIAS		LOD Offset ?
GL_TEXTURE_MIN_LOD
GL_TEXTURE_MAX_LOD
GL_TEXTURE_MAX_LEVEL

GL_TEXTURE_SWIZZLE_R
GL_TEXTURE_SWIZZLE_G
GL_TEXTURE_SWIZZLE_B
GL_TEXTURE_SWIZZLE_A
GL_TEXTURE_SWIZZLE_RGBA
	GL_RED		= col.r
	GL_GREEN	= col.g
	GL_BLUE		= col.b
	GL_ALPHA	= col.a
	GL_ZERO		= 0.0
	GL_ONE		= 1.0

GL_TEXTURE_WRAP_S	X
GL_TEXTURE_WRAP_T	Y
GL_TEXTURE_WRAP_R	Z
	GL_REPEAT				= Modular Loop
	GL_MIRRORED_REPEAT		= Modular Loop Reverse
	GL_CLAMP_TO_EDGE		= Edge
	GL_MIRROR_CLAMP_TO_EDGE	= 
	GL_CLAMP_TO_BORDER		= GL_TEXTURE_BORDER_COLOR
*/
void Texture::Base::DefaultParams()
{
	GL::TexParameteri(Target, GL::TextureParameterName::TextureWrapS, GL_REPEAT);
	GL::TexParameteri(Target, GL::TextureParameterName::TextureWrapT, GL_REPEAT);
	GL::TexParameteri(Target, GL::TextureParameterName::TextureMinFilter, GL_NEAREST);
	GL::TexParameteri(Target, GL::TextureParameterName::TextureMagFilter, GL_NEAREST);
	glGenerateMipmap((unsigned int)Target);
}



void Texture::Base::Full3D(Undex3D size, const void * data)
{
	//Debug::Log << "Texture: Full3D: " << size << Debug::Done;
	//std::cout << "Texture: Full3D: " << size << '\n';
	GL::TexImage3D(Target, 0, GL::TextureInternalFormat::Rgba8, size.X, size.Y, size.Z, 0, GL::TextureFormat::Rgba, GL::TextureType::UnsignedInt8888Rev, data);
}
void Texture::Base::Part3D(Undex3D size, Undex3D offset, const void * data)
{
	//Debug::Log << "Texture: Part3D: " << size << " | " << offset << Debug::Done;
	//std::cout << "Texture: Part3D: " << size << " | " << offset << '\n';
	GL::TexSubImage3D(Target, 0, offset.X, offset.Y, offset.Z, size.X, size.Y, size.Z, GL::TextureFormat::Rgba, GL::TextureType::UnsignedInt8888Rev, data);
}

