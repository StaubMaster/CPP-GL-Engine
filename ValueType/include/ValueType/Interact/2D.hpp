#ifndef  INTERACT_2D_HPP
# define INTERACT_2D_HPP

struct VectorF2;

struct RayF2;
struct LineF2;

namespace Interact2D
{
	bool	Is(
		const RayF2 & ray,
		const LineF2 & line
	);

	bool	Is(
		const LineF2 & line0,
		const LineF2 & line1
	);

	bool	Is(
		const LineF2 & line0,
		const LineF2 & line1,
		VectorF2 & ret
	);
};

#endif