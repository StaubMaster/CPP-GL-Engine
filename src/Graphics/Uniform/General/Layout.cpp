#include "Graphics/Uniform/General/Layout.hpp"
#include "Graphics/Uniform/General/Base.hpp"

#include "Graphics/Shader/Base.hpp"



Uniform::Layout::~Layout()
{ }
Uniform::Layout::Layout()
//	: Uniforms()
	: Shader(nullptr)
{ }

Uniform::Layout::Layout(const Layout & other)
//	: Uniforms(other.Uniforms)
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



void Uniform::Layout::UniformBlockBinding(GL::BlockIndex index, GL::BlockBinding binding)
{
	if (Shader != nullptr)
	{
		Shader -> UniformBlockBinding(index, binding);
	}
}



void Uniform::Layout::UpdateData()
{
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniforms[i] -> UpdateData();
	}
}




#include "Graphics/Uniform/General/FloatNBase.hpp"
#include "Graphics/Uniform/General/UIntNTypeBase.hpp"
#include "Graphics/Uniform/General/Buffer.hpp"

void Uniform::Layout::Find(FloatNBase * uniform) const
{
	if (uniform != nullptr)
	{
		if (Shader != nullptr)
		{
			uniform -> Index = Shader -> UniformLocation(uniform -> Name.c_str());
		}
		else
		{
			uniform -> Index = -1;
		}
	}
}
void Uniform::Layout::Find(UIntNBase * uniform) const
{
	if (uniform != nullptr)
	{
		if (Shader != nullptr)
		{
			uniform -> Index = Shader -> UniformLocation(uniform -> Name.c_str());
		}
		else
		{
			uniform -> Index = -1;
		}
	}
}
void Uniform::Layout::Find(Buffer * uniform) const
{
	if (uniform != nullptr)
	{
		if (Shader != nullptr)
		{
			uniform -> Index = Shader -> UniformBlockIndex(uniform -> Name.c_str());
		}
		else
		{
			uniform -> Index = -1;
		}
	}
}

void Uniform::Layout::Find()
{
	for (unsigned int i = 0; i < Uniforms.Count(); i++)
	{
		Uniform::Base * uniform = Uniforms[i];
		Find(dynamic_cast<Uniform::FloatNBase*>(uniform));
		Find(dynamic_cast<Uniform::UIntNBase*>(uniform));
		Find(dynamic_cast<Uniform::Buffer*>(uniform));
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
