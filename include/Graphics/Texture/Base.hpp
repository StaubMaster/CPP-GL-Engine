#ifndef  TEXTURE_BASE_HPP
# define TEXTURE_BASE_HPP

class FileContext;

namespace Texture
{
class Base
{
	protected:
	unsigned int ID;
	unsigned int Type;

	public:
	Base(unsigned int type);
	virtual ~Base();

	Base(const Base & other);
	Base & operator=(const Base & other);

	public:
	private:
	void Create();
	void Delete();

	public:
	virtual void Bind();
};
};

#endif
