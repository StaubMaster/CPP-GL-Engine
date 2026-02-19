#ifndef  UNI_RANGE_HPP
# define UNI_RANGE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"

struct Range;

namespace Uniform
{
class Range : public Uniform::GBase<::Range>
{
	private:
	Uniform::Float1 Min;
	Uniform::Float1 Len;
	Uniform::Float1 Max;

	public:
	Range(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::Range & obj) override;
};
};

#endif