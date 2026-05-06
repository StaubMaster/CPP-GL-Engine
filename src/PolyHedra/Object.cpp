#include "PolyHedra/Object.hpp"
#include "PolyHedra/ObjectData.hpp"
#include "PolyHedra/Manager.hpp"



bool				PolyHedraObject::Is() const { return (Data != nullptr); }
::PolyHedra *		PolyHedraObject::PolyHedra() const { return (Data -> PolyHedra); }

const Trans3D &		PolyHedraObject::Trans() const { return (Data -> Trans); }
Trans3D &			PolyHedraObject::Trans() { return (Data -> Trans); }



bool PolyHedraObject::FullVisibility() const { return (Data -> DrawFull); }
bool PolyHedraObject::WireVisibility() const { return (Data -> DrawWire); }

void PolyHedraObject::HideFull() { (Data -> DrawFull) = false; }
void PolyHedraObject::HideWire() { (Data -> DrawWire) = false; }

void PolyHedraObject::ShowFull() { (Data -> DrawFull) = true; }
void PolyHedraObject::ShowWire() { (Data -> DrawWire) = true; }



PolyHedraObject::~PolyHedraObject()
{
	if (Data != nullptr)
	{
		Data -> Remove = true;
	}
}
PolyHedraObject::PolyHedraObject()
	: Data(nullptr)
{ }

// Copy should copy in the same Manager. not the Current
PolyHedraObject::PolyHedraObject(const PolyHedraObject & other)
	: Data(PolyHedraManager::Current().CopyObject(other.Data))
{ }
PolyHedraObject & PolyHedraObject::operator=(const PolyHedraObject & other)
{
	if (Data != nullptr)
	{
		Data -> Remove = true;
	}
	Data = PolyHedraManager::Current().CopyObject(other.Data);
	return *this;
}





// Data should be nullptr if no Current
PolyHedraObject::PolyHedraObject(unsigned int polyhedra)
	: Data(PolyHedraManager::Current().PlaceObject(polyhedra, Trans3D()))
{ }
PolyHedraObject::PolyHedraObject(unsigned int polyhedra, Trans3D trans)
	: Data(PolyHedraManager::Current().PlaceObject(polyhedra, trans))
{ }



PolyHedraObject::PolyHedraObject(::PolyHedra * polyhedra)
	: Data(PolyHedraManager::Current().PlaceObject(polyhedra, Trans3D()))
{ }
PolyHedraObject::PolyHedraObject(::PolyHedra * polyhedra, Trans3D trans)
	: Data(PolyHedraManager::Current().PlaceObject(polyhedra, trans))
{ }





void PolyHedraObject::Delete()
{
	if (Data != nullptr)
	{
		Data -> Remove = true;
		Data = nullptr;
	}
}
void PolyHedraObject::Create(unsigned int polyhedra)
{
	if (Data == nullptr)
	{
		Data = PolyHedraManager::Current().PlaceObject(polyhedra, Trans3D());
	}
}
void PolyHedraObject::Create(::PolyHedra * polyhedra)
{
	if (Data == nullptr)
	{
		Data = PolyHedraManager::Current().PlaceObject(polyhedra, Trans3D());
	}
}
