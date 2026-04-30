#ifndef  UNI_TRANS_2D_HPP
# define UNI_TRANS_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/TypeDefs/VectorF2.hpp"
# include "Graphics/Uniform/TypeDefs/Matrix2x2.hpp"

struct Trans2D;

namespace Uniform
{
class Trans2D : public Uniform::GBase<::Trans2D>
{
	private:
	Uniform::VectorF2	Pos;
	Uniform::Matrix2x2	Rot;

	public:
	Trans2D(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Trans2D & obj) override;
};
};

#endif