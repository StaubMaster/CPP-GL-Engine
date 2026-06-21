#include "Graphics/Uniform/Base/UIntNBase.hpp"
#include "Graphics/Uniform/Layout.hpp"



Uniform::UIntNBase::~UIntNBase() { }
Uniform::UIntNBase::UIntNBase(Uniform::Layout & layout, std::string name)
	: Base(layout, name)
{ }



void Uniform::UIntNBase::PutVoid(const void * val)
{
	/*if (!Layout.IsBound())
	{
		Layout.Bind();
	}*/
	PutData((const unsigned int *)val);
}
