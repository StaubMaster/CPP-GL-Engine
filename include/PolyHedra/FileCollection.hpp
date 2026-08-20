#ifndef  POLYHEDRA_FILE_COLLECTION_HPP
# define POLYHEDRA_FILE_COLLECTION_HPP

# include "FileInfo.hpp"

# include "Generics/Container/Binary.hpp"

//class PolyHedra;
//class PolyHedra::ParsingData;

# include "PolyHedra/PolyHedra.hpp"

class PolyHedraFileCollection
{
	public:
	struct FileObject
	{
		FileInfo		File;
		PolyHedra *		Object;
	};

	public:
	Container::Binary<FileObject>	FileObjects;

	public:
	PolyHedra *		Find(const FileInfo & file) const;
	private:
	PolyHedra *		Make(const FileInfo & file);
	PolyHedra *		Make(const FileInfo & file, const PolyHedra::ParsingData & parent);
	public:
	PolyHedra *		FindMake(const FileInfo & file);
	PolyHedra *		FindMake(const FileInfo & file, const PolyHedra::ParsingData & parent);
};

#endif