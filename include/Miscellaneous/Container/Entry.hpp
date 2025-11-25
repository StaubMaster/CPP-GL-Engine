#ifndef  CONTAINER_ENTRY_HPP
# define CONTAINER_ENTRY_HPP

namespace Container
{

struct Entry
{
	public:
		unsigned int Offset;
		unsigned int Length;

	public:
		Entry() :
			Offset(0),
			Length(0)
		{ }
		Entry(unsigned int off, unsigned int len) :
			Offset(off),
			Length(len)
		{ }
		Entry(const Entry & other) :
			Offset(other.Offset),
			Length(other.Length)
		{ }
		~Entry()
		{ }

	public:
		Entry & operator =(const Entry & other)
		{
			Offset = other.Offset;
			Length = other.Length;
			return *this;
		}

	public:
		unsigned int Min() const { return Offset; }
		unsigned int Max() const { return Offset + Length; }
};

};

#endif