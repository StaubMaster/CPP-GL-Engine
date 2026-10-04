#include "Graphics/Uniform/General/Layout.hpp"
#include "Graphics/Uniform/General/Base.hpp"

#include "Graphics/Shader/Base.hpp"

#include "Graphics/Multiform/General/Base.hpp"
#include "Graphics/Uniform/General/Buffer.hpp"



void Uniform::Layout::Clear()
{
	unsigned int idx = 0xFFFFFFFF;
	unsigned int temp = 0xFFFFFFFF;
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		if (Uniforms[i] -> IsDynamic)
		{
			temp = i;
			break;
		}
	}
	while (temp != 0xFFFFFFFF)
	{
		idx = temp;
		temp = 0xFFFFFFFF;
		for (unsigned int i = idx + 1; i < Uniforms.Count(); i++)
		{
			if (Uniforms[i] -> IsDynamic)
			{
				temp = i;
				break;
			}
		}
		delete Uniforms[idx];
	}
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



void Uniform::Layout::AssignShader(::Shader::Base & shader)
{
	Shader = &shader;
}



Uniform::Layout::~Layout()
{
	unsigned int idx = 0xFFFFFFFF;
	unsigned int temp = 0xFFFFFFFF;
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		if (Uniforms[i] -> IsDynamic)
		{
			temp = i;
			break;
		}
	}
	while (temp != 0xFFFFFFFF)
	{
		idx = temp;
		temp = 0xFFFFFFFF;
		for (unsigned int i = idx + 1; i < Uniforms.Count(); i++)
		{
			if (Uniforms[i] -> IsDynamic)
			{
				temp = i;
				break;
			}
		}
		delete Uniforms[idx];
	}
}

Uniform::Layout::Layout(Shader::Base & shader)
	: Shader(&shader)
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

void Uniform::Layout::Bind(Buffer & uniform, GL::BlockBinding binding)
{
	if (Shader != nullptr)
	{
		Shader -> BindUniformBlockIndex(uniform.Index, binding);
	}
}
