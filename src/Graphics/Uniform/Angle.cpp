#include "Graphics/Uniform/Angle.hpp"
#include "ValueType/Angle.hpp"



Uniform::Angle::Angle(Uniform::NameShader name_shader) : Float1(name_shader)
{ }

void Uniform::Angle::Put(const ::Angle & obj)
{
	PutVoid(&obj);
}
