#ifndef  BUFFER_VERTEX_ARRAY_HPP
# define BUFFER_VERTEX_ARRAY_HPP

# include "Generics/Container/Binary.hpp"

# include "OpenGLTypes.hpp"

namespace Buffer { class Base; };

class _VertexArray
{
	protected:
	GL::VertexArrayID	ID;

	public:
	Container::Binary<Buffer::Base*>	Buffers;

	/* Attributes
		are stored in VertexArray
		depend on BufferArray
	*/

	//private:
	//// make these also a Binary<>
	//Attribute::Layout *		AttributeLayoutMain;
	//Attribute::Layout *		AttributeLayoutInst;
	//bool					AttributeLayoutMainBound;
	//bool					AttributeLayoutInstBound;

	public:
	// move this to the end
	void	LogInfo(bool self = true) const;



	public:
	virtual ~_VertexArray();
	_VertexArray();

	_VertexArray(const _VertexArray & other);
	_VertexArray & operator=(const _VertexArray & other);



	public:
	bool	Exists() const;
	bool	IsBound() const;
	void	Bind();

	static GL::VertexArrayID	Bound();
	static void		BindNone();



	public:
	void	Create();
	void	Delete();



	//public:
	//void	ChangeAttributeLayoutMain(Attribute::Layout & layout);
	//void	ChangeAttributeLayoutMain(Attribute::Layout * layout);
	//void	ChangeAttributeLayoutInst(Attribute::Layout & layout);
	//void	ChangeAttributeLayoutInst(Attribute::Layout * layout);
	//void	InitAttributeLayoutMain(Buffer::Array & buffer);
	//void	InitAttributeLayoutInst(Buffer::Array & buffer);



	//public:
	//virtual void	Draw(); // = 0; ?
};

#endif