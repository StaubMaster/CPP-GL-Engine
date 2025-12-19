#include "DataShow.hpp"

#include "DataStruct/Bool3D.hpp"
#include "DataStruct/Undex3D.hpp"
#include "DataStruct/UndexBox3D.hpp"
#include "DataStruct/UndexLoop3D.hpp"

#include <iostream>

int main()
{
	UndexLoop3D loop(
		Undex3D(0xFFFFFFFF - 1, 0xFFFFFFFF - 1, 0xFFFFFFFF - 1), Bool3D(false),
		Undex3D(0xFFFFFFFF - 0, 0xFFFFFFFF - 0, 0xFFFFFFFF - 0), Bool3D(false)
	);

	std::cout << 0xFFFFFFFF << '\n';
	unsigned int u = 0;
	Undex3D udx;
	for (udx = loop.Min(); loop.Check(udx).All(true); loop.Next(udx))
	{
		std::cout << u << ' ' << udx << '\n';
		u++;
	}
	std::cout << udx << '\n';

	return 0;
}
