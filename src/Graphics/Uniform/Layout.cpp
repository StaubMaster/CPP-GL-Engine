#include "Graphics/Uniform/Layout.hpp"
#include "Graphics/Uniform/Base/Base.hpp"

#include "Graphics/Shader/Base.hpp"



Uniform::Layout::~Layout()
{ }
Uniform::Layout::Layout()
	: Uniforms()
	, Shader(nullptr)
{ }

Uniform::Layout::Layout(const Layout & other)
	: Uniforms(other.Uniforms)
	, Shader(other.Shader)
{ }



bool Uniform::Layout::IsBound() const
{
	if (Shader != nullptr)
	{
		return Shader -> IsBound();
	}
	return false;
}
void Uniform::Layout::Bind()
{
	if (Shader != nullptr)
	{
		Shader -> Bind();
	}
}



void Uniform::Layout::Find()
{
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniforms[i] -> ReLocate();
	}
}
void Uniform::Layout::PutMultiformData()
{
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniforms[i] -> PutMultiformData();
	}
}
int Uniform::Layout::LocateUniform(const char * name) const
{
	if (Shader != nullptr)
	{
		return Shader -> LocateUniform(name);
	}
	return -1;
}
