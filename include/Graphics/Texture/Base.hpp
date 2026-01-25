#ifndef  TEXTURE_BASE_HPP
# define TEXTURE_BASE_HPP

# include "OpenGLTypes.hpp"

class FileInfo;

struct Undex3D;

namespace Texture
{
class Base
{
	private:
	static GL::TextureID None;

	protected:
	GL::TextureTarget Target;
	GL::TextureID ID;

	public:
	virtual void LogInfo(bool self = true) const;



	public:
	Base(GL::TextureTarget target);
	virtual ~Base();

	Base(const Base & other);
	Base & operator=(const Base & other);



	public:
	bool Exists() const;
	bool IsBound() const;
	void Bind();

	static GL::TextureID Bound(GL::TextureTarget target);
	static void BindNone(GL::TextureTarget target);



	public:
	void Create();
	void Delete();


	public:
	void DefaultParams();

	void Full3D(Undex3D size, const void * data);
	void Part3D(Undex3D size, Undex3D offset, const void * data);



	public:
	//static Base Tex2DArray(const Image * img);
	//static Base Tex2DArray(const FileInfo & file);
	//static Base Tex2DArray(unsigned int w, unsigned int h, const Container::Member<Image*> & imgs);
	//static Base Tex2DArray(unsigned int w, unsigned int h, const Container::Member<FileInfo> & files);
};
};

#endif