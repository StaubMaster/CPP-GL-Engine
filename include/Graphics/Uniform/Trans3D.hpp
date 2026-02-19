#ifndef  UNI_TRANS_3D_HPP
# define UNI_TRANS_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Point3D.hpp"
# include "Graphics/Uniform/Angle3D.hpp"

struct Trans3D;

namespace Uniform
{
class Trans3D : public Uniform::GBase<::Trans3D>
{
	private:
	Uniform::Point3D Pos;
	Uniform::Angle3D Rot;

	public:
	Trans3D(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Trans3D & obj) override;
};
};

#endif