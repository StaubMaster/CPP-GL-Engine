#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Miscellaneous/Container/Binary.hpp"
# include "Miscellaneous/Container/Pointer.hpp"

# include "FileInfo.hpp"

# include <string>
# include <exception>

namespace PolyHedraFull { namespace Main { struct Data; }; };

class SkinBase;

//struct Point2D;
struct VectorF2; typedef VectorF2 Point2D;
//struct AxisBox3D;
struct BoxF3; typedef BoxF3 AxisBox3D;

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
	FileInfo	File;
	SkinBase *	Skin;

	public:
	PolyHedra();
	~PolyHedra();

	PolyHedra(const PolyHedra & other) = delete;
	PolyHedra & operator=(const PolyHedra & other) = delete;

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
	Container::Pointer<PolyHedraFull::Main::Data>	ToMainData();

	public:
	std::string	ToInfo() const;
	AxisBox3D	CalcBound() const;

	public:
	struct Generate;

	private:
	struct ParsingData;
	public:
	static PolyHedra * Load(const FileInfo & file);
};

#endif