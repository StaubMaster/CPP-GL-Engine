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

void TestPointToX3D()
{
	EulerAngle3D a0 = EulerAngle3D::Degrees(65, 0, 81);
	Point3D axis(1, 0, 0);

	Point3D p1 = a0.Forward(axis);
	EulerAngle3D a1 = EulerAngle3D::PointToX(p1);

	std::cout << "a1.Z0: " << a1.Z0.ToDegrees() << '\n';
	std::cout << "a1.X1: " << a1.X1.ToDegrees() << '\n';
	std::cout << "a1.Y2: " << a1.Y2.ToDegrees() << '\n';
	std::cout << '\n';

	std::cout << "a0.Z0: " << a0.Z0.ToDegrees() << '\n';
	std::cout << "a0.X1: " << a0.X1.ToDegrees() << '\n';
	std::cout << "a0.Y2: " << a0.Y2.ToDegrees() << '\n';
	std::cout << '\n';
}
void TestPointToY3D()
{
	EulerAngle3D a0 = EulerAngle3D::Degrees(65, 81, 0);
	Point3D axis(0, 1, 0);

	Point3D p1 = a0.Forward(axis);
	EulerAngle3D a1 = EulerAngle3D::PointToY(p1);

	std::cout << "a1.Z0: " << a1.Z0.ToDegrees() << '\n';
	std::cout << "a1.X1: " << a1.X1.ToDegrees() << '\n';
	std::cout << "a1.Y2: " << a1.Y2.ToDegrees() << '\n';
	std::cout << '\n';

	std::cout << "a0.Z0: " << a0.Z0.ToDegrees() << '\n';
	std::cout << "a0.X1: " << a0.X1.ToDegrees() << '\n';
	std::cout << "a0.Y2: " << a0.Y2.ToDegrees() << '\n';
	std::cout << '\n';
}
void TestPointToZ3D()
{
	EulerAngle3D a0 = EulerAngle3D::Degrees(0, 65, 81);
	Point3D axis(0, 0, 1);

	Point3D p1 = a0.Forward(axis);
	EulerAngle3D a1 = EulerAngle3D::PointToZ(p1);

	std::cout << "a1.Z0: " << a1.Z0.ToDegrees() << '\n';
	std::cout << "a1.X1: " << a1.X1.ToDegrees() << '\n';
	std::cout << "a1.Y2: " << a1.Y2.ToDegrees() << '\n';
	std::cout << '\n';

	std::cout << "a0.Z0: " << a0.Z0.ToDegrees() << '\n';
	std::cout << "a0.X1: " << a0.X1.ToDegrees() << '\n';
	std::cout << "a0.Y2: " << a0.Y2.ToDegrees() << '\n';
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

	std::cout << '\n';
	TestPointToX3D();
	std::cout << '\n';
	TestPointToY3D();
	std::cout << '\n';
	TestPointToZ3D();
	std::cout << '\n';

	return 0;
}
