#ifndef  BUFFER_ATTRIBUTE_HPP
# define BUFFER_ATTRIBUTE_HPP

# include "Graphics/Buffer/Base.hpp"

# include "OpenGLEnums.hpp"

namespace Attribute { class Layout; };

namespace Buffer
{
class Array : public Base
{
	public:
	unsigned int			Count;

	private:
	bool					AttributesBound;
	Attribute::Layout *		AttributeLayout;

	public:
	~Array();
	Array() = delete;
	Array(GL::BufferDataUsage usage);

	Array(const Array & other) = default;
	Array & operator=(const Array & other) = default;

	public:
	void	Init(Attribute::Layout & layout);

	public:
	void	Update() override;
	void	NewSize(unsigned int size) override;

	public:
	void	LogInfo(bool self = true) const override;
};
};

#endif