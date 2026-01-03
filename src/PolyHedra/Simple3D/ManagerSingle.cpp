#include "PolyHedra/Simple3D/ManagerSingle.hpp"
#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Skin/SkinBase.hpp"
#include "Graphics/Texture/Base.hpp"



PolyHedra_Simple3D::ManagerSingle::ManagerSingle() :
	_PolyHedra(NULL),
	_Texture(NULL),
	_Buffer(),
	_Instances()
{ }
PolyHedra_Simple3D::ManagerSingle::~ManagerSingle()
{ }



void PolyHedra_Simple3D::ManagerSingle::Dispose()
{
	_Buffer.Delete();
	_Instances.Dispose();

	delete _PolyHedra;
	delete _Texture;
	_PolyHedra = NULL;
	_Texture = NULL;
}
void PolyHedra_Simple3D::ManagerSingle::Change(PolyHedra * polyhedra)
{
	delete _PolyHedra;
	delete _Texture;
	_Instances.Dispose();
	_Buffer.Create();

	_PolyHedra = polyhedra;
	{
		_Buffer.Bind();
		Container::Pointer<PolyHedra_MainData> data = _PolyHedra -> ToMainData();
		_Buffer.Main.Change(data);
		data.Dispose();
	}
	if (_PolyHedra -> Skin != NULL)
	{ _Texture = _PolyHedra -> Skin -> ToTexture(); }
	else { _Texture = NULL; }
}

void PolyHedra_Simple3D::ManagerSingle::Draw()
{
	if (_Instances.Changed)
	{
		_Buffer.Bind();
		_Buffer.Inst.Change(_Instances);
		_Instances.Changed = false;
	}
	if (_Texture != NULL)
	{
		_Texture -> Bind();
	}
	_Buffer.Draw();
}


