
#ifndef  POLYHEDRA_3D_BUFFER_ARRAY_HPP
# define POLYHEDRA_3D_BUFFER_ARRAY_HPP

//# include "Graphics/Buffer/Instance_Base_BufferArray.hpp"
# include "Graphics/Buffer/ArrayBase.hpp"

# include "PolyHedra/MainData/PolyHedra_MainData.hpp"
# include "PolyHedra/MainData/PolyHedra_MainBuffer.hpp"

# include "InstanceData/Simple3D/Simple3D_InstData.hpp"
# include "InstanceData/Simple3D/Simple3D_InstBuffer.hpp"



/*class PolyHedra_3D_BufferArray : public Instance_Base_BufferArray<
	PolyHedra_MainData,
	PolyHedra_MainBuffer,
	Simple3D_InstData,
	Simple3D_InstBuffer
>*/
class PolyHedra_3D_BufferArray : public Buffer::ArrayBase
{
	public:
	PolyHedra_MainBuffer	Main;
	Simple3D_InstBuffer		Inst;
	unsigned int			DrawMode;

	public:
	PolyHedra_3D_BufferArray();
	~PolyHedra_3D_BufferArray();
	
	PolyHedra_3D_BufferArray(const PolyHedra_3D_BufferArray & other);
	PolyHedra_3D_BufferArray & operator=(const PolyHedra_3D_BufferArray & other);

	protected:
	void CreateBuffers() override;
	void DeleteBuffers() override;

	public:
	void Draw();
};

#endif
