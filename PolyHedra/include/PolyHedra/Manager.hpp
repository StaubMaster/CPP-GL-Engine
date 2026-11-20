#ifndef  POLYHEDRA_MANAGER_HPP
# define POLYHEDRA_MANAGER_HPP

//# include "FileInfo.hpp"
class FileInfo;

# include "Generics/Container/Binary.hpp"

class PolyHedra;
//struct PolyHedraParser;
struct PolyHedraEntry;

# include <iosfwd>

class PolyHedraManager
{
	private: public:
	Container::Binary<PolyHedraEntry *>		Entrys;

	public:
	void	Clear();

	private:	PolyHedraEntry *	Make(const FileInfo & file);
	public:		PolyHedraEntry *	Find(const FileInfo & file) const;
	public:		PolyHedraEntry *	Take(const FileInfo & file);

	public:		PolyHedraEntry *	Find(const PolyHedra * polyhedra) const;

	public:		PolyHedra *		Find_Data(const FileInfo & file) const;
	public:		PolyHedra *		Take_Data(const FileInfo & file);

	public:
	void	ToInfo(std::ostream & s) const;



	public:
	static PolyHedraManager *	Current_;
	static PolyHedraManager &	Current();
	static bool		CheckCurrent();
	static void		ClearCurrent();
	bool	IsCurrent() const;
	void	MakeCurrent();

	public:
	static PolyHedraEntry *		sFind(const FileInfo & file);
	static PolyHedraEntry *		sTake(const FileInfo & file);

	static PolyHedraEntry *		sFind(const PolyHedra * polyhedra);

	static PolyHedra *			sFind_Data(const FileInfo & file);
	static PolyHedra *			sTake_Data(const FileInfo & file);
};

#endif