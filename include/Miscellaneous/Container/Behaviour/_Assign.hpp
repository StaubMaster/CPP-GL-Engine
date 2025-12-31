#ifndef  CONTAINER_BEHAVIOUR_ASSIGN_HPP
# define CONTAINER_BEHAVIOUR_ASSIGN_HPP

# include "Member.hpp"

/*	Dispose and Assign
there are 2 things here

what to do with old Data
what to do with new Data

"Constant" : Pointer to some outside data
	dont delete automatically
	maybe delete on demand ? (should this just allways be possible)
	Bind by default
	Bind would create a "Constant"
	Copy would create a "Local"

"Local" : allocated Data
	delete automatically
	delete on demand
	Copy by default
	Bind would Create a "Constant"
	Copy would create a "Local"

"Global" : allocated singular Data
	dont delete automatically
	delete on demand
	Bind by default
	Bind would create a "Constant"
	Copy would create a "Local"

"Global" and "Constant" are the same except for delete on demand
this should be handled from outside ?



Base(limit)					"Local"
Base(limit, * data)			"Global"
Base(limit, const * data)	"Constant"

Base(limit, count)					"Local"
Base(limit, count, * data)			"Global"
Base(limit, count, const * data)	"Constant"


void Bind(const & other)		"Constant"
void Bind(limit, const * data)	"Constant"

void Copy(const & other)		"Local"
void Copy(limit, const * data)	"Local"


void Allocate(limit)			"Local"

void Delete()	delete automatic
void Dispose()	delete demand
*/

namespace Container
{
namespace Behaviour
{
enum class EAssign
{
	Copy,	//	Allocate, copy Data
	Bind,	//	Copy Pointer
};

template<typename T>
void Assign(Member<T> & member, ConstMember<T> & other, EAssign assign)
{
	if (assign == EAssign::Bind)
	{
		member.Limit = other.Limit;
		member.Count = other.Count;
		member.Data = (T*)other.Data;
	}
	if (assign == EAssign::Copy)
	{
		member.Limit = other.Limit;
		member.Count = other.Count;
		member.Data = new T[member.Limit];
		for (unsigned int i = 0; i < member.Count; i++)
		{
			member.Data[i] = other.Data[i];
		}
	}
}

};
};


#endif