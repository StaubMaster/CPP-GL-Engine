#include "Graphics/Uniform/DepthFactors.hpp"
#include "DataStruct/DepthFactors.hpp"



Uniform::DepthFactors::DepthFactors(Uniform::NameShader name_shader) : GBase(name_shader),
	Location(7, name_shader)
{ }

void Uniform::DepthFactors::PutData(::DepthFactors val)
{
	Location.PutVoid(&val);
}
