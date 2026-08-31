#ifndef  UNI_RANGE_F_HPP
# define UNI_RANGE_F_HPP

# include "Graphics/Uniform/General/GBase.hpp"
# include "Graphics/Uniform/TypeDefs/Float.hpp"

struct RangeF;

namespace Uniform
{
class RangeF : public Uniform::GBase<::RangeF>
{
	private:
	Uniform::Float	Min;
	Uniform::Float	Len;
	Uniform::Float	Max;

	public:
	RangeF(std::string name);
	RangeF(Uniform::Layout & layout, std::string name);

	public:
	void	Put(const ::RangeF & obj) override;
};
};

#endif