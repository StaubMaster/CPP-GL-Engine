#include "Graphics/Uniform/General/Base.hpp"
#include "Graphics/Uniform/General/Layout.hpp"
#include "Graphics/Multiform/General/Base.hpp"



Uniform::Base::~Base() { }
Uniform::Base::Base(Uniform::Layout & layout, std::string name)
	: Name(name)
	, Multiform(nullptr)
{
	layout.Put(this);
}



void Uniform::Base::UpdateData()
{
	if (Multiform != nullptr)
	{
		Multiform -> PutData(*this);
	}
}
