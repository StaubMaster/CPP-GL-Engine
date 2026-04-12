#ifndef  BOX_HPP
# define BOX_HPP

template<typename VectorType> struct Box__
{
VectorType Min;
VectorType Max;



~Box__() { }

//Box__() {  }
Box__(VectorType min, VectorType max)
	: Min(min)
	, Max(max)
{ }

Box__(const Box__ & other)
	: Min(other.Min)
	, Max(other.Max)
{ }
Box__ & operator=(const Box__ & other)
{
	Min = other.Min;
	Max = other.Max;
	return *this;
}



VectorType Size() const
{
	return (Max - Min);
}
VectorType Center() const
{
	return ((Max + Min) / 2);
}
};

#endif