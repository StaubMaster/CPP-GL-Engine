#include "Miscellaneous/Container/BehaviourShow.hpp"
#include <iostream>



std::ostream & operator <<(std::ostream & o, const Container::Behaviour::EIncrease & val)
{
	switch (val)
	{
		case Container::Behaviour::EIncrease::None:		o << "None"; break;
		case Container::Behaviour::EIncrease::Fit:		o << "Fit"; break;
		case Container::Behaviour::EIncrease::Binary:	o << "Binary"; break;
	}
	return o;
}
std::ostream & operator <<(std::ostream & o, const Container::Behaviour::EDecrease & val)
{
	switch (val)
	{
		case Container::Behaviour::EDecrease::None:		o << "None"; break;
		case Container::Behaviour::EDecrease::Fit:		o << "Fit"; break;
		case Container::Behaviour::EDecrease::Binary:	o << "Binary"; break;
	}
	return o;
}
std::ostream & operator <<(std::ostream & o, const Container::Behaviour::EMemory & val)
{
	switch (val)
	{
		case Container::Behaviour::EMemory::Null:	o << "Null"; break;
		case Container::Behaviour::EMemory::Bind:	o << "Bind"; break;
		case Container::Behaviour::EMemory::Copy:	o << "Copy"; break;
	}
	return o;
}
