#include "Graphics/Uniform/DepthFactors.hpp"
#include "ValueType/DepthFactors.hpp"



Uniform::DepthFactors::DepthFactors(Uniform::NameShader name_shader) : Float1(name_shader, 7)
{ }



void Uniform::DepthFactors::Put(const ::DepthFactors & obj)
{
	PutVoid(&obj);
}
