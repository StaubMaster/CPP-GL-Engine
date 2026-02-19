#ifndef  BUFFER_ARRAYBASE_HPP
# define BUFFER_ARRAYBASE_HPP

# include "Miscellaneous/Container/Fixed.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Base; };

namespace BufferArray
{
class Base
{
	protected:
	GL::VertexArrayID ID;
	Container::Fixed<Buffer::Base*> Buffers;

	public:
	void LogInfo(bool self = true) const;



	public:
	virtual ~Base();
	Base();

	Base(const Base & other);
	Base & operator=(const Base & other);



	public:
	bool Exists() const;
	bool IsBound() const;
	void Bind();

	static GL::VertexArrayID Bound();
	static void BindNone();



	public:
	void Create();
	void Delete();



	public:
	virtual void Draw();
};
};

#endif