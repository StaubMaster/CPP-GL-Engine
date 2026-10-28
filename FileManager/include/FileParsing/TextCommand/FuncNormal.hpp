#ifndef  TEXT_COMMAND_FUNC_NORMAL_HPP
# define TEXT_COMMAND_FUNC_NORMAL_HPP

# include "FileParsing/TextCommand/Func.hpp"
# include "FileParsing/TextCommand/Args.hpp"

# include "Generics/Function/Pointer.hpp"

namespace TextCommand
{
struct FuncNormal : public Func
{
	Function::Pointer<const Args &>		Function;

	~FuncNormal() = default;
	FuncNormal() = delete;
	FuncNormal(const FuncNormal & other) = delete;
	FuncNormal & operator=(const FuncNormal & other) = delete;

	template<typename ObjectType> FuncNormal(
		std::string name,
		ObjectType * obj,
		void (ObjectType::*func)(const Args &)
	)
		: Func(name)
		, Function(obj, func)
	{ }

	bool	TryInvoke(const Args & cmd_args) const override;
};
};

#endif