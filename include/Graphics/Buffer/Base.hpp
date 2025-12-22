#ifndef  BUFFER_BASE_HPP
# define BUFFER_BASE_HPP

namespace Buffer
{
class Base
{
	private:
	unsigned int ID;



	public:
	Base();
	virtual ~Base();
	
	Base(const Base & other);
	Base & operator=(const Base & other);



	public:
	void Create();
	void Delete();
	void Bind(unsigned int target, unsigned int size, const void * data, unsigned int usage);

	protected:
	virtual void CreateRelay();
	virtual void DeleteRelay();
	virtual void BindRelay();
};
};

#endif