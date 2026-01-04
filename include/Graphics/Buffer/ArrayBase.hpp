#ifndef  BUFFER_ARRAYBASE_HPP
# define BUFFER_ARRAYBASE_HPP

# include "Miscellaneous/Container/Binary.hpp"

typedef unsigned int BufferArrayID;

namespace Buffer { class Base; };

namespace BufferArray
{
class Base
{
	private:
	static BufferArrayID None;

	private:
	BufferArrayID ID;
	protected:
	Container::Binary<Buffer::Base*> Buffers;

	public:
	void LogInfo(bool self = true) const;



	public:
	Base();
	virtual ~Base();

	Base(const Base & other);
	Base & operator=(const Base & other);



	public:
	bool Exists() const;
	bool IsBound() const;
	void Bind();

	static BufferArrayID Bound();
	static void BindNone();



	public:
	void Create();
	void Delete();



	public:
	virtual void Draw();
};
};

#endif