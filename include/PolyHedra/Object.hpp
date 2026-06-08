#ifndef  POLYHEDRA_OBJECT_HPP
# define POLYHEDRA_OBJECT_HPP

# include "ValueType/Trans3D.hpp"

class PolyHedra;
struct PolyHedraObjectData;
struct PolyHedraPalletManager;

#include <exception>

struct PolyHedraObject
{
	private:
	PolyHedraObjectData *	Data;

	public:
	bool			Is() const;

	::PolyHedraPalletManager *	PalletManager() const;
	::PolyHedra *				Pallet() const;

	bool	VisFull() const;
	bool	VisWire() const;

	void	HideFull();
	void	HideWire();

	void	ShowFull();
	void	ShowWire();

	const Trans3D &	Trans() const;
	Trans3D &		Trans();

	public:
	~PolyHedraObject();
	PolyHedraObject();
	PolyHedraObject(const PolyHedraObject & other);
	PolyHedraObject & operator=(const PolyHedraObject & other);

	public:
	PolyHedraObject(::PolyHedraPalletManager * pallet);
	PolyHedraObject(::PolyHedraPalletManager * pallet, Trans3D trans);

	public:
	PolyHedraObject(::PolyHedra * pallet);
	PolyHedraObject(::PolyHedra * pallet, Trans3D trans);

	public:
	void	Delete();
	void	Create(::PolyHedraPalletManager * pallet);
	void	Create(::PolyHedra * pallet);

	private:
	class ExceptionNullObject : public std::exception
	{
		const char * what() const noexcept;
	};
};

#endif