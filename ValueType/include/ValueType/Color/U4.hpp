#ifndef  COLOR_U4_HPP
# define COLOR_U4_HPP

struct ColorF4;

struct ColorU4
{
	unsigned char	R = 0;
	unsigned char	G = 0;
	unsigned char	B = 0;
	unsigned char	A = 0;

	~ColorU4() = default;
	ColorU4() = default;
	ColorU4(const ColorU4 & other) = default;
	ColorU4 & operator=(const ColorU4 & other) = default;

	ColorU4(unsigned char r, unsigned char g, unsigned char b);
	ColorU4(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

	static ColorU4	FromRGBA(unsigned int rgba);
	unsigned int	ToRGBA() const;

	static ColorU4	FromRGB(unsigned int rgb);

//	ColorU4(const ColorF4 & other);
//	ColorU4 & operator=(const ColorF4 & other);
	ColorF4		ToColorF4() const;
};

#endif