#include "Miscellaneous/Container/Void.hpp"



bool Container::Void::IsNull() const { return (Data == nullptr); }
void Container::Void::Clear()
{
	Size = 0;
	Data = nullptr;
}



Container::Void::~Void()
{ }
Container::Void::Void()
{ }
Container::Void::Void(const Void & other)
	: Size(other.Size)
	, Data(other.Data)
{ }
Container::Void & Container::Void::operator=(const Void & other)
{
	Size = other.Size;
	Data = other.Data;
	return *this;
}
