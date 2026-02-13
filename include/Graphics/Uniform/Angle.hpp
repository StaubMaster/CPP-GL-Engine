#ifndef  UNI_ANGLE_HPP
# define UNI_ANGLE_HPP

# include "Graphics/Uniform/Base/Float1.hpp"

struct Angle;

namespace Uniform
{
class Angle : public Uniform::Float1
{
	public:
	Angle(Uniform::NameShader name_shader);

	public:
	void Put(const ::Angle & obj);
};
};

#endif