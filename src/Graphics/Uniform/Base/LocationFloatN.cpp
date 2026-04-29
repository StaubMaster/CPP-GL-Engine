#include "Graphics/Uniform/Base/LocationFloatN.hpp"
#include "OpenGL.hpp"



Uniform::LocationFloatN::~LocationFloatN() { }

Uniform::LocationFloatN::LocationFloatN(::Shader::Base & shader, std::string name, unsigned int size0, unsigned int size1, unsigned int count)
	: Location(shader, name, size0, size1, count)
{ }



void Uniform::LocationFloatN::PutVoid(const void * val)
{
	PutData((const float *)val);
}
void Uniform::LocationFloatN::PutData(const float * val)
{
	if (Size1 == 1)
	{
		switch (Size0)
		{
			case 1: GL::Uniform1fv(Index, Count, val); return;
			case 2: GL::Uniform2fv(Index, Count, val); return;
			case 3: GL::Uniform3fv(Index, Count, val); return;
			case 4: GL::Uniform4fv(Index, Count, val); return;
		}
	}
	else if (Size0 == 2 && Size1 == 2) { GL::UniformMatrix2fv(Index, Count, false, val); }
	else if (Size0 == 3 && Size1 == 3) { GL::UniformMatrix3fv(Index, Count, false, val); }
	else if (Size0 == 4 && Size1 == 4) { GL::UniformMatrix4fv(Index, Count, false, val); }
}
