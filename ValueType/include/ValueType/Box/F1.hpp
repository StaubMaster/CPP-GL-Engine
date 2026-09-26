#ifndef  BOX_F_1_HPP
# define BOX_F_1_HPP




struct BoxF1
{
	float	Min = 0.0f;
	float	Max = 0.0f;

	float	Size() const;
	float	Center() const;

	~BoxF1() = default;
	BoxF1() = default;
	BoxF1(const BoxF1 & other) = default;
	BoxF1 & operator=(const BoxF1 & other) = default;

	BoxF1(const float & min, const float & max);

	static BoxF1	InverseLimit();

	void	Consider(const float & vec);
	void	Consider(const BoxF1 & box);

	bool	IsNormal() const;
	BoxF1	Normalize() const;

	bool	ContainsEdge(const float & vec) const;
	bool	ContainsInclusive(const float & vec) const;
	bool	ContainsExclusive(const float & vec) const;
	bool	IntersectsInclusive(const BoxF1 & box) const;
	bool	IntersectsExclusive(const BoxF1 & box) const;
	BoxF1	OuterBox(const BoxF1 & other) const;
	BoxF1	InnerBox(const BoxF1 & other) const;
};

#endif