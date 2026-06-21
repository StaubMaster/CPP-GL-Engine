#include "Graphics/Buffer/Uniform.hpp"
#include "OpenGL.hpp"



Buffer::Uniform::~Uniform() { }
Buffer::Uniform::Uniform(GL::BufferDataUsage usage, unsigned int binding)
	: Buffer::Base(GL::BufferTarget::UniformBuffer, usage)
	, Binding(binding)
{ }



void Buffer::Uniform::BindBase()
{
	GL::BindBufferBase(Target, Binding, ID);
}
