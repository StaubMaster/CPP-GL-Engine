#ifndef  VERTEX_ARRAY_MULTI_HPP
# define VERTEX_ARRAY_MULTI_HPP

# include "Graphics/VertexArray/Base.hpp"
# include "Graphics/Buffer/Array.hpp"

namespace VertexArray
{
class Multi : public Base
{
	public:
	struct Entry
	{
		VertexArray::Multi &	Buffer;
		unsigned int			Offset;
		unsigned int			Length;

		bool	IsEmpty() const;
		void	MakeEmpty();

		~Entry();
		Entry() = delete;
		Entry(VertexArray::Multi & buffer);

		Entry(const Entry & other) = delete;
		Entry & operator=(const Entry & other) = delete;
	};

	public:
	GL::DrawMode	Mode;

	public:
	::Buffer::Array		Buffer;

	public:
	~Multi();
	Multi();

	Multi(const Multi & other) = default;
	Multi & operator=(const Multi & other) = default;

	private:
	public:
	Container::Binary<VertexArray::Multi::Entry*>	Entrys;
	Container::Binary<int>		Offsets;
	Container::Binary<int>		Lengths;

	public:
	bool	CheckEntry(VertexArray::Multi::Entry & entry);
	void	Insert(VertexArray::Multi::Entry & entry);
	void	Remove(VertexArray::Multi::Entry & entry);

	public:
	void	NewSize(unsigned int size, unsigned int count);
	public:
	void	Put(VertexArray::Multi::Entry & entry, unsigned int size, const Container::Void & data, unsigned int count);

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