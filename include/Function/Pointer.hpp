#ifndef  FUNCTION_POINTER_HPP
# define FUNCTION_POINTER_HPP

# include "Base.hpp"

template<typename ... Arguments>
struct FunctionPointer
{
	BaseFunction<void, Arguments ...> *	Function;

	FunctionPointer() :
		Function(0)
	{ }
	~FunctionPointer()
	{
		if (Function != 0 && Function -> ShouldDelete) { delete Function; }
	}

	FunctionPointer(const FunctionPointer & other) :
		Function(other.Function)
	{ }
	FunctionPointer & operator=(const FunctionPointer & other)
	{
		if (Function != 0 && Function -> ShouldDelete) { delete Function; }
		Function = other.Function;
		return *this;
	}

	void Change(BaseFunction<void, Arguments ...> * func)
	{
		if (Function != 0 && Function -> ShouldDelete) { delete Function; }
		Function = func;
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