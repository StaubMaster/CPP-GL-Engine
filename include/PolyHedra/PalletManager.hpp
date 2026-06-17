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
	PolyHedraPalletManager() = delete;
	PolyHedraPalletManager(const PolyHedraPalletManager & other) = delete;
	PolyHedraPalletManager & operator=(const PolyHedraPalletManager & other) = delete;

	public:
	PolyHedraPalletManager(::PolyHedra * pallet);



	public:
	Container::Binary<PolyHedraObjectData*>	ObjectDatas;

	void	RemoveObjects();

	PolyHedraObjectData *		MakeObject();
	PolyHedraObjectData *		CopyObject(const PolyHedraObjectData * other);

	static PolyHedraObjectData *	TryMakeObject(PolyHedraPalletManager * pallet);
	static PolyHedraObjectData *	TryCopyObject(PolyHedraPalletManager * pallet, const PolyHedraObjectData * other);



	public:
	Container::Binary<Instance::Basic3D::Data>	InstancesFull;
	Container::Binary<Instance::Basic3D::Data>	InstancesWire;

	void	PutInstance(const PolyHedraObjectData & obj);
	void	PutInstance(const PolyHedraObjectData * obj);
	void	MakeInstances();



	public:
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

	private:
	void	UpdateFullBufferMain();
	public:
	void	DrawFull();

	private:
	void	UpdateWireBufferMain();
	public:
	void	DrawWire();
};

#endif