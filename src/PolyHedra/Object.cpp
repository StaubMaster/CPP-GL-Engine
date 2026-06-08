#include "PolyHedra/Object.hpp"
#include "PolyHedra/ObjectData.hpp"
#include "PolyHedra/Manager.hpp"



bool PolyHedraObject::Is() const
{
	if (Data != nullptr)
	{
		return (Data -> PalletManager != nullptr);
	}
	return false;
}

::PolyHedraPalletManager * PolyHedraObject::PalletManager() const
{
	if (Data != nullptr)
	{
		return (Data -> PalletManager);
	}
	throw ExceptionNullObject();
}
::PolyHedra * PolyHedraObject::Pallet() const
{
	if (Data != nullptr)
	{
		return (Data -> PalletManager -> Pallet);
	}
	throw ExceptionNullObject();
}



bool PolyHedraObject::VisFull() const { if (Data != nullptr) { return (Data -> DrawFull); } throw ExceptionNullObject(); }
bool PolyHedraObject::VisWire() const { if (Data != nullptr) { return (Data -> DrawWire); } throw ExceptionNullObject(); }

void PolyHedraObject::HideFull() { if (Data != nullptr) { (Data -> DrawFull) = false; } }
void PolyHedraObject::HideWire() { if (Data != nullptr) { (Data -> DrawWire) = false; } }

void PolyHedraObject::ShowFull() { if (Data != nullptr) { (Data -> DrawFull) = true; } }
void PolyHedraObject::ShowWire() { if (Data != nullptr) { (Data -> DrawWire) = true; } }



const Trans3D &		PolyHedraObject::Trans() const	{ if (Data != nullptr) { return (Data -> Trans); } throw ExceptionNullObject(); }
Trans3D &			PolyHedraObject::Trans()		{ if (Data != nullptr) { return (Data -> Trans); } throw ExceptionNullObject(); }



PolyHedraObject::~PolyHedraObject()
{
	if (Data != nullptr)
	{
		if (Data -> PalletManager != nullptr)
		{
			Data -> Remove = true;
		}
		else
		{
			delete Data;
		}
		Data = nullptr;
	}
}
PolyHedraObject::PolyHedraObject()
	: Data(nullptr)
{ }

// dont copy in current, copy in same
PolyHedraObject::PolyHedraObject(const PolyHedraObject & other)
	: Data(PolyHedraManager::sCopyObject(other.Data))
{ }
PolyHedraObject & PolyHedraObject::operator=(const PolyHedraObject & other)
{
	if (Data != nullptr)
	{
		Data -> Remove = true;
	}
	Data = PolyHedraManager::sCopyObject(other.Data);
	return *this;
}





// Data should be nullptr if no Current
PolyHedraObject::PolyHedraObject(::PolyHedraPalletManager * pallet)
	: Data(PolyHedraManager::sPlaceObject(pallet))
{ }
PolyHedraObject::PolyHedraObject(::PolyHedraPalletManager * pallet, Trans3D trans)
	: Data(PolyHedraManager::sPlaceObject(pallet))
{
	if (Data != nullptr)
	{
		Data -> Trans = trans;
	}
}



PolyHedraObject::PolyHedraObject(::PolyHedra * pallet)
	: Data(PolyHedraManager::sPlaceObject(pallet))
{ }
PolyHedraObject::PolyHedraObject(::PolyHedra * pallet, Trans3D trans)
	: Data(PolyHedraManager::sPlaceObject(pallet))
{
	if (Data != nullptr)
	{
		Data -> Trans = trans;
	}
}





void PolyHedraObject::Delete()
{
	if (Data != nullptr)
	{
		Data -> Remove = true;
		Data = nullptr;
	}
}
void PolyHedraObject::Create(::PolyHedraPalletManager * pallet)
{
	Delete();
	Data = PolyHedraManager::sPlaceObject(pallet);
}
void PolyHedraObject::Create(::PolyHedra * pallet)
{
	Delete();
	Data = PolyHedraManager::sPlaceObject(pallet);
}





const char * PolyHedraObject::ExceptionNullObject::what() const noexcept
{
	return "Attampted to access Null Object.";
}
