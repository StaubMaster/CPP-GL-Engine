#ifndef  PARSING_VARIABLE_ENTRY_HPP
# define PARSING_VARIABLE_ENTRY_HPP

# include <string>

struct VariableEntryBase
{
	std::string		Name;

	virtual ~VariableEntryBase() = default;
	VariableEntryBase() = default;
	VariableEntryBase(const VariableEntryBase & other) = default;
	VariableEntryBase & operator=(const VariableEntryBase & other) = default;
};

template<typename Type>
struct VariableEntryType : public VariableEntryBase
{
	Type	Data;

	~VariableEntryType() = default;
	VariableEntryType() = default;
	VariableEntryType(const VariableEntryType & other) = default;
	VariableEntryType & operator=(const VariableEntryType & other) = default;
};

#endif