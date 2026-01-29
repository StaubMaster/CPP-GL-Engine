#ifndef  FUNCTION_POINTER_HPP
# define FUNCTION_POINTER_HPP

# include "Base.hpp"
# include "Object.hpp"

template<typename ... Arguments>
struct FunctionPointer
{
	bool								ShouldDelete;
	BaseFunction<void, Arguments ...> *	Function;

	FunctionPointer() :
		ShouldDelete(false),
		Function(0)
	{ }
	~FunctionPointer()
	{
		if (ShouldDelete) { delete Function; }
	}

	FunctionPointer(const FunctionPointer & other) :
		ShouldDelete(other.ShouldDelete),
		Function(other.Function)
	{ }
	FunctionPointer & operator=(const FunctionPointer & other)
	{
		if (ShouldDelete) { delete Function; }
		Function = other.Function;
		ShouldDelete = other.ShouldDelete;
		return *this;
	}

	void Change(BaseFunction<void, Arguments ...> * func)
	{
		if (ShouldDelete) { delete Function; }
		ShouldDelete = false;
		Function = func;
	}

	template<typename ObjectType>
	void Change(ObjectType * obj, void (ObjectType::*func)(Arguments ...))
	{
		if (ShouldDelete) { delete Function; }
		Function = new ObjectFunction<ObjectType, void, Arguments ...>(obj, func);
		ShouldDelete = true;
	}

	void Invoke(Arguments ... args)
	{
		if (Function != 0)
		{
			return Function -> Invoke(args ...);
		}
	}

	void operator=(BaseFunction<void, Arguments ...> * func)
	{
		Change(func);
	}
	void operator()(Arguments ... args)
	{
		Invoke(args ...);
	}
};

#endif