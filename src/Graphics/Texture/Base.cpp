#include "Graphics/Texture/Base.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



Texture::Base::Base(unsigned int type) :
	ID(0),
	Type(type)
{
	Create();
	Debug::Log << "++++ Texture::Base " << ID << Debug::Done;
}
Texture::Base::~Base()
{
	Debug::Log << "---- Texture::Base " << ID << Debug::Done;
	Delete();
}

Texture::Base::Base(const Base & other) :
	ID(other.ID),
	Type(other.Type)
{
	Debug::Log << "==== Texture::Base " << ID << Debug::Done;
}
Texture::Base & Texture::Base::operator=(const Base & other)
{
	Debug::Log << "==== Texture::Base " << ID << " operator=" << Debug::Done;
	ID = other.ID;
	Type = other.Type;
	return *this;
}



void Texture::Base::Create()
{
	if (ID != 0) { return; }
	Debug::Log << "Texture::Base Creating " << ID << " ..." << Debug::Done;
	glGenTextures(1, &ID);
	glBindTexture(Type, ID);
	Debug::Log << "Texture::Base Creating " << ID << " done" << Debug::Done;
}
void Texture::Base::Delete()
{
	if (ID == 0) { return; }
	Debug::Log << "Texture::Base Deleting " << ID << " ..." << Debug::Done;
	glDeleteTextures(1, &ID);
	ID = 0;
	Debug::Log << "Texture::Base Deleting " << ID << " done" << Debug::Done;
}



void Texture::Base::Bind()
{
	glBindTexture(Type, ID);
}
