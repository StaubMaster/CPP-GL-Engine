#ifndef  MULTIFORM_GENERIC_BASE_HPP
# define MULTIFORM_GENERIC_BASE_HPP

# include "Graphics/Multiform/Base/Base.hpp"

# include "Graphics/Uniform/Base/Base.hpp"
# include "Graphics/Uniform/Layout.hpp"

# include "Graphics/Shader/Base.hpp"



namespace Multiform
{
template <typename DataType>
class GBase : public Base
{
	public:
	DataType	Data;

	public:
	virtual ~GBase()
	{ }
	GBase(std::string name)
		: Base(name)
	{ }

	public:
	void	PutData(Uniform::Base & uniform) override
	{
		uniform.PutVoid(&Data);
		uniform.Multiform = nullptr;
	}
	void	ChangeData(const DataType & data)
	{
		Data = data;
		for (unsigned int i = 0; i < Uniforms.Count(); i++)
		{
			if (Uniforms[i] -> Layout.Shader -> IsBound())
			{
				PutData(*Uniforms[i]);
			}
			else
			{
				Uniforms[i] -> Multiform = this;
			}
		}
	}
};
};

#endif