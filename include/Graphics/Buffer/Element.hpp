#ifndef  BUFFER_ELEMENT_HPP
# define BUFFER_ELEMENT_HPP

# include "Graphics/Buffer/Base.hpp"

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
	~Element();
	Element() = delete;
	Element(GL::BufferDataUsage usage, GL::DrawIndexType index_type);

	Element(const Element & other) = default;
	Element & operator=(const Element & other) = default;

	public:
	void	NewSize(unsigned int size) override;

	public:
	void	LogInfo(bool self = true) const override;
};
};

#endif