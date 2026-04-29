#include "Graphics/Uniform/Point2D.hpp"
#include "ValueType/Point2D.hpp"



Uniform::Point2D::Point2D(::Shader::Base & shader, std::string name)
	: FloatN(shader, name, 2, 1, 1)
{ }

void Uniform::Point2D::Put(const ::Point2D & obj)
{
	PutVoid(&obj);
}
