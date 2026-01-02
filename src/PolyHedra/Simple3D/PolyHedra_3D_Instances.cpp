#include "PolyHedra/Simple3D/PolyHedra_3D_Instances.hpp"
#include "PolyHedra/Skin/SkinBase.hpp"
#include "Graphics/Texture/Base.hpp"



PolyHedra_3D_Instances::PolyHedra_3D_Instances() :
	MainPolyHedra(NULL),
	MainTexture(NULL),
	Buffer(),
	Instances(NULL)
{ }
PolyHedra_3D_Instances::~PolyHedra_3D_Instances()
{ }

PolyHedra_3D_Instances::PolyHedra_3D_Instances(const PolyHedra_3D_Instances & other) :
	MainPolyHedra(other.MainPolyHedra),
	MainTexture(other.MainTexture),
	Buffer(other.Buffer),
	Instances(other.Instances)
{ }
PolyHedra_3D_Instances & PolyHedra_3D_Instances::operator=(const PolyHedra_3D_Instances & other)
{
	MainPolyHedra = other.MainPolyHedra;
	MainTexture = other.MainTexture;
	Buffer = other.Buffer;
	Instances = other.Instances;
	return *this;
}



void PolyHedra_3D_Instances::Create()
{
	Buffer.Create();

	Instances = new EntryContainer::Binary<Simple3D_InstData>();
}
void PolyHedra_3D_Instances::Delete()
{
	Buffer.Delete();

	delete MainPolyHedra;
	delete MainTexture;
	MainPolyHedra = NULL;
	MainTexture = NULL;

	delete Instances;
}



void PolyHedra_3D_Instances::SetPolyHedra(PolyHedra * polyhedra)
{
	MainPolyHedra = polyhedra;

	Container::Pointer<PolyHedra_MainData> data = polyhedra -> ToMainData();
	Buffer.Bind();
	Buffer.Main.Change(data);
	data.Dispose();

	if (polyhedra -> Skin != NULL)
	{
		MainTexture = polyhedra -> Skin -> ToTexture();
	}
	else
	{
		MainTexture = NULL;
	}
}



void PolyHedra_3D_Instances::Draw()
{
	if (Instances -> Changed)
	{
		Buffer.Bind();
		Buffer.Inst.Change(*Instances);
		Instances -> Changed = false;
	}
	if (MainTexture != NULL)
	{
		MainTexture -> Bind();
	}
	Buffer.Draw();
}
