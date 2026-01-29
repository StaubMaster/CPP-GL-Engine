#ifndef  BASE_FUNCTION_HPP
# define BASE_FUNCTION_HPP

template<typename ReturnType, typename ... Arguments>
struct BaseFunction
{
	BaseFunction()
	{ }
	virtual ~BaseFunction()
	{ }

	BaseFunction(const BaseFunction & other)
	{ }
	BaseFunction & operator=(const BaseFunction & other)
	{
		//(void)other;
		return *this;
	}

	virtual ReturnType Invoke(Arguments ... args) = 0;
};

#endif