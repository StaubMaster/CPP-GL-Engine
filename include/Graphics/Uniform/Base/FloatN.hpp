#ifndef  UNI_FLOAT_N_HPP
# define UNI_FLOAT_N_HPP

# include "Graphics/Uniform/Base/Base.hpp"
# include "Graphics/Uniform/Base/LocationFloatN.hpp"

# include "OpenGLTypes.hpp"

namespace Shader { class Base; };

namespace Uniform
{
class FloatN : public Uniform::Base
{
	protected:
	LocationFloatN	Location;

	public:
	void LogInfo(bool self = true) const override;

	public:
	FloatN(::Shader::Base & shader, std::string name,
		unsigned int size0,
		unsigned int size1,
		unsigned int count
	); // Size0 Size1 and Count with Template ?

	protected:
	virtual void	ReLocate() override;
	void			PutVoid(const void * val);
};
};

#endif