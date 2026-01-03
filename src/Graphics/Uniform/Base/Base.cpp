#include "Graphics/Uniform/Base/Base.hpp"
#include "Graphics/Multiform/Base/Base.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::NameShader::NameShader(std::string name, Shader::Base & shader) :
	Name(name), Shader(shader)
{ }
Uniform::NameShader::NameShader(const NameShader & other) :
	Name(other.Name),
	Shader(other.Shader)
{ }
Uniform::NameShader Uniform::NameShader::Suffix(std::string name) const
{
	return NameShader(Name + name, Shader);
}





Uniform::Base::Base(Uniform::NameShader & name_shader) :
	Name(name_shader.Name),
	Shader(name_shader.Shader),
	Multiform(NULL),
	MultiformChanged(false)
{
	Shader.Uniforms.Insert(this);
}
Uniform::Base::~Base()
{ }



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
