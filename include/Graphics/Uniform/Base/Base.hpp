#ifndef  UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <string>

namespace Multiform { class Base; };

namespace Uniform
{
class Layout;
class Base
{
	public:
	/*	does Uniform need to konw Layout / Shader ?
		Layout needs to know Shader once (when finding Locations)
		after that it is only used to automatically Bind shader when putting uniform
		doing this multiple times with different shaders that have the same thing is annlying anyway
		Mulform should be used for this
	*/
	Uniform::Layout &	Layout;
	std::string			Name;

	Multiform::Base *	Multiform;

	public:
	virtual void LogInfo(bool self = true) const;

	protected:
	virtual ~Base();
	Base(Uniform::Layout & layout, std::string name);

	Base(const Base & other) = delete;
	Base & operator=(const Base & other) = delete;

	public:
	int Locate() const;
	virtual void ReLocate();

	public:
	virtual void	PutVoid(const void * val) = 0;
	void	PutMultiformData();
};
};

#endif