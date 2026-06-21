#ifndef  BUFFER_UNIFORM_HPP
# define BUFFER_UNIFORM_HPP

# include "Graphics/Buffer/Base.hpp"

# include "OpenGLEnums.hpp"

namespace Buffer
{
class Uniform : public Base
{
	public:
	GL::BlockBinding	Binding;

	public:
	~Uniform();
	Uniform() = delete;
	Uniform(GL::BufferDataUsage usage, unsigned int binding);

	Uniform(const Uniform & other) = default;
	Uniform & operator=(const Uniform & other) = default;

	public:
	void	BindBase();

	public:
	void	LogInfo(bool self = true) const override;
};
};

#endif