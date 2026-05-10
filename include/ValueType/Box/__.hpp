#ifndef  BOX_HPP
# define BOX_HPP

// Convert between Types ?

/* what is a Box
	Min and Max Vectors of same Type and Size
	can check Intersections with Boxes of same Size
	can check Intersections with Vectors of same Size
	can be moves with
*/

// the point of these Templates is so I dont have to Copy and paste all the similar Code

template<typename VectorType, typename BoxType> struct Box__
{
VectorType Min;
VectorType Max;



~Box__() { }

//Box__() { }
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



bool IsNormal() const
{
	return (Min <= Max).All(true);
}
BoxType Normalize() const
{
	return BoxType(
		this -> Min.Min(this -> Max),
		this -> Max.Max(this -> Min)
	);
}

VectorType Size() const
{
	return (Max - Min);
}
VectorType Center() const
{
	return ((Max + Min) / 2.0f);
}



template<typename OtherBoxType>
BoxType OuterBox(const OtherBoxType & other) const
{
	return BoxType(this -> Min.Min(other.Min), this -> Max.Max(other.Max));
}

/*
a-------a
|       |
|   c---c---b
|   |   |   |
a---c---c   |
    |       |
    b-------b
Normal
c.Min = (b.Min.X, b.Min.Y)
c.Max = (a.Max.X, a.Max.Y)

a-------a
|       |
|       c---c-------b
|       |   |       |
a-------c---c       |
            |       |
            b-------b
not Normal
c.Min = (a.Max.X, b.Min.Y)
c.Max = (b.Min.X, a.Max.Y)
Min and Max are what they would be if they were Normaized

a-------a
|       |
|       |
|       |
a-------c-------c
        |       |
        c-------c-------b
                |       |
                |       |
                |       |
                b-------b
not Normal
c.Min = (a.Max.X, a.Max.Y)
c.Max = (b.Min.X, b.Min.Y)
Min and Max are what they would be if they were Normaized

    a-------a
    |       |
b---c-------c---b
|   |       |   |
|   |       |   |
|   |       |   |
b---c-------c---b
    |       |
    a-------a
Normal
c.Min = (a.Min.X, b.Min.Y)
c.Max = (a.Max.X, b.Max.Y)

    b-------b
    |       |
a---c---c   |
|   |   |   |
|   c---c---b
|       |
a-------a
Normal
c.Min = (b.Min.X, a.Min.Y)
c.Max = (a.Max.X, b.Max.Y)
*/
template<typename OtherBoxType>
BoxType InnerBox(const OtherBoxType & other) const 
{
	return BoxType(this -> Min.Max(other.Min), this -> Max.Min(other.Max));
}
};

#endif