#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "PolyHedra/Flesh.hpp"
# include "PolyHedra/Skin.hpp"

struct Trans3D;

# include <string>

class PolyHedra
{
	public:
	PolyHedraFlesh		Flesh;
	PolyHedraSkin		Skin;

	public:
	void	Combine(const PolyHedra & other);
	void	Combine(const PolyHedra & other, const Trans3D & trans);

	public:
	// store this in PolyHedraEntry ?
	/* this is bad here
		PolyHedra should just be static geometry Data
		make something else that contains multiple PolyHedras relative to eachother
	*/
	/*struct PolyHedraOther
	{
		const PolyHedra *	Object;
		Trans3D				Trans; // Matrix ?
	};
	Container::Binary<PolyHedraOther>	Others;*/
	//void	OthersCombine() { } // why is this in the Header ?

	public:
	bool	IsAutomatic = false; // store in Manager::Entry ?

	public:
	std::string		ToInfo() const; // put in Manager::Entry ?

	public:
	~PolyHedra() = default;
	PolyHedra() = default;
	PolyHedra(const PolyHedra & other) = delete;
	PolyHedra & operator=(const PolyHedra & other) = delete;
};

#endif