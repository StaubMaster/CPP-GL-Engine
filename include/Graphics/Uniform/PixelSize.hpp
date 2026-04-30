#ifndef  UNI_PIXEL_SIZE_HPP
# define UNI_PIXEL_SIZE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/TypeDefs/VectorF2.hpp"

struct PixelSize;

namespace Uniform
{
class PixelSize : public Uniform::GBase<::PixelSize>
{
	private:
	Uniform::VectorF2 Full;
	Uniform::VectorF2 Half;

	public:
	PixelSize(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::PixelSize & obj) override;
};
};

#endif