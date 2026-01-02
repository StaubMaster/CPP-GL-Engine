#ifndef  POLYHEDRA_SIMPLE3D_MANAGER_HPP
# define POLYHEDRA_SIMPLE3D_MANAGER_HPP

# include "PolyHedra/PolyHedra.hpp"
# include "PolyHedra_3D_Shader.hpp"
# include "PolyHedra_3D_BufferArray.hpp"

# include "Miscellaneous/Container/Dynamic.hpp"
# include "Miscellaneous/EntryContainer/Dynamic.hpp"

# include "Graphics/Shader/Base.hpp"
# include "Graphics/Buffer/BaseBufferArray.hpp"



namespace Texture
{
	class Base;
};

namespace PolyHedra_Simple3D
{
class Manager
{
	struct SinglePolyHedra
	{
		YMT::PolyHedra *	_PolyHedras;
		Texture::Base *			_Texture;
		PolyHedra_3D_BufferArray	_Buffers;
		EntryContainer::Dynamic<Simple3D_InstData>	_Entrys;

		SinglePolyHedra();
		~SinglePolyHedra();

		void Dispose();
		void Change(YMT::PolyHedra * polyhedra);

		void Draw();
	};

	//	PolyHedra
	//	Shader
	//	BufferArray
	private:
	PolyHedra_3D_Shader	_Shader;
	Container::Dynamic<SinglePolyHedra>	MultiplePolyHedra;

	public:
	Manager();
	~Manager();

	public:
	unsigned int Count() const;

	public:
	void InsertPolyHedra(YMT::PolyHedra * polyhedra);
	EntryContainer::Entry<Simple3D_InstData> InsertEntry(unsigned int polyhedra, unsigned int size);

	public:
	void Draw();
};
};

#endif