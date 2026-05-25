#ifndef  BUFFER_ATTRIBUTE_HPP
# define BUFFER_ATTRIBUTE_HPP

# include "Graphics/Buffer/Base.hpp"

# include "Graphics/Attribute/Base/Base.hpp"

# include "Miscellaneous/Container/Binary.hpp"

namespace Attribute { class Layout; };

# include "OpenGLEnums.hpp"

namespace Buffer
{
class Array : public Base
{
	public:
	unsigned int			Count;

	bool					AttributesBound;
	Attribute::Layout *		AttributeLayout;

	public:
	void LogInfo(bool self = true) const override;

	public:
	virtual ~Array();
	Array() = delete;
	Array(VertexArray & vertex_array, GL::BufferDataUsage usage);

	Array(const Array & other) = delete;
	Array(VertexArray & vertex_array, const Array & other);
	Array & operator=(const Array & other);

	public:
	void	Update() override;
	void	NewSize(unsigned int size) override;
};
};

#endif