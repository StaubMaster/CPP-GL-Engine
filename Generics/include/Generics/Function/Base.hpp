#ifndef  FUNCTION_BASE_HPP
# define FUNCTION_BASE_HPP

namespace Function
{
template<typename ReturnType, typename ... Arguments>
struct Base
{
	public:
	virtual ~Base() = default;
	Base() = default;
	Base(const Base & other) = default;
	Base & operator=(const Base & other) = default;

	// Clear

	public:
	virtual bool		CanInvoke() const = 0;
	virtual ReturnType	Invoke(Arguments ... args) const = 0;
	virtual ReturnType	operator()(Arguments ... args) const = 0;
};
};

#endif