#include "Graphics/VertexArray/Multi.hpp"
#include "OpenGL.hpp"





bool VertexArray::Multi::Entry::IsEmpty() const
{
	return (Offset == 0 && Length == 0);
}
void VertexArray::Multi::Entry::MakeEmpty()
{
	Offset = 0;
	Length = 0;
}

VertexArray::Multi::Entry::~Entry()
{
	//std::cout << "delete BufferUEntry of Length: " << Length << " at " << Offset << '\n';
	Buffer.Remove(*this);
}
VertexArray::Multi::Entry::Entry(VertexArray::Multi & buffer)
	: Buffer(buffer)
	, Offset(0)
	, Length(0)
{ }





VertexArray::Multi::~Multi()
{ }
VertexArray::Multi::Multi()
	: Base()
	, Mode(GL::DrawMode::Triangles)
	, Buffer(GL::BufferDataUsage::DynamicDraw)
{ }



static void FailedPutFunc(unsigned int len);

bool VertexArray::Multi::CheckEntry(VertexArray::Multi::Entry & entry)
{
	if ((entry.Offset + entry.Length) >= Buffer.Count)
	{
		return false;
	}
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		VertexArray::Multi::Entry & other = *(Entrys[i]);
		if (
			(entry.Offset + entry.Length) > (other.Offset) &&
			(entry.Offset) < (other.Offset + other.Length)
		)
		{
			return false;
		}
	}
	return true;
}
void VertexArray::Multi::Insert(VertexArray::Multi::Entry & entry)
{
	if (entry.Length == 0)
	{
		entry.MakeEmpty();
		return;
	}

	entry.Offset = 0;
	if (CheckEntry(entry))
	{
		Entrys.Insert(&entry);
		Offsets.Insert(entry.Offset);
		Lengths.Insert(entry.Length);
		return;
	}

	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		VertexArray::Multi::Entry & other = *(Entrys[i]);
		entry.Offset = other.Offset + other.Length;
		if (CheckEntry(entry))
		{
			Entrys.Insert(&entry);
			Offsets.Insert(entry.Offset);
			Lengths.Insert(entry.Length);
			return;
		}
	}

	entry.MakeEmpty();
	FailedPutFunc(entry.Length);
}
void VertexArray::Multi::Remove(VertexArray::Multi::Entry & entry)
{
	if (entry.IsEmpty())
	{
		return;
	}
	for (unsigned int i = 0; i < Entrys.Count(); i++)
	{
		if (Entrys[i] == &entry)
		{
			Entrys.RemoveAt(i);
			Offsets.RemoveAt(i);
			Lengths.RemoveAt(i);
			break;
		}
	}
	entry.MakeEmpty();
}

void VertexArray::Multi::NewSize(unsigned int size, unsigned int count)
{
	Buffer.DataFull(count * size);
	Buffer.Count = count;
}
void VertexArray::Multi::Put(VertexArray::Multi::Entry & entry, unsigned int size, const Container::Void & data, unsigned int count)
{
	Remove(entry);
	entry.Length = count;
	Insert(entry);
	if (!entry.IsEmpty())
	{
		Buffer.DataPart(entry.Offset * size, data);
	}
}



void VertexArray::Multi::Create()
{
	Base::Create();
	Buffer.Create();
}
void VertexArray::Multi::Delete()
{
	Base::Delete();
	Buffer.Delete();
}

void VertexArray::Multi::Init()
{
	Bind();

	Buffer.Init();
}

void VertexArray::Multi::Draw()
{
	GL::MultiDrawArrays(GL::DrawMode::Triangles, Offsets.ToArray().Memory(), Lengths.ToArray().Memory(), Entrys.Count());
}





#include <iostream>
static void FailedPutFunc(unsigned int len)
{
	std::cerr << "VertexArray::Multi::Entry: Failed to put Length: " << len << '\n';
}
