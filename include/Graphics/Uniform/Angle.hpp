#ifndef  UNI_ANGLE_HPP
# define UNI_ANGLE_HPP

# include "Graphics/Uniform/Base/Float1.hpp"

struct Angle;

namespace Uniform
{
class Angle : public Uniform::Float1
{
	public:
	Angle(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Angle & obj);
};
};

#endif