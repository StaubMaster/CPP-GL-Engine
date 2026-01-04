#ifndef POLYHEDRA_SIMPLE3D_MANAGER_SINGLE_HPP
#define POLYHEDRA_SIMPLE3D_MANAGER_SINGLE_HPP

#include "PolyHedra/PolyHedra.hpp"

#include "BufferArray.hpp"

#include "PolyHedra/Main/Data.hpp"
#include "InstanceData/Simple3D/Data.hpp"

#include "Miscellaneous/Container/Binary.hpp"
#include "Miscellaneous/EntryContainer/Binary.hpp"

namespace Texture
{
	class Base;
};

namespace PolyHedra_Simple3D
{
	struct ManagerSingle
	{
		PolyHedra *_PolyHedra;

		PolyHedra_Simple3D::BufferArray _Buffer;
		EntryContainer::Binary<Simple3D::Data> _Instances;

		ManagerSingle();
		~ManagerSingle();

		// SinglePolyHedra(const SinglePolyHedra & other);
		// SinglePolyHedra & operator=(const SinglePolyHedra & other);

		void Dispose();
		void Change(PolyHedra *polyhedra);

		void Draw();
	};
};

#endif