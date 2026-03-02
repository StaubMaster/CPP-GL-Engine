#include "Graphics/Uniform/DisplaySize.hpp"
#include "Display/DisplaySize.hpp"



Uniform::DisplaySize::DisplaySize(::Shader::Base & shader, std::string name)
	: GBase(shader, name)
	, Ratio(shader, name + ".Ratio")
	, Window(shader, name + ".Window")
	, Buffer(shader, name + ".Buffer")
{ }



void Uniform::DisplaySize::Put(const ::DisplaySize & obj)
{
	Ratio.Put(obj.Ratio);
	Window.Put(obj.Window);
	Buffer.Put(obj.Buffer);
}
