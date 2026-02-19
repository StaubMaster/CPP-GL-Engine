
#ifndef  GENERIC_UNIFORM_ARRAY_HPP
# define GENERIC_UNIFORM_ARRAY_HPP

# include "Graphics/Uniform/Base/Base.hpp"
# include "Graphics/Uniform/Base/GBase.hpp"

# include <sstream>

namespace Shader
{
	class Base;
};

namespace Uniform
{
template <typename UniformType, typename DataType>
class GArray
{
	//	Use Containers
	public:
	const unsigned int	Limit;
	private:
	UniformType **	Uniforms;

	public:
	GArray(unsigned int count, ::Shader::Base & shader, std::string name)
		: Limit(count)
	{
		Uniforms = new UniformType*[Limit];
		for (unsigned int i = 0; i < Limit; i++)
		{
			std::stringstream ss;
			ss << name << "[" << i << "]";
			Uniforms[i] = new UniformType(shader, ss.str());
		}
	}
	~GArray()
	{
		for (unsigned int i = 0; i < Limit; i++)
		{
			delete Uniforms[i];
		}
		delete[] Uniforms;
	}

	public:
	UniformType & operator[](unsigned int index)
	{
		return *(Uniforms[index]);
	}

	public:
	void PutData(DataType * data, unsigned int count)
	{
		if (Limit < count) { count = Limit; }
		for (unsigned int i = 0; i < count; i++)
		{
			Uniforms[i] -> PutData(data[i]);
		}
	}
};
};

#endif
