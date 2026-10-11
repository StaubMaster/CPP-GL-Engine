#include "Generics/Container/Exception.hpp"



const char * Container::Exception::InvalidIndex::what() const noexcept
{
	return "Container: Invalid Index";
}
