#ifndef  POLYHEDRA_SIMPLE3D_MANAGER_MULTI_HPP
# define POLYHEDRA_SIMPLE3D_MANAGER_MULTI_HPP

# include "PolyHedra/PolyHedra.hpp"

# include "Shader.hpp"
# include "InstanceData/Simple3D/Data.hpp"

# include "Miscellaneous/Container/Binary.hpp"
# include "Miscellaneous/EntryContainer/Binary.hpp"



namespace Texture
{
	class Base;
};

namespace PolyHedra_Simple3D
{
struct ManagerSingle;

class ManagerMulti
{
	public:
	PolyHedra_Simple3D::Shader			DefaultShader;
	Container::Binary<ManagerSingle*>	MultiplePolyHedra;

	public:
	ManagerMulti();
	~ManagerMulti();

	private:
	unsigned int FindIndex(PolyHedra * polyhedra) const;

	public:
	void Insert(PolyHedra * polyhedra);
	void Remove(PolyHedra * polyhedra);
	//void Remove(unsigned int polyhedra);

	EntryContainer::Entry<Simple3D::Data> Place(PolyHedra * polyhedra, unsigned int size);
	//EntryContainer::Entry<Simple3D_InstData> Place(unsigned int polyhedra, unsigned int size);
	void Clear();

	public:
	void Draw();
};
};

#endif