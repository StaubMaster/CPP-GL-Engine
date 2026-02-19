#include "Graphics/Uniform/DepthFactors.hpp"
#include "ValueType/DepthFactors.hpp"



Uniform::DepthFactors::DepthFactors(::Shader::Base & shader, std::string name)
	: Float1(shader, name, 7)
{ }



void Uniform::DepthFactors::Put(const ::DepthFactors & obj)
{
	PutVoid(&obj);
}
