#ifndef  DEPTH_FACTORS_HPP
# define DEPTH_FACTORS_HPP

struct DepthFactors
{
	private:
	float	Near;
	float	Far;

	float	Diff;
	float	Summ;
	float	Mul2;

	float	Factor0;
	float	Factor1;

	private:
	void	Calculate();

	public:
	float	GetNear() const;
	float	GetFar() const;

	public:
	void	SetNear(float val);
	void	SetFar(float val);

	public:
	~DepthFactors() = default;
	DepthFactors() = default;
	DepthFactors(const DepthFactors & other) = default;
	DepthFactors & operator=(const DepthFactors & other) = default;

	public:
	DepthFactors(float near, float far);
};

#endif