#include "FileParsing/Variables/Float.hpp"



bool ParsingVariable::Float::IsLiteral(const std::string & str)
{
	// only a partial check for now

	if (str.size() == 0) { return false; }

	char c = str[0];

	if (c == '+' || c == '-')
	{
		if (str.size() == 1) { return false; }
		c = str[1];
	}

	if (c >= '0' && c <= '9')
	{
		return true;
	}

	return false;
}
float ParsingVariable::Float::ParseLiteral(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == ',') { str[i] = '.'; }
	}
	return std::stof(str);
}

char ParsingVariable::Float::SignTake(std::string & str)
{
	if (str.size() == 0) { return '\0'; }

	char sign = str[0];
	if (sign != '+' && sign != '-')
	{
		return '\0';
	}
	else
	{
		str.erase(0, 1);
	}
	return sign;

}
float ParsingVariable::Float::SignPut(float value, char sign)
{
	if (sign == '+') { return +value; }
	if (sign == '-') { return -value; }
	return value;
}

#include "FileParsing/Variables/Memory.hpp"
float ParsingVariable::Float::Parse(const VariableMemory & vars, std::string str)
{
	if (ParsingVariable::Float::IsLiteral(str))
	{
		return ParsingVariable::Float::ParseLiteral(str);
	}
	char sign = ParsingVariable::Float::SignTake(str);
	float value;
	vars.Get(str, value);
	return ParsingVariable::Float::SignPut(value, sign);
}
