#ifndef  MULTIFORM_GENERIC_BASE_HPP
# define MULTIFORM_GENERIC_BASE_HPP

# include "Graphics/Multiform/Base/Base.hpp"

# include "Graphics/Uniform/Base/Base.hpp"
# include "Graphics/Uniform/Layout.hpp"

# include "Miscellaneous/Container/Array.hpp"

# include <typeinfo>
# include <iostream>



namespace Shader { class Base; };

namespace Multiform
{
template <typename UniformType, typename DataType>
class GBase : public Base
{
	public:
	Container::Array<UniformType *> Uniforms;
	DataType Data;

	public:
	virtual ~GBase() { }
	GBase(std::string name)
		: Base(name)
	{ }

	public:
	void	FindUniforms(Container::Array<Uniform::Layout *> & layouts) override
	{
		unsigned int m = 0;
		Uniforms.NewLength(layouts.Length());
		for (unsigned int s = 0; s < layouts.Length(); s++)
		{
			Uniform::Layout * layout = layouts[s];
			for (unsigned int u = 0; u < layout -> Uniforms.Count(); u++)
			{
				Uniform::Base * uni = layout -> Uniforms[u];
				if (uni -> Name == this -> Name)
				{
					if (typeid(*uni) == typeid(UniformType))
					{
						uni -> Multiform = this;
						Uniforms[m] = (UniformType*)uni;
						m++;
					}
					else
					{ /* Uniform has correct name but wrong Type */ }
				}
			}
		}
		Uniforms.NewLengthHere(m);
	}

	void	PutUniformData(Uniform::Base * uni_base) override
	{
		UniformType * uni = (UniformType*)uni_base;
		uni -> Put(Data);
		uni -> MultiformChanged = false;
	}
	void	ChangeData(DataType data)
	{
		Data = data;
		for (unsigned int i = 0; i < Uniforms.Length(); i++)
		{
			if (Uniforms[i] -> Layout.Shader -> IsBound())
			{
				PutUniformData(Uniforms[i]);
			}
			else
			{
				Uniforms[i] -> MultiformChanged = true;
			}
		}
	}
};
};

#endif