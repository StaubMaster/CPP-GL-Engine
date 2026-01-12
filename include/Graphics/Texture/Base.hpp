#ifndef  TEXTURE_BASE_HPP
# define TEXTURE_BASE_HPP

typedef unsigned int TextureID;
typedef unsigned int TextureType;

class FileInfo;

struct Undex3D;

namespace Texture
{
class Base
{
	private:
	static TextureID None;

	protected:
	TextureType Type;
	TextureID ID;

	public:
	virtual void LogInfo(bool self = true) const;



	public:
	Base(unsigned int type);
	virtual ~Base();

	Base(const Base & other);
	Base & operator=(const Base & other);



	public:
	bool Exists() const;
	bool IsBound() const;
	void Bind();

	static TextureID Bound(TextureType type);
	static void BindNone(TextureType type);



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