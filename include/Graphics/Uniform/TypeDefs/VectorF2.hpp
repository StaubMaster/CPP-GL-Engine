#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/FloatN.hpp"

//struct VectorF2;
struct VectorF2; typedef VectorF2 VectorF2;

namespace Uniform
{
typedef FloatN<2, 1, 1, ::VectorF2> VectorF2;
/*class VectorF2 : public Uniform::FloatN<2, 1, 1>
{
	public:
	VectorF2(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::VectorF2 & obj);
};*/
typedef VectorF2 VectorF2;
};

#endif