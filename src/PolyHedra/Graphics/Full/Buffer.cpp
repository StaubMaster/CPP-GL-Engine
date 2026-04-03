#include "PolyHedra/Graphics/Full/Buffer.hpp"



PolyHedraFull::Buffer::~Buffer() { }
PolyHedraFull::Buffer::Buffer()
	: ::BufferArray::MainInst<
		PolyHedraFull::Main::Buffer,
		Instance::Basic3D::Buffer
	>(GL::DrawMode::Triangles)
{
	Main.Position.Change(0);
	Main.Normal.Change(1);
	Main.Texture.Change(2);
	Inst.Trans.Change(3, 4, 5, 6);
	Inst.Normal.Change(7, 8, 9, 10);
}
