#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Miscellaneous/Container/Binary.hpp"
# include "Miscellaneous/Container/Pointer.hpp"

# include "FileInfo.hpp"

# include <string>
# include <exception>

namespace PolyHedraFull { namespace Main { struct Data; }; };

class SkinBase;

struct Point2D;
struct AxisBox3D;

class Image;

class PolyHedra
{
	public:
	struct Corner;
	struct Face;
	struct Edge;

	public:
	Container::Binary<Corner>	Corners;
	Container::Binary<Face>		Faces;
	Container::Binary<Edge>		Edges;

	public:
	FileInfo	File;
	SkinBase *	Skin;

	private:
	bool UseCornerNormals;

	private:
	PolyHedra();
	public:
	~PolyHedra();

	PolyHedra(const PolyHedra & other) = delete;
	PolyHedra & operator=(const PolyHedra & other) = delete;

	public:
	void Dispose();

	public:
	Container::Pointer<PolyHedraFull::Main::Data> ToMainData();

	public:
	std::string ToInfo() const;
	AxisBox3D	CalcBound() const;

	public:
	struct Template;
	Template * ToTemplate();

	public:
	struct Generate;

	private:
	struct ParsingData;
	public:
	static PolyHedra * Load(const FileInfo & file);
};

#endif