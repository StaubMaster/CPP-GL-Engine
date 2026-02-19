#ifndef  BUFFER_BASE_HPP
# define BUFFER_BASE_HPP

# include "OpenGLTypes.hpp"

namespace BufferArray { class Base; };

namespace Buffer
{
class Base
{
	protected:
	::BufferArray::Base & BufferArray;
	GL::BufferTarget Target;
	GL::BufferID ID;

	public:
	void LogInfo(bool self = true) const;



	public:
	virtual ~Base();
	Base(::BufferArray::Base & buffer_array, GL::BufferTarget target);

	Base(const Base & other);
	Base & operator=(const Base & other);



	public:
	void Create();
	void Delete();

	void Bind();
};
};

#endif