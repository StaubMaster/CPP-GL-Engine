#ifndef  POLYHEDRA_ENTRY_HPP
# define POLYHEDRA_ENTRY_HPP

# include "FileInfo.hpp"

class PolyHedra;
class PolyHedraManager;

struct PolyHedraEntry
{
	// Name
	FileInfo			File;
	PolyHedra *			Data = nullptr;

	PolyHedraManager &	Manager;
	PolyHedraEntry(PolyHedraManager & manager);

	void	Load();
};

#endif