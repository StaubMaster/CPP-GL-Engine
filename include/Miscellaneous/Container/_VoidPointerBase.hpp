#ifndef  CONTAINER_VOID_POINTER_BASE_HPP
# define CONTAINER_VOID_POINTER_BASE_HPP

namespace Container
{
class VoidPointerBase
{
	public:
	virtual unsigned int VoidSize() const = 0;
	virtual const void * VoidData() const = 0;
	virtual void * VoidData() = 0;

	public:
	virtual void Delete() = 0;
};
};

#endif