#ifndef  POLYHEDRA_ENTRY_HPP
# define POLYHEDRA_ENTRY_HPP

# include "FileInfo.hpp"

class PolyHedra;
class PolyHedraManager;

struct PolyHedraEntry
{
	// Name
	FileInfo		File;
	PolyHedra *		Data = nullptr;

	void	Load(PolyHedraManager & manager);
};

#endif