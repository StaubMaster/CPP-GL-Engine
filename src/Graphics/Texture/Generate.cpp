#include "Graphics/Texture/Generate.hpp"
#include "Image.hpp"



Image Texture::Generate::NoSkin()
{
	Image img(1, 1);

	img.Pixel(0, 0) = 0xFFFFFF;

	return img;
}

Image Texture::Generate::Orientation2D()
{
	Image img(2, 2);

	img.Pixel(0, 0) = 0x000000;
	img.Pixel(1, 0) = 0x0000FF;
	img.Pixel(1, 1) = 0x00FF00;
	img.Pixel(0, 1) = 0xFF0000;

	return img;
}

Image Texture::Generate::Orientation3D()
{
	Image img(8, 4);

	img.Pixel(0, 0) = 0x000000;
	img.Pixel(1, 0) = 0x0000FF;
	img.Pixel(2, 0) = 0x000000;
	img.Pixel(3, 0) = 0x00FF00;
	img.Pixel(4, 0) = 0x000000;
	img.Pixel(5, 0) = 0xFF0000;
	img.Pixel(6, 0) = 0x7F7F7F;
	img.Pixel(7, 0) = 0x7F7F7F;

	img.Pixel(0, 1) = 0x00FF00;
	img.Pixel(1, 1) = 0x00FFFF;
	img.Pixel(2, 1) = 0xFF0000;
	img.Pixel(3, 1) = 0xFFFF00;
	img.Pixel(4, 1) = 0x0000FF;
	img.Pixel(5, 1) = 0xFF00FF;
	img.Pixel(6, 1) = 0x7F7F7F;
	img.Pixel(7, 1) = 0x7F7F7F;

	img.Pixel(0, 2) = 0xFF0000;
	img.Pixel(1, 2) = 0xFF00FF;
	img.Pixel(2, 2) = 0x0000FF;
	img.Pixel(3, 2) = 0x00FFFF;
	img.Pixel(4, 2) = 0x00FF00;
	img.Pixel(5, 2) = 0xFFFF00;
	img.Pixel(6, 2) = 0x7F7F7F;
	img.Pixel(7, 2) = 0x7F7F7F;

	img.Pixel(0, 3) = 0xFFFF00;
	img.Pixel(1, 3) = 0xFFFFFF;
	img.Pixel(2, 3) = 0xFF00FF;
	img.Pixel(3, 3) = 0xFFFFFF;
	img.Pixel(4, 3) = 0x00FFFF;
	img.Pixel(5, 3) = 0xFFFFFF;
	img.Pixel(6, 3) = 0x7F7F7F;
	img.Pixel(7, 3) = 0x7F7F7F;

	return img;
}
