#ifndef  GENERIC_FUNCTION_OBJECT_FUNCTION_HPP
# define GENERIC_FUNCTION_OBJECT_FUNCTION_HPP

# include "Base.hpp"
# include "Exception.hpp"

namespace Function
{
template<typename ObjectType, typename ReturnType, typename ... Arguments>
struct Object : public Base<ReturnType, Arguments ...>
{
	typedef ReturnType (ObjectType::*FunctionType)(Arguments ...);

	private:
	ObjectType *	mObject = nullptr;
	FunctionType	mFunction = nullptr;

	public:
	~Object() = default;
	Object() = default;
	Object(const Object & other) = default;
	Object & operator=(const Object & other) = default;

	public:
	bool CanInvoke() const override
	{
		return ((mObject != nullptr) && (mFunction != nullptr));
	}
	ReturnType Invoke(Arguments ... args) const override
	{
		if (mObject == nullptr) { throw Exception::MissingObject(); }
		if (mFunction == nullptr) { throw Exception::MissingFunction(); }
		return (*mObject.*mFunction)(args ...);
	}
	ReturnType operator()(Arguments ... args) const override
	{
		return Invoke(args ...);
	}

	public:
	Object(ObjectType * obj, FunctionType func)
		: Base<ReturnType, Arguments ...>()
		, mObject(obj)
		, mFunction(func)
	{ }
	Object(ObjectType & obj, FunctionType func)
		: Base<ReturnType, Arguments ...>()
		, mObject(&obj)
		, mFunction(func)
	{ }

	public:
	void Assign(ObjectType * obj)
	{
		mObject = obj;
	}
	void Assign(ObjectType & obj)
	{
		mObject = &obj;
	}
	void Assign(FunctionType func)
	{
		mFunction = func;
	}

	public:
	void Assign(ObjectType * obj, FunctionType func)
	{
		Assign(obj);
		Assign(func);
	}
	void Assign(ObjectType & obj, FunctionType func)
	{
		Assign(obj);
		Assign(func);
	}

	public:
	void operator=(ObjectType * obj)
	{
		Assign(obj);
	}
	void operator=(ObjectType & obj)
	{
		Assign(obj);
	}
	void operator=(FunctionType func)
	{
		Assign(func);
	}
};
};

#endif