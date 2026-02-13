#ifndef  UNI_LINTER_HPP
# define UNI_LINTER_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"

struct LInter;

namespace Uniform
{
class LInter : public Uniform::GBase<::LInter>
{
	private:
	Uniform::Float1 T0;
	Uniform::Float1 T1;

	public:
	LInter(Uniform::NameShader name_shader);

	public:
	void Put(const ::LInter & obj) override;
};
};

#endif