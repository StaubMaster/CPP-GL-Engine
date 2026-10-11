#ifndef  FUNCTION_STATIC_HPP
# define FUNCTION_STATIC_HPP

# include "Base.hpp"
# include "Exception.hpp"

namespace Function
{
template<typename ReturnType, typename ... Arguments>
struct Static : public Base<ReturnType, Arguments ...>
{
	typedef ReturnType (*FunctionType)(Arguments ...);

	private:
	FunctionType	mFunction = nullptr;

	public:
	~Static() = default;
	Static() = default;
	Static(const Static & other) = default;
	Static & operator=(const Static & other) = default;

	public:
	bool CanInvoke() const override
	{
		return (mFunction != nullptr);
	}
	ReturnType Invoke(Arguments ... args) const override
	{
		if (mFunction == nullptr) { throw Exception::MissingFunction(); }
		return mFunction(args ...);
	}
	ReturnType operator()(Arguments ... args) const override
	{
		return Invoke(args ...);
	}

	public:
	Static(FunctionType func)
		: Base<ReturnType, Arguments ...>()
		, mFunction(func)
	{ }

	public:
	void Assign(FunctionType func)
	{
		mFunction = func;
	}

	public:
	void operator=(FunctionType func)
	{
		Assign(func);
	}
};
};

#endif