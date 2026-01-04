#ifndef  BUFFER_BASE_HPP
# define BUFFER_BASE_HPP

typedef unsigned int BufferID;

namespace Buffer
{
class Base
{
	private:
	static BufferID None;
	//	have referance to ArrayBuffer, Binding needs ArrayBuffer to be Bound

	protected:
	BufferID ID;

	public:
	void LogInfo(bool self = true) const;



	public:
	Base();
	virtual ~Base();
	
	Base(const Base & other);
	Base & operator=(const Base & other);



	public:
	void Create();
	void Delete();
};
};

#endif