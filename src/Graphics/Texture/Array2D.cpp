#include "Graphics/Texture/Array2D.hpp"
#include "Display/SizeRatio2D.hpp"
#include "DataStruct/Undex3D.hpp"

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



void Texture::Array2D::Assign(const Image * img)
{
	SizeRatio = Point2D(img -> W, img -> H);
	Full3D(Undex3D(img -> W, img -> H, 1), img -> Data32);
	DefaultParams();
}
void Texture::Array2D::Assign(const FileContext & file)
{
	Image * img = file.LoadImagePNG();
	Assign(img);
	delete img;
}
void Texture::Array2D::Assign(unsigned int w, unsigned int h, const Container::Member<Image*> & imgs)
{
	SizeRatio = Point2D(w, h);
	Full3D(Undex3D(w, h, imgs.Count()), NULL);
	Image * missing = Image::Missing();
	for (unsigned int i = 0; i < imgs.Count(); i++)
	{
		const Image * img = imgs[i];
		if (img == NULL) { img = missing; }
		Part3D(Undex3D(w, h, 1), Undex3D(0, 0, i), img -> Data32);
	}
	delete missing;
	DefaultParams();
}
void Texture::Array2D::Assign(unsigned int w, unsigned int h, const Container::Member<FileContext> & files)
{
	SizeRatio = Point2D(w, h);
	Full3D(Undex3D(w, h, files.Count()), NULL);
	Image * missing = Image::Missing();
	for (unsigned int i = 0; i < files.Count(); i++)
	{
		const Image * img = files[i].LoadImagePNG();
		if (img == NULL) { img = missing; }
		Part3D(Undex3D(w, h, 1), Undex3D(0, 0, i), img -> Data32);
		if (img != missing) { delete img; }
	}
	delete missing;
	DefaultParams();
}
