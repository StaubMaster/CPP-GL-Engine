#ifndef  UNI_DEPTH_HPP
# define UNI_DEPTH_HPP

# include "Graphics/Uniform/General/GBase.hpp"
# include "Graphics/Uniform/TypeDefs/DepthFactors.hpp"
# include "Graphics/Uniform/RangeF.hpp"
# include "Graphics/Uniform/TypeDefs/ColorF4.hpp"

struct Depth;

namespace Uniform
{
class Depth : public Uniform::GBase<::Depth>
{
	private:
	Uniform::DepthFactors	Factors;
	Uniform::RangeF			Range;
	Uniform::ColorF4		Color;

	public:
	Depth(Uniform::Layout & layout, std::string name);

	public:
	void Put(const ::Depth & obj) override;
};
};

#endif