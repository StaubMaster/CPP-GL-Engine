#ifndef  CONTAINER_BEHAVIOUR_DISPOSE_HPP
# define CONTAINER_BEHAVIOUR_DISPOSE_HPP

# include "Member.hpp"

namespace Container
{
namespace Behaviour
{
enum class EDispose
{
	Never,	//	never delete
	Demand,	//	only delete from Dispose(), not from Destructor
	Always,	//	allways delete
};

template<typename T>
void Destruct(EDispose dispose, Member<T> & member)
{
	if (dispose == EDispose::Always)
	{
		delete[] member.Data;
	}
	//member.Limit = 0;
	//member.Count = 0;
	//member.Data = 0;
}

template<typename T>
void Demand(EDispose dispose, Member<T> & member)
{
	if (dispose == EDispose::Demand || dispose == EDispose::Always)
	{
		delete[] member.Data;
	}
	member.Limit = 0;
	member.Count = 0;
	member.Data = 0;
}

};
};


#endif