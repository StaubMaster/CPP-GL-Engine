#ifndef  UNI_UINT_N_BASE_HPP
# define UNI_UINT_N_BASE_HPP

# include "Graphics/Uniform/General/Base.hpp"

# include "OpenGLTypes.hpp"

namespace Uniform
{
class UIntNBase : public Uniform::Base
{
	public:
	void	LogInfo(bool self = true) const override;

	public:
	GL::UniformLocation		Index;

	protected:
	virtual ~UIntNBase();
	UIntNBase(Uniform::Layout & layout, std::string name);

	public:
	void			PutVoid(const void * val) override;
	virtual void	PutData(const unsigned int * val) = 0;
};
};

#endif