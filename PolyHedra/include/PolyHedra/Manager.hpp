#ifndef  POLYHEDRA_MANAGER_HPP
# define POLYHEDRA_MANAGER_HPP

# include "FileInfo.hpp"

# include "Generics/Container/Binary.hpp"

class PolyHedra;
struct PolyHedraParser;

namespace ParsingVariable { struct FloatMemory; };

# include <iosfwd>

struct PolyHedraEntry
{
	// Name
	FileInfo		File;
	PolyHedra *		Object = nullptr; // Data
	ParsingVariable::FloatMemory *	Parameters = nullptr;
};

class PolyHedraManager
{
	private:
	Container::Binary<PolyHedraEntry>	Entrys;

	public:
	PolyHedra *		Find(const FileInfo & file) const;

	private:
	PolyHedra *		Make(const FileInfo & file);
	PolyHedra *		Make(const FileInfo & file, const PolyHedraParser & parser);

	public:
	PolyHedra *		Take(const FileInfo & file);
	PolyHedra *		Take(const FileInfo & file, const PolyHedraParser & parser);

	public:
	void	ToInfo(std::ostream & s) const;
};

#endif