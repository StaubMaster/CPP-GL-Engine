#ifndef  UNI_RANGE_HPP
# define UNI_RANGE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Float.hpp"

struct Range;

namespace Uniform
{
class Range : public Uniform::GBase<::Range>
{
	private:
	Uniform::Float Min;
	Uniform::Float Len;
	Uniform::Float Max;

	public:
	Range(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Range & obj) override;
};
};

#endif