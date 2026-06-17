#ifndef  MULTIFORM_BASE_HPP
# define MULTIFORM_BASE_HPP

# include <string>

# include "Miscellaneous/Container/Binary.hpp"

namespace Uniform { class Layout; class Base; };

namespace Multiform
{
class Base
{
	public:
	std::string Name;

	public:
	Container::Binary<Uniform::Base*> Uniforms;

	protected:
	virtual ~Base();
	Base(std::string name);

	public:
	void	FindUniforms(Uniform::Layout & layout);
	void	FindUniforms(Container::Array<Uniform::Layout *> & layouts);

	virtual void	PutData(Uniform::Base & uniform) = 0;
};
};

#endif