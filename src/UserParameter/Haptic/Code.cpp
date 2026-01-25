#include "UserParameter/Haptic/Code.hpp"



UserParameter::Haptic::Code::Code() :
	Flags(0)
{ }
UserParameter::Haptic::Code::Code(int flags) :
	Flags(flags)
{ }



bool UserParameter::Haptic::Code::operator==(int code) const
{
	return Flags == code;
}
