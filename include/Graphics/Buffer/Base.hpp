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
	Base() = delete;
	Base(VertexArray & vertex_array, GL::BufferTarget target, GL::BufferDataUsage usage);

	Base(const Base & other) = delete;
	Base(VertexArray & vertex_array, const Base & other);
	Base & operator=(const Base & other);

	public:
	bool	Exists() const;
	void	Create();
	void	Delete();

	void	Bind();



	public:
	virtual void	Init();
	virtual void	NewSize(unsigned int size);

	public:
	void	DataNull();
	void	DataFull(unsigned int size);
	void	DataFull(const Container::Void & data);
	void	DataPart(unsigned int offset, const Container::Void & data);
	void *	DataMap();
};
};

#endif