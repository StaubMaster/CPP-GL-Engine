#ifndef  BUFFER_ATTRIBUTE_HPP
# define BUFFER_ATTRIBUTE_HPP

# include "Base.hpp"

# include "Graphics/Attribute/Base/AttributeBase.hpp"

# include "Miscellaneous/Container/Base.hpp"

namespace Buffer
{
class Attribute : public Base
{
	private:
	public:
	Container::Base<::Attribute::Base*> Attributes;
	unsigned int Count;

	public:
	Attribute();
	virtual ~Attribute();
	
	Attribute(const Attribute & other);
	Attribute & operator=(const Attribute & other);

	public:
	void CreateRelay() override;
	void DeleteRelay() override;
	void BindRelay() override;
};
};

#endif