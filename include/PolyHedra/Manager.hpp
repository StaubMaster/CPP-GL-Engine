#ifndef  POLYHEDRA_MANAGER_HPP
# define POLYHEDRA_MANAGER_HPP

# include "PolyHedra/InstanceManager.hpp"

# include "Graphics/Shader/Base.hpp"
# include "PolyHedra/Graphics/Full/ShaderLayout.hpp"
# include "PolyHedra/Graphics/Wire/ShaderLayout.hpp"

# include "Miscellaneous/Container/Binary.hpp"

# include "ValueType/Undex.hpp"

class PolyHedra;
struct PolyHedraObjectData;
class DirectoryInfo;

struct PolyHedraManager
{
	static PolyHedraManager * CurrentPointer;
	static PolyHedraManager & Current();
	static bool CheckCurrent();
	static void ClearCurrent();
	bool IsCurrent() const;
	void MakeCurrent();



	Container::Binary<PolyHedraObjectData*>		ObjectDatas;

	bool										GraphicsExist;
	::Shader::Base								ShaderFullDefault;
	::Shader::Base								ShaderWireDefault;
	PolyHedraFull::ShaderLayout					ShaderLayoutFullDefault;
	PolyHedraWire::ShaderLayout					ShaderLayoutWireDefault;
	::Shader::Base *							ShaderFullOther;
	::Shader::Base *							ShaderWireOther;

	Container::Binary<PolyHedraInstanceManager>	InstanceManagers;

	~PolyHedraManager();
	PolyHedraManager();
	PolyHedraManager(const PolyHedraManager & other) = delete;
	PolyHedraManager & operator=(const PolyHedraManager & other) = delete;

	void	GraphicsCreate();
	void	GraphicsDelete();

	void	InitExternal(DirectoryInfo & media_dir);
	void	InitInternal();

	unsigned int	FindPolyHedra(::PolyHedra * polyhedra);
	unsigned int	PlacePolyHedra(::PolyHedra * polyhedra);

	PolyHedraObjectData *	PlaceObject(unsigned int polyhedra, Trans3D trans);
	PolyHedraObjectData *	PlaceObject(::PolyHedra * polyhedra, Trans3D trans);
	PolyHedraObjectData *	CopyObject(const PolyHedraObjectData * obj);

	void	ClearInstances();
	void	PlaceInstance(const PolyHedraObjectData & obj);
	void	UpdateInstances();

	void	DrawFull();
	void	DrawWire();
};

#endif
