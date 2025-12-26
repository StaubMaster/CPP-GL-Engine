#include "Miscellaneous/Container/Pointer.hpp"



unsigned int Container::Pointer::VoidSize() const { return _VoidSize; }
const void * Container::Pointer::VoidData() const { return _VoidData; }
void * Container::Pointer::VoidData() { return _VoidData; }

//bool Container::PointerBase::IsConstant() const { return _Const; }
//void Container::PointerBase::ChangeConstant(bool constant) { _Const = constant; }
//void Container::PointerBase::MakeUnConstant()
//{ }

Container::Pointer::Pointer() :
	_VoidSize(0),
	_VoidData(0)
{ }
Container::Pointer::Pointer(void * data, unsigned int size) :
	_VoidSize(size),
	_VoidData(data)
{ }
Container::Pointer::Pointer(const void * data, unsigned int size) :
	_VoidSize(size),
	_VoidData((void*)data)
{ }
Container::Pointer::~Pointer()
{ }

/*Container::PointerBase::PointerBase() :
	_ItemSize(1),
	_VoidSize(0),
	_VoidData(0),
	_Const(true)
{ }
Container::PointerBase::PointerBase(unsigned int item_size) :
	_ItemSize(item_size),
	_VoidSize(0),
	_VoidData(0),
	_Const(true)
{ }
Container::PointerBase::PointerBase(unsigned int item_size, void * data, unsigned int limit) :
	_ItemSize(item_size),
	_VoidSize(limit * _ItemSize),
	_VoidData(data),
	_Const(false)
{ }
Container::PointerBase::PointerBase(unsigned int item_size, const void * data, unsigned int limit) :
	_ItemSize(item_size),
	_VoidSize(limit * _ItemSize),
	_VoidData((void*)data),
	_Const(true)
{ }
Container::PointerBase::PointerBase(unsigned int item_size, unsigned int limit) :
	_ItemSize(item_size),
	_VoidSize(limit * _ItemSize),
	_VoidData(new char[_VoidSize]),
	_Const(false)
{ }
Container::PointerBase::~PointerBase()
{
	delete[] _VoidData;
}*/

Container::Pointer::Pointer(const Pointer & other) :
	_VoidSize(other._VoidSize),
	_VoidData(other._VoidData)
	//_Const(other._Const)
{ }
Container::Pointer & Container::Pointer::operator=(const Pointer & other)
{
	Dispose();
	_VoidSize = other._VoidSize;
	_VoidData = other._VoidData;
	//_Const = other._Const;
	return *this;
}





void Container::Pointer::VoidBind(void * data, unsigned int size)
{
	Dispose();
	_VoidSize = size;
	_VoidData = data;
	//_VoidSize = limit * _ItemSize;
	//_Const = false;
}
void Container::Pointer::VoidBind(const void * data, unsigned int size)
{
	Dispose();
	_VoidSize = size;
	_VoidData = (void*)data;
	//_VoidSize = limit * _ItemSize;
	//_Const = true;
}



void Container::Pointer::Dispose()
{
	delete[] _VoidData;
	_VoidData = 0;
	_VoidSize = 0;
}
/*void Container::PointerBase::Dispose()
{
	if (!_Const)
	{
		delete[] _VoidData;
	}
	_VoidSize = 0;
	_VoidData = 0;
	_Const = true;
}*/
/*void Container::PointerBase::Allocate(unsigned int limit)
{
	Dispose();
	_VoidSize = limit;
	_VoidData = new char[_VoidSize];
	_Const = false;
}*/
