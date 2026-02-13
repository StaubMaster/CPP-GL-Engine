#ifndef  UNI_TRANS_2D_HPP
# define UNI_TRANS_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Point2D.hpp"
# include "Graphics/Uniform/Angle2D.hpp"

struct Trans2D;

namespace Uniform
{
class Trans2D : public Uniform::GBase<::Trans2D>
{
	private:
	Uniform::Point2D Pos;
	Uniform::Angle2D Rot;

	public:
	Trans2D(Uniform::NameShader name_shader);

	public:
	void Put(const ::Trans2D & obj) override;
};
};

#endif