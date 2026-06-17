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
	}
}
PolyHedraObject::PolyHedraObject()
	: Data(nullptr)
{ }

PolyHedraObject::PolyHedraObject(const PolyHedraObject & other)
	: Data(nullptr)
{
	if (other.Data != nullptr)
	{
		if (other.Data -> PalletManager != nullptr)
		{
			Data = other.Data -> PalletManager -> CopyObject(other.Data);
		}
	}
}
PolyHedraObject & PolyHedraObject::operator=(const PolyHedraObject & other)
{
	if (Data != nullptr)
	{
		Data -> Remove = true;
	}
	Data = nullptr;
	if (other.Data != nullptr)
	{
		if (other.Data -> PalletManager != nullptr)
		{
			Data = other.Data -> PalletManager -> CopyObject(other.Data);
		}
	}
	return *this;
}





PolyHedraObject::PolyHedraObject(::PolyHedraPalletManager * pallet)
	: Data(PolyHedraPalletManager::TryMakeObject(pallet))
{ }
PolyHedraObject::PolyHedraObject(::PolyHedraPalletManager * pallet, Trans3D trans)
	: Data(PolyHedraPalletManager::TryMakeObject(pallet))
{
	if (Data != nullptr)
	{
		Data -> Trans = trans;
	}
}



PolyHedraObject::PolyHedraObject(::PolyHedra * pallet)
	: Data(PolyHedraManager::TryMakeObject(nullptr, pallet))
{ }
PolyHedraObject::PolyHedraObject(::PolyHedra * pallet, Trans3D trans)
	: Data(PolyHedraManager::TryMakeObject(nullptr, pallet))
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
	Data = PolyHedraManager::TryMakeObject(nullptr, pallet);
}
void PolyHedraObject::Create(::PolyHedra * pallet)
{
	Delete();
	Data = PolyHedraManager::TryMakeObject(nullptr, pallet);
}





const char * PolyHedraObject::ExceptionNullObject::what() const noexcept
{
	return "Attampted to access Null Object.";
}
