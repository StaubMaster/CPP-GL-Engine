#ifndef  UNIFORM_LOCATION_FLOAT_N_HPP
# define UNIFORM_LOCATION_FLOAT_N_HPP

# include "Graphics/Uniform/Base/Location.hpp"

# include "OpenGLTypes.hpp"

namespace Uniform
{
class LocationFloatN : public Uniform::Location
{
	public:
	~LocationFloatN();
	LocationFloatN(::Shader::Base & shader, std::string name, unsigned int size0, unsigned int size1, unsigned int count);

	LocationFloatN(const LocationFloatN & other) = delete;
	LocationFloatN & operator=(const LocationFloatN & other) = delete;

	public:
	void	Put(const float * val);
};
};

#endif