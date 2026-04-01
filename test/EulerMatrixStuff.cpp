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



void Position2Test()
{
	std::cout << "Position2Test\n";

	Point2D p2(1, 2);
	Point3D p3(p2.X, p2.Y, 1);

	Point2D diff(3, 4);
	Matrix3x3 mat0 = Matrix3x3(
		1, 0, +diff.X,
		0, 1, +diff.Y,
		0, 0, 1
	);
	Matrix3x3 mat1 = Matrix3x3(
		1, 0, -diff.X,
		0, 1, -diff.Y,
		0, 0, 1
	);

	std::cout << "p old * " << (p2 + diff) << '\n';
	std::cout << "p new * " << (mat0 * p3) << '\n';
	std::cout << "p new / " << (mat0 / p3) << '\n';
	std::cout << '\n';

	std::cout << "p old / " << (p2 - diff) << '\n';
	std::cout << "p new * " << (mat1 * p3) << '\n';
	std::cout << "p new / " << (mat1 / p3) << '\n';
	std::cout << '\n';

	std::cout << '\n';
}
void Rotation2Test()
{
	std::cout << "Rotation2Test\n";

	Point2D p(1, 2);

	Angle2D a = Angle2D(Angle::Degrees(123));
	Matrix2x2 mat = Matrix2x2::Rotation(a.Ang);

	std::cout << "p old * " << (a.Mat * p) << '\n';
	std::cout << "p new * " << (mat * p) << '\n';
	std::cout << '\n';

	std::cout << "p old / " << (a.Mat / p) << '\n';
	std::cout << "p new / " << (mat / p) << '\n';
	std::cout << '\n';

	std::cout << '\n';
}
void Transformation2Test()
{
	std::cout << "Transformation2Test\n";

	Point2D p2(1, 2);
	Point3D p3(p2.X, p2.Y, 1);

	Point2D diff(3, 4);
	Matrix3x3 mat0 = Matrix3x3(
		1, 0, +diff.X,
		0, 1, +diff.Y,
		0, 0, 1
	);
	Matrix3x3 mat1 = Matrix3x3(
		1, 0, -diff.X,
		0, 1, -diff.Y,
		0, 0, 1
	);

	Angle2D a = Angle2D(Angle::Degrees(123));
	Matrix3x3 mat2 = Matrix3x3::RotationZ(a.Ang);

	Trans2D trans(diff, a);

	std::cout << "p old * " << (trans * p2) << '\n';
	std::cout << "p old * " << ((a.Mat * p2) + diff) << '\n';
	std::cout << "p new * " << (mat0 * (mat2 * p3)) << '\n';
	std::cout << "p new * " << ((mat0 * mat2) * p3) << '\n';
	std::cout << '\n';

	std::cout << "p old * " << (trans / p2) << '\n';
	std::cout << "p old / " << (a.Mat / (p2 - diff)) << '\n';
	std::cout << "p new * " << (mat2.ToTranspose() * (mat1 * p3)) << '\n';
	std::cout << "p new * " << ((mat2.ToTranspose() * mat1) * p3) << '\n';
	std::cout << '\n';

	std::cout << '\n';
}

void Position3Test()
{
	std::cout << "Position3Test\n";

	Point3D p3(1, 2, 3);
	Point4D p4(p3.X, p3.Y, p3.Z, 1);

	Point3D diff(3, 4, 5);
	Matrix4x4 mat0 = Matrix4x4::Position(+diff);
	Matrix4x4 mat1 = Matrix4x4::Position(-diff);

	std::cout << "p old * " << (p3 + diff) << '\n';
	std::cout << "p new * " << (mat0 * p4) << '\n';

	std::cout << "p old / " << (p3 - diff) << '\n';
	std::cout << "p new / " << (mat1 * p4) << '\n';

	std::cout << '\n';
}
void Rotation3Test()
{
	std::cout << "Rotation3Test\n";

	Point3D p3(1, 2, 3);
	Point4D p4(p3.X, p3.Y, p3.Z, 1);

	Angle3D a(Angle::Degrees(9), Angle::Degrees(321), Angle::Degrees(123));
	EulerAngle3D e(a.X, a.Y, a.Z);

	Matrix4x4 mat = Matrix4x4::Rotation(e);

	std::cout << "p old * " << (a.Mat * p3) << '\n';
	std::cout << "p new * " << (mat * p4) << '\n';
	std::cout << '\n';

	std::cout << "p old / " << (a.Mat / p3) << '\n';
	std::cout << "p new / " << (mat / p4) << '\n';
	std::cout << '\n';

	std::cout << '\n';
}
void Transformation3Test()
{
	std::cout << "Transformation3Test\n";

	Point3D p3(1, 2, 3);
	Point4D p4(p3.X, p3.Y, p3.Z, 1);

	//Point3D diff(3, 4, 5);
	Point3D diff(0, 0, 0);
	
	Angle3D a(Angle::Degrees(9), Angle::Degrees(321), Angle::Degrees(123));
	EulerAngle3D e(a.X, a.Y, a.Z);

	Matrix4x4 mat0 = Matrix4x4::Position(+diff);
	Matrix4x4 mat1 = Matrix4x4::Position(-diff);
	Matrix4x4 mat2 = Matrix4x4::Rotation(e);

	std::cout << "p old * " << ((a.Mat * p3) + diff) << '\n';
	std::cout << "p old * " << (a.Mat * (p3 + diff)) << '\n';
	std::cout << "p old / " << (a.Mat / (p3 - diff)) << '\n';
	std::cout << "p old / " << ((a.Mat / p3) - diff) << '\n';
	std::cout << '\n';

	std::cout << "p new * " << (mat0 * (mat2 * p4)) << '\n';
	std::cout << "p new * " << (mat1 * (mat2 * p4)) << '\n';
	std::cout << "p new * " << (mat2 * (mat0 * p4)) << '\n';
	std::cout << "p new * " << (mat2 * (mat1 * p4)) << '\n';
	std::cout << '\n';

	std::cout << "p new * " << (mat0 * (mat2.ToTranspose() * p4)) << '\n';
	std::cout << "p new * " << (mat1 * (mat2.ToTranspose() * p4)) << '\n';
	std::cout << "p new * " << (mat2.ToTranspose() * (mat0 * p4)) << '\n';
	std::cout << "p new * " << (mat2.ToTranspose() * (mat1 * p4)) << '\n';
	std::cout << '\n';
}

int main()
{
	//Position2Test();
	//Rotation2Test();
	//Transformation2Test();

	//Position3Test();
	Rotation3Test();
	//Transformation3Test();

	return 0;
}
