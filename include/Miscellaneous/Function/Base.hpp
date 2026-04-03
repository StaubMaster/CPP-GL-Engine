#ifndef  BASE_FUNCTION_HPP
# define BASE_FUNCTION_HPP

template<typename ReturnType, typename ... Arguments>
struct BaseFunction
{
	virtual ~BaseFunction() { }

	BaseFunction() { }

	BaseFunction(const BaseFunction & other) = delete;
	BaseFunction & operator=(const BaseFunction & other) = delete;

	virtual ReturnType Invoke(Arguments ... args) = 0;
};

#endif