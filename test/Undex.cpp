#include "DataShow.hpp"

#include "DataStruct/Bool3D.hpp"
#include "DataStruct/Undex3D.hpp"
#include "DataStruct/UndexRange3D.hpp"
#include "DataStruct/UndexLoop3D.hpp"

#include <iostream>

int main()
{
	UndexLoop3D loop(Undex3D(3, 3, 3), Undex3D(5, 5, 5));

	for (Undex3D udx = loop.Min(); loop.CheckIn(udx).All(true); loop.Next(udx))
	{
		std::cout << udx << '\n';
	}

	return 0;
}
