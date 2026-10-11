#include "Generics/Container/Binary.hpp"



namespace Container
{
namespace Loop
{
template<typename TypeItem> void	Delete(Binary<TypeItem*> & container)
{
	unsigned long n = container.Count();
	for (unsigned long i = 0; i < n; i++)
	{
		delete container.At(i);
	}
}

template<typename TypeItem> void	Invoke(Binary<TypeItem*> & container, void (TypeItem::*func)(void))
{
	unsigned long n = container.Count();
	for (unsigned long i = 0; i < n; i++)
	{
		TypeItem * obj = container.At(i);
		if (obj != nullptr)
		{
			(*obj.*func)();
		}
	}
}
template<typename TypeItem> void	Invoke(const Binary<TypeItem*> & container, void (TypeItem::*func)(void) const)
{
	unsigned long n = container.Count();
	for (unsigned long i = 0; i < n; i++)
	{
		const TypeItem * obj = container.At(i);
		if (obj != nullptr)
		{
			(*obj.*func)();
		}
	}
}



template<typename TypeItem> unsigned int	SumUInt32(const Binary<TypeItem*> & container, unsigned int (TypeItem::*func)(void) const)
{
	unsigned int sum = 0;
	unsigned long n = container.Count();
	for (unsigned long i = 0; i < n; i++)
	{
		const TypeItem * obj = container.At(i);
		if (obj != nullptr)
		{
			sum += (*obj.*func)();
		}
	}
	return sum;
}



template<typename TypeItem, typename ... Parameters>
TypeItem *		Find(
	const Binary<TypeItem*> & container,
	bool (*func)(const TypeItem &, Parameters ...),
	Parameters ... params
)
{
	unsigned long n = container.Count();
	for (unsigned long i = 0; i < n; i++)
	{
		TypeItem * obj = container.At(i);
		if (obj != nullptr)
		{
			if ((*func)(*obj, params ...))
			{
				return obj;
			}
		}
	}
	return nullptr;
}

template<typename TypeItem, typename ... Parameters>
TypeItem *		Find(
	const Binary<TypeItem*> & container,
	bool (TypeItem::*func)(Parameters ...) const,
	Parameters ... params
)
{
	unsigned long n = container.Count();
	for (unsigned long i = 0; i < n; i++)
	{
		TypeItem * obj = container.At(i);
		if (obj != nullptr)
		{
			if ((*obj.*func)(params ...))
			{
				return obj;
			}
		}
	}
	return nullptr;
}

};
};
