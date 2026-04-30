#ifndef  UNI_FLOAT_N_HPP
# define UNI_FLOAT_N_HPP

# include "Graphics/Uniform/Base/FloatNBase.hpp"

namespace Uniform
{
template<unsigned int Size0, unsigned int Size1> void FloatNFunc(unsigned int Index, unsigned int Count, const float * val);

template <unsigned int Size0, unsigned int Size1, unsigned int Count, typename ValueType>
class FloatN : public Uniform::FloatNBase // FloatNTypeBase
{
	public:
	virtual ~FloatN() { }
	FloatN(::Shader::Base & shader, std::string name)
		: FloatNBase(shader, name)
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