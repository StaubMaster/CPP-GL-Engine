#ifndef  POLYHEDRA_INSTANCE_MANAGER_HPP
# define POLYHEDRA_INSTANCE_MANAGER_HPP

# include "PolyHedra/Graphics/Full/Buffer.hpp"
# include "PolyHedra/Graphics/Wire/Buffer.hpp"

# include "Instance/Basic3D/Data.hpp"

# include "Graphics/Texture/Array2D.hpp"

# include "Miscellaneous/Container/Binary.hpp"

class PolyHedra;
struct PolyHedraObjectData;
struct PolyHedraManager;

struct PolyHedraPalletManager
{
	::PolyHedra *	Pallet;

	// Object Defaults
	bool	DefaultVisibilityFull;
	bool	DefaultVisibilityWire;



	public:
	~PolyHedraPalletManager();
	PolyHedraPalletManager();
	PolyHedraPalletManager(const PolyHedraPalletManager & other) = delete;
	PolyHedraPalletManager & operator=(const PolyHedraPalletManager & other) = delete;

	public:
	PolyHedraPalletManager(::PolyHedra * pallet);
	void	Change(::PolyHedra * pallet);


	public:
	Container::Binary<Instance::Basic3D::Data>	InstancesFull;
	Container::Binary<Instance::Basic3D::Data>	InstancesWire;

	public:
	void	ClearInstances();
	void	PlaceInstance(const PolyHedraObjectData & obj);



	public:
	// put Flags into Buffers ?
	// store a Container of Data in Buffer ?
	// Main Data needs to be put into Buffers

	bool	BufferFullMainBound;
	bool	BufferWireMainBound;

	::PolyHedraFull::Buffer		BufferFull;
	::PolyHedraWire::Buffer		BufferWire;

	public:
	Texture::Array2D	TextureFull;

	public:
	void	ChangeMedia(PolyHedraManager & manager);



	public:
	bool	GraphicsExist;

	public:
	void	GraphicsCreate();
	void	GraphicsDelete();



	public:
	void	UpdateFullBufferMain();
	void	DrawFull();

	public:
	void	UpdateWireBufferMain();
	void	DrawWire();
};

#endif