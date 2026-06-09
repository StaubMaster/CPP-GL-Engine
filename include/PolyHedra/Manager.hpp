#ifndef  POLYHEDRA_MANAGER_HPP
# define POLYHEDRA_MANAGER_HPP

# include "PolyHedra/PalletManager.hpp"

# include "Graphics/Shader/Base.hpp"

# include "PolyHedra/Graphics/Full/ShaderLayout.hpp"
# include "PolyHedra/Graphics/Wire/ShaderLayout.hpp"

# include "PolyHedra/Graphics/Full/Main/Layout.hpp"
# include "PolyHedra/Graphics/Wire/Main/Layout.hpp"

# include "Instance/Basic3D/Layout.hpp"

# include "Miscellaneous/Container/Binary.hpp"

# include "ValueType/Undex.hpp"

class PolyHedra;
struct PolyHedraObjectData;
class DirectoryInfo;

struct PolyHedraManager
{
	public:
	static PolyHedraManager * CurrentPointer;
	static PolyHedraManager & Current();
	static bool CheckCurrent();
	static void ClearCurrent();
	bool IsCurrent() const;
	void MakeCurrent();



	public:
	~PolyHedraManager();
	PolyHedraManager();
	PolyHedraManager(const PolyHedraManager & other) = delete;
	PolyHedraManager & operator=(const PolyHedraManager & other) = delete;



	public:
	// make these Pointers again ?
	Container::Binary<PolyHedraPalletManager>	InstanceManagers;

	public:
	void	ClearInstances();
	void	PlaceInstance(const PolyHedraObjectData & obj);
	void	MakeInstances();

	public:
	::PolyHedraPalletManager *	FindPallet(::PolyHedra * pallet);
	::PolyHedraPalletManager *	PlacePallet(::PolyHedra * pallet);



	// store in InstanceManagers ?
	public:
	Container::Binary<PolyHedraObjectData*>		ObjectDatas;

	public:
	PolyHedraObjectData *	PlaceObject(::PolyHedraPalletManager * pallet);
	PolyHedraObjectData *	PlaceObject(::PolyHedra * pallet);
	PolyHedraObjectData *	CopyObject(const PolyHedraObjectData * other);

	public:
	static PolyHedraObjectData *	sPlaceObject(::PolyHedraPalletManager * pallet);
	static PolyHedraObjectData *	sPlaceObject(::PolyHedra * pallet);
	static PolyHedraObjectData *	sCopyObject(const PolyHedraObjectData * other);



	public:
	bool				GraphicsExist;

	::Shader::Base		ShaderFullDefault;
	::Shader::Base		ShaderWireDefault;

	::Shader::Base *	ShaderFullOther;
	::Shader::Base *	ShaderWireOther;

	PolyHedraFull::ShaderLayout		ShaderLayoutFullDefault;
	::PolyHedraFull::Main::Layout	BufferLayoutFullMain;
	::Instance::Basic3D::Layout		BufferLayoutFullInst;

	PolyHedraWire::ShaderLayout		ShaderLayoutWireDefault;
	::PolyHedraWire::Main::Layout	BufferLayoutWireMain;
	::Instance::Basic3D::Layout		BufferLayoutWireInst;

	public:
	void	ChangeMedia(const DirectoryInfo & dir);

	public:
	void	GraphicsCreate();
	void	GraphicsDelete();

	public:
	void	DrawFull();
	void	DrawWire();
};

#endif
