#ifndef  USER_PARAMETER_HAPTIC_CODE_HPP
# define USER_PARAMETER_HAPTIC_CODE_HPP

namespace UserParameter
{

namespace Haptic
{

struct Code
{
	//private:
	public:
	int Flags;

	public:
	Code();
	Code(int flags);

	public:
	bool	operator==(const Code & other) const;
	bool	operator==(int code) const;
};

};

};

#endif