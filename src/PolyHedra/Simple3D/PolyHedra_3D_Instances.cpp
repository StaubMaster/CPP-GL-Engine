#include "PolyHedra/Simple3D/PolyHedra_3D_Instances.hpp"
#include "PolyHedra/Skin/SkinBase.hpp"
#include "Graphics/Texture/Base.hpp"



PolyHedra_3D_Instances::PolyHedra_3D_Instances(YMT::PolyHedra * polyhedra)
{
	MainPolyHedra = polyhedra;

	Container::VoidPointer<PolyHedra_MainData> data = polyhedra -> ToMainData();
	Buffer.Main.Bind(data);
	data.Delete();

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
	//delete MainPolyHedra;
	delete MainTexture;
}





PolyHedra_3D_Instances & PolyHedra_3D_Instances::Update()
{
	if (Instances.Changed)
	{
		Container::VoidPointer<Simple3D_InstData> data(Instances.Count(), Instances.Data());
		Buffer.Inst.Bind(data);
		//Buffer.Inst.Bind(Instances.Data(), Instances.Count());
		//Buffer.Inst.Bind(GL_ARRAY_BUFFER, sizeof(Simple3D_InstData) * Instances.Count(), Instances.Data(), GL_STREAM_DRAW);
		//Buffer.Inst.Count = Instances.Count();
		//Buffer.BindInst(Instances.Data(), Instances.Count());
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
