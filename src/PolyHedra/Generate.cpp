#include "PolyHedra/Generate.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Template.hpp"

#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Graphics/Texture/Generate.hpp"

#include "ValueType/Angle3D.hpp"

#include "Image.hpp"



PolyHedra * PolyHedra::Generate::DuoHedra(Image img, float scale)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	temp.Insert_Corn(Point3D(-scale, -scale, 0));
	temp.Insert_Corn(Point3D(-scale, +scale, 0));
	temp.Insert_Corn(Point3D(+scale, -scale, 0));
	temp.Insert_Corn(Point3D(+scale, +scale, 0));

	temp.Insert_Face4(FaceCorner(0), FaceCorner(1), FaceCorner(2), FaceCorner(3));

	temp.Done();


	Skin2DA * skin = new Skin2DA();
	skin -> W = img.W();
	skin -> H = img.H();
	skin -> Images.Insert(img);

	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.0f, 1.0f)), Skin2DFaceCorner(Point2D(0.0f, 0.0f)), Skin2DFaceCorner(Point2D(1.0f, 1.0f)), Skin2DFaceCorner(Point2D(1.0f, 0.0f)));

	skin -> Done();


	ph -> Skin = skin;
	return ph;
}



PolyHedra * PolyHedra::Generate::TetraHedron(float scale)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	temp.Insert_Corn(Point3D(-scale, -scale, -scale));
	temp.Insert_Corn(Point3D(+scale, +scale, -scale));
	temp.Insert_Corn(Point3D(+scale, -scale, +scale));
	temp.Insert_Corn(Point3D(-scale, +scale, +scale));

	temp.Insert_Face3(FaceCorner(0b00), FaceCorner(0b01), FaceCorner(0b10));
	temp.Insert_Face3(FaceCorner(0b00), FaceCorner(0b10), FaceCorner(0b11));
	temp.Insert_Face3(FaceCorner(0b00), FaceCorner(0b11), FaceCorner(0b01));
	temp.Insert_Face3(FaceCorner(0b11), FaceCorner(0b10), FaceCorner(0b01));

	temp.Done();


	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	skin -> Insert_Face3(Skin2DFaceCorner(Point2D(0.00f, 0.00f)), Skin2DFaceCorner(Point2D(0.00f, 0.50f)), Skin2DFaceCorner(Point2D(0.25f, 0.00f)));
	skin -> Insert_Face3(Skin2DFaceCorner(Point2D(0.25f, 0.00f)), Skin2DFaceCorner(Point2D(0.00f, 0.50f)), Skin2DFaceCorner(Point2D(0.50f, 0.00f)));
	skin -> Insert_Face3(Skin2DFaceCorner(Point2D(0.50f, 0.00f)), Skin2DFaceCorner(Point2D(0.00f, 0.50f)), Skin2DFaceCorner(Point2D(0.75f, 0.00f)));
	skin -> Insert_Face3(Skin2DFaceCorner(Point2D(0.75f, 0.00f)), Skin2DFaceCorner(Point2D(0.00f, 0.50f)), Skin2DFaceCorner(Point2D(1.00f, 0.00f)));

	skin -> Done();


	ph -> Skin = skin;
	return ph;
}



PolyHedra * PolyHedra::Generate::HexaHedron(float scale)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	temp.Insert_Corn(Point3D(-scale, -scale, -scale));
	temp.Insert_Corn(Point3D(+scale, -scale, -scale));
	temp.Insert_Corn(Point3D(-scale, +scale, -scale));
	temp.Insert_Corn(Point3D(+scale, +scale, -scale));
	temp.Insert_Corn(Point3D(-scale, -scale, +scale));
	temp.Insert_Corn(Point3D(+scale, -scale, +scale));
	temp.Insert_Corn(Point3D(-scale, +scale, +scale));
	temp.Insert_Corn(Point3D(+scale, +scale, +scale));

	temp.Insert_Face4(FaceCorner(0b000), FaceCorner(0b010), FaceCorner(0b001), FaceCorner(0b011));
	temp.Insert_Face4(FaceCorner(0b000), FaceCorner(0b100), FaceCorner(0b010), FaceCorner(0b110));
	temp.Insert_Face4(FaceCorner(0b000), FaceCorner(0b001), FaceCorner(0b100), FaceCorner(0b101));

	temp.Insert_Face4(FaceCorner(0b111), FaceCorner(0b110), FaceCorner(0b101), FaceCorner(0b100));
	temp.Insert_Face4(FaceCorner(0b111), FaceCorner(0b101), FaceCorner(0b011), FaceCorner(0b001));
	temp.Insert_Face4(FaceCorner(0b111), FaceCorner(0b011), FaceCorner(0b110), FaceCorner(0b010));

	temp.Done();


	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.00f, 0.00f)), Skin2DFaceCorner(Point2D(0.00f, 0.50f)), Skin2DFaceCorner(Point2D(0.25f, 0.00f)), Skin2DFaceCorner(Point2D(0.25f, 0.50f)));
	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.25f, 0.00f)), Skin2DFaceCorner(Point2D(0.25f, 0.50f)), Skin2DFaceCorner(Point2D(0.50f, 0.00f)), Skin2DFaceCorner(Point2D(0.50f, 0.50f)));
	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.50f, 0.00f)), Skin2DFaceCorner(Point2D(0.50f, 0.50f)), Skin2DFaceCorner(Point2D(0.75f, 0.00f)), Skin2DFaceCorner(Point2D(0.75f, 0.50f)));

	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.25f, 1.00f)), Skin2DFaceCorner(Point2D(0.00f, 1.00f)), Skin2DFaceCorner(Point2D(0.25f, 0.50f)), Skin2DFaceCorner(Point2D(0.00f, 0.50f)));
	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.50f, 1.00f)), Skin2DFaceCorner(Point2D(0.25f, 1.00f)), Skin2DFaceCorner(Point2D(0.50f, 0.50f)), Skin2DFaceCorner(Point2D(0.25f, 0.50f)));
	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.75f, 1.00f)), Skin2DFaceCorner(Point2D(0.50f, 1.00f)), Skin2DFaceCorner(Point2D(0.75f, 0.50f)), Skin2DFaceCorner(Point2D(0.50f, 0.50f)));

	skin -> Done();


	ph -> Skin = skin;
	return ph;
}



PolyHedra * PolyHedra::Generate::ConeC(int segments, float width, float height)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	Angle3D angle;

	int idx_frst = ph -> Corners.Count();
	temp.Insert_Corn(Point3D(0, 0, +height));
	for (int i = 0; i < segments; i++)
	{
		angle.Z = (TAU * i) / segments;
		angle.CalcFore();
		temp.Insert_Corn(angle.rotate(Point3D(0, +width, -height)));
	}
	int idx_last = ph -> Corners.Count();
	temp.Insert_Corn(Point3D(0, 0, -height));

	for (int i = 0; i < segments; i++)
	{
		float tex0 = (0.0f + i) / segments;
		float tex1 = (1.0f + i) / segments;
		float texM = (0.5f + i) / segments;

		int idx_curr = ((i + 0) % segments) + 1;
		int idx_next = ((i + 1) % segments) + 1;

		temp.Insert_Face4(
			FaceCorner(idx_frst),
			FaceCorner(idx_next),
			FaceCorner(idx_curr),
			FaceCorner(idx_last)
		);

		skin -> Insert_Face4(
			Skin2DFaceCorner(Point2D(texM, 0.0f)),
			Skin2DFaceCorner(Point2D(tex1, 1.0f)),
			Skin2DFaceCorner(Point2D(tex0, 1.0f)),
			Skin2DFaceCorner(Point2D(texM, 0.0f))
		);
	}

	temp.Done();
	skin -> Done();
	ph -> Skin = skin;

	return ph;
}



#include "FileInfo.hpp"
#include "DirectoryInfo.hpp"
#include <vector>
#include "ValueType/uint.hpp"
#include <iostream>
#include "DataShow.hpp"
PolyHedra * PolyHedra::Generate::FramedImage(Image img, float img_scale)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	Skin2DA * skin = new Skin2DA();
	skin -> W = img.W();
	skin -> H = img.H();

	skin -> Images.Insert(img);
	skin -> Images.Insert(Texture::Generate::Wood16x16());
	/*{
		FileInfo file(R"(F:\Code\GitRepositorys\C++\CPP-GL-Examples\other\Engine\media\Images\Test.png)");
		skin -> Images.Insert(file.LoadImage());
	}*/

	Point3D FrameSizeInn(0, 0, 0.05f);
	Point3D FrameSizeOut(0.5f, 0.5f, 0.1f);

	Point3D tex01[4];
	tex01[0] = Point3D(0.0f, 1.0f, 0.0f);
	tex01[1] = Point3D(0.0f, 0.0f, 0.0f);
	tex01[2] = Point3D(1.0f, 1.0f, 0.0f);
	tex01[3] = Point3D(1.0f, 0.0f, 0.0f);

	Point2D scale(img.W() * img_scale * 0.01f * 0.5f, img.H() * img_scale * 0.01f * 0.5f);
	std::cout << "scale: " << scale << '\n';

	temp.Insert_Corn(Point3D(-scale.X, -scale.Y, -FrameSizeInn.Z));
	temp.Insert_Corn(Point3D(+scale.X, -scale.Y, -FrameSizeInn.Z));
	temp.Insert_Corn(Point3D(+scale.X, +scale.Y, -FrameSizeInn.Z));
	temp.Insert_Corn(Point3D(-scale.X, +scale.Y, -FrameSizeInn.Z));
	temp.Insert_Face4(FaceCorner(0), FaceCorner(3), FaceCorner(1), FaceCorner(2));
	skin -> Insert_Face4(tex01[0], tex01[1], tex01[2], tex01[3]);

	tex01[0] = Point3D(1.0f, 0.0f, 1.0f);
	tex01[1] = Point3D(0.0f, 0.0f, 1.0f);
	tex01[2] = Point3D(1.0f, 1.0f, 1.0f);
	tex01[3] = Point3D(0.0f, 1.0f, 1.0f);

	unsigned int off0 = 0;
	unsigned int off1 = 0;



	float Frame_Mid_X = scale.X / FrameSizeOut.X;

	Point3D texScaleMiddleInnX = Point3D(Frame_Mid_X * 2, FrameSizeInn.Z / (FrameSizeOut.Z * 2), 1);
	Skin2DFaceCorner texMiddleInnX[4];
	texMiddleInnX[0] = Skin2DFaceCorner((tex01[0] * texScaleMiddleInnX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleInnX[1] = Skin2DFaceCorner((tex01[1] * texScaleMiddleInnX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleInnX[2] = Skin2DFaceCorner((tex01[2] * texScaleMiddleInnX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleInnX[3] = Skin2DFaceCorner((tex01[3] * texScaleMiddleInnX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));

	Point3D texScaleMiddleOutX = Point3D(Frame_Mid_X * 2, 1.0f, 1);
	Skin2DFaceCorner texMiddleOutX[4];
	texMiddleOutX[0] = Skin2DFaceCorner((tex01[0] * texScaleMiddleOutX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleOutX[1] = Skin2DFaceCorner((tex01[1] * texScaleMiddleOutX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleOutX[2] = Skin2DFaceCorner((tex01[2] * texScaleMiddleOutX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texMiddleOutX[3] = Skin2DFaceCorner((tex01[3] * texScaleMiddleOutX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));

	Point3D texScaleCornerMinX = Point3D(1.0f, 1.0f, 1);
	Skin2DFaceCorner texCornerMinX[4];
	texCornerMinX[0] = Skin2DFaceCorner((tex01[0] * texScaleCornerMinX) + Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMinX[1] = Skin2DFaceCorner((tex01[1] * texScaleCornerMinX) + Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMinX[2] = Skin2DFaceCorner((tex01[2] * texScaleCornerMinX) + Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMinX[3] = Skin2DFaceCorner((tex01[3] * texScaleCornerMinX) + Point3D(Frame_Mid_X, 0.0f, 0.0f));

	Point3D texScaleCornerMaxX = Point3D(1.0f, 1.0f, 1);
	Skin2DFaceCorner texCornerMaxX[4];
	texCornerMaxX[0] = Skin2DFaceCorner((tex01[0] * texScaleCornerMaxX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMaxX[1] = Skin2DFaceCorner((tex01[1] * texScaleCornerMaxX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMaxX[2] = Skin2DFaceCorner((tex01[2] * texScaleCornerMaxX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));
	texCornerMaxX[3] = Skin2DFaceCorner((tex01[3] * texScaleCornerMaxX) - Point3D(Frame_Mid_X, 0.0f, 0.0f));



	float Frame_Mid_Y = scale.Y / FrameSizeOut.Y;

	Point3D texScaleMiddleInnY = Point3D(Frame_Mid_Y * 2, FrameSizeInn.Z / (FrameSizeOut.Z * 2), 1);
	Skin2DFaceCorner texMiddleInnY[4];
	texMiddleInnY[0] = Skin2DFaceCorner((tex01[0] * texScaleMiddleInnY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleInnY[1] = Skin2DFaceCorner((tex01[1] * texScaleMiddleInnY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleInnY[2] = Skin2DFaceCorner((tex01[2] * texScaleMiddleInnY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleInnY[3] = Skin2DFaceCorner((tex01[3] * texScaleMiddleInnY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));

	Point3D texScaleMiddleOutY = Point3D(Frame_Mid_Y * 2, 1.0f, 1);
	Skin2DFaceCorner texMiddleOutY[4];
	texMiddleOutY[0] = Skin2DFaceCorner((tex01[0] * texScaleMiddleOutY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleOutY[1] = Skin2DFaceCorner((tex01[1] * texScaleMiddleOutY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleOutY[2] = Skin2DFaceCorner((tex01[2] * texScaleMiddleOutY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texMiddleOutY[3] = Skin2DFaceCorner((tex01[3] * texScaleMiddleOutY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));

	Point3D texScaleCornerMinY = Point3D(1.0f, 1.0f, 1);
	Skin2DFaceCorner texCornerMinY[4];
	texCornerMinY[0] = Skin2DFaceCorner((tex01[0] * texScaleCornerMinY) + Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMinY[1] = Skin2DFaceCorner((tex01[1] * texScaleCornerMinY) + Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMinY[2] = Skin2DFaceCorner((tex01[2] * texScaleCornerMinY) + Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMinY[3] = Skin2DFaceCorner((tex01[3] * texScaleCornerMinY) + Point3D(Frame_Mid_Y, 0.0f, 0.0f));

	Point3D texScaleCornerMaxY = Point3D(1.0f, 1.0f, 1);
	Skin2DFaceCorner texCornerMaxY[4];
	texCornerMaxY[0] = Skin2DFaceCorner((tex01[0] * texScaleCornerMaxY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMaxY[1] = Skin2DFaceCorner((tex01[1] * texScaleCornerMaxY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMaxY[2] = Skin2DFaceCorner((tex01[2] * texScaleCornerMaxY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));
	texCornerMaxY[3] = Skin2DFaceCorner((tex01[3] * texScaleCornerMaxY) - Point3D(Frame_Mid_Y, 0.0f, 0.0f));



	off0 += 0;
	off1 += 4;
	temp.Insert_Corn(Point3D(-scale.X, -scale.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X, -scale.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X, +scale.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X, +scale.Y, -FrameSizeOut.Z));
	temp.Insert_Face4(FaceCorner(off0 + 0), FaceCorner(off0 + 1), FaceCorner(off1 + 0), FaceCorner(off1 + 1));
	temp.Insert_Face4(FaceCorner(off0 + 1), FaceCorner(off0 + 2), FaceCorner(off1 + 1), FaceCorner(off1 + 2));
	temp.Insert_Face4(FaceCorner(off0 + 2), FaceCorner(off0 + 3), FaceCorner(off1 + 2), FaceCorner(off1 + 3));
	temp.Insert_Face4(FaceCorner(off0 + 3), FaceCorner(off0 + 0), FaceCorner(off1 + 3), FaceCorner(off1 + 0));
	skin -> Insert_Face4(texMiddleInnX[0], texMiddleInnX[1], texMiddleInnX[2], texMiddleInnX[3]);
	skin -> Insert_Face4(texMiddleInnY[0], texMiddleInnY[1], texMiddleInnY[2], texMiddleInnY[3]);
	skin -> Insert_Face4(texMiddleInnX[0], texMiddleInnX[1], texMiddleInnX[2], texMiddleInnX[3]);
	skin -> Insert_Face4(texMiddleInnY[0], texMiddleInnY[1], texMiddleInnY[2], texMiddleInnY[3]);

	off0 += 4;
	off1 += 4;
	temp.Insert_Corn(Point3D(-scale.X - FrameSizeOut.X, -scale.Y - FrameSizeOut.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X,                  -scale.Y - FrameSizeOut.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X,                  -scale.Y - FrameSizeOut.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X + FrameSizeOut.X, -scale.Y - FrameSizeOut.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X + FrameSizeOut.X, -scale.Y,                  -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X + FrameSizeOut.X, +scale.Y,                  -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X + FrameSizeOut.X, +scale.Y + FrameSizeOut.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X,                  +scale.Y + FrameSizeOut.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X,                  +scale.Y + FrameSizeOut.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X - FrameSizeOut.X, +scale.Y + FrameSizeOut.Y, -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X - FrameSizeOut.X, +scale.Y,                  -FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X - FrameSizeOut.X, -scale.Y,                  -FrameSizeOut.Z));
	temp.Insert_Face3(FaceCorner(off0 + 0), FaceCorner(off1 + 1), FaceCorner(off1 + 0));
	temp.Insert_Face4(FaceCorner(off0 + 0), FaceCorner(off0 + 1), FaceCorner(off1 + 1), FaceCorner(off1 + 2));
	temp.Insert_Face3(FaceCorner(off1 + 2), FaceCorner(off0 + 1), FaceCorner(off1 + 3));
	temp.Insert_Face3(FaceCorner(off0 + 1), FaceCorner(off1 + 4), FaceCorner(off1 + 3));
	temp.Insert_Face4(FaceCorner(off0 + 1), FaceCorner(off0 + 2), FaceCorner(off1 + 4), FaceCorner(off1 + 5));
	temp.Insert_Face3(FaceCorner(off1 + 5), FaceCorner(off0 + 2), FaceCorner(off1 + 6));
	temp.Insert_Face3(FaceCorner(off0 + 2), FaceCorner(off1 + 7), FaceCorner(off1 + 6));
	temp.Insert_Face4(FaceCorner(off0 + 2), FaceCorner(off0 +  3), FaceCorner(off1 + 7), FaceCorner(off1 + 8));
	temp.Insert_Face3(FaceCorner(off1 + 8), FaceCorner(off0 +  3), FaceCorner(off1 + 9));
	temp.Insert_Face3(FaceCorner(off0 + 3), FaceCorner(off1 + 10), FaceCorner(off1 + 9));
	temp.Insert_Face4(FaceCorner(off0 +  3), FaceCorner(off0 + 0), FaceCorner(off1 + 10), FaceCorner(off1 + 11));
	temp.Insert_Face3(FaceCorner(off1 + 11), FaceCorner(off0 + 0), FaceCorner(off1 + 00));
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
	temp.Insert_Corn(Point3D(-scale.X - FrameSizeOut.X, -scale.Y - FrameSizeOut.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X,                  -scale.Y - FrameSizeOut.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X,                  -scale.Y - FrameSizeOut.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X + FrameSizeOut.X, -scale.Y - FrameSizeOut.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X + FrameSizeOut.X, -scale.Y,                  +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X + FrameSizeOut.X, +scale.Y,                  +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X + FrameSizeOut.X, +scale.Y + FrameSizeOut.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X,                  +scale.Y + FrameSizeOut.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X,                  +scale.Y + FrameSizeOut.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X - FrameSizeOut.X, +scale.Y + FrameSizeOut.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X - FrameSizeOut.X, +scale.Y,                  +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X - FrameSizeOut.X, -scale.Y,                  +FrameSizeOut.Z));
	temp.Insert_Face4(FaceCorner(off0 + 0x0), FaceCorner(off0 + 0x1), FaceCorner(off1 + 0x0), FaceCorner(off1 + 0x1));
	temp.Insert_Face4(FaceCorner(off0 + 0x1), FaceCorner(off0 + 0x2), FaceCorner(off1 + 0x1), FaceCorner(off1 + 0x2));
	temp.Insert_Face4(FaceCorner(off0 + 0x2), FaceCorner(off0 + 0x3), FaceCorner(off1 + 0x2), FaceCorner(off1 + 0x3));
	temp.Insert_Face4(FaceCorner(off0 + 0x3), FaceCorner(off0 + 0x4), FaceCorner(off1 + 0x3), FaceCorner(off1 + 0x4));
	temp.Insert_Face4(FaceCorner(off0 + 0x4), FaceCorner(off0 + 0x5), FaceCorner(off1 + 0x4), FaceCorner(off1 + 0x5));
	temp.Insert_Face4(FaceCorner(off0 + 0x5), FaceCorner(off0 + 0x6), FaceCorner(off1 + 0x5), FaceCorner(off1 + 0x6));
	temp.Insert_Face4(FaceCorner(off0 + 0x6), FaceCorner(off0 + 0x7), FaceCorner(off1 + 0x6), FaceCorner(off1 + 0x7));
	temp.Insert_Face4(FaceCorner(off0 + 0x7), FaceCorner(off0 + 0x8), FaceCorner(off1 + 0x7), FaceCorner(off1 + 0x8));
	temp.Insert_Face4(FaceCorner(off0 + 0x8), FaceCorner(off0 + 0x9), FaceCorner(off1 + 0x8), FaceCorner(off1 + 0x9));
	temp.Insert_Face4(FaceCorner(off0 + 0x9), FaceCorner(off0 + 0xA), FaceCorner(off1 + 0x9), FaceCorner(off1 + 0xA));
	temp.Insert_Face4(FaceCorner(off0 + 0xA), FaceCorner(off0 + 0xB), FaceCorner(off1 + 0xA), FaceCorner(off1 + 0xB));
	temp.Insert_Face4(FaceCorner(off0 + 0xB), FaceCorner(off0 + 0x0), FaceCorner(off1 + 0xB), FaceCorner(off1 + 0x0));
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
	temp.Insert_Corn(Point3D(-scale.X, -scale.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X, -scale.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(+scale.X, +scale.Y, +FrameSizeOut.Z));
	temp.Insert_Corn(Point3D(-scale.X, +scale.Y, +FrameSizeOut.Z));
	temp.Insert_Face3(FaceCorner(off1 + 0), FaceCorner(off0 + 0), FaceCorner(off0 + 1));
	temp.Insert_Face4(FaceCorner(off1 + 1), FaceCorner(off1 + 0), FaceCorner(off0 + 2), FaceCorner(off0 + 1));
	temp.Insert_Face3(FaceCorner(off0 + 3), FaceCorner(off1 + 1), FaceCorner(off0 + 2));
	temp.Insert_Face3(FaceCorner(off1 + 1), FaceCorner(off0 + 3), FaceCorner(off0 + 4));
	temp.Insert_Face4(FaceCorner(off1 + 2), FaceCorner(off1 + 1), FaceCorner(off0 + 5), FaceCorner(off0 + 4));
	temp.Insert_Face3(FaceCorner(off0 + 6), FaceCorner(off1 + 2), FaceCorner(off0 + 5));
	temp.Insert_Face3(FaceCorner(off1 + 2), FaceCorner(off0 + 6), FaceCorner(off0 + 7));
	temp.Insert_Face4(FaceCorner(off1 + 3), FaceCorner(off1 + 2), FaceCorner(off0 + 8), FaceCorner(off0 + 7));
	temp.Insert_Face3(FaceCorner(off0 + 9), FaceCorner(off1 + 3), FaceCorner(off0 + 8));
	temp.Insert_Face3(FaceCorner(off1 + 3), FaceCorner(off0 + 9), FaceCorner(off0 + 10));
	temp.Insert_Face4(FaceCorner(off1 + 0), FaceCorner(off1 + 3), FaceCorner(off0 + 11), FaceCorner(off0 + 10));
	temp.Insert_Face3(FaceCorner(off0 + 0), FaceCorner(off1 + 0), FaceCorner(off0 + 11));
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
	temp.Insert_Corn(Point3D(-scale.X, -scale.Y, +FrameSizeInn.Z));
	temp.Insert_Corn(Point3D(+scale.X, -scale.Y, +FrameSizeInn.Z));
	temp.Insert_Corn(Point3D(+scale.X, +scale.Y, +FrameSizeInn.Z));
	temp.Insert_Corn(Point3D(-scale.X, +scale.Y, +FrameSizeInn.Z));
	temp.Insert_Face4(FaceCorner(off0 + 0), FaceCorner(off0 + 1), FaceCorner(off1 + 0), FaceCorner(off1 + 1));
	temp.Insert_Face4(FaceCorner(off0 + 1), FaceCorner(off0 + 2), FaceCorner(off1 + 1), FaceCorner(off1 + 2));
	temp.Insert_Face4(FaceCorner(off0 + 2), FaceCorner(off0 + 3), FaceCorner(off1 + 2), FaceCorner(off1 + 3));
	temp.Insert_Face4(FaceCorner(off0 + 3), FaceCorner(off0 + 0), FaceCorner(off1 + 3), FaceCorner(off1 + 0));
	skin -> Insert_Face4(texMiddleInnX[0], texMiddleInnX[1], texMiddleInnX[2], texMiddleInnX[3]);
	skin -> Insert_Face4(texMiddleInnY[0], texMiddleInnY[1], texMiddleInnY[2], texMiddleInnY[3]);
	skin -> Insert_Face4(texMiddleInnX[0], texMiddleInnX[1], texMiddleInnX[2], texMiddleInnX[3]);
	skin -> Insert_Face4(texMiddleInnY[0], texMiddleInnY[1], texMiddleInnY[2], texMiddleInnY[3]);

	temp.Done();
	skin -> Done();
	ph -> Skin = skin;
	return ph;
}
