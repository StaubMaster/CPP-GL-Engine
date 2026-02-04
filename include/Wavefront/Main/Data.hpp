#ifndef  WAVEFRONT_OBJ_MAIN_DATA_HPP
# define WAVEFRONT_OBJ_MAIN_DATA_HPP

# include "ValueType/Point3D.hpp"
# include "ValueType/Point4D.hpp"
# include "ValueType/ColorF4.hpp"

namespace Wavefront
{
namespace Main
{
struct Data
{
	Point4D	Position;
	Point3D	Texture;
	Point3D	Normal;
	ColorF4	Color;

	ColorF4	AmbientColor;
	ColorF4	DiffuseColor;
	float	SpecularPower;
	ColorF4	SpecularColor;
};
};
};

#endif