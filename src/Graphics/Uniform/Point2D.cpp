#include "Graphics/Uniform/Point2D.hpp"
#include "ValueType/Point2D.hpp"



Uniform::Point2D::Point2D(Uniform::NameShader name_shader) : Float2(name_shader)
{ }

void Uniform::Point2D::Put(const ::Point2D & p)
{
	PutVoid(&p);
}
