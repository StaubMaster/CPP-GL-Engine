
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
	ValueType/Bool3D.cpp \
	ValueType/Undex2D.cpp \
	ValueType/UndexBox2D.cpp \
	ValueType/UndexLoop2D.cpp \
	ValueType/Undex3D.cpp \
	ValueType/UndexBox3D.cpp \
	ValueType/UndexLoop3D.cpp \
	ValueType/Point2D.cpp \
	ValueType/Point3D.cpp \
	ValueType/Point4D.cpp \
	ValueType/AxisBox1D.cpp \
	ValueType/AxisBox2D.cpp \
	ValueType/AxisBox3D.cpp \
	ValueType/Ray2D.cpp \
	ValueType/Ray3D.cpp \
	ValueType/Matrix2x2.cpp \
	ValueType/Matrix3x3.cpp \
	ValueType/Angle.cpp \
	ValueType/Angle2D.cpp \
	ValueType/Angle3D.cpp \
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
	DataShow.cpp
VALUE_TYPE_SRC := $(addprefix $(DIR_SRC)/,$(VALUE_TYPE))
VALUE_TYPE_OBJ := $(addprefix $(DIR_OBJ)/,$(VALUE_TYPE:.cpp=.o))

DISPLAY := \
	Display/AbsNormal2D.cpp \
	Display/RelNormal2D.cpp \
	Display/PixelCoord2D.cpp \
	Display/ScreenCoord2D.cpp \
	Display/SizeRatio2D.cpp \
	Display/WindowBufferSize2D.cpp
DISPLAY_SRC := $(addprefix $(DIR_SRC)/,$(DISPLAY))
DISPLAY_OBJ := $(addprefix $(DIR_OBJ)/,$(DISPLAY:.cpp=.o))

CONTAINER := \
	Miscellaneous/Container/Behaviour.cpp \
	Miscellaneous/Container/BehaviourShow.cpp
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
	Graphics/Uniform/Base/UIntN.cpp \
	Graphics/Uniform/Base/UInt1.cpp \
\
	Graphics/Uniform/ColorF4.cpp \
	Graphics/Uniform/Point2D.cpp \
	Graphics/Uniform/Point3D.cpp \
	Graphics/Uniform/Matrix2x2.cpp \
	Graphics/Uniform/Matrix3x3.cpp \
	Graphics/Uniform/Angle.cpp \
	Graphics/Uniform/Angle2D.cpp \
	Graphics/Uniform/Angle3D.cpp \
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
	Graphics/Uniform/SizeRatio2D.cpp \
	Graphics/Uniform/WindowBufferSize2D.cpp
UNIFORM_SRC := $(addprefix $(DIR_SRC)/,$(UNIFORM))
UNIFORM_OBJ := $(addprefix $(DIR_OBJ)/,$(UNIFORM:.cpp=.o))

MULTIFORM := \
	Graphics/Multiform/Base/Base.cpp \
	Graphics/Multiform/Trans3D.cpp \
	Graphics/Multiform/DepthFactors.cpp \
	Graphics/Multiform/Range.cpp \
	Graphics/Multiform/Depth.cpp \
	Graphics/Multiform/LInter.cpp \
	Graphics/Multiform/ColorF4.cpp \
	Graphics/Multiform/SizeRatio2D.cpp \
	Graphics/Multiform/WindowBufferSize2D.cpp
MULTIFORM_SRC := $(addprefix $(DIR_SRC)/,$(MULTIFORM))
MULTIFORM_OBJ := $(addprefix $(DIR_OBJ)/,$(MULTIFORM:.cpp=.o))

BUFFER := \
	Graphics/Buffer/Base.cpp \
	Graphics/Buffer/Attribute.cpp \
	Graphics/Buffer/MainInst.cpp \
	Graphics/Buffer/ArrayBase.cpp
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
\
	Graphics/Attribute/Point2D.cpp \
	Graphics/Attribute/Point3D.cpp \
	Graphics/Attribute/Point4D.cpp \
	Graphics/Attribute/Angle2D.cpp \
	Graphics/Attribute/Angle3D.cpp \
	Graphics/Attribute/Trans2D.cpp \
	Graphics/Attribute/Trans3D.cpp \
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
	InstanceData/Simple3D/Data.cpp \
	InstanceData/Simple3D/Buffer.cpp \
\
	InstanceData/Physics3D/Data.cpp \
	InstanceData/Physics3D/Buffer.cpp
INSTANCE_DATA_SRC := $(addprefix $(DIR_SRC)/,$(INSTANCE_DATA))
INSTANCE_DATA_OBJ := $(addprefix $(DIR_OBJ)/,$(INSTANCE_DATA:.cpp=.o))

POLYHEDRA := \
	PolyHedra/PolyHedra.cpp \
	PolyHedra/Data.cpp \
	PolyHedra/Template.cpp \
	PolyHedra/Parsing.cpp \
	PolyHedra/Generate.cpp \
\
	PolyHedra/Skin/SkinBase.cpp \
	PolyHedra/Skin/Skin2DA.cpp \
	PolyHedra/Skin/Skin2D_Data.cpp \
\
	PolyHedra/Main/Data.cpp \
	PolyHedra/Main/Buffer.cpp \
	PolyHedra/Simple3D/Shader.cpp \
	PolyHedra/Simple3D/BufferArray.cpp \
	PolyHedra/Simple3D/ManagerSingle.cpp \
	PolyHedra/Simple3D/ManagerMulti.cpp
POLYHEDRA_SRC := $(addprefix $(DIR_SRC)/,$(POLYHEDRA))
POLYHEDRA_OBJ := $(addprefix $(DIR_OBJ)/,$(POLYHEDRA:.cpp=.o))

POLYHEDRA_MAIN := 
POLYHEDRA_MAIN_SRC := $(addprefix $(DIR_SRC)/,$(POLYHEDRA_MAIN))
POLYHEDRA_MAIN_OBJ := $(addprefix $(DIR_OBJ)/,$(POLYHEDRA_MAIN:.cpp=.o))

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
	UserParameter/Haptic/Code.cpp \
	UserParameter/Haptic/Action.cpp \
	UserParameter/Haptic/Modifier.cpp \
	UserParameter/Haptic/State.cpp \
\
	UserParameter/KeyBoard/KeyRange1.cpp \
	UserParameter/KeyBoard/KeyRange2.cpp \
	UserParameter/KeyBoard/Key.cpp \
	UserParameter/KeyBoard/Text.cpp \
	UserParameter/KeyBoard/EventManager.cpp \
\
	UserParameter/Mouse/ButtonRange.cpp \
	UserParameter/Mouse/ButtonData.cpp \
	UserParameter/Mouse/Position.cpp \
	UserParameter/Mouse/Click.cpp \
	UserParameter/Mouse/Scroll.cpp \
	UserParameter/Mouse/EventManager.cpp
USERPARAMETER_SRC := $(addprefix $(DIR_SRC)/,$(USERPARAMETER))
USERPARAMETER_OBJ := $(addprefix $(DIR_OBJ)/,$(USERPARAMETER:.cpp=.o))

OTHER := \
	TimeMeasure.cpp \
	Window.cpp \
	Debug.cpp
OTHER_SRC := $(addprefix $(DIR_SRC)/,$(OTHER))
OTHER_OBJ := $(addprefix $(DIR_OBJ)/,$(OTHER:.cpp=.o))



ALL_SRC := \
	$(VALUE_TYPE_SRC) $(DISPLAY_SRC)\
	$(CONTAINER_SRC)\
	$(SHADER_SRC) $(UNIFORM_SRC) $(MULTIFORM_SRC)\
	$(BUFFER_SRC) $(ATTRIBUTE_SRC) $(TEXTURE_SRC)\
	$(INSTANCE_DATA_SRC)\
	$(POLYHEDRA_MAIN_SRC)\
	$(POLYHEDRA_SRC)\
	$(WAVEFRONT_SRC)\
	$(USERPARAMETER_SRC)\
	$(OTHER_SRC)

ALL_OBJ := \
	$(VALUE_TYPE_OBJ) $(DISPLAY_OBJ)\
	$(CONTAINER_OBJ)\
	$(SHADER_OBJ) $(UNIFORM_OBJ) $(MULTIFORM_OBJ)\
	$(BUFFER_OBJ) $(ATTRIBUTE_OBJ) $(TEXTURE_OBJ)\
	$(INSTANCE_DATA_OBJ)\
	$(POLYHEDRA_MAIN_OBJ)\
	$(POLYHEDRA_OBJ)\
	$(WAVEFRONT_OBJ)\
	$(USERPARAMETER_OBJ)\
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

fclean:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) -s clean
	@$(REMOVER) $(NAME)

re:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all clean fclean re

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


