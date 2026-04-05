#ifndef  POLYHEDRA_INSTANCE_MANAGER_HPP
# define POLYHEDRA_INSTANCE_MANAGER_HPP

# include "PolyHedra/Graphics/Full/Buffer.hpp"
# include "PolyHedra/Graphics/Wire/Buffer.hpp"

# include "Graphics/Texture/Array2D.hpp"

# include "Miscellaneous/Container/Binary.hpp"
# include "Instance/Basic3D/Data.hpp"

class PolyHedra;
struct PolyHedraObjectData;

struct PolyHedraInstanceManager
{
	::PolyHedra *				PolyHedra;

	bool						UpdateFullMain;
	bool						UpdateWireMain;

	::PolyHedraFull::Buffer		BufferFull;
	::PolyHedraWire::Buffer		BufferWire;
	
	Texture::Array2D			Texture;

	Container::Binary<Instance::Basic3D::Data>	InstancesFull;
	Container::Binary<Instance::Basic3D::Data>	InstancesWire;

	~PolyHedraInstanceManager();
	PolyHedraInstanceManager();
	PolyHedraInstanceManager(const PolyHedraInstanceManager & other);
	PolyHedraInstanceManager & operator=(const PolyHedraInstanceManager & other);

	PolyHedraInstanceManager(::PolyHedra * polyhedra);
	void	Change(::PolyHedra * polyhedra);



	void	GraphicsCreate();
	void	GraphicsDelete();

	void	InitExternal();
	void	InitInternal();



	void	UpdateBufferFullMain();
	void	UpdateBufferFullInst();
	void	DrawFull();

	void	UpdateBufferWireMain();
	void	UpdateBufferWireInst();
	void	DrawWire();



	void	ClearInstances();
	void	PlaceInstance(const PolyHedraObjectData & obj);
	void	PlaceInstances(const Container::Member<PolyHedraObjectData> & objs);
};

#endif