#include "InstanceData/Physics3D/Physics3D_InstBuffer.hpp"
#include "InstanceData/Physics3D/Physics3D_InstData.hpp"



Physics3D_InstBuffer::Physics3D_InstBuffer(
	unsigned int indexTransPos,
	unsigned int indexTransRot,
	unsigned int indexVelPos,
	unsigned int indexVelRot
) :
	Buffer::Attribute(GL_ARRAY_BUFFER, GL_STREAM_DRAW, sizeof(Physics3D_InstData)),
	Trans(1, sizeof(Physics3D_InstData), indexTransPos, indexTransRot),
	Vel(1, sizeof(Physics3D_InstData), indexVelPos, indexVelRot)
{
	Attributes.Allocate(2);
	Attributes.Insert(&Trans);
	Attributes.Insert(&Vel);
}
Physics3D_InstBuffer::~Physics3D_InstBuffer()
{ }
