#include "Graphics/Uniform/Base/FloatN.hpp"
#include "Graphics/Shader/Base.hpp"

#include <iostream>


Uniform::FloatN::FloatN(int count, Uniform::NameShader name_shader) : GBase(name_shader),
	Location(Find()),
	Count(count)
{ }



void Uniform::FloatN::PutVoid(const void * val)
{
	std::cout << "Uniform" << ' ' << "FloatN" << '\n';
	PutData((const float *)val);
}
