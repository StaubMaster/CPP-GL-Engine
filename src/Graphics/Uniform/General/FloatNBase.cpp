#include "Graphics/Uniform/General/FloatNBase.hpp"
#include "Graphics/Uniform/General/Layout.hpp"



Uniform::FloatNBase::~FloatNBase() { }
Uniform::FloatNBase::FloatNBase(Uniform::Layout & layout, std::string name)
	: Base(layout, name)
{ }



void Uniform::FloatNBase::PutVoid(const void * val)
{
	/*if (!Layout.IsBound())
	{
		Layout.Bind();
	}*/
	PutData((const float *)val);
}
