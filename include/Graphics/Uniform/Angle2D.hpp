#ifndef  UNI_ANGLE_2D_HPP
# define UNI_ANGLE_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Matrix2x2.hpp"
struct Angle2D;

namespace Uniform
{
class Angle2D : public Uniform::GBase<::Angle2D>
{
	private:
	Uniform::Matrix2x2	Mat;

	public:
	Angle2D(Uniform::NameShader name_shader);

	public:
	void Put(const ::Angle2D & obj) override;
};
};

#endif