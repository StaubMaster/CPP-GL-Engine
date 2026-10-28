#ifndef  TEXT_COMMAND_LOOP_HPP
# define TEXT_COMMAND_LOOP_HPP

# include "Generics/Container/Binary.hpp"

# include "FileInfo.hpp"

namespace TextCommand
{
class Args;
class Func;

// seperate FuncSelector
struct Loop
{
	FileInfo	File;

	unsigned int	ExceptionCount = 0;

	Container::Binary<TextCommand::Func *>	Commands;

	~Loop();
	Loop() = default;
	Loop(const Loop & other) = delete;
	Loop & operator=(const Loop & other) = delete;

	void	Clear();

	void	Parse(const TextCommand::Args & cmd_args);

	void	ParseFile();
};
};

#endif