#ifndef  TEXT_COMMAND_ARGS_HPP
# define TEXT_COMMAND_ARGS_HPP

# include <string>
# include "Generics/Container/Array.hpp"

namespace TextCommand
{
class Args
{
	private:
	Container::Array<std::string>	Segments;

	public:
	bool			Empty() const;
	std::string		Name() const;
	unsigned int	Count() const;

	public:
	std::string		ToString(unsigned int idx) const;
	unsigned int	ToUInt32(unsigned int idx) const;
	int				ToInt32(unsigned int idx) const;
	float			ToFloat(unsigned int idx) const;

	public:
	~Args() = default;
	Args() = default;
	Args(const Args & other) = default;
	Args & operator=(const Args & other) = default;

	public:
	void	Split(const std::string & str);
	Args	Split(unsigned int idx) const;
};
};

# include <iosfwd>
std::ostream &	operator<<(std::ostream & o, const TextCommand::Args & obj);

#endif