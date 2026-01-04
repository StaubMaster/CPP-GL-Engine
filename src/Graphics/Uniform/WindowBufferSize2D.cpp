#include "Graphics/Uniform/WindowBufferSize2D.hpp"
#include "Display/WindowBufferSize2D.hpp"



Uniform::WindowBufferSize2D::WindowBufferSize2D(Uniform::NameShader name_shader) : GBase(name_shader),
	WindowSize(name_shader.Suffix(".WindowSize")),
	BufferSize(name_shader.Suffix(".BufferSize")),
	Ratio(name_shader.Suffix(".Ratio"))
{ }



void Uniform::WindowBufferSize2D::Put(const ::WindowBufferSize2D & obj)
{
	WindowSize.Put(obj.WindowSize);
	BufferSize.Put(obj.BufferSize);
	Ratio.Put(obj.Ratio);
}
