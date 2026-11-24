#ifndef  STRING_HELP_STRING_RANGE_HPP
# define STRING_HELP_STRING_RANGE_HPP

#include <string>

struct StringRange
{
	size_t	Index0 = std::string::npos;
	size_t	Index1 = std::string::npos;

	~StringRange() = default;
	StringRange() = default;
	StringRange(const StringRange & other) = default;
	StringRange & operator=(const StringRange & other) = default;

	StringRange(const size_t & idx0, const size_t & idx1);

	//Section		Inclusive() const; // including the Boundary Characters
	//Section		Exclusive() const; // excluding the Boundary Characters

	std::string		LeaveInIn(const std::string & str) const;
	std::string		LeaveInEx(const std::string & str) const;
	std::string		LeaveExEx(const std::string & str) const;

	std::string		EraseInIn(const std::string & str) const;
	std::string		EraseInEx(const std::string & str) const;
	std::string		EraseExEx(const std::string & str) const;
};

#endif
