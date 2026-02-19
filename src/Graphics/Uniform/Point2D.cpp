#include "Graphics/Uniform/Point2D.hpp"
#include "ValueType/Point2D.hpp"



Uniform::Point2D::Point2D(::Shader::Base & shader, std::string name)
	: Float2(shader, name)
{ }

void Uniform::Point2D::Put(const ::Point2D & obj)
{
	PutVoid(&obj);
}
