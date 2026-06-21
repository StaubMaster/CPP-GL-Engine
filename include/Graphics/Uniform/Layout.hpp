#ifndef  UNIFORM_LAYOUT_HPP
# define UNIFORM_LAYOUT_HPP

# include "Miscellaneous/Container/Binary.hpp"

# include "OpenGLEnums.hpp"

namespace Shader { class Base; };
namespace Multiform { class Base; };

namespace Uniform
{
class Base;
class FloatNBase;
class UIntNBase;
class Buffer;
class Layout
{
	public:
	void	LogInfo() const;

	public:
	Container::Binary<::Uniform::Base*>		Uniforms;
	::Shader::Base *						Shader;

	public:
	virtual ~Layout();
	Layout();

	Layout(const Layout & other);
	Layout & operator=(const Layout & other) = delete;

	public:
	bool	IsBound() const;
	void	Bind();

	public:
	void	UniformBlockBinding(GL::BlockIndex index, GL::BlockBinding binding);

	public:
	void	UpdateData();

	private:
	void	Find(FloatNBase * uniform) const;
	void	Find(UIntNBase * uniform) const;
	void	Find(Buffer * uniform) const;

	public:
	void	Find();
	void	Find(Multiform::Base & multiform);
};
};

#endif