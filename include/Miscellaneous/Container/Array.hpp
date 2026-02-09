#ifndef  CONTAINER_ARRAY_HPP
# define CONTAINER_ARRAY_HPP

# include "Base.hpp"



namespace Container
{

template<typename T>
class Array : public Base<T>
{
	public:
	Array() : Base<T>()
	{ }
	Array(unsigned int limit) : Base<T>()
	{
		this -> Allocate(limit, limit);
	}
	~Array()
	{ }

	Array(const Array<T> & other) : Base<T>()
	{
		this -> mAssign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Array(other)\n";
	}
	Array & operator=(const Array<T> & other)
	{
		this -> Assign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Array::operator=(other)\n";
		return *this;
	}
	Array(const Member<T> & other) : Base<T>()
	{
		this -> mAssign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Array(other)\n";
	}
	Array & operator=(const Member<T> & other)
	{
		this -> Assign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Array::operator=(other)\n";
		return *this;
	}

	public:
	void	Clear() override
	{
		this -> mDelete();
	}
	protected:
	void	mAssign(const Member<T> other) override
	{
		this -> mCopy(other);
	}

	public:
	using Base<T>::Bind;
	using Base<T>::Copy;

	public:
	Array<T> Bind() const
	{
		Array<T> other;
		other.Bind(*this);
		return other;
	}
	Array<T> Copy() const
	{
		Array<T> other;
		other.Copy(*this);
		return other;
	}

	protected:
	unsigned int	CalcLimit(unsigned int wanted_count) override
	{
		(void)wanted_count;
		return this -> _Limit;
	}
};
};

#endif