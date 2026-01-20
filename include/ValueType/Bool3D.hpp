#ifndef  BOOL_3D_HPP
# define BOOL_3D_HPP

struct Bool3D
{
	private:
	unsigned char Bits;
	Bool3D(unsigned char bits);

	public:
	Bool3D();
	Bool3D(bool value);
	Bool3D(bool x, bool y, bool z);
	~Bool3D();
	
	Bool3D(const Bool3D & other);
	Bool3D & operator=(const Bool3D & other);

	public:
	Bool3D operator&(const Bool3D & other) const;
	Bool3D operator|(const Bool3D & other) const;
	Bool3D operator^(const Bool3D & other) const;

	bool operator==(const Bool3D & other) const;
	bool operator!=(const Bool3D & other) const;

	bool operator&(bool value) const;
	bool operator|(bool value) const;
	bool operator^(bool value) const;

	bool GetX() const;
	bool GetY() const;
	bool GetZ() const;

	void SetX(bool value);
	void SetY(bool value);
	void SetZ(bool value);

	bool All(bool value) const;
	bool Any(bool value) const;
};

#endif