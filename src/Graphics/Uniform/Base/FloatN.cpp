#include "Graphics/Uniform/Base/FloatN.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::FloatN::FloatN(int count, Uniform::NameShader name_shader) : GBase(name_shader),
	Location(Locate()),
	Count(count)
{ }



void Uniform::FloatN::ReLocate()
{
	Location = Locate();
}
void Uniform::FloatN::PutVoid(const void * val)
{
	PutData((const float *)val);
}
