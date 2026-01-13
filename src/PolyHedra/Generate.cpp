#include "PolyHedra/Generate.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Template.hpp"

#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Graphics/Texture/Generate.hpp"

#include "DataStruct/Angle3D.hpp"

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
PolyHedra * PolyHedra::Generate::FramedImage(Image img, float img_scale)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	Skin2DA * skin = new Skin2DA();
	skin -> W = img.W();
	skin -> H = img.H();

	skin -> Images.Insert(img);
	//skin -> Images.Insert(Image::Missing(16, 16));
	skin -> Images.Insert(Texture::Generate::Gradiant2D());
	//skin -> Images.Insert(Texture::Generate::Wood16x16());

	/*	Frame Textures should be fixed Scale
		have square Pixels
		possibly be Centered ?
		just use Vertex Position for Texture ?
	*/

	float FrameSize0 = 0.20f;
	float FrameSize1 = 0.10f;
	float FrameSize2 = 0.05f;

	Point3D tex01[4];
	tex01[0] = Point3D(0.0f, 1.0f, 0.0f);
	tex01[1] = Point3D(0.0f, 0.0f, 0.0f);
	tex01[2] = Point3D(1.0f, 1.0f, 0.0f);
	tex01[3] = Point3D(1.0f, 0.0f, 0.0f);

	Point2D scale(img.W() * img_scale * 0.01f, img.H() * img_scale * 0.01f);
	temp.Insert_Corn(Point3D(-scale.X, -scale.Y, -FrameSize2));
	temp.Insert_Corn(Point3D(+scale.X, -scale.Y, -FrameSize2));
	temp.Insert_Corn(Point3D(+scale.X, +scale.Y, -FrameSize2));
	temp.Insert_Corn(Point3D(-scale.X, +scale.Y, -FrameSize2));
	temp.Insert_Face4(FaceCorner(0), FaceCorner(3), FaceCorner(1), FaceCorner(2));
	skin -> Insert_Face4(tex01[0], tex01[1], tex01[2], tex01[3]);

	tex01[0] = Point3D(0.0f, 1.0f, 1.0f);
	tex01[1] = Point3D(0.0f, 0.0f, 1.0f);
	tex01[2] = Point3D(1.0f, 1.0f, 1.0f);
	tex01[3] = Point3D(1.0f, 0.0f, 1.0f);

	Point3D texPixelRatio = Point3D(16, 16, 1);

	unsigned int off0 = 0;
	unsigned int off1 = 0;
	Skin2DFaceCorner tex[4];
	Skin2DFaceCorner texMid[4];
	Skin2DFaceCorner texCrn[4];
	Point3D texPixelSize;
	Point3D texPixelSizeMid;
	Point3D texPixelSizeCrn;

	off0 += 0;
	off1 += 4;
	texPixelSize = Point3D(5, 128 * img_scale, 1);
	temp.Insert_Corn(Point3D(-scale.X, -scale.Y, -FrameSize1));
	temp.Insert_Corn(Point3D(+scale.X, -scale.Y, -FrameSize1));
	temp.Insert_Corn(Point3D(+scale.X, +scale.Y, -FrameSize1));
	temp.Insert_Corn(Point3D(-scale.X, +scale.Y, -FrameSize1));
	temp.Insert_Face4(FaceCorner(off0 + 0), FaceCorner(off0 + 1), FaceCorner(off1 + 0), FaceCorner(off1 + 1));
	temp.Insert_Face4(FaceCorner(off0 + 1), FaceCorner(off0 + 2), FaceCorner(off1 + 1), FaceCorner(off1 + 2));
	temp.Insert_Face4(FaceCorner(off0 + 2), FaceCorner(off0 + 3), FaceCorner(off1 + 2), FaceCorner(off1 + 3));
	temp.Insert_Face4(FaceCorner(off0 + 3), FaceCorner(off0 + 0), FaceCorner(off1 + 3), FaceCorner(off1 + 0));
	tex[0] = Skin2DFaceCorner((tex01[0] * texPixelSize) / texPixelRatio);
	tex[1] = Skin2DFaceCorner((tex01[1] * texPixelSize) / texPixelRatio);
	tex[2] = Skin2DFaceCorner((tex01[2] * texPixelSize) / texPixelRatio);
	tex[3] = Skin2DFaceCorner((tex01[3] * texPixelSize) / texPixelRatio);
	skin -> Insert_Face4(tex[0], tex[1], tex[2], tex[3]);
	skin -> Insert_Face4(tex[0], tex[1], tex[2], tex[3]);
	skin -> Insert_Face4(tex[0], tex[1], tex[2], tex[3]);
	skin -> Insert_Face4(tex[0], tex[1], tex[2], tex[3]);

	off0 += 4;
	off1 += 4;
	texPixelSizeMid = Point3D(16, 128, 1);
	texPixelSizeCrn = Point3D(16, 16, 1);
	texMid[0] = Skin2DFaceCorner((tex01[0] * texPixelSizeMid) / texPixelRatio);
	texMid[1] = Skin2DFaceCorner((tex01[1] * texPixelSizeMid) / texPixelRatio);
	texMid[2] = Skin2DFaceCorner((tex01[2] * texPixelSizeMid) / texPixelRatio);
	texMid[3] = Skin2DFaceCorner((tex01[3] * texPixelSizeMid) / texPixelRatio);
	texCrn[0] = Skin2DFaceCorner((tex01[0] * texPixelSizeCrn) / texPixelRatio);
	texCrn[1] = Skin2DFaceCorner((tex01[1] * texPixelSizeCrn) / texPixelRatio);
	texCrn[2] = Skin2DFaceCorner((tex01[2] * texPixelSizeCrn) / texPixelRatio);
	texCrn[3] = Skin2DFaceCorner((tex01[3] * texPixelSizeCrn) / texPixelRatio);
	temp.Insert_Corn(Point3D(-scale.X - FrameSize0, -scale.Y - FrameSize0, -FrameSize1));
	temp.Insert_Corn(Point3D(-scale.X,              -scale.Y - FrameSize0, -FrameSize1));
	temp.Insert_Corn(Point3D(+scale.X,              -scale.Y - FrameSize0, -FrameSize1));
	temp.Insert_Corn(Point3D(+scale.X + FrameSize0, -scale.Y - FrameSize0, -FrameSize1));
	temp.Insert_Corn(Point3D(+scale.X + FrameSize0, -scale.Y,              -FrameSize1));
	temp.Insert_Corn(Point3D(+scale.X + FrameSize0, +scale.Y,              -FrameSize1));
	temp.Insert_Corn(Point3D(+scale.X + FrameSize0, +scale.Y + FrameSize0, -FrameSize1));
	temp.Insert_Corn(Point3D(+scale.X,              +scale.Y + FrameSize0, -FrameSize1));
	temp.Insert_Corn(Point3D(-scale.X,              +scale.Y + FrameSize0, -FrameSize1));
	temp.Insert_Corn(Point3D(-scale.X - FrameSize0, +scale.Y + FrameSize0, -FrameSize1));
	temp.Insert_Corn(Point3D(-scale.X - FrameSize0, +scale.Y,              -FrameSize1));
	temp.Insert_Corn(Point3D(-scale.X - FrameSize0, -scale.Y,              -FrameSize1));
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
	skin -> Insert_Face3(texCrn[1], texCrn[3], texCrn[2]);
	skin -> Insert_Face4(texMid[0], texMid[1], texMid[2], texMid[3]);
	skin -> Insert_Face3(texCrn[2], texCrn[0], texCrn[3]);
	skin -> Insert_Face3(texCrn[1], texCrn[3], texCrn[2]);
	skin -> Insert_Face4(texMid[0], texMid[1], texMid[2], texMid[3]);
	skin -> Insert_Face3(texCrn[2], texCrn[0], texCrn[3]);
	skin -> Insert_Face3(texCrn[1], texCrn[3], texCrn[2]);
	skin -> Insert_Face4(texMid[0], texMid[1], texMid[2], texMid[3]);
	skin -> Insert_Face3(texCrn[2], texCrn[0], texCrn[3]);
	skin -> Insert_Face3(texCrn[1], texCrn[3], texCrn[2]);
	skin -> Insert_Face4(texMid[0], texMid[1], texMid[2], texMid[3]);
	skin -> Insert_Face3(texCrn[2], texCrn[0], texCrn[3]);

	//off0 += 4;
	//off1 += 12;
	//temp.Insert_Corn(Point3D(-scale.X - FrameSize0, -scale.Y - FrameSize0, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(-scale.X, -scale.Y - FrameSize0, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(+scale.X, -scale.Y - FrameSize0, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(+scale.X + FrameSize0, -scale.Y - FrameSize0, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(+scale.X + FrameSize0, -scale.Y, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(+scale.X + FrameSize0, +scale.Y, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(+scale.X + FrameSize0, +scale.Y + FrameSize0, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(+scale.X, +scale.Y + FrameSize0, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(-scale.X, +scale.Y + FrameSize0, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(-scale.X - FrameSize0, +scale.Y + FrameSize0, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(-scale.X - FrameSize0, +scale.Y, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(-scale.X - FrameSize0, -scale.Y, +FrameThicknessDepth));
	//temp.Insert_Face4(FaceCorner(off0 + 0x0), FaceCorner(off0 + 0x1), FaceCorner(off1 + 0x0), FaceCorner(off1 + 0x1));
	//temp.Insert_Face4(FaceCorner(off0 + 0x1), FaceCorner(off0 + 0x2), FaceCorner(off1 + 0x1), FaceCorner(off1 + 0x2));
	//temp.Insert_Face4(FaceCorner(off0 + 0x2), FaceCorner(off0 + 0x3), FaceCorner(off1 + 0x2), FaceCorner(off1 + 0x3));
	//temp.Insert_Face4(FaceCorner(off0 + 0x3), FaceCorner(off0 + 0x4), FaceCorner(off1 + 0x3), FaceCorner(off1 + 0x4));
	//temp.Insert_Face4(FaceCorner(off0 + 0x4), FaceCorner(off0 + 0x5), FaceCorner(off1 + 0x4), FaceCorner(off1 + 0x5));
	//temp.Insert_Face4(FaceCorner(off0 + 0x5), FaceCorner(off0 + 0x6), FaceCorner(off1 + 0x5), FaceCorner(off1 + 0x6));
	//temp.Insert_Face4(FaceCorner(off0 + 0x6), FaceCorner(off0 + 0x7), FaceCorner(off1 + 0x6), FaceCorner(off1 + 0x7));
	//temp.Insert_Face4(FaceCorner(off0 + 0x7), FaceCorner(off0 + 0x8), FaceCorner(off1 + 0x7), FaceCorner(off1 + 0x8));
	//temp.Insert_Face4(FaceCorner(off0 + 0x8), FaceCorner(off0 + 0x9), FaceCorner(off1 + 0x8), FaceCorner(off1 + 0x9));
	//temp.Insert_Face4(FaceCorner(off0 + 0x9), FaceCorner(off0 + 0xA), FaceCorner(off1 + 0x9), FaceCorner(off1 + 0xA));
	//temp.Insert_Face4(FaceCorner(off0 + 0xA), FaceCorner(off0 + 0xB), FaceCorner(off1 + 0xA), FaceCorner(off1 + 0xB));
	//temp.Insert_Face4(FaceCorner(off0 + 0xB), FaceCorner(off0 + 0x0), FaceCorner(off1 + 0xB), FaceCorner(off1 + 0x0));
	//skin -> Insert_Face4(texCrn[0], texCrn[1], texCrn[2], texCrn[3]);
	//skin -> Insert_Face4(texMid[0], texMid[1], texMid[2], texMid[3]);
	//skin -> Insert_Face4(texCrn[0], texCrn[1], texCrn[2], texCrn[3]);
	//skin -> Insert_Face4(texCrn[0], texCrn[1], texCrn[2], texCrn[3]);
	//skin -> Insert_Face4(texMid[0], texMid[1], texMid[2], texMid[3]);
	//skin -> Insert_Face4(texCrn[0], texCrn[1], texCrn[2], texCrn[3]);
	//skin -> Insert_Face4(texCrn[0], texCrn[1], texCrn[2], texCrn[3]);
	//skin -> Insert_Face4(texMid[0], texMid[1], texMid[2], texMid[3]);
	//skin -> Insert_Face4(texCrn[0], texCrn[1], texCrn[2], texCrn[3]);
	//skin -> Insert_Face4(texCrn[0], texCrn[1], texCrn[2], texCrn[3]);
	//skin -> Insert_Face4(texMid[0], texMid[1], texMid[2], texMid[3]);
	//skin -> Insert_Face4(texCrn[0], texCrn[1], texCrn[2], texCrn[3]);

	//off0 += 12;
	//off1 += 12;
	//temp.Insert_Corn(Point3D(-scale.X, -scale.Y, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(+scale.X, -scale.Y, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(+scale.X, +scale.Y, +FrameThicknessDepth));
	//temp.Insert_Corn(Point3D(-scale.X, +scale.Y, +FrameThicknessDepth));
	//temp.Insert_Face3(FaceCorner(off1 + 0), FaceCorner(off0 + 0), FaceCorner(off0 + 1));
	//temp.Insert_Face4(FaceCorner(off1 + 1), FaceCorner(off1 + 0), FaceCorner(off0 + 2), FaceCorner(off0 + 1));
	//temp.Insert_Face3(FaceCorner(off0 + 3), FaceCorner(off1 + 1), FaceCorner(off0 + 2));
	//temp.Insert_Face3(FaceCorner(off1 + 1), FaceCorner(off0 + 3), FaceCorner(off0 + 4));
	//temp.Insert_Face4(FaceCorner(off1 + 2), FaceCorner(off1 + 1), FaceCorner(off0 + 5), FaceCorner(off0 + 4));
	//temp.Insert_Face3(FaceCorner(off0 + 6), FaceCorner(off1 + 2), FaceCorner(off0 + 5));
	//temp.Insert_Face3(FaceCorner(off1 + 2), FaceCorner(off0 + 6), FaceCorner(off0 + 7));
	//temp.Insert_Face4(FaceCorner(off1 + 3), FaceCorner(off1 + 2), FaceCorner(off0 + 8), FaceCorner(off0 + 7));
	//temp.Insert_Face3(FaceCorner(off0 + 9), FaceCorner(off1 + 3), FaceCorner(off0 + 8));
	//temp.Insert_Face3(FaceCorner(off1 + 3), FaceCorner(off0 + 9), FaceCorner(off0 + 10));
	//temp.Insert_Face4(FaceCorner(off1 + 0), FaceCorner(off1 + 3), FaceCorner(off0 + 11), FaceCorner(off0 + 10));
	//temp.Insert_Face3(FaceCorner(off0 + 0), FaceCorner(off1 + 0), FaceCorner(off0 + 11));
	//skin -> Insert_Face3(texCrn[3], texCrn[0], texCrn[1]);
	//skin -> Insert_Face4(texMid[3], texMid[2], texMid[1], texMid[0]);
	//skin -> Insert_Face3(texCrn[1], texCrn[2], texCrn[0]);
	//skin -> Insert_Face3(texCrn[3], texCrn[0], texCrn[1]);
	//skin -> Insert_Face4(texMid[3], texMid[2], texMid[1], texMid[0]);
	//skin -> Insert_Face3(texCrn[1], texCrn[2], texCrn[0]);
	//skin -> Insert_Face3(texCrn[3], texCrn[0], texCrn[1]);
	//skin -> Insert_Face4(texMid[3], texMid[2], texMid[1], texMid[0]);
	//skin -> Insert_Face3(texCrn[1], texCrn[2], texCrn[0]);
	//skin -> Insert_Face3(texCrn[3], texCrn[0], texCrn[1]);
	//skin -> Insert_Face4(texMid[3], texMid[2], texMid[1], texMid[0]);
	//skin -> Insert_Face3(texCrn[1], texCrn[2], texCrn[0]);

	temp.Done();
	skin -> Done();
	ph -> Skin = skin;
	return ph;
}
