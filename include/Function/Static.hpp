#ifndef  STATIC_FUNCTION_HPP
# define STATIC_FUNCTION_HPP

# include "Base.hpp"

template<typename ReturnType, typename ... Arguments>
struct StaticCallBack : public BaseFunction<ReturnType, Arguments ...>
{
	typedef ReturnType (*FunctionType)(Arguments ...);

	FunctionType	Function;

	StaticCallBack(FunctionType * func) :
		BaseFunction<ReturnType, Arguments ...>(),
		Function(0)
	{ }
	StaticCallBack(FunctionType * func) :
		BaseFunction<ReturnType, Arguments ...>(),
		Function(func)
	{ }
	~StaticCallBack()
	{ }

	StaticCallBack(const StaticCallBack & other) :
		BaseFunction<ReturnType, Arguments ...>(other),
		Function(other.Function)
	{ }
	StaticCallBack & operator=(const StaticCallBack & other)
	{
		BaseFunction<ReturnType, Arguments ...>::operator=(other);
		Function = other.Function;
		return *this;
	}

	void Change(FunctionType func)
	{
		Function = func;
	}

	//	throw error when Function is NULL ?
	ReturnType Invoke(Arguments ... args) override
	{
		return Function(args ...);
	}
};

#endif