
/*
	stores the angle and how to interpret it ?
	{
		if these are used in Angle3D
		I would have to skip the values for the Buffers
		
		{
			maybe figure out how to get the angles back from the matrix ?
			but that would require knowing if it was calculates foreward or backward
			but the differance between those is that they are transposed
			so just allways calculate one way
			and when the other is needed just multiply transposedly
		}
			
		but calculating the inital angles everytime they are changed might be slow ?
		just uncalculate all of them into a Point3D (used as Float3)
		then change them, then calculate back ?
		
		and have behaviour to add/sub by a Point3D (Float3) and then do this stuff internally
		maybe optimize it
		but that would have to be differentiated from rotating a Point
		maybe use + - for one and * / for the other idk
	}

	the differant angle types are:
	Radiant		0 to 2 Pi (1 Tau) for a full Circle
	Degrees		0 to 360 for a full Circle
	Normal		0 to 1
	maybe some other ?
	or just store the multiplyer ?

	or only store one but have it be a struct
	so functions can be used to add/sub Degrees ?
	that might be the simplest
*/
