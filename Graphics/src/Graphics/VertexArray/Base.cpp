#include "Graphics/VertexArray/Base.hpp"
#include "OpenGL.hpp"



bool VertexArray::Base::Exists() const { return (ID != 0); }
bool VertexArray::Base::IsBound() const { return (Bound() == ID); }
void VertexArray::Base::Bind()
{
	if (Exists() && !IsBound())
	{
		GL::BindVertexArray(ID);
	}
}

GL::VertexArrayID VertexArray::Base::Bound()
{
	return GL::GetIntegerv(GL::ParameterName::VertexArrayBinding);
}
void VertexArray::Base::BindNone()
{
	GL::BindVertexArray(0);
}



void VertexArray::Base::Create()
{
	if (Exists()) { return; }

	ID = GL::CreateVertexArray();

	LogLine("[Create]");
}
void VertexArray::Base::Delete()
{
	if (!Exists()) { return; }

	LogLine("[Delete]");

	GL::DeleteVertexArray(ID); ID = 0;
}



/*void VertexArray::Base::ChangeAttributeLayoutMain(Attribute::Layout & layout)
{
	AttributeLayoutMain = &layout;
	AttributeLayoutMainBound = false;
}
void VertexArray::Base::ChangeAttributeLayoutMain(Attribute::Layout * layout)
{
	if (layout != nullptr)
	{
		ChangeAttributeLayoutMain(*layout);
	}
}
void VertexArray::Base::ChangeAttributeLayoutInst(Attribute::Layout & layout)
{
	AttributeLayoutInst = &layout;
	AttributeLayoutInstBound = false;
}
void VertexArray::Base::ChangeAttributeLayoutInst(Attribute::Layout * layout)
{
	if (layout != nullptr)
	{
		ChangeAttributeLayoutInst(*layout);
	}
}
void VertexArray::Base::InitAttributeLayoutMain(Buffer::Array & buffer)
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
void VertexArray::Base::InitAttributeLayoutInst(Buffer::Array & buffer)
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
