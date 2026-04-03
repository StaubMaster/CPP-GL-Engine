#ifndef  STATIC_FUNCTION_HPP
# define STATIC_FUNCTION_HPP

# include "Base.hpp"

template<typename ReturnType, typename ... Arguments>
struct StaticFunction : public BaseFunction<ReturnType, Arguments ...>
{
	typedef ReturnType (*FunctionType)(Arguments ...);

	FunctionType	Function;

	~StaticFunction() { }

	StaticFunction() :
		BaseFunction<ReturnType, Arguments ...>(),
		Function(nullptr)
	{ }
	StaticFunction(FunctionType func) :
		BaseFunction<ReturnType, Arguments ...>(),
		Function(func)
	{ }

	StaticFunction(const StaticFunction & other) :
		BaseFunction<ReturnType, Arguments ...>(other),
		Function(other.Function)
	{ }
	StaticFunction & operator=(const StaticFunction & other)
	{
		BaseFunction<ReturnType, Arguments ...>::operator=(other);
		Function = other.Function;
		return *this;
	}

	void Assign(FunctionType func)
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