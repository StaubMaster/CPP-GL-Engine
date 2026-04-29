#include "Graphics/Uniform/DepthFactors.hpp"
#include "ValueType/DepthFactors.hpp"



Uniform::DepthFactors::DepthFactors(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 1, 1, 7)
{ }



void Uniform::DepthFactors::Put(const ::DepthFactors & obj)
{
	PutVoid(&obj);
}
