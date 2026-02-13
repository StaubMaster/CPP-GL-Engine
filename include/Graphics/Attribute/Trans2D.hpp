#ifndef  ATTRIB_TRANS_2D_HPP
# define ATTRIB_TRANS_2D_HPP

# include "Graphics/Attribute/Base/Location.hpp"
# include "Graphics/Attribute/Base/Base.hpp"

# include "Point2D.hpp"
# include "Angle2D.hpp"

namespace Attribute
{
class Trans2D : public Attribute::Base
{
	private:
	Attribute::Point2D Pos;
	Attribute::Angle2D Rot;

	public:
	Trans2D();
	Trans2D(
		unsigned int divisor,
		unsigned int stride,
		unsigned int indexPos,
		unsigned int indexRot
	);
	~Trans2D();

	Trans2D(const Trans2D & other);
	Trans2D & operator=(const Trans2D & other);

	public:
	void Bind(const unsigned char * & offset) const override;
};
};

#endif