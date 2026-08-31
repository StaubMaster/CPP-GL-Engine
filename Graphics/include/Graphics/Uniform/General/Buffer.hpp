#ifndef  UNI_BUFFER_HPP
# define UNI_BUFFER_HPP

# include "Graphics/Uniform/General/Base.hpp"

struct DisplaySize;

namespace Uniform
{
class Buffer : public Base
{
	public:
	GL::BlockIndex	Index;

	public:
	Buffer(std::string name);
	Buffer(Uniform::Layout & layout, std::string name);

	public:
	void	Find(Shader::Base & shader) override;

	protected:
	void	PutVoid(const void * val) override;

	public:
	void	LogInfo(bool self = true) const override;
};
};

#endif