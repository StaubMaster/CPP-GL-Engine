#ifndef  BUFFER_ATTRIBUTE_HPP
# define BUFFER_ATTRIBUTE_HPP

# include "Graphics/Buffer/Base.hpp"

# include "OpenGLEnums.hpp"

//namespace Attribute { class Layout; };

namespace Buffer
{
class Array : public Base
{
	public:
	unsigned int	SizeOf;
	unsigned int	Count;

	private:
	// Attributes are per VertexArrayBuffer
	// same ArrayBuffer can have different Attributes
	//bool					AttributesBound;
	//Attribute::Layout *		AttributeLayout;

	public:
	~Array();
	Array() = delete;
	Array(GL::BufferDataUsage usage);

	Array(const Array & other) = default;
	Array & operator=(const Array & other) = default;

	//public:
	//void	Init(Attribute::Layout & layout);

	public:
	void	NewSize(unsigned int size) override;

	public:
	void	LogInfo(bool self = true) const override;
};
};

#endif