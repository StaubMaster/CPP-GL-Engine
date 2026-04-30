#include "Graphics/Uniform/Base/Base.hpp"
#include "Graphics/Multiform/Base/Base.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::Base::~Base() { }
Uniform::Base::Base(::Shader::Base & shader, std::string name)
	: Shader(shader)
	, Name(name)
	, Multiform(NULL)
	, MultiformChanged(false)
{
	Shader.Uniforms.Insert(this);
}

/*Uniform::Base::Base(const Base & other)
	: Shader(other.Shader)
	, Name(other.Name)
	, Multiform(other.Multiform)
	, MultiformChanged(other.MultiformChanged)
{ }*/
/*Uniform::Base::Base & operator=(const Base & other)
{
	Shader = other.Shader;
	Name = other.Name;
	Multiform = other.Multiform;
	MultiformChanged = other.MultiformChanged;
	return *this;
}*/



int Uniform::Base::Locate() const
{
	return Shader.LocateUniform(Name.c_str());
}
void Uniform::Base::ReLocate() { }



void Uniform::Base::PutMultiformData()
{
	if (MultiformChanged)
	{
		Multiform -> PutUniformData(this);
	}
}
