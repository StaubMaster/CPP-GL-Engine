#ifndef  OBJECT_FUNCTION_HPP
# define OBJECT_FUNCTION_HPP

# include "Base.hpp"

template<typename ObjectType, typename ReturnType, typename ... Arguments>
struct ObjectFunction : public BaseFunction<ReturnType, Arguments ...>
{
	typedef ReturnType (ObjectType::*FunctionType)(Arguments ...);

	ObjectType *	Object;
	FunctionType	Function;

	~ObjectFunction() { }

	ObjectFunction() :
		BaseFunction<ReturnType, Arguments ...>(),
		Object(nullptr),
		Function(nullptr)
	{ }
	ObjectFunction(ObjectType * obj, FunctionType func) :
		BaseFunction<ReturnType, Arguments ...>(),
		Object(obj),
		Function(func)
	{ }

	ObjectFunction(const ObjectFunction & other) :
		BaseFunction<ReturnType, Arguments ...>(other),
		Object(other.Object),
		Function(other.Function)
	{ }
	ObjectFunction & operator=(const ObjectFunction & other)
	{
		BaseFunction<ReturnType, Arguments ...>::operator=(other);
		Object = other.Object;
		Function = other.Function;
		return *this;
	}

	void Assign(ObjectType * obj)
	{
		Object = obj;
	}
	void Assign(FunctionType func)
	{
		Function = func;
	}

	//	throw error when Function of Object is NULL ?
	ReturnType Invoke(Arguments ... args) override
	{
		return (*Object.*Function)(args ...);
	}
};

#endif