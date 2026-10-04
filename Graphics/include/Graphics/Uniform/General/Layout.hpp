#ifndef  UNIFORM_LAYOUT_HPP
# define UNIFORM_LAYOUT_HPP

# include "Generics/Container/Binary.hpp"

# include "OpenGLEnums.hpp"

namespace Shader { class Base; };
namespace Multiform { class Base; };

namespace Uniform
{
class Base;
class Buffer;
class Layout
{
	private:
	Container::Binary<Base*>	Uniforms;
	public:
	bool	IsDynamic = false; // delete with Shader
	public:
	void	Clear();
	void	Put(Base & uniform);
	void	Put(Base * uniform);

	private:
	::Shader::Base *	Shader = nullptr;
	public:
	void	AssignShader(::Shader::Base & shader);
	//void	AssignShader(::Shader::Base * shader);

	public:
	virtual ~Layout();
	Layout() = default;
	Layout(const Layout & other) = default;
	Layout & operator=(const Layout & other) = delete;

	Layout(Shader::Base & shader);

	public:
	bool	IsBound() const;
	void	Bind();

	public:
	void	Find();
	void	Find(Multiform::Base & multiform);

	public:
	void	UpdateData();

	public:
	void	Bind(Buffer & uniform, GL::BlockBinding binding);



	public:
	void	LogInfo() const;
	void	LogLine() const;
};
};

#endif