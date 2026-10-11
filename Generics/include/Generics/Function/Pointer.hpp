#ifndef  GENERIC_FUNCTION_FUNCTION_POINTER_HPP
# define GENERIC_FUNCTION_FUNCTION_POINTER_HPP

# include "Base.hpp"
# include "Static.hpp"
# include "Object.hpp"

# include "Exception.hpp"

// allow these to return something ?
// the only reason to return void if for TryInvoke
// when those are not used, they dont complain ?
// C++ is like that, I think.

namespace Function
{
template<typename ... Arguments>
struct Pointer : public Base<void, Arguments ...>
{
	private:
	unsigned int *					Count = nullptr; // mShared
	Base<void, Arguments ...> *		Function = nullptr;

	public:
	~Pointer()
	{
		if (Count != nullptr)
		{
			if ((*Count) == 0)
			{
				delete Count;
				delete Function;
			}
			else
			{
				(*Count)--;
			}
		}
	}
	Pointer()
		: Count(nullptr)
		, Function(nullptr)
	{ }
	Pointer(const Pointer & other)
		: Count(other.Count)
		, Function(other.Function)
	{
		if (Count != nullptr)
		{
			(*Count)++;
		}
	}
	Pointer & operator=(const Pointer & other)
	{
		if (Count != nullptr)
		{
			if ((*Count) == 0)
			{
				delete Count;
				delete Function;
			}
			else
			{
				(*Count)--;
			}
		}

		Count = other.Count;
		Function = other.Function;

		if (Count != nullptr)
		{
			(*Count)++;
		}

		return *this;
	}

	public:
	bool CanInvoke() const override
	{
		return (Function != nullptr);
	}
	void Invoke(Arguments ... args) const override
	{
		if (Function == nullptr) { throw Function::Exception::MissingFunction(); }
		return Function -> Invoke(args ...);
	}
	void operator()(Arguments ... args) const override
	{
		Invoke(args ...);
	}

	public:
	void TryInvoke(Arguments ... args) const
	{
		if (!CanInvoke()) { return; }
		Function -> Invoke(args ...);
	}

	public:
	Pointer(Base<void, Arguments ...> * func)
		: Count(nullptr)
		, Function(func)
	{ }
	void Assign(Base<void, Arguments ...> * func)
	{
		if (Count != nullptr)
		{
			if ((*Count) == 0)
			{
				delete Count;
				delete Function;
			}
			else
			{
				(*Count)--;
			}
		}
	
		Count = nullptr;
		Function = func;
	}
	void operator=(Base<void, Arguments ...> * func)
	{
		Assign(func);
	}

	public:
	

	public:
	Pointer(void (*func)(Arguments ...))
		: Count(new unsigned int)
		, Function(new Static<void, Arguments ...>(func))
	{
		(*Count) = 0;
	}
	void Assign(void (*func)(Arguments ...))
	{
		if (Count != nullptr)
		{
			if ((*Count) == 0)
			{
				delete Count;
				delete Function;
			}
			else
			{
				(*Count)--;
			}
		}

		Count = new unsigned int;
		(*Count) = 0;
		Function = new Static<void, Arguments ...>(func);
	}

	public:
	template<typename ObjectType>
	Pointer(ObjectType * obj, void (ObjectType::*func)(Arguments ...))
		: Count(new unsigned int)
		, Function(new Object<ObjectType, void, Arguments ...>(obj, func))
	{
		(*Count) = 0;
	}
	template<typename ObjectType>
	void Assign(ObjectType * obj, void (ObjectType::*func)(Arguments ...))
	{
		if (Count != nullptr)
		{
			if ((*Count) == 0)
			{
				delete Count;
				delete Function;
			}
			else
			{
				(*Count)--;
			}
		}

		Count = new unsigned int;
		(*Count) = 0;
		Function = new Object<ObjectType, void, Arguments ...>(obj, func);
	}
	// typedef these function pointers
};
};

#endif