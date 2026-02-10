#ifndef  SKIN_2DA_HPP
# define SKIN_2DA_HPP

# include "PolyHedra/Skin/SkinGenericBase.hpp"
# include "PolyHedra/Skin/Skin2D_Data.hpp"
# include "Graphics/Texture/Array2D.hpp"

//# include "Miscellaneous/Container/Dynamic.hpp"

# include "ValueType/Point2D.hpp"
# include "ValueType/Point3D.hpp"

class Skin2DA : public SkinGenericBase<Skin2DCorner, Skin2DFaceCorner, Skin2DFace>
{
	public:
	unsigned int W;
	unsigned int H;

	private:
	unsigned int TextureIndex;

	public:
	Skin2DA();
	~Skin2DA();

	private:
	Texture::Base * ToTexture() const override;
	public:
	void ToTexture(Texture::Array2D & tex) const;

	public:
	void Parse(const TextCommand & cmd) override;
	void Parse_W(const TextCommand & cmd);
	void Parse_H(const TextCommand & cmd);
	void Parse_File(const TextCommand & cmd);
	void Parse_t(const TextCommand & cmd);
	void Parse_TextureIndex(const TextCommand & cmd);
	void Parse_TextureIndexFace4(const TextCommand & cmd);
	void Parse_TextureIndexQuad(const TextCommand & cmd);
};

#endif
