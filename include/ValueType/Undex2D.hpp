#ifndef  UNDEX_2D_HPP
# define UNDEX_2D_HPP

# include "VectorU2.hpp"

typedef VectorU2 Undex2D;

//struct Bool2D;

/*struct Undex2D
{
	public:
	unsigned int X;
	unsigned int Y;



	public:
	~Undex2D();

	Undex2D();
	Undex2D(unsigned int x, unsigned int y);

	Undex2D(const Undex2D & other);
	Undex2D & operator=(const Undex2D & other);



	public:
	unsigned int	Product() const;



	public:
	Undex2D		operator+(const Undex2D & other) const;
	Undex2D		operator-(const Undex2D & other) const;
	Undex2D		operator*(const Undex2D & other) const;
	Undex2D		operator/(const Undex2D & other) const;
	Undex2D		operator%(const Undex2D & other) const;

	public:
	Undex2D		operator~() const;
	Undex2D		operator&(const Undex2D & other) const;
	Undex2D		operator|(const Undex2D & other) const;
	Undex2D		operator^(const Undex2D & other) const;
	Undex2D		operator<<(const Undex2D & other) const;
	Undex2D		operator>>(const Undex2D & other) const;

	public:
	Bool2D		operator==(const Undex2D & other) const;
	Bool2D		operator!=(const Undex2D & other) const;
	Bool2D		operator<(const Undex2D & other) const;
	Bool2D		operator>(const Undex2D & other) const;
	Bool2D		operator<=(const Undex2D & other) const;
	Bool2D		operator>=(const Undex2D & other) const;



	public:
	static bool		Box_inclusive(Undex2D idx, Undex2D min, Undex2D max);
	static bool		Box_exclusive(Undex2D idx, Undex2D min, Undex2D max);

	static bool		loop_inclusive(Undex2D & idx, Undex2D min, Undex2D max);
	static bool		loop_exclusive(Undex2D & idx, Undex2D min, Undex2D max);
	static bool		loop_inclusive(Undex2D & idx, unsigned int min, unsigned int max);
	static bool		loop_exclusive(Undex2D & idx, unsigned int min, unsigned int max);



	public:
	unsigned int ConvertX(Undex2D udx) const;
	Undex2D ConvertX(unsigned int udx) const;

	static unsigned int		Convert(unsigned int size, Undex2D udx);
	static Undex2D			Convert(unsigned int size, unsigned int udx);
};*/

#endif