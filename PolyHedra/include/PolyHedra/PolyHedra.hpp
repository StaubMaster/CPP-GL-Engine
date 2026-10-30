#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Generics/Container/Binary.hpp"

# include "FileInfo.hpp"

# include <string>

class Skin;

struct BoxF3;

//struct Trans3D;
# include "ValueType/Trans/3D.hpp"

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
	void	Insert_Corn(float x, float y, float z);
	void	Insert_Corn(VectorF3 vec);

	public:
	void	Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2);
	void	Insert_Face3(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int normal_group);
	void	Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3);
	void	Insert_Face4(unsigned int corn0, unsigned int corn1, unsigned int corn2, unsigned int corn3, unsigned int normal_group);

	public:
	void	Belt_Face(unsigned int temp[4], bool f_direction, unsigned int normal_group);
	void	Belt(unsigned int len, unsigned int list0[], unsigned int list1[], bool f_direction, bool f_closed, unsigned int normal_group);

	public:
	void	Fan_Face(unsigned int middle, unsigned int blade[2], bool f_direction, bool f_middle, unsigned int normal_group);
	void	Fan(unsigned int len, unsigned int middle, unsigned int blade[], bool f_direction, bool f_middle, bool f_closed, unsigned int normal_group);

	public:
	void	Done();

	public:
	BoxF3	CalcBound() const; // LimitBox()
	// LimitDist()
	// CenterAverage()

	public:
	void	Combine(const PolyHedra & other);
	void	Combine(const PolyHedra & other, const Trans3D & trans);

	public:
	::Skin *	Skin = nullptr;
	// combine Skin into PolyHedra ?
	/*
		how to apply Skin afterwards ?
		Skin data is generally seperate but synced with PolyHedra Data
		how to make sure they stay synced
	*/

	public:
	// store this in PolyHedraEntry ?
	/* this is bad here
		PolyHedra should just be static geometry Data
		make something else that contains multiple PolyHedras relative to eachother
	*/
	struct PolyHedraOther
	{
		const PolyHedra *	Object;
		Trans3D				Trans; // Matrix ?
	};
	Container::Binary<PolyHedraOther>	Others;
	void	OthersCombine()
	{

	}
	/* store static Other PolyHedra
		only combine them when Buffer is made
		not combining them means less space is taken if same PolyHedra us used multiple times
		and they can be more reasily changed in Editor
		make a function that .Combines all static Others

		are dynamics even needed then ?
		just have a Container of Other
	*/
	/* what about Parameter Files
		files that make Geometry based on Parameters
		and then a Skin is applied afterwards
		how to apply Skin to Other ?

		"Skin" applys Skin File to this
		make "otherSkin" that applys Skin to other

		what if I want to put the same Geometry with different Skins ?
		"otherPut" puts other in Container
	*/

	public:
	bool	IsAutomatic = false; // store in Manager::Entry ?

	public:
	std::string		ToInfo() const; // put in Manager::Entry ?

	public:
	~PolyHedra();
	PolyHedra();

	public:
	PolyHedra(const PolyHedra & other) = delete;
	PolyHedra & operator=(const PolyHedra & other) = delete;
};

#endif