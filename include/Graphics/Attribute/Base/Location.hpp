#ifndef  ATTRIBUTE_LOCATION_HPP
# define ATTRIBUTE_LOCATION_HPP

# include "OpenGLTypes.hpp"

namespace Attribute
{
class Location
{
	public:
	void LogInfo() const;

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
	const unsigned int Count;
	const unsigned int Size;

	//	from Buffer
	GL::AttributeLocation Index;

	public:
	~Location();
	Location() = delete;
	Location(
		GL::AttributeType type,
		unsigned int count,
		unsigned int size
	);

	Location(const Location & other);
	Location & operator=(const Location & other);

	public:
	void Change(GL::AttributeLocation index);

	public:
	virtual void Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const = 0;
};
};

#endif