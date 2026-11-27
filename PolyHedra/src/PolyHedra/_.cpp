#include "PolyHedra/.hpp"



void PolyHedra::Combine(const PolyHedra & other, const Trans3D & trans)
{
	Flesh.Combine(other.Flesh, trans);

	if (Flesh.Faces.Count() < (Skin.Faces.Count()))
	{
		// Trim
		while (Flesh.Faces.Count() < (Skin.Faces.Count()))
		{
			Skin.Faces.RemoveAt(Flesh.Faces.Count());
		}
	}
	else if (Flesh.Faces.Count() > (Skin.Faces.Count()))
	{
		// Pad
		while (Flesh.Faces.Count() > (Skin.Faces.Count()))
		{
			Skin.Faces.Insert(PolyHedraSkin::Face());
		}
	}
	// there should be a Container function for these
	// TrimLength(unsigned int)
	// PadLength(unsigned int, const Item & default_item)
	// ToLength(unsigned int, const Item & default_item)

	Skin.Combine(other.Skin);
}



#include <sstream>
#include <iostream>
#include "ValueType/_Show.hpp"
#include "ValueType/Box/F3.hpp"
std::string PolyHedra::ToInfo() const
{
	std::stringstream ss;

//	ss << "File: " << File.Path << '\n';
	ss << "IsAutomatic: " << IsAutomatic << '\n';

	ss << "PolyHedra Count Vertex: " << Flesh.Corners.Count() << '\n';
	ss << "PolyHedra Count Face: " << Flesh.Faces.Count() << '\n';
	
	BoxF3 bound = Flesh.LimitBox();
	ss << "PolyHedra Bound Limit: " << bound << '\n';
	ss << "PolyHedra Bound Size: " << bound.Size() << '\n';

	return ss.str();
}
