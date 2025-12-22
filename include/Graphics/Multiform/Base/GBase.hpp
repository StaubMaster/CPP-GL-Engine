
#ifndef  GENERIC_MULTIFORM_BASE_HPP
# define GENERIC_MULTIFORM_BASE_HPP

# include "Graphics/Shader/Base.hpp"
# include "Graphics/Multiform/Base/Base.hpp"
# include "Graphics/Uniform/Base/Base.hpp"

# include "Miscellaneous/Container/Base.hpp"

# include <typeinfo>



namespace Shader
{
	class Base;
};

namespace Multiform
{
template <typename UniformType, typename DataType>
class GBase : public Base
{
	public:
	Container::Base<UniformType *> Uniforms;
	DataType Data;

	public:
		GBase(std::string name) :
			Base(name)
		{ }
		virtual ~GBase()
		{ }

	public:
		void FindUniforms(Container::Base<Shader::Base *> & shaders) override
		{
			Container::Base<UniformType *> uniforms(shaders.Count());
			int c = 0;

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
							uniforms[c] = (UniformType*)(uni);
							c++;
						}
						else { /* Uniform has correct name but wrong Type */ }
					}
				}
			}

			Uniforms.Allocate(c);
			for (int i = 0; i < c; i++)
			{ Uniforms[i] = uniforms[i]; }
		}

		void PutUniformData(Uniform::Base * uni_base) override
		{
			UniformType * uni = (UniformType*)uni_base;
			uni -> PutData(Data);
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
