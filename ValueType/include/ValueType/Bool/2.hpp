#ifndef  BOOL_2_HPP
# define BOOL_2_HPP

struct Bool2
{
	private:
	unsigned char Bits = 0;

	Bool2(unsigned char bits);
	public:

	bool	GetX() const;
	bool	GetY() const;

	void	SetX(bool value);
	void	SetY(bool value);

	~Bool2() = default;
	Bool2() = default;
	Bool2(const Bool2 & other) = default;
	Bool2 & operator=(const Bool2 & other) = default;

	Bool2(bool value);
	Bool2(bool x, bool y);

	bool	All(bool value) const;
	bool	Any(bool value) const;

	unsigned char	Count(bool value) const;

	// Convert to bool   .All(true)



	Bool2 operator!() const;
	Bool2 operator&(const Bool2 & other) const;
	Bool2 operator|(const Bool2 & other) const;
	Bool2 operator^(const Bool2 & other) const;

	bool operator==(const Bool2 & other) const;
	bool operator!=(const Bool2 & other) const;

	bool operator&(bool value) const;
	bool operator|(bool value) const;
	bool operator^(bool value) const;
};

#endif