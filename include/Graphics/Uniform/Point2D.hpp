#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float2.hpp"
struct Point2D;

namespace Uniform
{
class Point2D : public Uniform::Float2
{
	public:
	Point2D(Uniform::NameShader name_shader);

	public:
	void Put(const ::Point2D & obj);
};
};

#endif