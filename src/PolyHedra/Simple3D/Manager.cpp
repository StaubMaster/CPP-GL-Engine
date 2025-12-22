#include "PolyHedra/Simple3D/Manager.hpp"



PolyHedra_Simple3D::Manager::SinglePolyHedra::SinglePolyHedra()
{

}
PolyHedra_Simple3D::Manager::SinglePolyHedra::~SinglePolyHedra()
{

}

void PolyHedra_Simple3D::Manager::SinglePolyHedra::Dispose()
{

}
void PolyHedra_Simple3D::Manager::SinglePolyHedra::Change(YMT::PolyHedra * polyhedra)
{

}

void PolyHedra_Simple3D::Manager::SinglePolyHedra::Draw()
{
	if (Instances.Changed)
	{
		Buffer.BindInst(Instances.Data(), Instances.Count());
		Instances.Changed = false;
	}
	if (Texture != NULL)
	{
		Texture -> Bind();
	}
	Buffer.Draw();
}





PolyHedra_Simple3D::Manager::Manager()
{

}
PolyHedra_Simple3D::Manager::~Manager()
{

}



unsigned int PolyHedra_Simple3D::Manager::Count() const
{
	return _Singles.Count();
}



void PolyHedra_Simple3D::Manager::InsertPolyHedra(YMT::PolyHedra * polyhedra)
{

}
EntryContainer::Entry<Simple3D_InstData> PolyHedra_Simple3D::Manager::InsertEntry(unsigned int polyhedra, unsigned int size)
{

}



void PolyHedra_Simple3D::Manager::Draw()
{

}
