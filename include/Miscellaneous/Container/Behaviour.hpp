#ifndef  CONTAINER_BEHAVIOUR_HPP
# define CONTAINER_BEHAVIOUR_HPP

//# include "Base.hpp"

# include "Behaviour/Increase.hpp"
# include "Behaviour/Decrease.hpp"
//# include "Behaviour/Dispose.hpp"
//# include "Behaviour/Assign.hpp"
# include "Behaviour/Memory.hpp"

namespace Container
{
namespace Behaviour
{
unsigned int BinarySize(unsigned int wanted_size);
};
};

/*	I once had it so that all Behviour is in the Base
	Dynamic:	Inc/Dec Binary
	Fixed:		Inc/Dec None

Rename
	Fixed:		Array
	Dynamic:	ArrayList / List

	Fixed:		Limit != Count
	Array:		Limit == Count
*/

/*	organize Behaviour ?

Inc/Dec
	calculate new Size
		requires to maybe know current Size
Dispose
	needs Data Pointer
	also change Count and Limit
Assign
	needs Data Pointer and Count and Limit

giving it the whole Base dosent work since the members are inacessible
make another Base that has them public
then make Base inherit that as protected

make then new Base inherit form amother like VoidPointerBase

this makes the Void functions inacessible


Behaviour::Data
{
	public:
	& _Limit;
	& _Count;
	& _Data;
}

Container::Void
{
	dosent store anything
	just has the Void access functions
	used for Buffers that want a referance to Data
	but dont care about what type the Data has
	only a Pointer and ByteSize
}

Container::Data : public Container::Void
{
	protected:
	_Limit;
	_Count;
	_Data;

	public:
	Behaviour::Data BehaviourData() const;

	public:
	operator[]
	at()
}

Container::Base : public Container::Data
{
	Behaviour::EIncrease;
	Behaviour::EDecrease;
}

*/

#endif