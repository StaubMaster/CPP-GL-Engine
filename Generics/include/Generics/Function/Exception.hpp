#ifndef  FUNCTION_EXCEPTION_HPP
# define FUNCTION_EXCEPTION_HPP

# include <exception>

namespace Function
{
namespace Exception
{
class MissingFunction : public std::exception
{
	const char * what() const noexcept;
};
class MissingObject : public std::exception
{
	const char * what() const noexcept;
};
};
};

#endif