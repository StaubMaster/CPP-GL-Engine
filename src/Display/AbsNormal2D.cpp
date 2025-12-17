# include "Display/AbsNormal2D.hpp"
# include "Display/RelNormal2D.hpp"



AbsNormal2D::AbsNormal2D() { }
AbsNormal2D::AbsNormal2D(const Point2D & p) : Point2D(p) { }



RelNormal2D AbsNormal2D::ToRelative() const { return RelNormal2D(((*this) * 2) - 1); }
