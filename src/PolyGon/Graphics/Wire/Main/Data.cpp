#include "PolyHedra/Graphics/Wire/Main/Data.hpp"



PolyHedraWire::Main::Data::Data()
	: Pos()
	, Col()
{ }
PolyHedraWire::Main::Data::Data(Point3D pos)
	: Pos(pos)
	, Col()
{ }
PolyHedraWire::Main::Data::Data(Point3D pos, ColorF4 col)
	: Pos(pos)
	, Col(col)
{ }
