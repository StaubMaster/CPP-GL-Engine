#ifndef  POLYHEDRA_ENTRY_HPP
# define POLYHEDRA_ENTRY_HPP

# include "FileInfo.hpp"

class PolyHedra;
class PolyHedraManager;

# include <string>

struct PolyHedraEntry
{
	PolyHedraManager &	Manager;
	PolyHedraEntry(PolyHedraManager & manager);

	// Name
	FileInfo			File;
	PolyHedra *			Data = nullptr;

	void	Load();
};

#endif