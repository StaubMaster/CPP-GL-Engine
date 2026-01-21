#include "Graphics/Texture/Base.hpp"
#include "ValueType/Undex3D.hpp"
#include "OpenGL/openGL.h"
#include <sstream>

#include "Debug.hpp"
#include "DataShow.hpp"
#include <iostream>

/*	Debug::Log << "GL_TEXTURE_...\n";
	Debug::Log << "GL_TEXTURE_1D" << ' ' << GL_TEXTURE_1D << '\n';
	Debug::Log << "GL_TEXTURE_2D" << ' ' << GL_TEXTURE_2D << '\n';
	Debug::Log << "GL_TEXTURE_3D" << ' ' << GL_TEXTURE_3D << '\n';
	Debug::Log << "GL_TEXTURE_1D_ARRAY" << ' ' << GL_TEXTURE_1D_ARRAY << '\n';
	Debug::Log << "GL_TEXTURE_2D_ARRAY" << ' ' << GL_TEXTURE_2D_ARRAY << '\n';
	Debug::Log << "GL_TEXTURE_RECTANGLE" << ' ' << GL_TEXTURE_RECTANGLE << '\n';
	Debug::Log << "GL_TEXTURE_CUBE_MAP" << ' ' << GL_TEXTURE_CUBE_MAP << '\n';
	Debug::Log << "GL_TEXTURE_CUBE_MAP_ARRAY" << ' ' << GL_TEXTURE_CUBE_MAP_ARRAY << '\n';
	Debug::Log << "GL_TEXTURE_BUFFER" << ' ' << GL_TEXTURE_BUFFER << '\n';
	Debug::Log << "GL_TEXTURE_2D_MULTISAMPLE" << ' ' << GL_TEXTURE_2D_MULTISAMPLE << '\n';
	Debug::Log << "GL_TEXTURE_2D_MULTISAMPLE_ARRAY" << ' ' << GL_TEXTURE_2D_MULTISAMPLE_ARRAY << '\n';
	Debug::Log << Debug::Done;
*/

TextureType Texture::Base::None = 0;

void Texture::Base::LogInfo(bool self) const
{
	if (self)
	{
		Debug::Log << Debug::Tabs << "Texture Info\n";
		Debug::Log << Debug::TabInc;
	}
	Debug::Log << Debug::Tabs << "ID " << ID << '\n';
	Debug::Log << Debug::Tabs << "Type " << Type << '\n';
	if (self)
	{
		Debug::Log << Debug::TabDec;
		Debug::Log << Debug::Done;
	}
}



Texture::Base::Base(unsigned int type) :
	Type(type),
	ID(None)
{ }
Texture::Base::~Base()
{ }

Texture::Base::Base(const Base & other) :
	Type(other.Type),
	ID(other.ID)
{ }
Texture::Base & Texture::Base::operator=(const Base & other)
{
	Type = other.Type;
	ID = other.ID;
	return *this;
}



bool Texture::Base::Exists() const { return (ID != None); }
bool Texture::Base::IsBound() const { return (Bound(Type) == ID); }
void Texture::Base::Bind()
{
	if (Exists() && !IsBound())
	{
		glBindTexture(Type, ID);
	}
}

TextureID Texture::Base::Bound(TextureType type)
{
	unsigned int t;
	switch (type)
	{
		case GL_TEXTURE_2D_ARRAY:	t = GL_TEXTURE_BINDING_2D_ARRAY;	break;
		default: return None;
	};
	int ID;
	glGetIntegerv(t, &ID);
	return ID;
}
void Texture::Base::BindNone(TextureType type)
{
	glBindTexture(type, None);
}



void Texture::Base::Create()
{
	if (ID != None) { return; }

	Debug::Log << "Texture::Base Creating " << ID << " ..." << Debug::Done;
	glGenTextures(1, &ID);
	glBindTexture(Type, ID);
	Debug::Log << "Texture::Base Creating " << ID << " done" << Debug::Done;
}
void Texture::Base::Delete()
{
	if (ID == None) { return; }

	Debug::Log << "Texture::Base Deleting " << ID << " ..." << Debug::Done;
	glDeleteTextures(1, &ID);
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
	glTexParameteri(Type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(Type, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(Type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(Type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glGenerateMipmap(Type);
}



void Texture::Base::Full3D(Undex3D size, const void * data)
{
	//Debug::Log << "Texture: Full3D: " << size << Debug::Done;
	//std::cout << "Texture: Full3D: " << size << '\n';
	glTexImage3D(Type, 0, GL_RGBA8, size.X, size.Y, size.Z, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, data);
}
void Texture::Base::Part3D(Undex3D size, Undex3D offset, const void * data)
{
	//Debug::Log << "Texture: Part3D: " << size << " | " << offset << Debug::Done;
	//std::cout << "Texture: Part3D: " << size << " | " << offset << '\n';
	glTexSubImage3D(Type, 0, offset.X, offset.Y, offset.Z, size.X, size.Y, size.Z, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, data);
}

