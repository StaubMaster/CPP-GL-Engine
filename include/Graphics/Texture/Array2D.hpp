#ifndef  TEXTURE_ARRAY_2D_HPP
# define TEXTURE_ARRAY_2D_HPP

# include "Base.hpp"
# include "Display/SizeRatio2D.hpp"
# include "Miscellaneous/Container/Member.hpp"

/*	dont need Array2D as inherited class
make it a static nested class ?

put Init3D() and Sub3D() into Base.
make a struct for the wrapping stuff
the struct only stores a referance to the Base Texture
I think there are GL functions for getting this informations
make the struct have Wrapper funcitons to get/set or is/make that stuff
*/

class FileInfo;
class Image;

namespace Texture
{
class Array2D : public Base
{
	public:
	SizeRatio2D	SizeRatio;



	public:
	Array2D();
	~Array2D();

	Array2D(const Array2D & other);
	Array2D & operator=(const Array2D & other);



	public:
	void Assign(const Image & img);
	void Assign(const FileInfo & file);
	void Assign(unsigned int w, unsigned int h, const Container::Member<Image> & imgs);
	void Assign(unsigned int w, unsigned int h, const Container::Member<FileInfo> & files);
};
};

#endif
