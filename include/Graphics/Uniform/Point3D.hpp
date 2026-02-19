#ifndef  UNI_POINT_3D_HPP
# define UNI_POINT_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float3.hpp"

struct Point3D;

namespace Uniform
{
class Point3D : public Uniform::Float3
{
	public:
	Point3D(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Point3D & obj);
};
};

#endif