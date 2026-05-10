#include "PolyHedra/Generate.hpp"
#include "PolyHedra/Data.hpp"

#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Graphics/Texture/Generate.hpp"

#include "ValueType/Angle.hpp"
#include "ValueType/EulerAngle3D.hpp"

#include "Image.hpp"

//#include "FileInfo.hpp"
//#include "DirectoryInfo.hpp"
//#include "DataShow.hpp"
#include "Debug.hpp"
#include <sstream>
#include <iostream>

PolyHedra * PolyHedra::Generate::DuoHedra(Image img, float scale)
{
	PolyHedra * polyhedra = new PolyHedra();

	polyhedra -> Insert_Corn(VectorF3(-scale, -scale, 0));
	polyhedra -> Insert_Corn(VectorF3(-scale, +scale, 0));
	polyhedra -> Insert_Corn(VectorF3(+scale, -scale, 0));
	polyhedra -> Insert_Corn(VectorF3(+scale, +scale, 0));

	polyhedra -> Insert_Face4(0, 1, 2, 3);



	Skin2DA * skin = new Skin2DA();
	skin -> W = img.W();
	skin -> H = img.H();
	skin -> Images.Insert(img);

	skin -> Insert_Face4(Skin2DFaceCorner(0.0f, 1.0f, 0.0f), Skin2DFaceCorner(0.0f, 0.0f, 0.0f), Skin2DFaceCorner(1.0f, 1.0f, 0.0f), Skin2DFaceCorner(1.0f, 0.0f, 0.0f));

	skin -> Done();


	polyhedra -> Skin = skin;
	polyhedra -> Done();
	return polyhedra;
}



PolyHedra * PolyHedra::Generate::TetraHedron(float scale)
{
	PolyHedra * polyhedra = new PolyHedra();

	polyhedra -> Insert_Corn(VectorF3(-scale, -scale, -scale));
	polyhedra -> Insert_Corn(VectorF3(+scale, +scale, -scale));
	polyhedra -> Insert_Corn(VectorF3(+scale, -scale, +scale));
	polyhedra -> Insert_Corn(VectorF3(-scale, +scale, +scale));

	polyhedra -> Insert_Face3(0b00, 0b01, 0b10);
	polyhedra -> Insert_Face3(0b00, 0b10, 0b11);
	polyhedra -> Insert_Face3(0b00, 0b11, 0b01);
	polyhedra -> Insert_Face3(0b11, 0b10, 0b01);



	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	skin -> Insert_Face3(Skin2DFaceCorner(0.00f, 0.00f, 0.0f), Skin2DFaceCorner(0.00f, 0.50f, 0.0f), Skin2DFaceCorner(0.25f, 0.00f, 0.0f));
	skin -> Insert_Face3(Skin2DFaceCorner(0.25f, 0.00f, 0.0f), Skin2DFaceCorner(0.00f, 0.50f, 0.0f), Skin2DFaceCorner(0.50f, 0.00f, 0.0f));
	skin -> Insert_Face3(Skin2DFaceCorner(0.50f, 0.00f, 0.0f), Skin2DFaceCorner(0.00f, 0.50f, 0.0f), Skin2DFaceCorner(0.75f, 0.00f, 0.0f));
	skin -> Insert_Face3(Skin2DFaceCorner(0.75f, 0.00f, 0.0f), Skin2DFaceCorner(0.00f, 0.50f, 0.0f), Skin2DFaceCorner(1.00f, 0.00f, 0.0f));

	skin -> Done();


	polyhedra -> Skin = skin;
	polyhedra -> Done();
	return polyhedra;
}



PolyHedra * PolyHedra::Generate::HexaHedron(float scale)
{
	PolyHedra * polyhedra = new PolyHedra();

	polyhedra -> Insert_Corn(VectorF3(-scale, -scale, -scale));
	polyhedra -> Insert_Corn(VectorF3(+scale, -scale, -scale));
	polyhedra -> Insert_Corn(VectorF3(-scale, +scale, -scale));
	polyhedra -> Insert_Corn(VectorF3(+scale, +scale, -scale));
	polyhedra -> Insert_Corn(VectorF3(-scale, -scale, +scale));
	polyhedra -> Insert_Corn(VectorF3(+scale, -scale, +scale));
	polyhedra -> Insert_Corn(VectorF3(-scale, +scale, +scale));
	polyhedra -> Insert_Corn(VectorF3(+scale, +scale, +scale));

	polyhedra -> Insert_Face4(0b000, 0b010, 0b001, 0b011);
	polyhedra -> Insert_Face4(0b000, 0b100, 0b010, 0b110);
	polyhedra -> Insert_Face4(0b000, 0b001, 0b100, 0b101);

	polyhedra -> Insert_Face4(0b111, 0b110, 0b101, 0b100);
	polyhedra -> Insert_Face4(0b111, 0b101, 0b011, 0b001);
	polyhedra -> Insert_Face4(0b111, 0b011, 0b110, 0b010);




	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	skin -> Insert_Face4(Skin2DFaceCorner(0.00f, 0.00f, 0.0f), Skin2DFaceCorner(0.00f, 0.50f, 0.0f), Skin2DFaceCorner(0.25f, 0.00f, 0.0f), Skin2DFaceCorner(0.25f, 0.50f, 0.0f));
	skin -> Insert_Face4(Skin2DFaceCorner(0.25f, 0.00f, 0.0f), Skin2DFaceCorner(0.25f, 0.50f, 0.0f), Skin2DFaceCorner(0.50f, 0.00f, 0.0f), Skin2DFaceCorner(0.50f, 0.50f, 0.0f));
	skin -> Insert_Face4(Skin2DFaceCorner(0.50f, 0.00f, 0.0f), Skin2DFaceCorner(0.50f, 0.50f, 0.0f), Skin2DFaceCorner(0.75f, 0.00f, 0.0f), Skin2DFaceCorner(0.75f, 0.50f, 0.0f));

	skin -> Insert_Face4(Skin2DFaceCorner(0.25f, 1.00f, 0.0f), Skin2DFaceCorner(0.00f, 1.00f, 0.0f), Skin2DFaceCorner(0.25f, 0.50f, 0.0f), Skin2DFaceCorner(0.00f, 0.50f, 0.0f));
	skin -> Insert_Face4(Skin2DFaceCorner(0.50f, 1.00f, 0.0f), Skin2DFaceCorner(0.25f, 1.00f, 0.0f), Skin2DFaceCorner(0.50f, 0.50f, 0.0f), Skin2DFaceCorner(0.25f, 0.50f, 0.0f));
	skin -> Insert_Face4(Skin2DFaceCorner(0.75f, 1.00f, 0.0f), Skin2DFaceCorner(0.50f, 1.00f, 0.0f), Skin2DFaceCorner(0.75f, 0.50f, 0.0f), Skin2DFaceCorner(0.50f, 0.50f, 0.0f));

	skin -> Done();


	polyhedra -> Skin = skin;
	polyhedra -> Done();
	return polyhedra;
}



PolyHedra * PolyHedra::Generate::ConeC(int segments, float width, float height)
{
	PolyHedra * polyhedra = new PolyHedra();

	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	EulerAngle3D angle;

	int idx_frst = polyhedra -> Corners.Count();
	polyhedra -> Insert_Corn(VectorF3(0, 0, +height));
	for (int i = 0; i < segments; i++)
	{
		angle.Z0 = Angle::Section(segments) * i;
		polyhedra -> Insert_Corn(angle.reverse(VectorF3(0, +width, -height)));
	}
	int idx_last = polyhedra -> Corners.Count();
	polyhedra -> Insert_Corn(VectorF3(0, 0, -height));

	for (int i = 0; i < segments; i++)
	{
		float tex0 = (0.0f + i) / segments;
		float tex1 = (1.0f + i) / segments;
		float texM = (0.5f + i) / segments;

		int idx_curr = ((i + 0) % segments) + 1;
		int idx_next = ((i + 1) % segments) + 1;

		polyhedra -> Insert_Face4(
			idx_frst,
			idx_next,
			idx_curr,
			idx_last
		);

		skin -> Insert_Face4(
			Skin2DFaceCorner(texM, 0.0f, 0.0f),
			Skin2DFaceCorner(tex1, 1.0f, 0.0f),
			Skin2DFaceCorner(tex0, 1.0f, 0.0f),
			Skin2DFaceCorner(texM, 0.0f, 0.0f)
		);
	}

	skin -> Done();
	polyhedra -> Skin = skin;
	polyhedra -> Done();
	return polyhedra;
}



PolyHedra * PolyHedra::Generate::FramedImage(Image img, float img_scale)
{
	Debug::Log << "Polyhedra: Generate: FramedImage: (" << img.W() << "x" << img.H() << ") ..." << Debug::Done;
	PolyHedra * polyhedra = new PolyHedra();

	Skin2DA * skin = new Skin2DA();
	skin -> W = img.W();
	skin -> H = img.H();

	skin -> Images.Insert(img);
	skin -> Images.Insert(Texture::Generate::Wood16x16());
	/*{
		FileInfo file(R"(F:\Code\GitRepositorys\C++\CPP-GL-Examples\other\Engine\media\Images\Test.png)");
		skin -> Images.Insert(file.LoadImage());
	}*/

	VectorF3 FrameSizeInn(0, 0, 0.05f);
	VectorF3 FrameSizeOut(0.5f, 0.5f, 0.1f);

	VectorF3 tex01[4];
	tex01[0] = VectorF3(0.0f, 1.0f, 0.0f);
	tex01[1] = VectorF3(0.0f, 0.0f, 0.0f);
	tex01[2] = VectorF3(1.0f, 1.0f, 0.0f);
	tex01[3] = VectorF3(1.0f, 0.0f, 0.0f);

	VectorF2 scale(img.W() * img_scale * 0.01f * 0.5f, img.H() * img_scale * 0.01f * 0.5f);

	polyhedra -> Insert_Corn(VectorF3(-scale.X, -scale.Y, -FrameSizeInn.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X, -scale.Y, -FrameSizeInn.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X, +scale.Y, -FrameSizeInn.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X, +scale.Y, -FrameSizeInn.Z));
	polyhedra -> Insert_Face4(0, 3, 1, 2);
	skin -> Insert_Face4(tex01[0], tex01[1], tex01[2], tex01[3]);

	tex01[0] = VectorF3(1.0f, 0.0f, 1.0f);
	tex01[1] = VectorF3(0.0f, 0.0f, 1.0f);
	tex01[2] = VectorF3(1.0f, 1.0f, 1.0f);
	tex01[3] = VectorF3(0.0f, 1.0f, 1.0f);

	unsigned int off0 = 0;
	unsigned int off1 = 0;



	float Frame_Mid_X = scale.X / FrameSizeOut.X;

	VectorF3 texScaleMiddleInnX = VectorF3(Frame_Mid_X * 2, FrameSizeInn.Z / (FrameSizeOut.Z * 2), 1);
	Skin2DFaceCorner texMiddleInnX[4];
	texMiddleInnX[0] = Skin2DFaceCorner((tex01[0] * texScaleMiddleInnX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleInnX[1] = Skin2DFaceCorner((tex01[1] * texScaleMiddleInnX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleInnX[2] = Skin2DFaceCorner((tex01[2] * texScaleMiddleInnX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleInnX[3] = Skin2DFaceCorner((tex01[3] * texScaleMiddleInnX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));

	VectorF3 texScaleMiddleOutX = VectorF3(Frame_Mid_X * 2, 1.0f, 1);
	Skin2DFaceCorner texMiddleOutX[4];
	texMiddleOutX[0] = Skin2DFaceCorner((tex01[0] * texScaleMiddleOutX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleOutX[1] = Skin2DFaceCorner((tex01[1] * texScaleMiddleOutX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleOutX[2] = Skin2DFaceCorner((tex01[2] * texScaleMiddleOutX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleOutX[3] = Skin2DFaceCorner((tex01[3] * texScaleMiddleOutX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));

	VectorF3 texScaleCornerMinX = VectorF3(1.0f, 1.0f, 1);
	Skin2DFaceCorner texCornerMinX[4];
	texCornerMinX[0] = Skin2DFaceCorner((tex01[0] * texScaleCornerMinX) + VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMinX[1] = Skin2DFaceCorner((tex01[1] * texScaleCornerMinX) + VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMinX[2] = Skin2DFaceCorner((tex01[2] * texScaleCornerMinX) + VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMinX[3] = Skin2DFaceCorner((tex01[3] * texScaleCornerMinX) + VectorF3(Frame_Mid_X, 0.0f, 0.0f));

	VectorF3 texScaleCornerMaxX = VectorF3(1.0f, 1.0f, 1);
	Skin2DFaceCorner texCornerMaxX[4];
	texCornerMaxX[0] = Skin2DFaceCorner((tex01[0] * texScaleCornerMaxX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMaxX[1] = Skin2DFaceCorner((tex01[1] * texScaleCornerMaxX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMaxX[2] = Skin2DFaceCorner((tex01[2] * texScaleCornerMaxX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMaxX[3] = Skin2DFaceCorner((tex01[3] * texScaleCornerMaxX) - VectorF3(Frame_Mid_X, 0.0f, 0.0f));



	float Frame_Mid_Y = scale.Y / FrameSizeOut.Y;

	VectorF3 texScaleMiddleInnY = VectorF3(Frame_Mid_Y * 2, FrameSizeInn.Z / (FrameSizeOut.Z * 2), 1);
	Skin2DFaceCorner texMiddleInnY[4];
	texMiddleInnY[0] = Skin2DFaceCorner((tex01[0] * texScaleMiddleInnY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleInnY[1] = Skin2DFaceCorner((tex01[1] * texScaleMiddleInnY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleInnY[2] = Skin2DFaceCorner((tex01[2] * texScaleMiddleInnY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleInnY[3] = Skin2DFaceCorner((tex01[3] * texScaleMiddleInnY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));

	VectorF3 texScaleMiddleOutY = VectorF3(Frame_Mid_Y * 2, 1.0f, 1);
	Skin2DFaceCorner texMiddleOutY[4];
	texMiddleOutY[0] = Skin2DFaceCorner((tex01[0] * texScaleMiddleOutY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleOutY[1] = Skin2DFaceCorner((tex01[1] * texScaleMiddleOutY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleOutY[2] = Skin2DFaceCorner((tex01[2] * texScaleMiddleOutY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleOutY[3] = Skin2DFaceCorner((tex01[3] * texScaleMiddleOutY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));

	VectorF3 texScaleCornerMinY = VectorF3(1.0f, 1.0f, 1);
	Skin2DFaceCorner texCornerMinY[4];
	texCornerMinY[0] = Skin2DFaceCorner((tex01[0] * texScaleCornerMinY) + VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMinY[1] = Skin2DFaceCorner((tex01[1] * texScaleCornerMinY) + VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMinY[2] = Skin2DFaceCorner((tex01[2] * texScaleCornerMinY) + VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMinY[3] = Skin2DFaceCorner((tex01[3] * texScaleCornerMinY) + VectorF3(Frame_Mid_Y, 0.0f, 0.0f));

	VectorF3 texScaleCornerMaxY = VectorF3(1.0f, 1.0f, 1);
	Skin2DFaceCorner texCornerMaxY[4];
	texCornerMaxY[0] = Skin2DFaceCorner((tex01[0] * texScaleCornerMaxY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMaxY[1] = Skin2DFaceCorner((tex01[1] * texScaleCornerMaxY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMaxY[2] = Skin2DFaceCorner((tex01[2] * texScaleCornerMaxY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMaxY[3] = Skin2DFaceCorner((tex01[3] * texScaleCornerMaxY) - VectorF3(Frame_Mid_Y, 0.0f, 0.0f));



	off0 += 0;
	off1 += 4;
	polyhedra -> Insert_Corn(VectorF3(-scale.X, -scale.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X, -scale.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X, +scale.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X, +scale.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Face4(off0 + 0, off0 + 1, off1 + 0, off1 + 1);
	polyhedra -> Insert_Face4(off0 + 1, off0 + 2, off1 + 1, off1 + 2);
	polyhedra -> Insert_Face4(off0 + 2, off0 + 3, off1 + 2, off1 + 3);
	polyhedra -> Insert_Face4(off0 + 3, off0 + 0, off1 + 3, off1 + 0);
	skin -> Insert_Face4(texMiddleInnX[0], texMiddleInnX[1], texMiddleInnX[2], texMiddleInnX[3]);
	skin -> Insert_Face4(texMiddleInnY[0], texMiddleInnY[1], texMiddleInnY[2], texMiddleInnY[3]);
	skin -> Insert_Face4(texMiddleInnX[0], texMiddleInnX[1], texMiddleInnX[2], texMiddleInnX[3]);
	skin -> Insert_Face4(texMiddleInnY[0], texMiddleInnY[1], texMiddleInnY[2], texMiddleInnY[3]);

	off0 += 4;
	off1 += 4;
	polyhedra -> Insert_Corn(VectorF3(-scale.X - FrameSizeOut.X, -scale.Y - FrameSizeOut.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X,                  -scale.Y - FrameSizeOut.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X,                  -scale.Y - FrameSizeOut.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X + FrameSizeOut.X, -scale.Y - FrameSizeOut.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X + FrameSizeOut.X, -scale.Y,                  -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X + FrameSizeOut.X, +scale.Y,                  -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X + FrameSizeOut.X, +scale.Y + FrameSizeOut.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X,                  +scale.Y + FrameSizeOut.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X,                  +scale.Y + FrameSizeOut.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X - FrameSizeOut.X, +scale.Y + FrameSizeOut.Y, -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X - FrameSizeOut.X, +scale.Y,                  -FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X - FrameSizeOut.X, -scale.Y,                  -FrameSizeOut.Z));
	polyhedra -> Insert_Face3(off0 +  0, off1 +  1, off1 +  0);
	polyhedra -> Insert_Face4(off0 +  0, off0 +  1, off1 +  1, off1 + 2);
	polyhedra -> Insert_Face3(off1 +  2, off0 +  1, off1 +  3);
	polyhedra -> Insert_Face3(off0 +  1, off1 +  4, off1 +  3);
	polyhedra -> Insert_Face4(off0 +  1, off0 +  2, off1 +  4, off1 + 5);
	polyhedra -> Insert_Face3(off1 +  5, off0 +  2, off1 +  6);
	polyhedra -> Insert_Face3(off0 +  2, off1 +  7, off1 +  6);
	polyhedra -> Insert_Face4(off0 +  2, off0 +  3, off1 +  7, off1 + 8);
	polyhedra -> Insert_Face3(off1 +  8, off0 +  3, off1 +  9);
	polyhedra -> Insert_Face3(off0 +  3, off1 + 10, off1 +  9);
	polyhedra -> Insert_Face4(off0 +  3, off0 +  0, off1 + 10, off1 + 11);
	polyhedra -> Insert_Face3(off1 + 11, off0 +  0, off1 + 00);
	skin -> Insert_Face3(texCornerMinX[1], texCornerMinX[3], texCornerMinX[2]);
	skin -> Insert_Face4(texMiddleOutX[0], texMiddleOutX[1], texMiddleOutX[2], texMiddleOutX[3]);
	skin -> Insert_Face3(texCornerMaxX[2], texCornerMaxX[0], texCornerMaxX[3]);
	skin -> Insert_Face3(texCornerMinY[1], texCornerMinY[3], texCornerMinY[2]);
	skin -> Insert_Face4(texMiddleOutY[0], texMiddleOutY[1], texMiddleOutY[2], texMiddleOutY[3]);
	skin -> Insert_Face3(texCornerMaxY[2], texCornerMaxY[0], texCornerMaxY[3]);
	skin -> Insert_Face3(texCornerMinX[1], texCornerMinX[3], texCornerMinX[2]);
	skin -> Insert_Face4(texMiddleOutX[0], texMiddleOutX[1], texMiddleOutX[2], texMiddleOutX[3]);
	skin -> Insert_Face3(texCornerMaxX[2], texCornerMaxX[0], texCornerMaxX[3]);
	skin -> Insert_Face3(texCornerMinY[1], texCornerMinY[3], texCornerMinY[2]);
	skin -> Insert_Face4(texMiddleOutY[0], texMiddleOutY[1], texMiddleOutY[2], texMiddleOutY[3]);
	skin -> Insert_Face3(texCornerMaxY[2], texCornerMaxY[0], texCornerMaxY[3]);

	off0 += 4;
	off1 += 12;
	polyhedra -> Insert_Corn(VectorF3(-scale.X - FrameSizeOut.X, -scale.Y - FrameSizeOut.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X,                  -scale.Y - FrameSizeOut.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X,                  -scale.Y - FrameSizeOut.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X + FrameSizeOut.X, -scale.Y - FrameSizeOut.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X + FrameSizeOut.X, -scale.Y,                  +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X + FrameSizeOut.X, +scale.Y,                  +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X + FrameSizeOut.X, +scale.Y + FrameSizeOut.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X,                  +scale.Y + FrameSizeOut.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X,                  +scale.Y + FrameSizeOut.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X - FrameSizeOut.X, +scale.Y + FrameSizeOut.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X - FrameSizeOut.X, +scale.Y,                  +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X - FrameSizeOut.X, -scale.Y,                  +FrameSizeOut.Z));
	polyhedra -> Insert_Face4(off0 + 0x0, off0 + 0x1, off1 + 0x0, off1 + 0x1);
	polyhedra -> Insert_Face4(off0 + 0x1, off0 + 0x2, off1 + 0x1, off1 + 0x2);
	polyhedra -> Insert_Face4(off0 + 0x2, off0 + 0x3, off1 + 0x2, off1 + 0x3);
	polyhedra -> Insert_Face4(off0 + 0x3, off0 + 0x4, off1 + 0x3, off1 + 0x4);
	polyhedra -> Insert_Face4(off0 + 0x4, off0 + 0x5, off1 + 0x4, off1 + 0x5);
	polyhedra -> Insert_Face4(off0 + 0x5, off0 + 0x6, off1 + 0x5, off1 + 0x6);
	polyhedra -> Insert_Face4(off0 + 0x6, off0 + 0x7, off1 + 0x6, off1 + 0x7);
	polyhedra -> Insert_Face4(off0 + 0x7, off0 + 0x8, off1 + 0x7, off1 + 0x8);
	polyhedra -> Insert_Face4(off0 + 0x8, off0 + 0x9, off1 + 0x8, off1 + 0x9);
	polyhedra -> Insert_Face4(off0 + 0x9, off0 + 0xA, off1 + 0x9, off1 + 0xA);
	polyhedra -> Insert_Face4(off0 + 0xA, off0 + 0xB, off1 + 0xA, off1 + 0xB);
	polyhedra -> Insert_Face4(off0 + 0xB, off0 + 0x0, off1 + 0xB, off1 + 0x0);
	skin -> Insert_Face4(texCornerMinX[0], texCornerMinX[1], texCornerMinX[2], texCornerMinX[3]);
	skin -> Insert_Face4(texMiddleOutX[0], texMiddleOutX[1], texMiddleOutX[2], texMiddleOutX[3]);
	skin -> Insert_Face4(texCornerMaxX[0], texCornerMaxX[1], texCornerMaxX[2], texCornerMaxX[3]);
	skin -> Insert_Face4(texCornerMinY[0], texCornerMinY[1], texCornerMinY[2], texCornerMinY[3]);
	skin -> Insert_Face4(texMiddleOutY[0], texMiddleOutY[1], texMiddleOutY[2], texMiddleOutY[3]);
	skin -> Insert_Face4(texCornerMaxY[0], texCornerMaxY[1], texCornerMaxY[2], texCornerMaxY[3]);
	skin -> Insert_Face4(texCornerMinX[0], texCornerMinX[1], texCornerMinX[2], texCornerMinX[3]);
	skin -> Insert_Face4(texMiddleOutX[0], texMiddleOutX[1], texMiddleOutX[2], texMiddleOutX[3]);
	skin -> Insert_Face4(texCornerMaxX[0], texCornerMaxX[1], texCornerMaxX[2], texCornerMaxX[3]);
	skin -> Insert_Face4(texCornerMinY[0], texCornerMinY[1], texCornerMinY[2], texCornerMinY[3]);
	skin -> Insert_Face4(texMiddleOutY[0], texMiddleOutY[1], texMiddleOutY[2], texMiddleOutY[3]);
	skin -> Insert_Face4(texCornerMaxY[0], texCornerMaxY[1], texCornerMaxY[2], texCornerMaxY[3]);

	off0 += 12;
	off1 += 12;
	polyhedra -> Insert_Corn(VectorF3(-scale.X, -scale.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X, -scale.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X, +scale.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X, +scale.Y, +FrameSizeOut.Z));
	polyhedra -> Insert_Face3(off1 + 0, off0 + 0, off0 + 1);
	polyhedra -> Insert_Face4(off1 + 1, off1 + 0, off0 + 2, off0 + 1);
	polyhedra -> Insert_Face3(off0 + 3, off1 + 1, off0 + 2);
	polyhedra -> Insert_Face3(off1 + 1, off0 + 3, off0 + 4);
	polyhedra -> Insert_Face4(off1 + 2, off1 + 1, off0 + 5, off0 + 4);
	polyhedra -> Insert_Face3(off0 + 6, off1 + 2, off0 + 5);
	polyhedra -> Insert_Face3(off1 + 2, off0 + 6, off0 + 7);
	polyhedra -> Insert_Face4(off1 + 3, off1 + 2, off0 + 8, off0 + 7);
	polyhedra -> Insert_Face3(off0 + 9, off1 + 3, off0 + 8);
	polyhedra -> Insert_Face3(off1 + 3, off0 + 9, off0 + 10);
	polyhedra -> Insert_Face4(off1 + 0, off1 + 3, off0 + 11, off0 + 10);
	polyhedra -> Insert_Face3(off0 + 0, off1 + 0, off0 + 11);
	skin -> Insert_Face3(texCornerMinX[3], texCornerMinX[0], texCornerMinX[1]);
	skin -> Insert_Face4(texMiddleOutX[3], texMiddleOutX[2], texMiddleOutX[1], texMiddleOutX[0]);
	skin -> Insert_Face3(texCornerMaxX[1], texCornerMaxX[2], texCornerMaxX[0]);
	skin -> Insert_Face3(texCornerMinY[3], texCornerMinY[0], texCornerMinY[1]);
	skin -> Insert_Face4(texMiddleOutY[3], texMiddleOutY[2], texMiddleOutY[1], texMiddleOutY[0]);
	skin -> Insert_Face3(texCornerMaxY[1], texCornerMaxY[2], texCornerMaxY[0]);
	skin -> Insert_Face3(texCornerMinX[3], texCornerMinX[0], texCornerMinX[1]);
	skin -> Insert_Face4(texMiddleOutX[3], texMiddleOutX[2], texMiddleOutX[1], texMiddleOutX[0]);
	skin -> Insert_Face3(texCornerMaxX[1], texCornerMaxX[2], texCornerMaxX[0]);
	skin -> Insert_Face3(texCornerMinY[3], texCornerMinY[0], texCornerMinY[1]);
	skin -> Insert_Face4(texMiddleOutY[3], texMiddleOutY[2], texMiddleOutY[1], texMiddleOutY[0]);
	skin -> Insert_Face3(texCornerMaxY[1], texCornerMaxY[2], texCornerMaxY[0]);

	off0 += 12;
	off1 += 4;
	polyhedra -> Insert_Corn(VectorF3(-scale.X, -scale.Y, +FrameSizeInn.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X, -scale.Y, +FrameSizeInn.Z));
	polyhedra -> Insert_Corn(VectorF3(+scale.X, +scale.Y, +FrameSizeInn.Z));
	polyhedra -> Insert_Corn(VectorF3(-scale.X, +scale.Y, +FrameSizeInn.Z));
	polyhedra -> Insert_Face4(off0 + 0, off0 + 1, off1 + 0, off1 + 1);
	polyhedra -> Insert_Face4(off0 + 1, off0 + 2, off1 + 1, off1 + 2);
	polyhedra -> Insert_Face4(off0 + 2, off0 + 3, off1 + 2, off1 + 3);
	polyhedra -> Insert_Face4(off0 + 3, off0 + 0, off1 + 3, off1 + 0);
	skin -> Insert_Face4(texMiddleInnX[0], texMiddleInnX[1], texMiddleInnX[2], texMiddleInnX[3]);
	skin -> Insert_Face4(texMiddleInnY[0], texMiddleInnY[1], texMiddleInnY[2], texMiddleInnY[3]);
	skin -> Insert_Face4(texMiddleInnX[0], texMiddleInnX[1], texMiddleInnX[2], texMiddleInnX[3]);
	skin -> Insert_Face4(texMiddleInnY[0], texMiddleInnY[1], texMiddleInnY[2], texMiddleInnY[3]);

	skin -> Done();
	polyhedra -> Skin = skin;
	Debug::Log << "Polyhedra: Generate: FramedImage: (" << img.W() << "x" << img.H() << ") done" << Debug::Done;
	polyhedra -> Done();
	return polyhedra;
}
