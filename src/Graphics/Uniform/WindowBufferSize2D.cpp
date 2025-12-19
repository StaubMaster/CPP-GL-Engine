#include "Graphics/Uniform/WindowBufferSize2D.hpp"
#include "Display/WindowBufferSize2D.hpp"
#include "DataStruct/Point2D.hpp"
#include "OpenGL/openGL.h"



Uniform::WindowBufferSize2D::WindowBufferSize2D(Uniform::NameShader name_shader) : GBase(name_shader),
	WindowSize(name_shader.Suffix(".WindowSize")),
	BufferSize(name_shader.Suffix(".BufferSize")),
	Ratio(name_shader.Suffix(".Ratio"))
{ }

void Uniform::WindowBufferSize2D::PutData(::WindowBufferSize2D sr)
{
	WindowSize.PutData(sr.WindowSize);
	BufferSize.PutData(sr.BufferSize);
	Ratio.PutData(sr.Ratio);
}
