#ifndef  MULTIFORM_GENERIC_BASE_HPP
# define MULTIFORM_GENERIC_BASE_HPP

# include "Graphics/Shader/Base.hpp"
# include "Graphics/Multiform/Base/Base.hpp"
# include "Graphics/Uniform/Base/Base.hpp"

# include "Miscellaneous/Container/Base.hpp"
# include "Miscellaneous/Container/Fixed.hpp"

# include <typeinfo>
# include <iostream>



namespace Shader { class Base; };

namespace Multiform
{
template <typename UniformType, typename DataType>
class GBase : public Base
{
	public:
	Container::Fixed<UniformType *> Uniforms;
	DataType Data;

	public:
	virtual ~GBase() { }
	GBase(std::string name)
		: Base(name)
	{ }

	public:
	void FindUniforms(Container::Base<Shader::Base *> & shaders) override
	{
		Uniforms.Allocate(shaders.Count());
		for (unsigned int s = 0; s < shaders.Count(); s++)
		{
			Shader::Base * shader = shaders[s];
			for (unsigned int u = 0; u < shader -> Uniforms.Count(); u++)
			{
				Uniform::Base * uni = shader -> Uniforms[u];
				if (uni -> Name == this -> Name)
				{
					if (typeid(*uni) == typeid(UniformType))
					{
						uni -> Multiform = this;
						Uniforms.Insert((UniformType*)(uni));
					}
					else
					{ /* Uniform has correct name but wrong Type */ }
				}
			}
		}
		Uniforms.Trim();
	}

	void PutUniformData(Uniform::Base * uni_base) override
	{
		UniformType * uni = (UniformType*)uni_base;
		uni -> Put(Data);
		uni -> MultiformChanged = false;
	}
	void ChangeData(DataType data)
	{
		Data = data;
		for (unsigned int i = 0; i < Uniforms.Count(); i++)
		{
			if (Uniforms[i] -> Shader.IsBound())
			{ PutUniformData(Uniforms[i]); }
			else
			{ Uniforms[i] -> MultiformChanged = true; }
		}
	}
};
};

#endif