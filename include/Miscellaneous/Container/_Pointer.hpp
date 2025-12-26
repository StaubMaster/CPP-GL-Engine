#ifndef  CONTAINER_POINTER_HPP
# define CONTAINER_POINTER_HPP

# include "PointerBase.hpp"

namespace Container
{
template<typename Type>
class Pointer
{
	public:
	unsigned int Limit() const override;
	const void * Data() const;
	void * Data();

	public:
	Pointer();
	Pointer(Type * data, unsigned int limit);
	Pointer(const Type * data, unsigned int limit);
	Pointer(unsigned int limit);
	~Pointer();

	Pointer(const Pointer & other);
	Pointer & operator=(const Pointer & other);

	public:
	void Bind(Type * data, unsigned int limit);
	void Bind(const Type * data, unsigned int limit);
};
};

#endif