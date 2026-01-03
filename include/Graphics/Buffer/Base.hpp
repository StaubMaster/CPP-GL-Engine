#ifndef  BUFFER_BASE_HPP
# define BUFFER_BASE_HPP

namespace Buffer
{
class Base
{
	//protected:
	public:
	unsigned int ID;



	public:
	Base();
	virtual ~Base();
	
	Base(const Base & other);
	Base & operator=(const Base & other);



	public:
	void Create();
	void Delete();

	protected:
	virtual void CreateRelay();
	virtual void DeleteRelay();
};
};

#endif