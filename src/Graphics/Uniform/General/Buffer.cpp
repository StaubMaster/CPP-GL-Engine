#include "Graphics/Uniform/General/Buffer.hpp"
#include "Graphics/Uniform/General/Layout.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::Buffer::Buffer(Uniform::Layout & layout, std::string name)
	: Uniform::Base(layout, name)
	, Index(0)
{ }



void Uniform::Buffer::PutVoid(const void * val)
{
	(void)val;
}
