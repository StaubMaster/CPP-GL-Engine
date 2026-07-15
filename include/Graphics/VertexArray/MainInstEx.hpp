#ifndef  VERTEX_ARRAY_MAIN_INST_EX_HPP
# define VERTEX_ARRAY_MAIN_INST_EX_HPP

# include "Graphics/VertexArray/Base.hpp"

namespace Buffer { class Array; };
namespace Attribute { class Layout; };

namespace VertexArray
{

class MainInstEx : public VertexArray::Base
{
	public:
	GL::DrawMode		Mode;

	::Buffer::Array *	MainBuffer;
	::Buffer::Array *	InstBuffer;

	Attribute::Layout *		MainLayout = nullptr;
	Attribute::Layout *		InstLayout = nullptr;

	public:
	~MainInstEx();
	MainInstEx();

	MainInstEx(const MainInstEx & other) = default;
	MainInstEx & operator=(const MainInstEx & other) = default;

	//public:
	//void	Create() override;
	//void	Delete() override;

	public:
	void	Init();

	public:
	void	Draw();
};
};

#endif