#include "Graphics/Uniform/Range.hpp"
#include "DataStruct/Range.hpp"
#include "OpenGL/openGL.h"



Uniform::Range::Range(Uniform::NameShader name_shader) : GBase(name_shader),
	Min(name_shader.Suffix(".Min")),
	Len(name_shader.Suffix(".Len")),
	Max(name_shader.Suffix(".Max"))
{ }

void Uniform::Range::PutData(::Range val)
{
	Min.PutVoid(&val.Min);
	Len.PutVoid(&val.Len);
	Max.PutVoid(&val.Max);
}
