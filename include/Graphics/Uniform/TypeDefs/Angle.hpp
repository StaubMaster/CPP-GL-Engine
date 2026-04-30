#ifndef  UNI_ANGLE_HPP
# define UNI_ANGLE_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

struct Angle;

namespace Uniform
{
typedef FloatN<1, 1, 1, ::Angle> Angle;
/*class Angle : public Uniform::FloatN<1, 1, 1>
{
	public:
	Angle(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Angle & obj);
};*/
};

#endif