#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Miscellaneous/Container/Binary.hpp"
# include "Miscellaneous/Container/Array.hpp"

# include "FileInfo.hpp"

# include <string>
# include <exception>

namespace PolyHedraFull { namespace Main { struct Data; }; };

class Skin;

struct VectorF2;
struct BoxF3;

class Image;

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
	Container::Binary<Skin*>	Skins;

	public: // Information stuff
	FileInfo	File;
	std::string	Name;

	public:
	~PolyHedra();
	PolyHedra();
	PolyHedra(const PolyHedra & other) = delete;
	PolyHedra & operator=(const PolyHedra & other) = delete;

	public:
	void	Done();

	public:
	void	Calc_Face_Normals();
	void	Calc_Corn_Normals();
	bool	UseCornerNormals;

	void	Insert_Corn(Corner corn);
	void	Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2);
	void	Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3);

	void	Belt(unsigned int idx0[], unsigned int idx1[], unsigned int len, bool direction, bool closure);
	void	Band(unsigned int idx0[], unsigned int idx1[], unsigned int len, bool direction, bool closure);
	void	Fan(unsigned int middle, unsigned int blade[], unsigned int len, bool direction, bool closure);

	public:
	// ToBuffer ?
	Container::Array<PolyHedraFull::Main::Data>		ToMainData();
	// seperate ToFullData and ToWireData
	// Wire data is made of Vertexes and Element
	// make seperatly ?

	public:
	std::string		ToInfo() const;
	BoxF3			CalcBound() const;

	public:
	struct Generate;

	private:
	struct ParsingData;
	public:
	static PolyHedra * Load(const FileInfo & file);
};

#endif