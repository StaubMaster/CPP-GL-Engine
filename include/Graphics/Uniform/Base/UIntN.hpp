#ifndef  UNI_UINT_N_HPP
# define UNI_UINT_N_HPP

# include "Graphics/Uniform/Base/Base.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class UIntN : public Uniform::Base
{
	protected:
	int Location;
	int Count;

	public:
	void LogInfo(bool self = true) const override;

	public:
	UIntN(Uniform::NameShader name_shader, int count);

	public:
	virtual void ReLocate() override;
	virtual void PutData(const unsigned int * val) = 0;
	void PutVoid(const void * val);
};
};

#endif