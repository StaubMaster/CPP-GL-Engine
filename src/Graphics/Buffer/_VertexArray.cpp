#include "Graphics/Buffer/VertexArray.hpp"
#include "Graphics/Buffer/Base.hpp"
#include "Graphics/Buffer/Array.hpp"
#include "Graphics/Attribute/General/Layout.hpp"
#include "OpenGL.hpp"

#include "Debug.hpp"
#include <sstream>



_VertexArray::~_VertexArray()
{ }
_VertexArray::_VertexArray()
	: ID(0)
	, Buffers()
//	, AttributeLayoutMain(nullptr)
//	, AttributeLayoutInst(nullptr)
//	, AttributeLayoutMainBound(false)
//	, AttributeLayoutInstBound(false)
{ }

_VertexArray::_VertexArray(const _VertexArray & other)
	: ID(other.ID)
	, Buffers()
//	, AttributeLayoutMain(other.AttributeLayoutMain)
//	, AttributeLayoutInst(other.AttributeLayoutInst)
//	, AttributeLayoutMainBound(other.AttributeLayoutMainBound)
//	, AttributeLayoutInstBound(other.AttributeLayoutInstBound)
{ }
_VertexArray & _VertexArray::operator=(const _VertexArray & other)
{
	ID = other.ID;
//	AttributeLayoutMain = other.AttributeLayoutMain;
//	AttributeLayoutInst = other.AttributeLayoutInst;
//	AttributeLayoutMainBound = other.AttributeLayoutMainBound;
//	AttributeLayoutInstBound = other.AttributeLayoutInstBound;
	return *this;
}



bool _VertexArray::Exists() const { return (ID != 0); }
bool _VertexArray::IsBound() const { return (Bound() == ID); }
void _VertexArray::Bind()
{
	if (Exists() && !IsBound())
	{
		GL::BindVertexArray(ID);
		for (unsigned int i = 0; i < Buffers.Count(); i++)
		{
			Buffers[i] -> Bind();
		}
	}
}

GL::VertexArrayID _VertexArray::Bound()
{
	return GL::GetIntegerv(GL::ParameterName::VertexArrayBinding);
}
void _VertexArray::BindNone()
{
	GL::BindVertexArray(0);
}



void _VertexArray::Create()
{
	if (ID != 0) { return; }

	Debug::Log << "Buffer::ArrayBase Creating " << ID << " ..." << Debug::Done;
	ID = GL::CreateVertexArray();
	Debug::Log << "Buffer::ArrayBase Creating " << ID << " done" << Debug::Done;

	for (unsigned int i = 0; i < Buffers.Count(); i++)
	{
		Buffers[i] -> Create();
	}

	Debug::Log << "Create BufferArray: " << ID << Debug::Done;
	LogInfo();
}
void _VertexArray::Delete()
{
	if (ID == 0) { return; }

	Debug::Log << "Delete BufferArray: " << ID << Debug::Done;
	LogInfo();

	Debug::Log << "Buffer::ArrayBase Deleting " << ID << " ..." << Debug::Done;
	GL::DeleteVertexArray(ID);
	ID = 0;
	Debug::Log << "Buffer::ArrayBase Deleting " << ID << " done" << Debug::Done;

	for (unsigned int i = 0; i < Buffers.Count(); i++)
	{
		Buffers[i] -> Delete();
	}
}



/*void _VertexArray::ChangeAttributeLayoutMain(Attribute::Layout & layout)
{
	AttributeLayoutMain = &layout;
	AttributeLayoutMainBound = false;
}
void _VertexArray::ChangeAttributeLayoutMain(Attribute::Layout * layout)
{
	if (layout != nullptr)
	{
		ChangeAttributeLayoutMain(*layout);
	}
}
void _VertexArray::ChangeAttributeLayoutInst(Attribute::Layout & layout)
{
	AttributeLayoutInst = &layout;
	AttributeLayoutInstBound = false;
}
void _VertexArray::ChangeAttributeLayoutInst(Attribute::Layout * layout)
{
	if (layout != nullptr)
	{
		ChangeAttributeLayoutInst(*layout);
	}
}
void _VertexArray::InitAttributeLayoutMain(Buffer::Array & buffer)
{
	buffer.Bind();
	if (!AttributeLayoutMainBound)
	{
		if (AttributeLayoutMain != nullptr)
		{
			AttributeLayoutMain -> Bind();
			AttributeLayoutMainBound = true;
		}
	}
}
void _VertexArray::InitAttributeLayoutInst(Buffer::Array & buffer)
{
	buffer.Bind();
	if (!AttributeLayoutInstBound)
	{
		if (AttributeLayoutInst != nullptr)
		{
			AttributeLayoutInst -> Bind();
			AttributeLayoutInstBound = true;
		}
	}
}*/



//void _VertexArray::Draw() { }
