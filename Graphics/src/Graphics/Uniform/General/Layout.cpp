#include "Graphics/Uniform/General/Layout.hpp"
#include "Graphics/Uniform/General/Base.hpp"

#include "Graphics/Shader/Base.hpp"



void Uniform::Layout::Clear()
{
	Uniforms.Clear();
}
void Uniform::Layout::Put(Uniform::Base & uniform)
{
	Uniforms.Insert(&uniform);
}
void Uniform::Layout::Put(Uniform::Base * uniform)
{
	if (uniform != nullptr)
	{
		Uniforms.Insert(uniform);
	}
}



Uniform::Layout::~Layout()
{ }
Uniform::Layout::Layout()
	: Shader(nullptr)
{ }
Uniform::Layout::Layout(Shader::Base & shader)
	: Shader(&shader)
{ }

Uniform::Layout::Layout(const Layout & other)
	: Shader(other.Shader)
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
	if (Shader == nullptr) { return; }
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniforms[i] -> Find(*Shader);
	}
}



#include "Graphics/Multiform/General/Base.hpp"
void Uniform::Layout::Find(Multiform::Base & multiform)
{
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniform::Base * uniform = Uniforms[i];
		if (multiform.Name == uniform -> Name)
		{
			multiform.Uniforms.Insert(uniform);
		}
	}
}





void Uniform::Layout::UpdateData()
{
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniforms[i] -> UpdateData();
	}
	if (Shader != nullptr)
	{
		for (unsigned int i = 0; i < Uniforms.Count(); i++)
		{
			Uniforms[i] -> UpdateData(*Shader);
		}
	}
}

#include "Graphics/Uniform/General/Buffer.hpp"
void Uniform::Layout::Bind(Buffer & uniform, GL::BlockBinding binding)
{
	if (Shader != nullptr)
	{
		Shader -> BindUniformBlockIndex(uniform.Index, binding);
	}
}
