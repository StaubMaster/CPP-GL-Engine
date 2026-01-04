#ifndef  POLYHEDRA_SIMPLE3D_BUFFER_MANAGER
# define POLYHEDRA_SIMPLE3D_BUFFER_MANAGER

# include "PolyHedra/PolyHedra.hpp"

# include "PolyHedra/Main/Data.hpp"
# include "InstanceData/Simple3D/Data.hpp"

# include "BufferArray.hpp"
# include "Miscellaneous/EntryContainer/Binary.hpp"

# include "OpenGL/openGL.h"
# include <iostream>



namespace Texture
{
	class Base;
};

class PolyHedra_3D_Instances
{
	public:
	PolyHedra * MainPolyHedra;
	Texture::Base * MainTexture;

	PolyHedra_Simple3D::BufferArray Buffer;
	EntryContainer::Binary<Simple3D::Data> * Instances;

	public:
	PolyHedra_3D_Instances();
	~PolyHedra_3D_Instances();

	PolyHedra_3D_Instances(const PolyHedra_3D_Instances & other);
	PolyHedra_3D_Instances & operator=(const PolyHedra_3D_Instances & other);

	public:
	void Create();
	void Delete();

	public:
	void SetPolyHedra(PolyHedra * polyhedra);

	public:
	void Draw();
};

#endif