#include "PolyHedra/Simple3D/PolyHedra_3D_Instances.hpp"
#include "PolyHedra/Skin/SkinBase.hpp"
#include "Graphics/Texture/Base.hpp"



PolyHedra_3D_Instances::PolyHedra_3D_Instances(YMT::PolyHedra * polyhedra)
{
	MainPolyHedra = polyhedra;

	Container::Pointer<PolyHedra_MainData> data = polyhedra -> ToMainData();
	Buffer.Main.Bind(data);
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
PolyHedra_3D_Instances::~PolyHedra_3D_Instances()
{
	delete MainTexture;
}





PolyHedra_3D_Instances & PolyHedra_3D_Instances::Update()
{
	if (Instances.Changed)
	{
		Container::Pointer<Simple3D_InstData> data(Instances.Count(), Instances.Data());
		Buffer.Inst.Bind(data);
		Instances.Changed = false;
	}
	return *this;
}
PolyHedra_3D_Instances & PolyHedra_3D_Instances::Draw()
{
	if (MainTexture != NULL)
	{
		MainTexture -> Bind();
	}
	Buffer.Draw();
	return *this;
}
