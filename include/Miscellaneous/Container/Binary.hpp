#ifndef  CONTAINER_BINARY_HPP
# define CONTAINER_BINARY_HPP

# include "Base.hpp"



namespace Container
{

template<typename T>
class Binary : public Base<T>
{
	public:
	Binary() : Base<T>()
	{ }
	~Binary()
	{ }

	Binary(const Binary<T> & other) : Base<T>()
	{
		this -> mAssign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Binary(other)\n";
	}
	Binary & operator=(const Binary<T> & other)
	{
		this -> Assign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Binary::operator=(other)\n";
		return *this;
	}
	Binary(const Member<T> & other) : Base<T>()
	{
		this -> mAssign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Binary(other)\n";
	}
	Binary & operator=(const Member<T> & other)
	{
 		this -> Assign(other);
		std::cout << __FILE__ << ':' << __LINE__ << ' ' << "Container::Binary::operator=(other)\n";
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
	Binary<T> Bind() const
	{
		Binary<T> other;
		other.Bind(*this);
		return other;
	}
	Binary<T> Copy() const
	{
		Binary<T> other;
		other.Copy(*this);
		return other;
	}

	protected:
	unsigned int	CalcLimit(unsigned int wanted_count) override
	{
		for (unsigned char shift = 31; shift < 32; shift--)
		{
			unsigned int size = 0xFFFFFFFF >> shift;
			if (size >= wanted_count)
			{
				return size;
			}
		}
		return 0;
	}
};
};

#endif