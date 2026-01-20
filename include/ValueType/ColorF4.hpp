#ifndef  COLOR_F4_HPP
# define COLOR_F4_HPP

struct ColorF4
{
	public:
	float R;
	float G;
	float B;
	float A;

	public:
	ColorF4();
	ColorF4(float r, float g, float b);
	ColorF4(float r, float g, float b, float a);
	~ColorF4();

	ColorF4(const ColorF4 & other);
	ColorF4 & operator=(const ColorF4 & other);

	public:
	static ColorF4 FromRGB(unsigned int rgb);
	static ColorF4 FromRGBA(unsigned int rgba);

	unsigned int ToRGBA() const;
};

#endif