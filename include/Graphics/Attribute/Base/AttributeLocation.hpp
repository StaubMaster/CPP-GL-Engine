#ifndef  ATTRIBUTE_LOCATION_HPP
# define ATTRIBUTE_LOCATION_HPP

# include "OpenGLTypes.hpp"

namespace Attribute
{
class Location
{
	/*
		Offset inside Data Pointer
		Size is not directly used by gl
		glPointer uses offset + Offset
		offset is increased by Size
	*/
	private:
	public:
	//	from Child
	const GL::AttributeType Type;
	const unsigned int Size;
	const unsigned int Count;

	//	from Buffer
	const GL::AttributeDivisor Divisor;
	const unsigned int Stride;
	const GL::AttributeID Index;

	public:
	Location();
	Location(
		GL::AttributeType type,
		unsigned int size,
		unsigned int count,
		GL::AttributeDivisor divisor,
		unsigned int stride,
		GL::AttributeID index);
	~Location();

	Location(const Location & other);
	Location & operator=(const Location & other) = delete;
};
};

#endif