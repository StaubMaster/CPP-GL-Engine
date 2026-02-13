#ifndef  BOOL_2D_HPP
# define BOOL_2D_HPP

struct Bool2D
{
	private:
	unsigned char Bits;
	Bool2D(unsigned char bits);

	public:
	Bool2D();
	Bool2D(bool value);
	Bool2D(bool x, bool y);
	~Bool2D();
	
	Bool2D(const Bool2D & other);
	Bool2D & operator=(const Bool2D & other);

	public:
	Bool2D operator&(const Bool2D & other) const;
	Bool2D operator|(const Bool2D & other) const;
	Bool2D operator^(const Bool2D & other) const;

	bool operator==(const Bool2D & other) const;
	bool operator!=(const Bool2D & other) const;

	bool operator&(bool value) const;
	bool operator|(bool value) const;
	bool operator^(bool value) const;

	bool GetX() const;
	bool GetY() const;

	void SetX(bool value);
	void SetY(bool value);

	bool All(bool value) const;
	bool Any(bool value) const;
};

#endif