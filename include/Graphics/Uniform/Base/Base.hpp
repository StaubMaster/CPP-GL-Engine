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
	//Uniform::Layout &		Layout;
	std::string				Name;
	Multiform::Base *		Multiform;

	protected:
	virtual ~Base();
	Base(Uniform::Layout & layout, std::string name);

	Base(const Base & other) = delete;
	Base & operator=(const Base & other) = delete;

	public:
	virtual void	PutVoid(const void * val) = 0;

	public:
	void	UpdateData();

	public:
	virtual void LogInfo(bool self = true) const;
};
};

#endif