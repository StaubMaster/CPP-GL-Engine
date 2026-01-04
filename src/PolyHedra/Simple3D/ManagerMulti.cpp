#include "PolyHedra/Simple3D/ManagerMulti.hpp"
#include "PolyHedra/Simple3D/ManagerSingle.hpp"



PolyHedra_Simple3D::ManagerMulti::ManagerMulti() :
	DefaultShader()
{ }
PolyHedra_Simple3D::ManagerMulti::~ManagerMulti()
{
	DefaultShader.Delete();
	for (unsigned int i = 0; i < MultiplePolyHedra.Count(); i++)
	{
		MultiplePolyHedra[i] -> Dispose();
		delete MultiplePolyHedra[i];
	}
}



unsigned int PolyHedra_Simple3D::ManagerMulti::FindIndex(PolyHedra * polyhedra) const
{
	for (unsigned int i = 0; i < MultiplePolyHedra.Count(); i++)
	{
		if (MultiplePolyHedra[i] -> _PolyHedra == polyhedra)
		{ return i; }
	}
	return 0xFFFFFFFF;
}



void PolyHedra_Simple3D::ManagerMulti::Insert(PolyHedra * polyhedra)
{
	unsigned int idx = FindIndex(polyhedra);
	if (idx != 0xFFFFFFFF) { return; }

	ManagerSingle * man = new ManagerSingle();
	MultiplePolyHedra.Insert(man);
	man -> Change(polyhedra);
}
void PolyHedra_Simple3D::ManagerMulti::Remove(PolyHedra * polyhedra)
{
	unsigned int idx = FindIndex(polyhedra);
	if (idx == 0xFFFFFFFF) { return; }

	ManagerSingle * man = MultiplePolyHedra[idx];
	MultiplePolyHedra.Remove(idx);
	delete man;
}

EntryContainer::Entry<Simple3D::Data> PolyHedra_Simple3D::ManagerMulti::Place(PolyHedra * polyhedra, unsigned int size)
{
	Insert(polyhedra);
	unsigned int idx = FindIndex(polyhedra);
	//if (idx == 0xFFFFFFFF) { return; }

	ManagerSingle * man = MultiplePolyHedra[idx];
	return EntryContainer::Entry<Simple3D::Data>(man -> _Instances, size);
}



void PolyHedra_Simple3D::ManagerMulti::Clear()
{
	for (unsigned int i = 0; i < MultiplePolyHedra.Count(); i++)
	{
		MultiplePolyHedra[i] -> Dispose();
		delete MultiplePolyHedra[i];
	}
	MultiplePolyHedra.Dispose();
}



void PolyHedra_Simple3D::ManagerMulti::Draw()
{
	DefaultShader.Bind();
	for (unsigned int i = 0; i < MultiplePolyHedra.Count(); i++)
	{
		MultiplePolyHedra[i] -> Draw();
	}
}
