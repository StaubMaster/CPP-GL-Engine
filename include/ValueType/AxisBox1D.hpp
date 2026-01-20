#ifndef  AXISBOX_1D_HPP
# define AXISBOX_1D_HPP

struct AxisBox1D
{
	public:
	float	Min;
	float	Max;

	public:
	AxisBox1D();
	AxisBox1D(float min, float max);

	AxisBox1D(const AxisBox1D & other);
	AxisBox1D & operator=(const AxisBox1D & other);

	public:
	void Consider(float val);

	public:
	float Size() const;
	float Center() const;

	public:
	bool Intersekt(float val) const;
};

#endif
