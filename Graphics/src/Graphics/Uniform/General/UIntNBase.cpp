#include "Graphics/Uniform/General/UIntNBase.hpp"
#include "Graphics/Uniform/General/Layout.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::UIntNBase::~UIntNBase()
{ }

Uniform::UIntNBase::UIntNBase(std::string name)
	: Base(name)
{ }
Uniform::UIntNBase::UIntNBase(Uniform::Layout & layout, std::string name)
	: Base(layout, name)
{ }



void Uniform::UIntNBase::Find(Shader::Base & shader)
{
	Index = shader.FindUniformLocation(Name.c_str());
}



void Uniform::UIntNBase::PutVoid(const void * val)
{
	/*if (!Layout.IsBound())
	{
		Layout.Bind();
	}*/
	PutData((const unsigned int *)val);
}
