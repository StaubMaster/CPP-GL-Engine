#ifndef  INTERACT_3D_HPP
# define INTERACT_3D_HPP

struct VectorF3;

struct RayF3;
struct RayHitF3;

struct NormalPlaneF3;
struct TriangleF3;

namespace Interact3D
{
	void	Skew(
		const RayF3 & ray0, RayHitF3 & hit0,
		const RayF3 & ray1, RayHitF3 & hit1
	);

	RayHitF3	Plane(
		const RayF3 & ray,
		const NormalPlaneF3 & plane
	);
	RayHitF3	Triangle(
		const RayF3 & ray,
		const TriangleF3 & triangle
	);
};

#endif