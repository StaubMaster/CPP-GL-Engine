#include "Graphics/Uniform/WindowBufferSize2D.hpp"
#include "Display/WindowBufferSize2D.hpp"
#include "DataStruct/Point2D.hpp"
#include "OpenGL/openGL.h"



Uniform::WindowBufferSize2D::WindowBufferSize2D(std::string name, Shader::Base & shader) : GBase(name, shader),
	WindowSize(name + ".WindowSize", shader),
	BufferSize(name + ".BufferSize", shader),
	Ratio(name + ".Ratio", shader)
{

}

void Uniform::WindowBufferSize2D::PutData(::WindowBufferSize2D sr)
{
	WindowSize.PutData(sr.WindowSize);
	BufferSize.PutData(sr.BufferSize);
	Ratio.PutData(sr.Ratio);
}
