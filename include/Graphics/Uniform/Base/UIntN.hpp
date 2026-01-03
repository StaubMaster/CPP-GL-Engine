
#ifndef  UNI_UINT_N_HPP
# define UNI_UINT_N_HPP

# include "Graphics/Uniform/Base/GBase.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class UIntN : public Uniform::GBase<const unsigned int *>
{
	protected:
	int Location;
	int Count;

	public:
	UIntN(int count, Uniform::NameShader name_shader);

	public:
	virtual void ReLocate() override;
	virtual void PutData(const unsigned int * val) = 0;
	void PutVoid(const void * val);
};
};

#endif
