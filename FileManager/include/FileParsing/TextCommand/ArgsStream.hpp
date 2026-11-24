#ifndef  TEXT_COMMAND_ARGS_STREAM_HPP
# define TEXT_COMMAND_ARGS_STREAM_HPP

# include "Args.hpp"
# include "LineStream.hpp"
# include "Generics/Container/Array.hpp"
# include <string>

namespace TextCommand
{
class ArgsStream
{
	private:
	LineStream		_Stream;
	unsigned int					Index = 0xFFFFFFFF;
	Container::Array<std::string>	Segments;

	public:
	ArgsStream(const std::string & text);

	public:
	bool	Continue(Args & cmd_args);
};
};

#endif