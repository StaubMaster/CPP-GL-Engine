#include "Graphics/Uniform/Base/FloatNBase.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::FloatNBase::~FloatNBase() { }
Uniform::FloatNBase::FloatNBase(::Shader::Base & shader, std::string name)
	: Base(shader, name)
{ }



void Uniform::FloatNBase::PutVoid(const void * val)
{
	if (!Shader.IsBound())
	{
		Shader.Bind();
	}
	PutData((const float *)val);
}



void Uniform::FloatNBase::ReLocate()
{
	Index = Locate();
}
