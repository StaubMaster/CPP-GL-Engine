#ifndef  GENERIC_FUNCTION_FUNCTION_POINTER_HPP
# define GENERIC_FUNCTION_FUNCTION_POINTER_HPP

# include "Base.hpp"
# include "Object.hpp"

template<typename ... Arguments>
struct FunctionPointer : public BaseFunction<void, Arguments ...>
{
	private:
	bool	ShouldDelete; // IsDynamic IsNew
	BaseFunction<void, Arguments ...> *	Function = nullptr;

	public:
	~FunctionPointer()
	{
		if (ShouldDelete) { delete Function; }
	}
	FunctionPointer()
		: ShouldDelete(false)
		, Function(nullptr)
	{ }
	FunctionPointer(const FunctionPointer & other)
		: ShouldDelete(other.ShouldDelete)
		, Function(other.Function)
	{ }
	FunctionPointer & operator=(const FunctionPointer & other)
	{
		if (ShouldDelete) { delete Function; }
		Function = other.Function;
		ShouldDelete = other.ShouldDelete;
		return *this;
	}

	public:
	bool CanInvoke() const override
	{
		return (Function != nullptr);
	}
	void Invoke(Arguments ... args) const override
	{
		if (Function == nullptr) { throw "FunctionBase is null"; }
		return Function -> Invoke(args ...);
	}
	void operator()(Arguments ... args) const override
	{
		Invoke(args ...);
	}

	public:
	FunctionPointer(BaseFunction<void, Arguments ...> * func)
		: ShouldDelete(false)
		, Function(func)
	{ }
	void Assign(BaseFunction<void, Arguments ...> * func)
	{
		if (ShouldDelete) { delete Function; }
		ShouldDelete = false;
		Function = func;
	}
	void operator=(BaseFunction<void, Arguments ...> * func)
	{
		Assign(func);
	}

	public:
	template<typename ObjectType>
	FunctionPointer(ObjectType * obj, void (ObjectType::*func)(Arguments ...))
		: ShouldDelete(true)
		, Function(new ObjectFunction<ObjectType, void, Arguments ...>(obj, func))
	{ }
	template<typename ObjectType>
	void Assign(ObjectType * obj, void (ObjectType::*func)(Arguments ...))
	{
		if (ShouldDelete) { delete Function; }
		ShouldDelete = true;
		Function = new ObjectFunction<ObjectType, void, Arguments ...>(obj, func);
	}
	// typedef these function pointers
};

#endif