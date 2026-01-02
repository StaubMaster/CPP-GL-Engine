#include "Graphics/Texture/Array2D.hpp"
#include "Display/SizeRatio2D.hpp"

#include "Format/Image.hpp"
#include "FileContext.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



Texture::Array2D::Array2D()
	: Texture::Base(GL_TEXTURE_2D_ARRAY)
{ }
Texture::Array2D::~Array2D()
{ }

Texture::Array2D::Array2D(const Array2D & other) :
	Base(other)
{ }
Texture::Array2D & Texture::Array2D::operator=(const Array2D & other)
{
	Base::operator=(other);
	return *this;
}



void Texture::Array2D::Init3D(unsigned int w, unsigned int h, unsigned int l, const void * data)
{
	SizeRatio = SizeRatio2D(Point2D(w, h));
	glTexImage3D(Type, 0, GL_RGBA8, w, h, l, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, data);
}
void Texture::Array2D::InitStuff()
{
	glTexParameteri(Type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(Type, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(Type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(Type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glGenerateMipmap(Type);
}
void Texture::Array2D::Sub3D(unsigned int w, unsigned int h, unsigned int l, const Image & img)
{
	Image * scaled = img.Scale(w, h);
	glTexSubImage3D(Type, 0, 0, 0, l, w, h, 1, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, scaled -> Data32);
	delete scaled;
}



void Texture::Array2D::Assign(const Image * img)
{
	Init3D(img -> W, img -> H, 1, img -> Data32);
	InitStuff();
}
void Texture::Array2D::Assign(const FileContext & file)
{
	Image * img = file.LoadImagePNG();
	Assign(img);
	delete img;
}
void Texture::Array2D::Assign(unsigned int w, unsigned int h, const Container::Member<Image*> & imgs)
{
	Init3D(w, h, imgs.Count(), NULL);
	Image * missing = Image::Missing();
	for (unsigned int i = 0; i < imgs.Count(); i++)
	{
		const Image * img = imgs[i];
		if (img == NULL) { img = missing; }
		Sub3D(w, h, i, *img);
	}
	delete missing;
	InitStuff();
}
void Texture::Array2D::Assign(unsigned int w, unsigned int h, const Container::Member<FileContext> & files)
{
	Init3D(w, h, files.Count(), NULL);
	Image * missing = Image::Missing();
	for (unsigned int i = 0; i < files.Count(); i++)
	{
		const Image * img = files[i].LoadImagePNG();
		if (img == NULL) { img = missing; }
		Sub3D(w, h, i, *img);
		if (img != missing) { delete img; }
	}
	delete missing;
	InitStuff();
}
