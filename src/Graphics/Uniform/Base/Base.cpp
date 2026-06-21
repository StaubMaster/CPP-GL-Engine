#include "Graphics/Uniform/Base/Base.hpp"
#include "Graphics/Uniform/Layout.hpp"
#include "Graphics/Multiform/Base/Base.hpp"



Uniform::Base::~Base() { }
Uniform::Base::Base(Uniform::Layout & layout, std::string name)
	//: Layout(layout)
	: Name(name)
	, Multiform(nullptr)
{
	layout.Uniforms.Insert(this);
}



void Uniform::Base::UpdateData()
{
	if (Multiform != nullptr)
	{
		Multiform -> PutData(*this);
	}
}
