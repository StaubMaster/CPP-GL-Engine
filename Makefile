
NAME := Engine.a

COMPILER := g++ -g -std=c++11
FLAGS := -Wall -Wextra -Werror -D ENGINE_DIR='"$(shell pwd)"'
ARCHIVER := ar -rcs
REMOVER := rm -f

FANCY_NAME := Engine
include fancy.mk



DIR_SRC := src/
DIR_OBJ := obj/



VALUE_TYPE := \
	ValueType/Bool2.cpp \
	ValueType/Bool3.cpp \
	ValueType/Bool4.cpp \
	\
	ValueType/VectorF2.cpp \
	ValueType/VectorF3.cpp \
	ValueType/VectorF4.cpp \
	ValueType/BoxF1.cpp \
	ValueType/BoxF2.cpp \
	ValueType/BoxF3.cpp \
	\
	ValueType/VectorU2.cpp \
	ValueType/VectorU3.cpp \
	ValueType/BoxU2.cpp \
	ValueType/BoxU3.cpp \
	\
	ValueType/VectorI2.cpp \
	ValueType/VectorI3.cpp \
	ValueType/BoxI2.cpp \
	ValueType/BoxI3.cpp \
	ValueType/LoopI2.cpp \
	ValueType/LoopI3.cpp \
\
	ValueType/Undex.cpp \
	ValueType/UndexLoop2D.cpp \
	ValueType/UndexLoop3D.cpp \
	ValueType/Line2D.cpp \
	ValueType/Line3D.cpp \
	ValueType/Ray2D.cpp \
	ValueType/Ray3D.cpp \
	ValueType/Matrix2x2.cpp \
	ValueType/Matrix3x3.cpp \
	ValueType/Matrix4x4.cpp \
	ValueType/Angle.cpp \
	ValueType/EulerAngle3D.cpp \
	ValueType/Trans2D.cpp \
	ValueType/Trans3D.cpp \
	ValueType/DepthFactors.cpp \
	ValueType/Depth.cpp \
	ValueType/ColorF4.cpp \
	ValueType/Range.cpp \
	ValueType/LInter.cpp \
	ValueType/LightBase.cpp \
	ValueType/LightSolar.cpp \
	ValueType/LightSpot.cpp \
	ValueType/View2D.cpp \
	ValueType/View3D.cpp \
	ValueType/Intersect.cpp \
	ValueType/_Show.cpp
VALUE_TYPE_SRC := $(addprefix $(DIR_SRC)/,$(VALUE_TYPE))
VALUE_TYPE_OBJ := $(addprefix $(DIR_OBJ)/,$(VALUE_TYPE:.cpp=.o))

DISPLAY := \
	Display/AspectRatio.cpp \
	Display/PixelSize.cpp \
	Display/DisplaySize.cpp \
	Display/PixelPosition.cpp \
	Display/DisplayPosition.cpp \
	Display/NormalPosition.cpp \

DISPLAY_SRC := $(addprefix $(DIR_SRC)/,$(DISPLAY))
DISPLAY_OBJ := $(addprefix $(DIR_OBJ)/,$(DISPLAY:.cpp=.o))

CONTAINER :=
CONTAINER_SRC := $(addprefix $(DIR_SRC)/,$(CONTAINER))
CONTAINER_OBJ := $(addprefix $(DIR_OBJ)/,$(CONTAINER:.cpp=.o))

SHADER := \
	Graphics/Shader/Code.cpp \
	Graphics/Shader/Base.cpp
SHADER_SRC := $(addprefix $(DIR_SRC)/,$(SHADER))
SHADER_OBJ := $(addprefix $(DIR_OBJ)/,$(SHADER:.cpp=.o))

UNIFORM := \
	Graphics/Uniform/Base/Base.cpp \
	Graphics/Uniform/Base/FloatN.cpp \
	Graphics/Uniform/Base/Float1.cpp \
	Graphics/Uniform/Base/Float2.cpp \
	Graphics/Uniform/Base/Float3.cpp \
	Graphics/Uniform/Base/Float4.cpp \
	Graphics/Uniform/Base/Float2x2.cpp \
	Graphics/Uniform/Base/Float3x3.cpp \
	Graphics/Uniform/Base/Float4x4.cpp \
	Graphics/Uniform/Base/UIntN.cpp \
	Graphics/Uniform/Base/UInt1.cpp \
\
	Graphics/Uniform/Float.cpp \
	Graphics/Uniform/UInt.cpp \
\
	Graphics/Uniform/ColorF4.cpp \
	Graphics/Uniform/Point2D.cpp \
	Graphics/Uniform/Point3D.cpp \
	Graphics/Uniform/Matrix2x2.cpp \
	Graphics/Uniform/Matrix3x3.cpp \
	Graphics/Uniform/Matrix4x4.cpp \
	Graphics/Uniform/Angle.cpp \
	Graphics/Uniform/Trans2D.cpp \
	Graphics/Uniform/Trans3D.cpp \
\
	Graphics/Uniform/DepthFactors.cpp \
	Graphics/Uniform/Depth.cpp \
	Graphics/Uniform/Range.cpp \
	Graphics/Uniform/LInter.cpp \
	Graphics/Uniform/LightBase.cpp \
	Graphics/Uniform/LightSolar.cpp \
	Graphics/Uniform/LightSpot.cpp \
	Graphics/Uniform/AspectRatio.cpp \
	Graphics/Uniform/PixelSize.cpp \
	Graphics/Uniform/DisplaySize.cpp \

UNIFORM_SRC := $(addprefix $(DIR_SRC)/,$(UNIFORM))
UNIFORM_OBJ := $(addprefix $(DIR_OBJ)/,$(UNIFORM:.cpp=.o))

MULTIFORM := \
	Graphics/Multiform/Base/Base.cpp \
	Graphics/Multiform/Float.cpp \
	Graphics/Multiform/ColorF4.cpp \
	Graphics/Multiform/Trans2D.cpp \
	Graphics/Multiform/Trans3D.cpp \
	Graphics/Multiform/DepthFactors.cpp \
	Graphics/Multiform/Depth.cpp \
	Graphics/Multiform/Range.cpp \
	Graphics/Multiform/LInter.cpp \

MULTIFORM_SRC := $(addprefix $(DIR_SRC)/,$(MULTIFORM))
MULTIFORM_OBJ := $(addprefix $(DIR_OBJ)/,$(MULTIFORM:.cpp=.o))

BUFFER := \
	Graphics/Buffer/Base.cpp \
	Graphics/Buffer/Array.cpp \
	Graphics/Buffer/Element.cpp \
	Graphics/Buffer/VertexArray.cpp
BUFFER_SRC := $(addprefix $(DIR_SRC)/,$(BUFFER))
BUFFER_OBJ := $(addprefix $(DIR_OBJ)/,$(BUFFER:.cpp=.o))

ATTRIBUTE := \
	Graphics/Attribute/Base/Location.cpp \
	Graphics/Attribute/Base/LocationFloatN.cpp \
	Graphics/Attribute/Base/Base.cpp \
	Graphics/Attribute/Base/Float1.cpp \
	Graphics/Attribute/Base/Float2.cpp \
	Graphics/Attribute/Base/Float3.cpp \
	Graphics/Attribute/Base/Float4.cpp \
	Graphics/Attribute/Base/Float2x2.cpp \
	Graphics/Attribute/Base/Float3x3.cpp \
	Graphics/Attribute/Base/Float4x4.cpp \
\
	Graphics/Attribute/Point2D.cpp \
	Graphics/Attribute/Point3D.cpp \
	Graphics/Attribute/Point4D.cpp \
	Graphics/Attribute/AxisBox2D.cpp \
	Graphics/Attribute/ColorF4.cpp \
\
	Graphics/Attribute/Log.cpp
ATTRIBUTE_SRC := $(addprefix $(DIR_SRC)/,$(ATTRIBUTE))
ATTRIBUTE_OBJ := $(addprefix $(DIR_OBJ)/,$(ATTRIBUTE:.cpp=.o))

TEXTURE := \
	Graphics/Texture/Base.cpp \
	Graphics/Texture/Array2D.cpp \
	Graphics/Texture/Generate.cpp
TEXTURE_SRC := $(addprefix $(DIR_SRC)/,$(TEXTURE))
TEXTURE_OBJ := $(addprefix $(DIR_OBJ)/,$(TEXTURE:.cpp=.o))

INSTANCE_DATA := \
\
	Instance/Basic2D/Buffer.cpp \
	Instance/Basic2D/Data.cpp \
\
	Instance/Basic3D/Buffer.cpp \
	Instance/Basic3D/Data.cpp \

INSTANCE_DATA_SRC := $(addprefix $(DIR_SRC)/,$(INSTANCE_DATA))
INSTANCE_DATA_OBJ := $(addprefix $(DIR_OBJ)/,$(INSTANCE_DATA:.cpp=.o))

POLYGON := \
	PolyGon/PolyGon.cpp \
\
	PolyGon/Graphics/Full/Main/Data.cpp \
	PolyGon/Graphics/Full/Main/Buffer.cpp \
	PolyGon/Graphics/Full/Shader.cpp \
\
	PolyGon/Graphics/Wire/Main/Buffer.cpp \
	PolyGon/Graphics/Wire/Elem/Buffer.cpp \
	PolyGon/Graphics/Wire/Shader.cpp \
\
	PolyGon/InstanceManager.cpp \
	PolyGon/ObjectData.cpp \
	PolyGon/Manager.cpp \
	PolyGon/Object.cpp \

POLYGON_SRC := $(addprefix $(DIR_SRC)/,$(POLYGON))
POLYGON_OBJ := $(addprefix $(DIR_OBJ)/,$(POLYGON:.cpp=.o))

POLYHEDRA := \
	PolyHedra/PolyHedra.cpp \
	PolyHedra/Data.cpp \
	PolyHedra/Parsing.cpp \
	PolyHedra/Generate.cpp \
\
	PolyHedra/Skin/SkinBase.cpp \
	PolyHedra/Skin/Skin2DA.cpp \
	PolyHedra/Skin/Skin2D_Data.cpp \
\
	PolyHedra/Graphics/Full/Main/Buffer.cpp \
	PolyHedra/Graphics/Full/Buffer.cpp \
	PolyHedra/Graphics/Full/Shader.cpp \
\
	PolyHedra/Graphics/Wire/Main/Buffer.cpp \
	PolyHedra/Graphics/Wire/Main/Data.cpp \
	PolyHedra/Graphics/Wire/Elem/Buffer.cpp \
	PolyHedra/Graphics/Wire/Buffer.cpp \
	PolyHedra/Graphics/Wire/Shader.cpp \
\
	PolyHedra/InstanceManager.cpp \
	PolyHedra/ObjectData.cpp \
	PolyHedra/Manager.cpp \
	PolyHedra/Object.cpp \
	PolyHedra/ObjectArray.cpp \

POLYHEDRA_SRC := $(addprefix $(DIR_SRC)/,$(POLYHEDRA))
POLYHEDRA_OBJ := $(addprefix $(DIR_OBJ)/,$(POLYHEDRA:.cpp=.o))

WAVEFRONT := \
	Wavefront/OBJ.cpp \
	Wavefront/Main/Data.cpp \
	Wavefront/Main/Buffer.cpp \
	Wavefront/Simple3D/BufferArray.cpp \
	Wavefront/Simple3D/Shader.cpp \
	Wavefront/MTL.cpp
WAVEFRONT_SRC := $(addprefix $(DIR_SRC)/,$(WAVEFRONT))
WAVEFRONT_OBJ := $(addprefix $(DIR_OBJ)/,$(WAVEFRONT:.cpp=.o))

USERPARAMETER := \
\
	User/Enums/Modifier.cpp \
	User/Enums/Action.cpp \
	User/Enums/State.cpp \
	User/Enums/MouseButtons.cpp \
	User/Enums/Keys.cpp \
\
	User/Args/KeyArgs.cpp \
	User/Args/TextArgs.cpp \
	User/Args/ClickArgs.cpp \
	User/Args/DragArgs.cpp \
	User/Args/MoveArgs.cpp \
	User/Args/ScrollArgs.cpp \
\
	User/KeyState.cpp \
	User/MouseState.cpp \
	User/MouseManager.cpp \
	User/KeyBoardManager.cpp \

USERPARAMETER_SRC := $(addprefix $(DIR_SRC)/,$(USERPARAMETER))
USERPARAMETER_OBJ := $(addprefix $(DIR_OBJ)/,$(USERPARAMETER:.cpp=.o))

OTHER := \
	TimeMeasure.cpp \
	FrameTime.cpp \
	Window.cpp \
	Debug.cpp
OTHER_SRC := $(addprefix $(DIR_SRC)/,$(OTHER))
OTHER_OBJ := $(addprefix $(DIR_OBJ)/,$(OTHER:.cpp=.o))



ALL_SRC := \
	$(VALUE_TYPE_SRC) $(DISPLAY_SRC) \
	$(CONTAINER_SRC) \
	$(SHADER_SRC) $(UNIFORM_SRC) $(MULTIFORM_SRC) \
	$(BUFFER_SRC) $(ATTRIBUTE_SRC) $(TEXTURE_SRC) \
	$(INSTANCE_DATA_SRC) \
	$(POLYGON_SRC) $(POLYHEDRA_SRC) \
	$(USERPARAMETER_SRC) \
	$(OTHER_SRC)

ALL_OBJ := \
	$(VALUE_TYPE_OBJ) $(DISPLAY_OBJ) \
	$(CONTAINER_OBJ) \
	$(SHADER_OBJ) $(UNIFORM_OBJ) $(MULTIFORM_OBJ) \
	$(BUFFER_OBJ) $(ATTRIBUTE_OBJ) $(TEXTURE_OBJ) \
	$(INSTANCE_DATA_OBJ) \
	$(POLYHEDRA_MAIN_OBJ) \
	$(POLYGON_OBJ) $(POLYHEDRA_OBJ) \
	$(USERPARAMETER_OBJ) \
	$(OTHER_OBJ)





################################################################
#                  Standard Makefile Commands                  #
################################################################

all:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) $(NAME) -s

clean:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(ALL_OBJ)

aclean:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(NAME)

fclean:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) -s clean
	@$(MAKE) -s aclean

re:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) -s fclean
	@$(MAKE) -s all

are:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) -s aclean
	@$(MAKE) -s all

.PHONY: all clean aclean fclean re are

$(NAME) : $(ALL_OBJ)
	@$(call fancyNameArchivingEcho,$@)
	@$(ARCHIVER) $(NAME) $(ALL_OBJ)

################################################################






$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp
	@$(call fancyNameCompilingEcho,$@)
	@mkdir -p $(dir $@)
	@$(COMPILER) $(FLAGS) $(ARGS_INCLUDES) -c $< -o $@





################################################################

remake_VALUE_TYPE:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(VALUE_TYPE_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Display:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(DISPLAY_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Container:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(CONTAINER_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Shader:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(SHADER_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Uniform:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(UNIFORM_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Multiform:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(MULTIFORM_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Buffer:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(BUFFER_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Attribute:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(ATTRIBUTE_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Texture:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(TEXTURE_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Inst:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(INSTANCE_DATA_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Main:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(POLYHEDRA_MAIN_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_PolyHedra:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(POLYHEDRA_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_WavefRONT:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(WAVEFRONT_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_UserParameter:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(USERPARAMETER_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

remake_Other:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(OTHER_OBJ)
	@$(REMOVER) $(NAME)
	@$(MAKE) -s all

################################################################







################################################################
#                     Environment Variables                    #
################################################################

LIBRARYS = $(NAME)
INCLUDES = include/
ARGUMENTS =

ARGS_LIBRARYS = $(foreach library,$(LIBRARYS),$(library))
ARGS_INCLUDES = $(foreach include,$(INCLUDES),-I$(include))

#	shell true with '' to discard output from cloning repos
librarys:
	$(shell true '$(shell $(MAKE) repos_clone -s)')
	@echo $(LIBRARYS)

includes:
	$(shell true '$(shell $(MAKE) repos_clone -s)')
	@echo $(INCLUDES)

arguments:
	$(shell true '$(shell $(MAKE) repos_clone -s)')
	@echo $(ARGUMENTS)

.PHONY: librarys includes arguments

################################################################



REPOS_DIR := ../



################################################################
#                            OpenGL                            #
################################################################

OPENGL_REPO := $(REPOS_DIR)/OpenGL

#OPENGL_LIBRARYS = $(call repoLibrarys,$(OPENGL_REPO))
#OPENGL_INCLUDES = $(call repoIncludes,$(OPENGL_REPO))
#OPENGL_ARGUMENTS = $(call repoArguments,$(OPENGL_REPO))

OPENGL_LIBRARYS = $(OPENGL_REPO)/openGL.a
OPENGL_INCLUDES = $(OPENGL_REPO)/include

#ifeq ($(CheckOS), Windows)
#OPENGL_ARGUMENTS = -lglfw3 -lgdi32
#endif
#
#ifeq ($(CheckOS), Darwin)
#OPENGL_ARGUMENTS = -lglfw
#endif
#
#ifeq ($(CheckOS), Linux)
#OPENGL_ARGUMENTS = -lglfw
#endif

LIBRARYS += $(OPENGL_LIBRARYS)
INCLUDES += $(OPENGL_INCLUDES)
ARGUMENTS += $(OPENGL_ARGUMENTS)

################################################################





################################################################
#                         File Manager                         #
################################################################

FM_REPO := $(REPOS_DIR)/FileManager

#FM_LIBRARYS = $(call repoLibrarys,$(FM_REPO))
#FM_INCLUDES = $(call repoIncludes,$(FM_REPO))
#FM_ARGUMENTS = $(call repoArguments,$(FM_REPO))

FM_LIBRARYS = $(FM_REPO)/FileManager.a
FM_INCLUDES = $(FM_REPO)/include
FM_ARGUMENTS = 

LIBRARYS += $(FM_LIBRARYS)
INCLUDES += $(FM_INCLUDES)
ARGUMENTS += $(FM_ARGUMENTS)

################################################################


