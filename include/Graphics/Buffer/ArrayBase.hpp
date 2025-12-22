#ifndef  BUFFER_ARRAYBASE_HPP
# define BUFFER_ARRAYBASE_HPP

namespace Buffer
{
class ArrayBase
{
	private:
	unsigned int ID;



	public:
	ArrayBase();
	virtual ~ArrayBase();

	ArrayBase(const ArrayBase & other);
	ArrayBase & operator=(const ArrayBase & other);



	public:
	bool Exists() const;
	bool IsBound() const;
	void Bind();

	static unsigned int Bound();
	static void BindNone();



	public:
	void Create();
	void Delete();
	protected:
	virtual void CreateBuffers();
	virtual void DeleteBuffers();



	public:
	virtual void Draw();
};
};

#endif