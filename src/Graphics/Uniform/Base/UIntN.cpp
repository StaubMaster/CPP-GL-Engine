#include "Graphics/Uniform/Base/UIntN.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::UIntN::UIntN(int count, Uniform::NameShader name_shader) : GBase(name_shader),
	Location(Find()),
	Count(count)
{ }



void Uniform::UIntN::PutVoid(const void * val)
{
	PutData((const unsigned int *)val);
}
