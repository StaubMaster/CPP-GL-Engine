#ifndef  STRING_HELP_RANGE_HPP
# define STRING_HELP_RANGE_HPP

#include <string>

namespace StringHelp
{
	struct Range
	{
		size_t	Index0 = std::string::npos;
		size_t	Index1 = std::string::npos;

		~Range() = default;
		Range() = default;
		Range(const Range & other) = default;
		Range & operator=(const Range & other) = default;

		Range(const size_t & idx0, const size_t & idx1);

		//Section		Inclusive() const; // including the Boundary Characters
		//Section		Exclusive() const; // excluding the Boundary Characters

		std::string		CutInIn(const std::string & str) const;
		std::string		CutInEx(const std::string & str) const;
		std::string		CutExEx(const std::string & str) const;

		std::string		EraseInIn(const std::string & str) const;
		std::string		EraseInEx(const std::string & str) const;
		std::string		EraseExEx(const std::string & str) const;
	};
};

#endif
