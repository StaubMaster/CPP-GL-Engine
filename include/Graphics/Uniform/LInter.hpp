#ifndef  UNI_LINTER_HPP
# define UNI_LINTER_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Float.hpp"

struct LInter;

namespace Uniform
{
class LInter : public Uniform::GBase<::LInter>
{
	private:
	Uniform::Float T0;
	Uniform::Float T1;

	public:
	LInter(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::LInter & obj) override;
};
};

#endif