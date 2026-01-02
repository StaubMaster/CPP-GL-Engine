#ifndef  POLYHEDRA_SIMPLE3D_BUFFER_MANAGER
# define POLYHEDRA_SIMPLE3D_BUFFER_MANAGER

# include "PolyHedra/PolyHedra.hpp"
# include "Miscellaneous/EntryContainer/Binary.hpp"

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
	EntryContainer::Binary<Simple3D_InstData> * Instances;

	public:
	PolyHedra_3D_Instances();
	~PolyHedra_3D_Instances();

	PolyHedra_3D_Instances(const PolyHedra_3D_Instances & other);
	PolyHedra_3D_Instances & operator=(const PolyHedra_3D_Instances & other);

	public:
	void Create();
	void Delete();

	public:
	void SetPolyHedra(YMT::PolyHedra * polyhedra);

	public:
	void Draw();
};

#endif