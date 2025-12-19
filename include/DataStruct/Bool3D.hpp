#ifndef  BOOL_3D_HPP
# define BOOL_3D_HPP

struct Bool3D
{
	private:
	unsigned char Bits;
	Bool3D(unsigned char bits);

	public:
	Bool3D();
	Bool3D(bool x, bool y, bool z);
	~Bool3D();
	
	Bool3D(const Bool3D & other);
	Bool3D & operator=(const Bool3D & other);

	public:
	Bool3D operator&(const Bool3D & other);
	Bool3D operator|(const Bool3D & other);
	Bool3D operator^(const Bool3D & other);

	bool operator==(const Bool3D & other);
	bool operator!=(const Bool3D & other);

	bool GetX() const;
	bool GetY() const;
	bool GetZ() const;

	void SetX(bool val);
	void SetY(bool val);
	void SetZ(bool val);

	bool All(bool val) const;
	bool Any(bool val) const;
};

#endif