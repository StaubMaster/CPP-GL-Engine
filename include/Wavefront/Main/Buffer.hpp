#ifndef  WAVEFRONT_OBJ_MAIN_BUFFER_HPP
# define WAVEFRONT_OBJ_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Attribute.hpp"

# include "Graphics/Attribute/Point4D.hpp"
# include "Graphics/Attribute/Point3D.hpp"
# include "Graphics/Attribute/ColorF4.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Wavefront
{
namespace Main
{
class Buffer : public ::Buffer::Attribute
{
	private:
	::Attribute::Point4D	Position;
	::Attribute::Point3D	Texture;
	::Attribute::Point3D	Normal;
	::Attribute::ColorF4	Color;

	::Attribute::ColorF4	AmbientColor;
	::Attribute::ColorF4	DiffuseColor;
	::Attribute::FloatN		SpecularPower;
	::Attribute::ColorF4	SpecularColor;

	public:
	Buffer(
		unsigned int indexPosition,
		unsigned int indexTexture,
		unsigned int indexNormal,
		unsigned int indexColor,
		unsigned int indexAmbientColor,
		unsigned int indexDiffuseColor,
		unsigned int indexSpecularPower,
		unsigned int indexSpecularColor
	);
	~Buffer();

	Buffer(const Buffer & other) = delete;
	Buffer & operator=(const Buffer & other) = delete;
};
};
};

#endif