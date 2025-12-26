#ifndef  OBJ_3D_BUFFER_ARRAY_HPP
# define OBJ_3D_BUFFER_ARRAY_HPP

//# include "Graphics/Buffer/Instance_Base_BufferArray.hpp"
# include "Graphics/Buffer/ArrayBase.hpp"

# include "OBJ_Main.hpp"

# include "InstanceData/Simple3D/Simple3D_InstData.hpp"
# include "InstanceData/Simple3D/Simple3D_InstBuffer.hpp"



/*class OBJ_3D_BufferArray : public Instance_Base_BufferArray<
	OBJ_MainData,
	OBJ_MainBuffer,
	Simple3D_InstData,
	Simple3D_InstBuffer
>*/
class OBJ_3D_BufferArray : Buffer::ArrayBase
{
	public:
	OBJ_MainBuffer			Main;
	Simple3D_InstBuffer		Inst;
	unsigned int			DrawMode;

	public:
	OBJ_3D_BufferArray();
	~OBJ_3D_BufferArray();

	void Draw();
};

#endif