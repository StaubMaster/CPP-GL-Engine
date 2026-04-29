#ifndef  BUFFER_ARRAYBASE_HPP
# define BUFFER_ARRAYBASE_HPP

# include "Miscellaneous/Container/Fixed.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Base; };

class VertexArray
{
	protected:
	GL::VertexArrayID ID;
	public:
	Container::Fixed<Buffer::Base*> Buffers;

	public:
	void LogInfo(bool self = true) const;



	public:
	virtual ~VertexArray();
	VertexArray();

	VertexArray(const VertexArray & other);
	VertexArray & operator=(const VertexArray & other);



	public:
	bool Exists() const;
	bool IsBound() const;
	void Bind();

	static GL::VertexArrayID Bound();
	static void BindNone();



	public:
	void	Create();
	void	Delete();



	public:
	virtual void	Draw(); // = 0; ?
};

#endif