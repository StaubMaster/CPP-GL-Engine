#ifndef  ATTRIBUTE_LOCATION_HPP
# define ATTRIBUTE_LOCATION_HPP

# include "OpenGLTypes.hpp"

namespace Buffer { class Array; };

namespace Attribute
{
class Location
{
	public:
	void LogInfo() const;

	protected:
	//	from Child
	const GL::AttributeType	Type;
	const unsigned int		Size0; // AttributeCount Size1 Size2 Size3 Size4
	const unsigned int		Size1; // AttributeCount Size1 Size2 Size3 Size4
	const unsigned int		Offset;

	//	from Buffer
	GL::AttributeLocation	Index;

	public:
	~Location();
	Location() = delete;
	Location(
		Buffer::Array & buffer,
		GL::AttributeType type,
		unsigned int size0,
		unsigned int size1,
		unsigned int offset
	);

	Location(const Location & other);
	Location & operator=(const Location & other);

	public:
	void			Change(GL::AttributeLocation index);

	public:
	virtual void	Bind(GL::AttributeDivisor divisor, GL::AttributeStride stride, GL::AttributeOffset & offset) const = 0;
};
};

#endif