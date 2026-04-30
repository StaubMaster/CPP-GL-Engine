#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/FloatN.hpp"

//struct Point2D;
struct VectorF2; typedef VectorF2 Point2D;

namespace Uniform
{
typedef FloatN<2, 1, 1, ::Point2D> Point2D;
/*class Point2D : public Uniform::FloatN<2, 1, 1>
{
	public:
	Point2D(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Point2D & obj);
};*/
};

#endif