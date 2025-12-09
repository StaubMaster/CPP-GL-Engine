#ifndef  USER_PARAMETER_CLICK_HPP
# define USER_PARAMETER_CLICK_HPP

#include "DataStruct/Point2D.hpp"

namespace UserParameter
{

struct Click
{
	int Code;
	int Action;
	int Mods;
	Point2D Position;

	Click(int code, int action, int mods, Point2D pos);
};

};

#endif