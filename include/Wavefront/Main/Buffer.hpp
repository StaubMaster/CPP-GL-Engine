#ifndef  WAVEFRONT_OBJ_MAIN_BUFFER_HPP
# define WAVEFRONT_OBJ_MAIN_BUFFER_HPP

# include "Graphics/Buffer/Array.hpp"

# include "Graphics/Attribute/Point4D.hpp"
# include "Graphics/Attribute/Point3D.hpp"
# include "Graphics/Attribute/ColorF4.hpp"
# include "Graphics/Attribute/Base/Float1.hpp"

namespace BufferArray { class Base; };

namespace Wavefront
{
namespace Main
{
class Buffer : public ::Buffer::Array
{
	public:
	::Attribute::Point4D	Position;
	::Attribute::Point3D	Texture;
	::Attribute::Point3D	Normal;
	::Attribute::ColorF4	Color;

	::Attribute::ColorF4	AmbientColor;
	::Attribute::ColorF4	DiffuseColor;
	::Attribute::Float1		SpecularPower;
	::Attribute::ColorF4	SpecularColor;

	public:
	~Buffer();
	Buffer(VertexArray & vertex_array);

	Buffer(const Buffer & other) = delete;
	Buffer & operator=(const Buffer & other) = delete;
};
};
};

#endif