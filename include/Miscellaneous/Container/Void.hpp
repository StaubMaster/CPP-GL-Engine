#ifndef  CONTAINER_VOID_HPP
# define CONTAINER_VOID_HPP

namespace Container
{
struct Void
{
	unsigned long	Size = 0;
	const void *	Data = nullptr;

	bool	IsNull() const;
	void	Clear();

	~Void();
	Void();
	Void(const Void & other);
	Void & operator=(const Void & other);
};
};

#endif