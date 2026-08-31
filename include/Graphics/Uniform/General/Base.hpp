#ifndef  UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <string>

# include "OpenGLTypes.hpp"

namespace Shader { class Base; };

namespace Multiform { class Base; };

namespace Uniform
{
class Layout;
class Base
{
	public:
	std::string			Name;
	Multiform::Base *	Multiform;

	public:
	virtual ~Base();
	Base() = delete;
	Base(const Base & other) = delete;
	Base & operator=(const Base & other) = delete;

	public:
	Base(Uniform::Layout & layout, std::string name);

	public:
	virtual void	PutVoid(const void * val) = 0;

	public:
	void	UpdateData();
	void	UpdateData(Shader::Base & shader);

	public:
	virtual void LogInfo(bool self = true) const;
};
};

#endif