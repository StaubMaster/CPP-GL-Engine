#ifndef  UNI_Angle_3D_HPP
# define UNI_Angle_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Matrix3x3.hpp"
# include "DataDeclare.hpp"

namespace Uniform
{
class Angle3D : public Uniform::GBase<::Angle3D>
{
	private:
	Uniform::Matrix3x3	Mat;

	public:
	Angle3D(Uniform::NameShader name_shader);

	public:
	void Put(const ::Angle3D & obj) override;
};
};

#endif