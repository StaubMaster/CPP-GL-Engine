#ifndef  UNI_FLOAT_N_HPP
# define UNI_FLOAT_N_HPP

# include "Graphics/Uniform/Base/Base.hpp"

# include "OpenGLTypes.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class FloatN : public Uniform::Base
{
	protected:
	GL::UniformLocation Location;
	int Count;

	public:
	void LogInfo(bool self = true) const override;

	public:
	FloatN(::Shader::Base & shader, std::string name, int count);

	public:
	virtual void ReLocate() override;
	virtual void PutData(const float * val) = 0;
	void PutVoid(const void * val);
};
};

#endif