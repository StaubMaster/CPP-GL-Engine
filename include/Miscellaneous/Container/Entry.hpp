#ifndef  CONTAINER_ENTRY_HPP
# define CONTAINER_ENTRY_HPP

# include "DebugDefines.hpp"

namespace Container
{

struct Entry
{
	public:
		unsigned int Offset;
		unsigned int Length;

	public:
		unsigned int Min() const { return Offset; }
		unsigned int Max() const { return (Offset + Length) - 1; }
		unsigned int Limit() const { return Offset + Length; }

	public:
		virtual void DebugInfo()
		{
			Debug::Console << Debug::Tabs << ">>>> Container::Entry.Info()\n";
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << this << '\n';

			Debug::Console << Debug::Tabs << "Offset" << ' ' << Offset << '\n';
			Debug::Console << Debug::Tabs << "Length" << ' ' << Length << '\n';

			Debug::Console << Debug::TabDec;
			Debug::Console << Debug::Tabs << "<<<< Container::Entry.Info()\n";
		}

	public:
		Entry() :
			Offset(0),
			Length(0)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "Container::Entry" << "  ++++  " << "Entry()" << '\n';
			Debug::Console << Debug::TabDec;
#endif
		}
		Entry(unsigned int off, unsigned int len) :
			Offset(off),
			Length(len)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "Container::Entry" << "  ++++  " << "Entry(off, len)" << '\n';
			Debug::Console << Debug::TabDec;
#endif
		}
		virtual ~Entry()
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "Container::Entry" << "  ----  " << "~Entry()" << '\n';
			Debug::Console << Debug::TabDec;
#endif
		}

	public:
		Entry(const Entry & other) :
			Offset(other.Offset),
			Length(other.Length)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "Container::Entry" << "  ====  " << "Entry(other)" << '\n';
			Debug::Console << Debug::TabDec;
#endif
		}
		Entry & operator =(const Entry & other)
		{
#ifdef CONTAINER_DEBUG
			Debug::Console << Debug::TabInc;
			Debug::Console << Debug::Tabs << "Container::Entry" << "  ====  " << "operator =(other)" << '\n';
			Debug::Console << Debug::TabDec;
#endif
			Offset = other.Offset;
			Length = other.Length;
			return *this;
		}

	/*	Memory Reordering ?
		Copy Input Data with Gaps onto Output Data with Gaps

		Invert Entrys ?
			the Entrys become Gaps
			the Gaps become Entrys
	*/
};

};

#endif