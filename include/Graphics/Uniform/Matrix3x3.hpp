#ifndef  UNI_MATRIX_3X3_HPP
# define UNI_MATRIX_3X3_HPP

# include "Graphics/Uniform/Base/Float3x3.hpp"
# include "DataDeclare.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Matrix3x3 : public Uniform::Float3x3
{
	public:
	Matrix3x3(Uniform::NameShader name_shader);

	public:
	void Put(const ::Matrix3x3 & obj);
};
};

#endif