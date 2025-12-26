#ifndef  CONTAINER_POINTER_HPP
# define CONTAINER_POINTER_HPP

/*
change this to Base, and current Base to Fixed ?

to copy this would copy each Byte
this would remove the need for operator=
*/

namespace Container
{
class Pointer
{
	protected:
//	unsigned int	_ItemSize;
//	unsigned int	_VoidSize;
//	void *			_VoidData;
//	bool			_Const;

	public:
	unsigned int VoidSize() const;
	const void * VoidData() const;
	void * VoidData();

//	public:
//	bool IsConstant() const;
//	void ChangeConstant(bool constant);	//	change flag
//	void MakeUnConstant();				//	allocate

	public:
	Pointer();
	Pointer(void * data, unsigned int size);
	Pointer(const void * data, unsigned int size);
	~Pointer();
//	PointerBase();
//	PointerBase(unsigned int item_size);
//	PointerBase(unsigned int item_size, void * data, unsigned int limit);
//	PointerBase(unsigned int item_size, const void * data, unsigned int limit);
//	PointerBase(unsigned int item_size, unsigned int limit);
//	~PointerBase();

	Pointer(const Pointer & other);
	Pointer & operator=(const Pointer & other);

	public:
	void VoidBind(void * data, unsigned int size);
	void VoidBind(const void * data, unsigned int size);

	void Dispose();
//	virtual void Dispose();
//	virtual void Allocate(unsigned int limit);

//	public:
//	PointerBase ConstantCopy() const;
};
};

#endif