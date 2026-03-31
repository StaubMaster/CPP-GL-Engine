#ifndef  UNI_UINT_HPP
# define UNI_UINT_HPP

# include "Graphics/Uniform/Base/UInt1.hpp"

namespace Uniform
{
class UInt : public Uniform::UInt1
{
	public:
	UInt(::Shader::Base & shader, std::string name);

	public:
	void Put(const unsigned int & val);
};
};

#endif