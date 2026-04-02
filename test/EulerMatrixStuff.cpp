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



/*void TestRotate2D()
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
}*/

/*void Test()
{
	std::cout << "Test\n";

	Point3D p3(1, 2, 3);
	Trans3D trans(Point3D(3, 4, 5), EulerAngle3D::Degrees(9, 321, 123));

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
	std::cout << ((p3 * trans.ToMatrixReverse()) * trans.ToMatrixForward()) << '\n';
	std::cout << ((p3 * trans.ToMatrixForward()) * trans.ToMatrixReverse()) << '\n';
	std::cout << '\n';
}*/

#include <math.h>

void TestPointTo2D()
{
	Point2D dir(2, 3);
	Point2D unit = dir.normalize();
	Point2D axis(1, 0);

	Angle a = Angle::SaTan2(
		dir.Y, dir.X
	);

	std::cout << unit << '\n';
	std::cout << (a.Forward(axis)) << '\n';
	std::cout << '\n';

	std::cout << axis << '\n';
	std::cout << (a.Reverse(unit)) << '\n';
	std::cout << '\n';
}
void TestPointTo3D()
{
//	EulerAngle3D a0 = EulerAngle3D::Degrees(0, 155, 127);
	EulerAngle3D a0 = EulerAngle3D::Degrees(0, 65, 97);

//	Point3D axis(1, 0, 0);
//	Point3D axis(0, 1, 0);
	Point3D axis(0, 0, 1);

	std::cout << "a0.Z0: " << a0.Z0.ToDegrees() << '\n';
	std::cout << "a0.X1: " << a0.X1.ToDegrees() << '\n';
	std::cout << "a0.Y2: " << a0.Y2.ToDegrees() << '\n';
	std::cout << '\n';

	Point3D p1 = a0.Forward(axis);

	float lenX = sqrt((p1.Y * p1.Y) + (p1.Z * p1.Z));
	float lenY = sqrt((p1.Z * p1.Z) + (p1.X * p1.X));
	float lenZ = sqrt((p1.X * p1.X) + (p1.Y * p1.Y));

	std::cout << Angle::SaTan2(p1.Y, p1.Z).ToDegrees() << '\n'; 
	std::cout << Angle::SaTan2(p1.Z, p1.X).ToDegrees() << '\n';
	std::cout << Angle::SaTan2(p1.X, p1.Y).ToDegrees() << '\n';
	std::cout << '\n';

	std::cout << Angle::SaTan2(p1.Z, p1.Y).ToDegrees() << '\n';
	std::cout << Angle::SaTan2(p1.X, p1.Z).ToDegrees() << '\n'; // axisZ Y2
	std::cout << Angle::SaTan2(p1.Y, p1.X).ToDegrees() << '\n';
	std::cout << '\n';

	std::cout << Angle::SaTan2(p1.X, lenX).ToDegrees() << '\n';
	std::cout << Angle::SaTan2(p1.Y, lenY).ToDegrees() << '\n'; // axisZ X1
	std::cout << Angle::SaTan2(p1.Z, lenZ).ToDegrees() << '\n';
	std::cout << '\n';

	std::cout << Angle::SaTan2(lenX, p1.X).ToDegrees() << '\n'; // axisX Y2
	std::cout << Angle::SaTan2(lenY, p1.Y).ToDegrees() << '\n'; // axisY X1
	std::cout << Angle::SaTan2(lenZ, p1.Z).ToDegrees() << '\n';
	std::cout << '\n';

	EulerAngle3D AngleToZ = EulerAngle3D(
		Angle(),
		Angle::SaTan2(p1.Y, lenY),
		Angle::SaTan2(p1.X, p1.Z)
	);
	std::cout << "AngleToZ.Z0: " << AngleToZ.Z0.ToDegrees() << '\n';
	std::cout << "AngleToZ.X1: " << AngleToZ.X1.ToDegrees() << '\n';
	std::cout << "AngleToZ.Y2: " << AngleToZ.Y2.ToDegrees() << '\n';
	std::cout << '\n';
}

int main()
{
	std::cout << '\n';
	//TestRotate2D();
	std::cout << '\n';
	//Test();
	std::cout << '\n';
	//TestPointTo2D();
	std::cout << '\n';
	TestPointTo3D();
	std::cout << '\n';
	return 0;
}
