#include "PolyHedra/Simple3D/ManagerSingle.hpp"
#include "PolyHedra/PolyHedra.hpp"

#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Graphics/Texture/Base.hpp"
#include "Graphics/Texture/Array2D.hpp"



PolyHedra_Simple3D::ManagerSingle::ManagerSingle() :
	_PolyHedra(NULL),
	_Buffer(),
	_Instances()
{ }
PolyHedra_Simple3D::ManagerSingle::~ManagerSingle()
{ }



void PolyHedra_Simple3D::ManagerSingle::Dispose()
{
	_Buffer.Delete();
	_Buffer.Texture.Delete();
	_Instances.Clear();

	delete _PolyHedra;
	_PolyHedra = NULL;
}
void PolyHedra_Simple3D::ManagerSingle::Change(PolyHedra * polyhedra)
{
	delete _PolyHedra;
	_Instances.Clear();
	_Buffer.Create();

	_PolyHedra = polyhedra;
	{
		_Buffer.Bind();
		Container::Pointer<PolyHedra_Main::Data> data = _PolyHedra -> ToMainData();
		_Buffer.Main.Change(data);
		data.Clear();
	}
	if (_PolyHedra -> Skin != NULL)
	{
		//_Texture = _PolyHedra -> Skin -> ToTexture();
		Skin2DA * skin = (Skin2DA*)(_PolyHedra -> Skin);
		skin -> ToTexture(_Buffer.Texture);
	}
	else
	{
		//_Texture = NULL;
		_Buffer.Texture.Delete();
	}
}

void PolyHedra_Simple3D::ManagerSingle::Draw()
{
	if (_Instances.Changed())
	{
		_Buffer.Bind();
		_Buffer.Inst.Change(_Instances);
		_Instances.UnChange();
	}
	/*if (_Texture != NULL)
	{
		_Texture -> Bind();
	}*/
	_Buffer.Draw();
}
