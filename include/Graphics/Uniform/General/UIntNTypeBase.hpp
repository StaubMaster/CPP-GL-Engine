#ifndef  UNI_UINT_N_TYPE_BASE_HPP
# define UNI_UINT_N_TYPE_BASE_HPP

# include "Graphics/Uniform/General/UIntNBase.hpp"

namespace Uniform
{
template<unsigned int Size0, unsigned int Size1> void UIntNFunc(unsigned int Index, unsigned int Count, const unsigned int * val);

template <unsigned int Size0, unsigned int Size1, unsigned int Count, typename ValueType>
class UIntNTypeBase : public Uniform::UIntNBase // UIntNTypeBase
{
	public:
	virtual ~UIntNTypeBase() { }
	UIntNTypeBase(Uniform::Layout & layout, std::string name)
		: UIntNBase(layout, name)
	{ }

	protected:
	void	PutData(const unsigned int * val) override
	{
		UIntNFunc<Size0, Size1>(Index, Count, val);
	}

	public:
	void Put(const ValueType & obj)
	{
		PutVoid(&obj);
	}
	void Put(const ValueType * obj)
	{
		PutVoid(obj);
	}
};

template<> void UIntNFunc<1, 1>(unsigned int Index, unsigned int Count, const unsigned int * val);
template<> void UIntNFunc<2, 1>(unsigned int Index, unsigned int Count, const unsigned int * val);
template<> void UIntNFunc<3, 1>(unsigned int Index, unsigned int Count, const unsigned int * val);
template<> void UIntNFunc<4, 1>(unsigned int Index, unsigned int Count, const unsigned int * val);

};

#endif