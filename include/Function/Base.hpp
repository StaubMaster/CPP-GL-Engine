#ifndef  BASE_FUNCTION_HPP
# define BASE_FUNCTION_HPP

template<typename ReturnType, typename ... Arguments>
struct BaseFunction
{
	bool	ShouldDelete;

	BaseFunction() :
		ShouldDelete(false)
	{ }
	virtual ~BaseFunction()
	{ }

	BaseFunction(const BaseFunction & other) :
		ShouldDelete(other.ShouldDelete)
	{ }
	BaseFunction & operator=(const BaseFunction & other)
	{
		//(void)other;
		ShouldDelete = other.ShouldDelete;
		return *this;
	}

	virtual ReturnType Invoke(Arguments ... args) = 0;
};

#endif