#ifndef  UNIFORM_LAYOUT_HPP
# define UNIFORM_LAYOUT_HPP

# include "Miscellaneous/Container/Binary.hpp"

# include "OpenGLEnums.hpp"

namespace Shader { class Base; };
namespace Uniform
{
class Base;
class Layout
{
	public:
	void	LogInfo() const;

	public:
	Container::Binary<::Uniform::Base*>	Uniforms;
	::Shader::Base *					Shader;

	public:
	virtual ~Layout();
	Layout();

	Layout(const Layout & other);
	Layout & operator=(const Layout & other) = delete;

	public:
	bool	IsBound() const;
	void	Bind();

	public:
	void	Find();
	void	PutMultiformData();
	int		LocateUniform(const char * name) const;
};
};

#endif