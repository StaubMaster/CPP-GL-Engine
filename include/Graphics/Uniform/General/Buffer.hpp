#ifndef  UNI_BUFFER_HPP
# define UNI_BUFFER_HPP

# include "Graphics/Uniform/General/Base.hpp"

struct DisplaySize;

namespace Uniform
{
class Buffer : public Base
{
	public:
	void	LogInfo(bool self = true) const override;

	public:
	GL::BlockIndex	Index;

	public:
	Buffer(Uniform::Layout & layout, std::string name);

	protected:
	void	PutVoid(const void * val) override;
};
};

#endif