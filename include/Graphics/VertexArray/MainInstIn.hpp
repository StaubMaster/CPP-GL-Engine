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
	GL::DrawMode	Mode;

	private:
	::Buffer::Array		MainBuffer;
	::Buffer::Array		InstBuffer;

	private:
	Attribute::Layout *		MainLayout = nullptr;
	Attribute::Layout *		InstLayout = nullptr;

	public:
	bool	MainDataWant;
	bool	InstDataWant;

	public:
	bool	MainDataHave;
	bool	InstDataHave;
	
	public:
	~MainInstIn();
	MainInstIn();

	MainInstIn(const MainInstIn & other) = default;
	MainInstIn & operator=(const MainInstIn & other) = default;

	public:
	void	MainChange(Attribute::Layout & layout, unsigned int size_of);
	void	InstChange(Attribute::Layout & layout, unsigned int size_of);

	public:
	void	MainChange(Attribute::Layout * layout, unsigned int size_of);
	void	InstChange(Attribute::Layout * layout, unsigned int size_of);

	public:
	void	MainData(const Container::Void & data);
	void	InstData(const Container::Void & data);

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