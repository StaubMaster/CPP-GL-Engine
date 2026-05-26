#include "Graphics/Uniform/Base/FloatNBase.hpp"
#include "Graphics/Uniform/Layout.hpp"



Uniform::FloatNBase::~FloatNBase() { }
Uniform::FloatNBase::FloatNBase(Uniform::Layout & layout, std::string name)
	: Base(layout, name)
{ }



void Uniform::FloatNBase::PutVoid(const void * val)
{
	if (!Layout.IsBound())
	{
		Layout.Bind();
	}
	PutData((const float *)val);
}



void Uniform::FloatNBase::ReLocate()
{
	Index = Locate();
}
