#ifndef  UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <string>

namespace Shader { class Base; };

namespace Multiform { class Base; };

namespace Uniform
{

class Base
{
	public:
	::Shader::Base &	Shader;
	std::string			Name;

	Multiform::Base *	Multiform;
	bool				MultiformChanged;

	public:
	virtual void LogInfo(bool self = true) const;

	protected:
	virtual ~Base();
	Base(::Shader::Base & shader, std::string name);

	Base(const Base & other) = delete;
	Base & operator=(const Base & other) = delete;

	public:
	int Locate() const;
	virtual void ReLocate();

	public:
	void PutMultiformData();
};
};

#endif