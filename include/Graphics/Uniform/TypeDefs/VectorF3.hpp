#ifndef  UNI_POINT_3D_HPP
# define UNI_POINT_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/FloatN.hpp"

//struct VectorF3;
struct VectorF3; typedef VectorF3 VectorF3;

namespace Uniform
{
typedef FloatN<3, 1, 1, ::VectorF3> VectorF3;
/*class VectorF3 : public Uniform::FloatN<3, 1, 1>
{
	public:
	VectorF3(::Shader::Base & shader, std::string name);

	public:
	void Put(const ::VectorF3 & obj);
};*/
typedef VectorF3 VectorF3;
};

#endif