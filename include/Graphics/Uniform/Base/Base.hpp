#ifndef  UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <string>

namespace Shader
{
	class Base;
};

namespace Multiform
{
	class Base;
};

namespace Uniform
{
struct NameShader
{
	std::string		Name;
	Shader::Base &	Shader;
	NameShader(std::string name, Shader::Base & shader);
	NameShader(const NameShader & other);
	NameShader & operator=(const NameShader & other) = delete;
	NameShader Suffix(std::string name) const;
};

class Base
{
	public:
	std::string			Name;
	Shader::Base &		Shader;
	Multiform::Base *	Multiform;
	bool				MultiformChanged;

	public:
	virtual void LogInfo(bool self = true) const;

	protected:
	Base(Uniform::NameShader & name_shader);
	virtual ~Base();

	public:
	int Locate() const;
	virtual void ReLocate();

	public:
	void PutMultiformData();
};
};

#endif