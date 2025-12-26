#include "InstanceData/Simple3D/Simple3D_InstBuffer.hpp"
#include "InstanceData/Simple3D/Simple3D_InstData.hpp"



Simple3D_InstBuffer::Simple3D_InstBuffer(
	unsigned int indexTransPos,
	unsigned int indexTransRot
) :
	Buffer::Attribute(GL_ARRAY_BUFFER, GL_STREAM_DRAW, sizeof(Simple3D_InstData)),
	Trans(1, sizeof(Simple3D_InstData), indexTransPos, indexTransRot)
{
	Attributes.Allocate(1);
	Attributes[0] = &Trans;
}
Simple3D_InstBuffer::~Simple3D_InstBuffer()
{ }
