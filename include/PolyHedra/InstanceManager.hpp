#ifndef  POLYHEDRA_INSTANCE_MANAGER_HPP
# define POLYHEDRA_INSTANCE_MANAGER_HPP

# include "PolyHedra/Graphics/Full/Buffer.hpp"
# include "PolyHedra/Graphics/Wire/Buffer.hpp"

# include "Graphics/Texture/Array2D.hpp"

# include "Miscellaneous/Container/Binary.hpp"
# include "Instance/Basic3D/Data.hpp"

class PolyHedra;
struct PolyHedraObjectData;

// rename. PalletManager ?
struct PolyHedraInstanceManager
{
	::PolyHedra *	PolyHedra; // Main "Key"

	// Object Defaults
	bool	DefaultFullVisibility;
	bool	DefaultWireVisibility;

	// put Flags into Buffers ?
	// store a Container of Data in Buffer ?
	// Main Data needs to be put into Buffers
	bool	UpdateFullMain;
	bool	UpdateWireMain;
	// Attributes in Buffers need to be initialized
	bool	UpdateFullInit;
	bool	UpdateWireInit;

	bool						GraphicsExist;
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



	void	UpdateFullBufferInit();
	void	UpdateFullBufferMain();
	void	UpdateFullBufferInst();
	void	DrawFull();

	void	UpdateWireBufferInit();
	void	UpdateWireBufferMain();
	void	UpdateWireBufferInst();
	void	DrawWire();



	void	ClearInstances();
	void	PlaceInstance(const PolyHedraObjectData & obj);
	void	PlaceInstances(const Container::Member<PolyHedraObjectData> & objs);
};

#endif