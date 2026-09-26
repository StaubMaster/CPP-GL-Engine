#include "ValueType/DepthFactors.hpp"



void DepthFactors::Calculate()
{
	Diff = Far - Near;
	Summ = Far + Near;
	Mul2 = Far * Near * 2;

	Factor0 = Summ / Diff;
	Factor1 = Mul2 / Diff;
}



float DepthFactors::GetNear() const
{
	return Near;
}
float DepthFactors::GetFar() const
{
	return Far;
}

void DepthFactors::SetNear(float near)
{
	Near = near;
	Calculate();
}
void DepthFactors::SetFar(float far)
{
	Far = far;
	Calculate();
}



DepthFactors::DepthFactors(float near, float far)
{
	Near = near;
	Far = far;
	Calculate();
}
