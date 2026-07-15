#ifndef  VERTEX_ARRAY_MAIN_INST_IN_HPP
# define VERTEX_ARRAY_MAIN_INST_IN_HPP

# include "Graphics/VertexArray/Base.hpp"
# include "Graphics/Buffer/Array.hpp"

namespace Attribute { class Layout; };

namespace VertexArray
{

class MainInstIn : public VertexArray::Base
{
	public:
	GL::DrawMode		Mode;

	::Buffer::Array		MainBuffer;
	::Buffer::Array		InstBuffer;

	Attribute::Layout *		MainLayout = nullptr;
	Attribute::Layout *		InstLayout = nullptr;

	public:
	~MainInstIn();
	MainInstIn();

	MainInstIn(const MainInstIn & other) = default;
	MainInstIn & operator=(const MainInstIn & other) = default;

	public:
	void	Create() override;
	void	Delete() override;

	public:
	void	Init();

	public:
	void	Draw();
};
};

#endif