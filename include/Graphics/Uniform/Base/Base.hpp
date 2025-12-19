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
	std::string Name;
	Shader::Base & Shader;
	Multiform::Base * Uniform;
	bool Changed;

	/*
		name and shader go down the Constructor chain until here
		put them both into one container called UniformData or something
		so only one thing needs to be passed down instead of 2 ?
	*/

	protected:
	Base(Uniform::NameShader & name_shader);
	virtual ~Base();

	public:
	int Find() const;

	public:
	void PutData();
};
};

#endif