#ifndef  UNI_UINT_N_BASE_HPP
# define UNI_UINT_N_BASE_HPP

# include "Graphics/Uniform/Base/Base.hpp"

# include "OpenGLTypes.hpp"

namespace Uniform
{
class UIntNBase : public Uniform::Base
{
	public:
	void LogInfo(bool self = true) const override;

	protected:
	GL::UniformLocation		Index;

	protected:
	virtual ~UIntNBase();
	UIntNBase(Uniform::Layout & layout, std::string name);

	protected:
	void			PutVoid(const void * val) override;
	virtual void	PutData(const unsigned int * val) = 0;

	protected:
	void	ReLocate();
};
};

#endif