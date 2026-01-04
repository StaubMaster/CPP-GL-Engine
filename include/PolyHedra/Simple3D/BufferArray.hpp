#ifndef  POLYHEDRA_SIMPLE3D_BUFFER_ARRAY_HPP
# define POLYHEDRA_SIMPLE3D_BUFFER_ARRAY_HPP

# include "Graphics/Buffer/ArrayBase.hpp"
# include "Graphics/Texture/Array2D.hpp"
# include "PolyHedra/Main/Buffer.hpp"
# include "InstanceData/Simple3D/Buffer.hpp"



namespace PolyHedra_Simple3D
{
class BufferArray : public ::BufferArray::Base
{
	public:
	PolyHedra_Main::Buffer	Main;
	Simple3D::Buffer		Inst;
	Texture::Array2D		Texture;
	unsigned int			DrawMode;

	public:
	BufferArray();
	~BufferArray();
	
	BufferArray(const BufferArray & other);
	BufferArray & operator=(const BufferArray & other);

	public:
	void Draw();
};
};

#endif
