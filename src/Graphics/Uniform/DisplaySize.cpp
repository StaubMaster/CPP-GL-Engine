#include "Graphics/Uniform/DisplaySize.hpp"
#include "Display/DisplaySize.hpp"



Uniform::DisplaySize::DisplaySize(Uniform::Layout & layout,  std::string name)
	: GBase(layout, name)
	, Ratio(layout, name + ".Ratio")
	, Window(layout, name + ".Window")
	, Buffer(layout, name + ".Buffer")
{ }



void Uniform::DisplaySize::Put(const ::DisplaySize & obj)
{
	Ratio.Put(obj.Ratio);
	Window.Put(obj.Window);
	Buffer.Put(obj.Buffer);
}
