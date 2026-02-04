#ifndef  OBJ_3D_BUFFER_ARRAY_HPP
# define OBJ_3D_BUFFER_ARRAY_HPP

//# include "Graphics/Buffer/Instance_Base_BufferArray.hpp"
# include "Graphics/Buffer/ArrayBase.hpp"

# include "OBJ_Main.hpp"

# include "InstanceData/Simple3D/Data.hpp"
# include "InstanceData/Simple3D/Buffer.hpp"



/*class OBJ_3D_BufferArray : public Instance_Base_BufferArray<
	OBJ_MainData,
	OBJ_MainBuffer,
	Simple3D_InstData,
	Simple3D_InstBuffer
>*/
class OBJ_3D_BufferArray : public BufferArray::Base
{
	public:
	OBJ_MainBuffer			Main;
	Simple3D::Buffer		Inst;
	GL::DrawMode			DrawMode;

	public:
	OBJ_3D_BufferArray();
	~OBJ_3D_BufferArray();

	OBJ_3D_BufferArray(const OBJ_3D_BufferArray & other) = delete;
	OBJ_3D_BufferArray & operator=(const OBJ_3D_BufferArray & other) = delete;

	void Draw();
};

#endif