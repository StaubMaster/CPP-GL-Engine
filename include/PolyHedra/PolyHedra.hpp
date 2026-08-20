#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Generics/Container/Binary.hpp"

# include "FileInfo.hpp"

# include <string>

class Skin;

struct BoxF3;

namespace ParsingVariable { struct FloatMemory; }

struct Trans3D;

class PolyHedraFileCollection;

class PolyHedra
{
	public:
	struct Corner;
	struct Face;
	struct Edge;

	public:
	Container::Binary<Corner>	Corners;
	Container::Binary<Edge>		Edges;
	Container::Binary<Face>		Faces;

	public:
	BoxF3	CalcBound() const;

	public:
	::Skin *	Skin = nullptr;

	public:
	FileInfo	File;

	bool	IsAutomatic = false;

	public:
	ParsingVariable::FloatMemory *	Parameters = nullptr;

	/* dynamic PolyHedra
		List of { Trans PolyHedra } Pairs
	*/
	/* static PolyHedra
		List of { Trans PolyHedra } Pairs
		Combine when Buffer is made
		what if this changes the Data of static ?
	*/
	/*
		List of { Trans PolyHedra Enum } ?
		Enum is "static" or "dynamic"
	*/

	public:
	std::string		ToInfo() const;

	public:
	~PolyHedra();
	PolyHedra();

	public:
	PolyHedra(const PolyHedra & other) = delete;
	PolyHedra & operator=(const PolyHedra & other) = delete;

	public:
	void	Done();

	public:
	void	CalcNormals();
	bool	UseCornerNormals;

	void	Insert_Corn(Corner corn);
	void	Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2);
	void	Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3);

	private:
	void	Belt_Face(unsigned int temp[4], bool f_direction);
	void	Belt(unsigned int len, unsigned int list0[], unsigned int list1[], bool f_direction, bool f_closed);

	private:
	void	Fan_Face(unsigned int middle, unsigned int blade[2], bool f_direction, bool f_middle);
	void	Fan(unsigned int len, unsigned int middle, unsigned int blade[], bool f_direction, bool f_middle, bool f_closed);

	public:
	void	Combine(const PolyHedra & other);
	void	Combine(const PolyHedra & other, const Trans3D & trans);

	public:
	struct ParsingData;
	public:
	static PolyHedra *	Load(const FileInfo & file);
};

#endif