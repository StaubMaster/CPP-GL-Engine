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
	GL::DrawMode	Mode;

	private:
	::Buffer::Array *	MainBuffer = nullptr;
	::Buffer::Array *	InstBuffer = nullptr;

	private:
	Attribute::Layout *		MainLayout = nullptr;
	Attribute::Layout *		InstLayout = nullptr;

	public:
	~MainInstEx();
	MainInstEx();

	MainInstEx(const MainInstEx & other) = default;
	MainInstEx & operator=(const MainInstEx & other) = default;

	public:
	void	MainChange(::Buffer::Array & buffer, Attribute::Layout & layout, unsigned int size_of);
	void	InstChange(::Buffer::Array & buffer, Attribute::Layout & layout, unsigned int size_of);

	public:
	void	MainChange(::Buffer::Array * buffer, Attribute::Layout * layout, unsigned int size_of);
	void	InstChange(::Buffer::Array * buffer, Attribute::Layout * layout, unsigned int size_of);

	public:
	void	MainData(const Container::Void & data);
	void	InstData(const Container::Void & data);

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