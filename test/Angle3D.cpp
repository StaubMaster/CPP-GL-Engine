#include <iostream>
#include "DataShow.hpp"
#include "ValueType/Angle3D.hpp"
#include "ValueType/Point3D.hpp"

int main()
{
	std::cout << '\n';
	{
		{
			Angle3D	a(
				Angle::Radians(132),
				Angle::Radians(23),
				Angle::Radians(1)
			);
			Point3D p(13, 43, 54);
			Point3D p00 = a.rotateFore(p);
			Point3D p01 = a.rotateBack(p00);
			Point3D p10 = a.rotateBack(p);
			Point3D p11 = a.rotateFore(p10);
			std::cout << p << '\n';
			std::cout << p00 << '\n';
			std::cout << p01 << '\n';
			std::cout << p10 << '\n';
			std::cout << p11 << '\n';
		}
	}
	std::cout << '\n';
	return 0;
}
