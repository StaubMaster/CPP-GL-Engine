#ifndef  MULTIFORM_BASE_HPP
# define MULTIFORM_BASE_HPP

# include <string>

# include "Generics/Container/Binary.hpp"

namespace Shader { class Base; };

namespace Uniform { class Layout; class Base; };

namespace Multiform
{
class Base
{
	public:
	std::string		Name;

	public:
	Container::Binary<Uniform::Base*>	Uniforms;

	protected:
	virtual ~Base();
	Base(std::string name);

	public:
	void	Clear();

	public:
	void	FindUniforms(Uniform::Layout & layout);
	void	FindUniforms(Uniform::Layout * layout);
	void	FindUniforms(Container::Array<Uniform::Layout*> & layouts);

	public:
	virtual void	PutData(Uniform::Base & uniform) = 0;
	virtual void	PutData(Uniform::Base & uniform, Shader::Base & shader) = 0;

	public:
	void	PutUniformThis();
};
};

#endif