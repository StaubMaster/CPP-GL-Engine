#include "Graphics/Buffer/Base.hpp"
#include "Graphics/Buffer/VertexArray.hpp"
#include "OpenGL.hpp"



Buffer::Base::~Base()
{ }
Buffer::Base::Base(
	VertexArray & vertex_array,
	GL::BufferTarget target,
	GL::BufferDataUsage usage
)	: BufferArray(vertex_array)
	, Target(target)
	, Usage(usage)
	, ID(0)
{ }

Buffer::Base::Base(VertexArray & vertex_array, const Base & other)
	: BufferArray(other.BufferArray)
	, Target(other.Target)
	, Usage(other.Usage)
	, ID(other.ID)
{
	(void)vertex_array; // add to VertexArray Buffers Container
}
Buffer::Base & Buffer::Base::operator=(const Base & other)
{
	Target = other.Target;
	Usage = other.Usage;
	ID = other.ID;
	return *this;
}



bool Buffer::Base::Exists() const
{
	//return GL::IsBuffer(ID);
	return (ID != 0);
}
void Buffer::Base::Create()
{
	if (Exists()) { return; }

	//Debug::Log << "Buffer::Base Creating " << ID << " ..." << Debug::Done;
	ID = GL::CreateBuffer();
	//Debug::Log << "Buffer::Base Creating " << ID << " done" << Debug::Done;
}
void Buffer::Base::Delete()
{
	if (!Exists()) { return; }

	//Debug::Log << "Buffer::Base Deleting " << ID << " ..." << Debug::Done;
	GL::DeleteBuffer(ID);
	ID = 0;
	//Debug::Log << "Buffer::Base Deleting " << ID << " done" << Debug::Done;
}

void Buffer::Base::Bind()
{
	BufferArray.Bind();
	GL::BindBuffer(Target, ID);
}



void Buffer::Base::Init() { }
void Buffer::Base::NewSize(unsigned int size) { (void)size; }

void Buffer::Base::DataNull()
{
	Bind();
	GL::BufferData(Target, 0, nullptr, Usage);
	NewSize(0);
}
void Buffer::Base::DataFull(unsigned int size)
{
	Bind();
	GL::BufferData(Target, size, nullptr, Usage);
	NewSize(size);
}
void Buffer::Base::DataFull(const Container::Void & data)
{
	Bind();
	GL::BufferData(Target, data.Size, data.Data, Usage);
	NewSize(data.Size);
}
void Buffer::Base::DataPart(unsigned int offset, const Container::Void & data)
{
	Bind();
	GL::BufferSubData(Target, offset, data.Size, data.Data);
}
void * Buffer::Base::DataMap()
{
	return GL::MapBuffer(Target, GL::BufferAccess::ReadWrite);
}
