#ifndef  POLYHEDRA_SIMPLE3D_BUFFER_MANAGER
# define POLYHEDRA_SIMPLE3D_BUFFER_MANAGER

# include "PolyHedra/PolyHedra.hpp"
# include "Miscellaneous/EntryContainer/Dynamic.hpp"

# include "PolyHedra_3D_BufferArray.hpp"

# include "OpenGL/openGL.h"
# include <iostream>



namespace Texture
{
	class Base;
};

class PolyHedra_3D_Instances
{
	public:
	YMT::PolyHedra * MainPolyHedra;
	Texture::Base * MainTexture;
	PolyHedra_3D_BufferArray Buffer;
	EntryContainer::Dynamic<Simple3D_InstData> Instances;

	public:
	PolyHedra_3D_Instances(YMT::PolyHedra * polyhedra);
	~PolyHedra_3D_Instances();

	public:
	PolyHedra_3D_Instances & Update();
	PolyHedra_3D_Instances & Draw();
};

#endif