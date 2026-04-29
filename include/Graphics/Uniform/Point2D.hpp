#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/FloatN.hpp"

//struct Point2D;
struct VectorF2; typedef VectorF2 Point2D;

namespace Uniform
{
class Point2D : public Uniform::FloatN
{
	public:
	Point2D(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Point2D & obj);
};
};

#endif