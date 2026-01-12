#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Template.hpp"

#include "PolyHedra/Skin/Skin2DA.hpp"

#include "PolyHedra/Main/Data.hpp"

#include "DataStruct/Angle3D.hpp"
#include "DataStruct/AxisBox3D.hpp"

#include "Graphics/Texture/Generate.hpp"
#include "Image.hpp"

#include "FileParsing/Text/TextCommand.hpp"
#include "FileParsing/Text/TextCommandStream.hpp"

//#include "FileInfo.hpp"

#include <sstream>

//#include "DataShow.hpp"
//#include <iostream>



PolyHedra::PolyHedra() :
	Corners(), Faces(),
	File(),
	Skin(NULL)
{
	UseCornerNormals = false;
}
PolyHedra::~PolyHedra()
{
	delete Skin;
}





std::string PolyHedra::ToInfo() const
{
	std::ostringstream ss;

	ss << "PolyHedra Info";
	ss << "\n" << "Corner Count: " << Corners.Count();
	ss << "\n" << "Face Count: " << Faces.Count();

	return ss.str();
}

AxisBox3D	PolyHedra::CalcBound() const
{
	AxisBox3D box;
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		box.Consider(Corners[i].Position);
	}
	return box;
}





#include <iostream>
#include "DataShow.hpp"
Container::Pointer<PolyHedra_Main::Data> PolyHedra::ToMainData()
{
	Container::Pointer<PolyHedra_Main::Data> data(Faces.Count() * 3);

	/*
	std::cout << "C " << Corners.Count() << "\n";
	std::cout << "F " << Faces.Count() << "\n";
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		std::cout << Corners[i].Position << "\n";
	}
	std::cout << "\n";
	*/

	for (unsigned int f = 0; f < Faces.Count(); f++)
	{
		int c = f * 3;
		const Face & face = Faces[f];
		if (face.Corner0.Udx < Corners.Count() &&
			face.Corner1.Udx < Corners.Count() &&
			face.Corner2.Udx < Corners.Count())
		{
			const Corner & cornerX = Corners[face.Corner0.Udx];
			const Corner & cornerY = Corners[face.Corner1.Udx];
			const Corner & cornerZ = Corners[face.Corner2.Udx];

			data[c + 0].Position = cornerX.Position;
			data[c + 1].Position = cornerY.Position;
			data[c + 2].Position = cornerZ.Position;

			if (!UseCornerNormals)
			{
				data[c + 0].Normal = face.Normal;
				data[c + 1].Normal = face.Normal;
				data[c + 2].Normal = face.Normal;
			}
			else
			{
				data[c + 0].Normal = cornerX.Normal;
				data[c + 1].Normal = cornerY.Normal;
				data[c + 2].Normal = cornerZ.Normal;
			}
		}
		else
		{
			//std::cout << "Invalid Face\n";
		}
	}

	if (Skin == NULL)
	{
		for (unsigned int i = 0; i < data.Count(); i++)
		{
			data[i].Texture = Point3D();
		}
	}
	else
	{
		const Skin2DA * skin = (const Skin2DA *)Skin;
		for (unsigned int f = 0; f < skin -> Faces.Count(); f++)
		{
			int c = f * 3;
			const Skin2DFace & face = ((Skin2DA*)Skin) -> Faces[f];
			data[c + 0].Texture = face.Corner0.Tex;
			data[c + 1].Texture = face.Corner1.Tex;
			data[c + 2].Texture = face.Corner2.Tex;
		}
	}

	//std::cout << "Main: " << data.Limit() << ' ' << data.Count() << '\n';
	//for (unsigned int i = 0; i < data.Count(); i++)
	//{ std::cout << data[i].Position << " : " << data[i].Normal << " : " << data[i].Texture << '\n'; }

	return data;
}
