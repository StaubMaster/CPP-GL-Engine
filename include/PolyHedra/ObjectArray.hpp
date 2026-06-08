#ifndef  POLYHEDRA_OBJECT_ARRAY_HPP
# define POLYHEDRA_OBJECT_ARRAY_HPP

# include "PolyHedra/Object.hpp"

struct PolyHedraObjectArray
{
	private:
	unsigned int		_Count;
	PolyHedraObject *	Data;
	public:

	bool			Is() const;
	unsigned int	Count() const;

	PolyHedraObject &	operator[](unsigned int i);

	~PolyHedraObjectArray();
	PolyHedraObjectArray();
	PolyHedraObjectArray(const PolyHedraObjectArray & other);
	PolyHedraObjectArray & operator=(const PolyHedraObjectArray & other);

	PolyHedraObjectArray(unsigned int count, ::PolyHedraPalletManager * pallet);
	PolyHedraObjectArray(unsigned int count, ::PolyHedra * pallet);

	void	Delete();
	void	Create(unsigned int count, ::PolyHedraPalletManager * pallet);
	void	Create(unsigned int count, ::PolyHedra * pallet);
};

#endif