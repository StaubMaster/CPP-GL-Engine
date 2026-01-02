#ifndef  POLYHEDRA_GENERATE_HPP
# define POLYHEDRA_GENERATE_HPP

# include "PolyHedra.hpp"

struct PolyHedra::Generate
{
	Generate() = delete;

	static PolyHedra * DuoHedra(Image * img, float scale = 1.0f);
	static PolyHedra * TetraHedron(float scale = 1.0f);
	static PolyHedra * HexaHedron(float scale = 1.0f);

	static PolyHedra * ConeC(int segments, float width = 1.0f, float height = 1.0f);
};

#endif
