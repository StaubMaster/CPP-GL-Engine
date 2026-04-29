#include "Graphics/Uniform/Angle.hpp"
#include "ValueType/Angle.hpp"



Uniform::Angle::Angle(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1, 1, 1)
{ }

void Uniform::Angle::Put(const ::Angle & obj)
{
	PutVoid(&obj);
}
