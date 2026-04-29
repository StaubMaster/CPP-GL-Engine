#ifndef  BUFFER_ELEMENT_HPP
# define BUFFER_ELEMENT_HPP

# include "Graphics/Buffer/Base.hpp"

# include "Miscellaneous/Container/Void.hpp"

# include "OpenGLEnums.hpp"

namespace Buffer
{
class Element : public Base
{
	public:
	GL::DrawIndexType		IndexType;
	unsigned int			IndexSize;
	unsigned int			Count;

	public:
	void LogInfo(bool self = true) const override;

	public:
	virtual ~Element();
	Element(VertexArray & vertex_array, GL::BufferDataUsage usage, GL::DrawIndexType index_type);

	Element(const Element & other);
	Element & operator=(const Element & other);

	public:
	void	Data(const Container::Void & data) override;
};
};

#endif