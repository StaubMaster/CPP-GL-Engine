#include "PolyHedra/FileCollection.hpp"
#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Parsing.hpp"



PolyHedra * PolyHedraFileCollection::Find(const FileInfo & file) const
{
	for (unsigned int i = 0; i < FileObjects.Count(); i++)
	{
		const FileObject & file_obj = FileObjects[i];
		if (std::string(file_obj.File.Path.ToString()) == std::string(file.Path.ToString()))
		{
			return file_obj.Object;
		}
	}
	return nullptr;
}
#include <iostream>
PolyHedra * PolyHedraFileCollection::Make(const FileInfo & file)
{
	PolyHedra * object = PolyHedra::ParsingData::Load(file, nullptr, this);
	if (object -> Parameters == nullptr)
	{
		FileObject file_obj;
		file_obj.File = file;
		file_obj.Object = object;
		FileObjects.Insert(file_obj);
	}
	return object;
}
PolyHedra * PolyHedraFileCollection::Make(const FileInfo & file, const PolyHedra::ParsingData & parent)
{
	PolyHedra * object = PolyHedra::ParsingData::Load(file, &parent, this);
	if (object -> Parameters == nullptr)
	{
		FileObject file_obj;
		file_obj.File = file;
		file_obj.Object = object;
		FileObjects.Insert(file_obj);
	}
	return object;
}
PolyHedra * PolyHedraFileCollection::FindMake(const FileInfo & file)
{
	PolyHedra * object = Find(file);
	if (object == nullptr)
	{
		object = Make(file);
	}
	return object;
}
PolyHedra * PolyHedraFileCollection::FindMake(const FileInfo & file, const PolyHedra::ParsingData & parent)
{
	PolyHedra * object = Find(file);
	if (object == nullptr)
	{
		object = Make(file, parent);
	}
	return object;
}
