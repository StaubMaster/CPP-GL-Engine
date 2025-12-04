#ifndef  SIZE_RATIO_2D_HPP
# define SIZE_RATIO_2D_HPP

# include "Point2D.hpp"

struct SizeRatio2D
{
	public:
		Point2D	Size;
		Point2D	Ratio;

	public:
		SizeRatio2D();
		SizeRatio2D(float w, float h);

	private:
		void Calc();
};

#endif