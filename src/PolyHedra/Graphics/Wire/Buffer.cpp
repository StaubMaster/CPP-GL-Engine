#include "PolyHedra/Graphics/Wire/Buffer.hpp"



PolyHedraWire::Buffer::~Buffer() { }

PolyHedraWire::Buffer::Buffer()
	: ::BufferArray::MainElemInst<
		PolyHedraWire::Main::Buffer,
		PolyHedraWire::Elem::Buffer,
		Instance::Basic3D::Buffer
	>(GL::DrawMode::Lines, 2)
{
	Main.Pos.Change(0);
	Main.Col.Change(1);
	Inst.Trans.Change(3, 4, 5, 6);
	Inst.Normal.Change(-1, -1, -1, -1);
}
