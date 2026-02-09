#ifndef  CONTAINER_TIGHT_HPP
# define CONTAINER_TIGHT_HPP

# include "Base.hpp"



namespace Container
{

template<typename T>
class Tight : public Base<T>
{
	public:
	Tight() : Base<T>()
	{ }
	~Tight()
	{ }

	Tight(const Tight<T> & other) : Base<T>()
	{
		this -> mAssign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Tight(other)\n";
	}
	Tight & operator=(const Tight<T> & other)
	{
		this -> Assign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Tight::operator=(other)\n";
		return *this;
	}
	Tight(const Member<T> & other) : Base<T>()
	{
		this -> mAssign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Tight(other)\n";
	}
	Tight & operator=(const Member<T> & other)
	{
		this -> Assign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Tight::operator=(other)\n";
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
	Tight<T> Bind() const
	{
		Tight<T> other;
		other.Bind(*this);
		return other;
	}
	Tight<T> Copy() const
	{
		Tight<T> other;
		other.Copy(*this);
		return other;
	}

	protected:
	unsigned int	CalcLimit(unsigned int wanted_count) override
	{
		return wanted_count;
	}
};
};

#endif