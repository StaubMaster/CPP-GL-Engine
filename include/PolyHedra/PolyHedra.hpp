#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Miscellaneous/Container/Binary.hpp"
# include "Miscellaneous/Container/Pointer.hpp"

# include "FileInfo.hpp"

# include <string>
# include <exception>

namespace PolyHedra_Main { struct Data; };

class SkinBase;

struct Point2D;
struct AxisBox3D;

class Image;

/*
Functions for changing the PolyHedra
are required for creating it
but I dont want them exposed once the PolyHedra is done

go back to having a seperate PolyHedra::Templace for that ?
it has all the Functions for changing the PolyHedra
Template dosent need to store its own Values
it can just referance the PolyHedra
if I make it nested

but if I make it nested, then I need put it all in the same Header
which is what I want to avoid

make the Template "parallel" to PolyHedra
PolyHedra.ToTemplate() will return a Template with referances to its

YES I CAN forward declare nested classes
thats literally what the first thing in the class is

but the question still is what to catually store in the Template
probably FileInfo

maybe other Context stuff
*/

/*	non Pointer
make this like Image ?
this one uses Containers to store Data
so Assignment just Copys the Pointers, then it would get Deleted
with Image it only Delets the Data when Dispose is called
but what if a "Copy" of the PolyHedra that Points to the same Data
changes the Container, like Inserting something that requires reallocation ?

Idea: smart(er) Pointers
smart Pointers already exist as part of c++(11 I think)
but they are just a wrapper to auto set Pointers to NULL
make a CountingPointer
that count how many times it has been Assigned
when Assignment hits 0, delete it
this is basically just a simple version of a garbadge collector ?
but that dosent seem right here ?

right now the PolyHedra is not supposed to be changed directly
only with the Template

the Template currently has a Referance to a PolyHedra
change it so It is completely seperate ?

do the Template has a Binary Container
and the PolyHedra has a Array Container
*/

class PolyHedra
{
	public:
	struct Corner;
	struct FaceCorner;
	struct Face;

	private:
	Container::Binary<Corner>	Corners;
	Container::Binary<Face>		Faces;
	public:
	FileInfo	File;
	SkinBase *	Skin;

	private:
	bool UseCornerNormals;

	private:
	PolyHedra();
	public:
	~PolyHedra();

	//PolyHedra(const PolyHedra & other);
	//PolyHedra & operator=(const PolyHedra & other);

	public:
	void Dispose();

	public:
	Container::Pointer<PolyHedra_Main::Data> ToMainData();

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