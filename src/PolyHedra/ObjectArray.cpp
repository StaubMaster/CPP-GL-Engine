#include "PolyHedra/ObjectArray.hpp"
#include "PolyHedra/Object.hpp"



bool			PolyHedraObjectArray::Is() const { return (Data != nullptr); }
unsigned int	PolyHedraObjectArray::Count() const { return _Count; }



PolyHedraObject & PolyHedraObjectArray::operator[](unsigned int i) { return Data[i]; }



PolyHedraObjectArray::~PolyHedraObjectArray()
{
	delete[] Data;
}
PolyHedraObjectArray::PolyHedraObjectArray()
	: _Count(0)
	, Data(nullptr)
{ }



void PolyHedraObjectArray::Delete()
{
	delete[] Data;
	Data = nullptr;
	_Count = 0;
}

void PolyHedraObjectArray::Create(unsigned int count, PolyHedra * polyhedra)
{
	_Count = count;
	Data = new PolyHedraObject[_Count];
	for (unsigned int i = 0; i < _Count; i++)
	{
		Data[i].Create(polyhedra);
	}
}
void PolyHedraObjectArray::Create(unsigned int count, unsigned int polyhedra)
{
	_Count = count;
	Data = new PolyHedraObject[_Count];
	for (unsigned int i = 0; i < _Count; i++)
	{
		Data[i].Create(polyhedra);
	}
}
