#include "Graphics/Uniform/Buffer.hpp"
#include "Graphics/Uniform/Layout.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::Buffer::Buffer(Uniform::Layout & layout, std::string name)
	: Uniform::Base(layout, name)
	, Index(0)
{ }



void Uniform::Buffer::BindBlock(GL::BlockBinding binding)
{
	(void)binding;
	//Layout.UniformBlockBinding(Index, binding);
}



void Uniform::Buffer::PutVoid(const void * val)
{
	(void)val;
}
