#ifndef  BUFFER_BASE_HPP
# define BUFFER_BASE_HPP

# include "OpenGLTypes.hpp"

namespace Container { class Void; };

namespace Buffer
{
class Base
{
	protected:
	GL::BufferTarget		Target;
	GL::BufferDataUsage		Usage;
	GL::BufferID			ID;

	public:
	/* DataWant
		new Data should be generated for this Buffer
	*/
	bool	DataWant;
	/* DataHave
		new Data has been generated for this Buffer
		this Buffer should take the Data
	*/
	bool	DataHave;



	// store and automatically put Data in Buffer when needed
	// store Container::Void ?
	// might become invalid

	// store Count here ?
	// Size: full Size of Data
	// Stride: Size of Vertex
	// Count: number of Vertexes
	//
	// VertexSize
	// VertexCount



	public:
	virtual ~Base();
	Base() = delete;
	Base(::GL::BufferTarget target, GL::BufferDataUsage usage); // take sizeof Vertex

	Base(const Base & other) = default;
	Base & operator=(const Base & other) = default;

	public:
	bool	Exists() const;
	void	Create();
	void	Delete();

	public:
	void	Bind();

	public:
	void	DataNull();
	void	DataFull(unsigned int size);
	void	DataFull(const Container::Void & data);
	void	DataPart(unsigned int offset, const Container::Void & data);

	public:
	void *	DataMap();

	public:
	virtual void	NewSize(unsigned int size);

	public:
	virtual void	LogInfo(bool self = true) const;
};
};

#endif