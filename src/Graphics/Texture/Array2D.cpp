#include "Graphics/Texture/Array2D.hpp"
#include "Display/SizeRatio2D.hpp"
#include "ValueType/Undex3D.hpp"

#include "Image.hpp"
#include "FileInfo.hpp"

#include "OpenGL.hpp"



Texture::Array2D::Array2D()
	: Texture::Base(GL::TextureTarget::Texture2DArray)
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



void Texture::Array2D::Assign(const Image & img)
{
	SizeRatio = Point2D(img.W(), img.H());
	Full3D(Undex3D(img.W(), img.H(), 1), img.Data());
	DefaultParams();
}
void Texture::Array2D::Assign(const FileInfo & file)
{
	Image img = file.LoadImage();
	Assign(img);
	img.Dispose();
}
void Texture::Array2D::Assign(unsigned int w, unsigned int h, const Container::Member<Image> & imgs)
{
	SizeRatio = Point2D(w, h);
	Full3D(Undex3D(w, h, imgs.Count()), NULL);
	Image missing = Image::Missing(Undex2D(4, 4));
	missing.Scale(Undex2D(w, h));
	for (unsigned int i = 0; i < imgs.Count(); i++)
	{
		if (imgs[i].Empty())
		{
			Part3D(Undex3D(w, h, 1), Undex3D(0, 0, i), missing.Data());
		}
		else
		{
			Image img = imgs[i].Scaled(Undex2D(w, h));
			Part3D(Undex3D(w, h, 1), Undex3D(0, 0, i), img.Data());
			img.Dispose();
		}
	}
	missing.Dispose();
	DefaultParams();
}
void Texture::Array2D::Assign(unsigned int w, unsigned int h, const Container::Member<FileInfo> & files)
{
	SizeRatio = Point2D(w, h);
	Full3D(Undex3D(w, h, files.Count()), NULL);
	Image missing = Image::Missing(Undex2D(4, 4));
	missing.Scale(Undex2D(w, h));
	for (unsigned int i = 0; i < files.Count(); i++)
	{
		Image img = files[i].LoadImage();
		if (img.Empty())
		{
			Part3D(Undex3D(w, h, 1), Undex3D(0, 0, i), missing.Data());
		}
		else
		{
			img.Scale(Undex2D(w, h));
			Part3D(Undex3D(w, h, 1), Undex3D(0, 0, i), img.Data());
			img.Dispose();
		}
	}
	missing.Dispose();
	DefaultParams();
}
