#ifndef  UNI_DEPTH_HPP
# define UNI_DEPTH_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/DepthFactors.hpp"
# include "Graphics/Uniform/Range.hpp"
# include "Graphics/Uniform/ColorF4.hpp"

struct Depth;

namespace Uniform
{
class Depth : public Uniform::GBase<::Depth>
{
	private:
	Uniform::DepthFactors Factors;
	Uniform::Range Range;
	Uniform::ColorF4 Color;

	public:
	Depth(Uniform::NameShader name_shader);

	public:
	void Put(const ::Depth & obj) override;
};
};

#endif