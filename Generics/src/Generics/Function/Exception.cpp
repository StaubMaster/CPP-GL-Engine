#include "Generics/Function/Exception.hpp"



const char * Function::Exception::MissingFunction::what() const noexcept
{
	return "Function: Missing Function";
}
const char * Function::Exception::MissingObject::what() const noexcept
{
	return "Function: Missing Object";
}
