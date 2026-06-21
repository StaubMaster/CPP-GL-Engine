#include "Graphics/Buffer/Base.hpp"
#include "OpenGL.hpp"



Buffer::Base::~Base()
{ }
Buffer::Base::Base(
	GL::BufferTarget target,
	GL::BufferDataUsage usage
)
	: Target(target)
	, Usage(usage)
	, ID(0)
	, DataWant(false)
	, DataHave(false)
{ }



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

	DataWant = false;
	DataHave = false;
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
	GL::BindBuffer(Target, ID);
}



void Buffer::Base::Update() { }
void Buffer::Base::NewSize(unsigned int size) { (void)size; }



#include "Miscellaneous/Container/Void.hpp"

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
