#include "Graphics/Uniform/WindowBufferSize2D.hpp"
#include "Display/WindowBufferSize2D.hpp"



Uniform::WindowBufferSize2D::WindowBufferSize2D(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, WindowSize(shader, name + ".WindowSize")
	, BufferSize(shader, name + ".BufferSize")
	, Ratio(shader, name + ".Ratio")
{ }



void Uniform::WindowBufferSize2D::Put(const ::WindowBufferSize2D & obj)
{
	WindowSize.Put(obj.WindowSize);
	BufferSize.Put(obj.BufferSize);
	Ratio.Put(obj.Ratio);
}
