#ifndef  OBJECT_FUNCTION_HPP
# define OBJECT_FUNCTION_HPP

# include "Base.hpp"

template<typename ObjectType, typename ReturnType, typename ... Arguments>
struct ObjectFunction : public BaseFunction<ReturnType, Arguments ...>
{
	typedef ReturnType (ObjectType::*FunctionType)(Arguments ...);

	ObjectType *	Object;
	FunctionType	Function;

	ObjectFunction() :
		BaseFunction<ReturnType, Arguments ...>(),
		Object(0),
		Function(0)
	{ }
	ObjectFunction(ObjectType * obj, FunctionType func) :
		BaseFunction<ReturnType, Arguments ...>(),
		Object(obj),
		Function(func)
	{ }
	~ObjectFunction()
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

	static ObjectFunction * New(ObjectType * obj, FunctionType func)
	{
		ObjectFunction * obj_func = new ObjectFunction(obj, func);
		obj_func -> ShouldDelete = true;
		return obj_func;
	}

	void Change(ObjectType * obj)
	{
		Object = obj;
	}
	void Change(FunctionType func)
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