#include "Graphics/Multiform/Layout.hpp"
#include "Graphics/Multiform/Base/Base.hpp"
#include "Graphics/Uniform/Layout.hpp"



Multiform::Layout::~Layout()
{ }
Multiform::Layout::Layout()
{ }



void Multiform::Layout::Find(Uniform::Layout & layout)
{
	for (unsigned int i = 0; i < Multiforms.Count(); i++)
	{
		layout.Find(*Multiforms[i]);
	}
}
void Multiform::Layout::Find(Container::Array<Uniform::Layout *> & layouts)
{
	for (unsigned int i = 0; i < Multiforms.Count(); i++)
	{
		Multiforms[i] -> FindUniforms(layouts);
	}
}
