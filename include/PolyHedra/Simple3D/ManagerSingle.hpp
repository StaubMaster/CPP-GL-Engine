#ifndef  POLYHEDRA_SIMPLE3D_MANAGER_SINGLE_HPP
# define POLYHEDRA_SIMPLE3D_MANAGER_SINGLE_HPP

# include "PolyHedra/PolyHedra.hpp"
//# include "PolyHedra_3D_Shader.hpp"
# include "PolyHedra_3D_BufferArray.hpp"

# include "Miscellaneous/Container/Binary.hpp"
# include "Miscellaneous/EntryContainer/Binary.hpp"



namespace Texture
{
	class Base;
};

namespace PolyHedra_Simple3D
{
struct ManagerSingle
{
	PolyHedra *				_PolyHedra;
	Texture::Base *			_Texture;

	PolyHedra_3D_BufferArray	_Buffer;
	EntryContainer::Binary<Simple3D_InstData>	_Instances;

	ManagerSingle();
	~ManagerSingle();

	//SinglePolyHedra(const SinglePolyHedra & other);
	//SinglePolyHedra & operator=(const SinglePolyHedra & other);

	void Dispose();
	void Change(PolyHedra * polyhedra);

	void Draw();
};
};

#endif