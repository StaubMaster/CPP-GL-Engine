#ifndef  POLYHEDRA_FLESH_HPP
# define POLYHEDRA_FLESH_HPP

# include "Generics/Container/Binary.hpp"

# include "ValueType/Vector/F3.hpp"

struct BoxF3;
struct Trans3D;

class PolyHedraFlesh
{
	public:
	struct Corner
	{
		VectorF3	Position;

		~Corner() = default;
		Corner() = default;
		Corner(const Corner & other) = default;
		Corner & operator=(const Corner & other) = default;

		Corner(VectorF3 pos);
		Corner(float x, float y, float z);
	};
	struct Face
	{
		unsigned int	idx[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
		unsigned int	NormalGroup = 0xFFFFFFFF;
		VectorF3		Normal; // Calculate when Buffer is made ?

		bool	Check(unsigned int count) const;

		~Face() = default;
		Face() = default;
		Face(const Face & other) = default;
		Face & operator=(const Face & other) = default;

		Face(unsigned int idx0, unsigned int idx1, unsigned int idx2);
		Face(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int normal_group);
	};
	struct Edge
	{
		unsigned int	idx[2] = { 0xFFFFFFFF, 0xFFFFFFFF };

		bool	Check(unsigned int count) const;

		~Edge() = default;
		Edge() = default;
		Edge(const Edge & other) = default;
		Edge & operator=(const Edge & other) = default;

		Edge(unsigned int idx0, unsigned int idx1);
	};

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
	// take (unsigend int corn[n])

	public:
	void	Belt_Face(unsigned int temp[4], bool f_direction, unsigned int normal_group);
	void	Belt(unsigned int len, unsigned int list0[], unsigned int list1[], bool f_direction, bool f_closed, unsigned int normal_group);

	public:
	void	Fan_Face(unsigned int middle, unsigned int blade[2], bool f_direction, bool f_middle, unsigned int normal_group);
	void	Fan(unsigned int len, unsigned int middle, unsigned int blade[], bool f_direction, bool f_middle, bool f_closed, unsigned int normal_group);

	public:
	void	TrimData();



	public:
	//void	Combine(const PolyHedraFlesh & other);
	void	Combine(const PolyHedraFlesh & other, const Trans3D & trans);



	public:
	BoxF3	LimitBox() const;
	//float	LimitDist() const;
	//VectorF3	CenterAverage() const;



	public:
	~PolyHedraFlesh() = default;
	PolyHedraFlesh() = default;
	PolyHedraFlesh(const PolyHedraFlesh & other) = delete;
	PolyHedraFlesh & operator=(const PolyHedraFlesh & other) = delete;
};

#endif