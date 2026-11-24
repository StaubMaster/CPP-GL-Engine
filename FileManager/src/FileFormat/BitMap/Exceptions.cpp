#include "FileFormat/BitMap/Exceptions.hpp"
#include <sstream>



BitMap::Exceptions::UnknownSignature::UnknownSignature()
	: TextExceptionBase()
{
	Text = "BitMap: Unknown Signature.";
}



BitMap::Exceptions::UnknownHeader::UnknownHeader()
	: TextExceptionBase()
{
	Text = "BitMap: Unknown Header.";
}



BitMap::Exceptions::UnknownHeaderValue::UnknownHeaderValue(const char * name, const char * val)
	: TextExceptionBase()
{
	std::ostringstream ss("BitMap: UnknownHeaderValue: ");
	ss << name << ": " << val << ".";
	Text = ss.str();
}
BitMap::Exceptions::UnknownHeaderValue::UnknownHeaderValue(const char * name, uint8 val)
	: TextExceptionBase()
{
	std::ostringstream ss("BitMap: UnknownHeaderValue: ");
	ss << name << ": " << val << ".";
	Text = ss.str();
}
BitMap::Exceptions::UnknownHeaderValue::UnknownHeaderValue(const char * name, uint16 val)
	: TextExceptionBase()
{
	std::ostringstream ss("BitMap: UnknownHeaderValue: ");
	ss << name << ": " << val << ".";
	Text = ss.str();
}
BitMap::Exceptions::UnknownHeaderValue::UnknownHeaderValue(const char * name, uint32 val)
	: TextExceptionBase()
{
	std::ostringstream ss("BitMap: UnknownHeaderValue: ");
	ss << name << ": " << val << ".";
	Text = ss.str();
}
BitMap::Exceptions::UnknownHeaderValue::UnknownHeaderValue(const char * name, uint64 val)
	: TextExceptionBase()
{
	std::ostringstream ss("BitMap: UnknownHeaderValue: ");
	ss << name << ": " << val << ".";
	Text = ss.str();
}
