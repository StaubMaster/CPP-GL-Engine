
#ifndef  OBJ_MAIN_HPP
# define OBJ_MAIN_HPP



# include "ValueType/Point3D.hpp"
# include "ValueType/Point4D.hpp"
# include "ValueType/ColorF4.hpp"



# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"

# include "Graphics/Attribute/Point4D.hpp"
# include "Graphics/Attribute/Point3D.hpp"
# include "Graphics/Attribute/ColorF4.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"



//# include "Graphics/Buffer/BaseBuffer.hpp"
# include "Graphics/Buffer/Attribute.hpp"



struct OBJ_MainData
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



class OBJ_MainBuffer : public Buffer::Attribute
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
	OBJ_MainBuffer(
		unsigned int indexPosition,
		unsigned int indexTexture,
		unsigned int indexNormal,
		unsigned int indexColor,
		unsigned int indexAmbientColor,
		unsigned int indexDiffuseColor,
		unsigned int indexSpecularPower,
		unsigned int indexSpecularColor
	);
	~OBJ_MainBuffer();
};



#endif
