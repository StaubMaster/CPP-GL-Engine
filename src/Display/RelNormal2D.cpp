# include "Display/RelNormal2D.hpp"
# include "Display/AbsNormal2D.hpp"



RelNormal2D::RelNormal2D() { }
RelNormal2D::RelNormal2D(const Point2D & p) : Point2D(p) { }



AbsNormal2D RelNormal2D::ToAbsolute() const { return AbsNormal2D(((*this) + 1) / 2); }
