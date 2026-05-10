#ifndef  POLYHEDRA_GRAPHICS_WIRE_MAIN_DATA_HPP
# define POLYHEDRA_GRAPHICS_WIRE_MAIN_DATA_HPP

# include "ValueType/Vector/F3.hpp"
# include "ValueType/ColorF4.hpp"

namespace PolyHedraWire
{
namespace Main
{
struct Data
{
	VectorF3		Pos;
	ColorF4		Col;
	Data();
	Data(VectorF3 pos);
	Data(VectorF3 pos, ColorF4 col);
};
};
};

#endif