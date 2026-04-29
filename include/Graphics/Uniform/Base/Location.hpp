#ifndef  UNIFORM_LOCATION_HPP
# define UNIFORM_LOCATION_HPP

# include "OpenGLTypes.hpp"

# include <string>

namespace Shader { class Base; };

namespace Uniform
{
class Location
{
	public:
	void LogInfo(bool self = true) const;

	protected:
	::Shader::Base &		Shader;
	std::string				Name;

	unsigned int	Size0;
	unsigned int	Size1;
	unsigned int	Count;

	GL::UniformLocation		Index;

	public:
	virtual ~Location();
	Location() = delete;
	Location(::Shader::Base & shader, std::string name,
		unsigned int size0,
		unsigned int size1,
		unsigned int count
	);

	Location(const Location & other) = delete;
	Location & operator=(const Location & other) = delete;

	void	Change(GL::UniformLocation index);
};
};

#endif