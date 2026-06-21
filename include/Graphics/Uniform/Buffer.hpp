#ifndef  UNI_BUFFER_HPP
# define UNI_BUFFER_HPP

# include "Graphics/Uniform/Base/Base.hpp"

struct DisplaySize;

namespace Uniform
{
class Buffer : public Base
{
	public:
	GL::BlockIndex	Index;

	public:
	Buffer(Uniform::Layout & layout, std::string name);

	public:
	void	BindBlock(GL::BlockBinding binding);

	protected:
	void	PutVoid(const void * val) override;
};
};

#endif