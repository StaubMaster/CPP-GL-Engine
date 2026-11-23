#ifndef  PARSING_VARIABLE_FLOAT_HPP
# define PARSING_VARIABLE_FLOAT_HPP

# include <string>

struct VariableMemory;

namespace ParsingVariable
{
namespace Float
{
	bool	IsLiteral(const std::string & str);
	float	ParseLiteral(std::string str);

	char	SignTake(std::string & str);
	float	SignPut(float value, char sign);

	float	Parse(const VariableMemory & vars, std::string str);
};
};

#endif