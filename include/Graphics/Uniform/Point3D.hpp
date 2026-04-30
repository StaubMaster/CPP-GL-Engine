#ifndef  UNI_POINT_3D_HPP
# define UNI_POINT_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/FloatN.hpp"

//struct Point3D;
struct VectorF3; typedef VectorF3 Point3D;

namespace Uniform
{
typedef FloatN<3, 1, 1, ::Point3D> Point3D;
/*class Point3D : public Uniform::FloatN<3, 1, 1>
{
	public:
	Point3D(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Point3D & obj);
};*/
};

#endif