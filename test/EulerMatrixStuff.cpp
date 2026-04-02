#include <iostream>
#include "DataShow.hpp"

#include "ValueType/Point2D.hpp"
#include "ValueType/Point3D.hpp"
#include "ValueType/Point4D.hpp"

#include "ValueType/Angle.hpp"
#include "ValueType/Angle2D.hpp"
#include "ValueType/Angle3D.hpp"
#include "ValueType/EulerAngle3D.hpp"

#include "ValueType/Trans2D.hpp"
#include "ValueType/Trans3D.hpp"

#include "ValueType/Matrix2x2.hpp"
#include "ValueType/Matrix3x3.hpp"
#include "ValueType/Matrix4x4.hpp"

#include "ValueType/Transformation3D.hpp"



void TestRotate2D()
{
	Point2D p(1, 0);
	Angle a = Angle::Degrees(90);
	Matrix2x2 m = Matrix2x2::Rotation(a);

	std::cout << p << '\n';
	std::cout << '\n';

	std::cout << (p * m) << '\n';
	std::cout << (a.Forward(p)) << '\n';
	std::cout << '\n';

	std::cout << (p * ~m) << '\n';
	std::cout << (p / m) << '\n';
	std::cout << (a.Reverse(p)) << '\n';
	std::cout << '\n';
}

void Test()
{
	std::cout << "Test\n";

	Point3D p3(1, 2, 3);
	Transformation3D trans(Point3D(3, 4, 5), EulerAngle3D::Degrees(9, 321, 123));

	std::cout << (p3) << '\n';
	std::cout << '\n';

	std::cout << (p3 * trans.ToMatrixForward()) << '\n';
	std::cout << (trans.Forward(p3)) << '\n';
	std::cout << '\n';

	std::cout << (p3 * trans.ToMatrixReverse()) << '\n';
	std::cout << (trans.Reverse(p3)) << '\n';
	std::cout << '\n';
	
	std::cout << (trans.Reverse(trans.Forward(p3))) << '\n';
	std::cout << (trans.Forward(trans.Reverse(p3))) << '\n';
	std::cout << '\n';
}

int main()
{
	std::cout << '\n';
	//TestRotate2D();
	std::cout << '\n';
	Test();
	std::cout << '\n';
	return 0;
}
