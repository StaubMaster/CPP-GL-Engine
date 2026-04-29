#ifndef  BUFFER_BASE_HPP
# define BUFFER_BASE_HPP

# include "OpenGLTypes.hpp"

class VertexArray;

namespace Container { class Void; };

namespace Buffer
{
class Base
{
	protected:
	VertexArray &			BufferArray; // VertexBufferArray
	GL::BufferTarget		Target;
	GL::BufferDataUsage		Usage;
	GL::BufferID			ID;

	public:
	virtual void LogInfo(bool self = true) const;

	public:
	virtual ~Base();
	Base(VertexArray & vertex_array, GL::BufferTarget target, GL::BufferDataUsage usage);

	Base(const Base & other);
	Base & operator=(const Base & other);

	public:
	bool	Exists() const;
	void	Create();
	void	Delete();

	void	Bind();



	public:
	virtual void	Init();

	public:
	void			Data();
	virtual void	Data(const Container::Void & data);
};
};

#endif