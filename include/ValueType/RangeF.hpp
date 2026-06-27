#ifndef  RANGE_F_HPP
# define RANGE_F_HPP

struct RangeF
{
	private:
	float	Min;
	float	Len;
	float	Max;

	public:
	~RangeF();
	RangeF();
	RangeF(float min, float max);

	RangeF(const RangeF & other) = default;
	RangeF & operator=(const RangeF & other) = default;

	public:
	float	GetMin() const;
	float	GetMax() const;
	
	void	SetMin(float min);
	void	SetMax(float max);

	public:
	float	Length() const;
	void	MinLength(float len);
	void	MaxLength(float len);
};

#endif