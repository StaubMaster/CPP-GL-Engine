#ifndef  PARSING_VARIABLE_EXCEPTION_HPP
# define PARSING_VARIABLE_EXCEPTION_HPP

# include "TextExceptionBase.hpp"

# include <string>

class VariableNotFound : public TextExceptionBase
{
	public: VariableNotFound(const std::string & name);
};
class VariableIncorrentType: public TextExceptionBase
{
	public: VariableIncorrentType(const std::string & name);
};

#endif