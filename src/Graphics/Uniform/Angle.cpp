#include "Graphics/Uniform/Angle.hpp"
#include "ValueType/Angle.hpp"



Uniform::Angle::Angle(::Shader::Base & shader, std::string name)
	: Float1(shader, name)
{ }

void Uniform::Angle::Put(const ::Angle & obj)
{
	PutVoid(&obj);
}
