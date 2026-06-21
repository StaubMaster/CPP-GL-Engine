#ifndef  UNI_FLOAT_N_TYPE_BASE_HPP
# define UNI_FLOAT_N_TYPE_BASE_HPP

# include "Graphics/Uniform/General/FloatNBase.hpp"

namespace Uniform
{
template<unsigned int Size0, unsigned int Size1> void FloatNFunc(unsigned int Index, unsigned int Count, const float * val);

template <unsigned int Size0, unsigned int Size1, unsigned int Count, typename ValueType>
class FloatNTypeBase : public Uniform::FloatNBase
{
	public:
	virtual ~FloatNTypeBase() { }
	FloatNTypeBase(Uniform::Layout & layout, std::string name)
		: FloatNBase(layout, name)
	{ }

	protected:
	void	PutData(const float * val) override
	{
		FloatNFunc<Size0, Size1>(Index, Count, val);
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

template<> void FloatNFunc<1, 1>(unsigned int Index, unsigned int Count, const float * val);
template<> void FloatNFunc<2, 1>(unsigned int Index, unsigned int Count, const float * val);
template<> void FloatNFunc<3, 1>(unsigned int Index, unsigned int Count, const float * val);
template<> void FloatNFunc<4, 1>(unsigned int Index, unsigned int Count, const float * val);

template<> void FloatNFunc<2, 2>(unsigned int Index, unsigned int Count, const float * val);
template<> void FloatNFunc<3, 3>(unsigned int Index, unsigned int Count, const float * val);
template<> void FloatNFunc<4, 4>(unsigned int Index, unsigned int Count, const float * val);

};

#endif