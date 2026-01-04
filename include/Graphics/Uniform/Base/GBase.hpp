
#ifndef  GENERIC_UNIFORM_BASE_HPP
# define GENERIC_UNIFORM_BASE_HPP

# include "Graphics/Uniform/Base/Base.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
template <typename DataType>
class GBase : public Uniform::Base
{
	protected:
		GBase(Uniform::NameShader name_shader) :
			Uniform::Base(name_shader) { }
		virtual ~GBase() { }

	public:
	virtual void Put(const DataType & data) = 0;
	/*
		PutData() is the only purpose of GBase ?
		just make sure that functions is allways there ?
		maybe make all the Bases, FloatN and such Generic
		so they can force it ?
		I dont like Templates in c++
		I like c++ less and less the more I use it
		I would rather work with C# again
		or Rust ? that also allowed
		but I dont want to redo this whole thing
		so basically just Sunk Cost Fallacy ?
	*/
};
};

#endif
