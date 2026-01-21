


NAME := Engine.a
#COMPILER := c++ -std=c++11
COMPILER := g++ -g -std=c++11
FLAGS := -Wall -Wextra -Werror -D ENGINE_DIR='"$(shell pwd)"'



DIR_SRC := src/
DIR_OBJ := obj/



ValueType/ := \
	ValueType/Point2D.cpp \
	ValueType/Point3D.cpp \
	ValueType/Point4D.cpp \
	ValueType/Angle3D.cpp \
	ValueType/Trans3D.cpp \
	ValueType/AxisBox1D.cpp \
	ValueType/AxisBox2D.cpp \
	ValueType/AxisBox3D.cpp \
	ValueType/Ray3D.cpp \
	ValueType/Undex3D.cpp \
	ValueType/UndexBox3D.cpp \
	ValueType/UndexLoop3D.cpp \
	ValueType/Bool3D.cpp \
	ValueType/Matrix3x3.cpp \
	ValueType/DepthFactors.cpp \
	ValueType/Depth.cpp \
	ValueType/Range.cpp \
	ValueType/LInter.cpp \
	ValueType/ColorF4.cpp \
	ValueType/LightBase.cpp \
	ValueType/LightSolar.cpp \
	ValueType/LightSpot.cpp \
	DataShow.cpp
ValueType/_SRC := $(addprefix $(DIR_SRC)/,$(ValueType/))
ValueType/_OBJ := $(addprefix $(DIR_OBJ)/,$(ValueType/:.cpp=.o))

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
	Graphics/Uniform/Base/Float3x3.cpp \
	Graphics/Uniform/Base/UIntN.cpp \
	Graphics/Uniform/Base/UInt1.cpp \
\
	Graphics/Uniform/Point2D.cpp \
	Graphics/Uniform/Point3D.cpp \
	Graphics/Uniform/ColorF4.cpp \
	Graphics/Uniform/Matrix3x3.cpp \
	Graphics/Uniform/DepthFactors.cpp \
\
	Graphics/Uniform/Angle3D.cpp \
	Graphics/Uniform/Trans3D.cpp \
	Graphics/Uniform/Range.cpp \
	Graphics/Uniform/Depth.cpp \
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

#	Graphics/Buffer/BaseBufferArray.cpp
#	Graphics/Buffer/BaseBuffer.cpp
BUFFER := \
	Graphics/Buffer/Base.cpp \
	Graphics/Buffer/Attribute.cpp \
	Graphics/Buffer/ArrayBase.cpp
BUFFER_SRC := $(addprefix $(DIR_SRC)/,$(BUFFER))
BUFFER_OBJ := $(addprefix $(DIR_OBJ)/,$(BUFFER:.cpp=.o))

ATTRIBUTE := \
	Graphics/Attribute/Base/AttributeLocation.cpp \
	Graphics/Attribute/Base/AttributeBase.cpp \
	Graphics/Attribute/Base/FloatN.cpp \
\
	Graphics/Attribute/Point3D.cpp \
	Graphics/Attribute/Angle3D.cpp \
	Graphics/Attribute/Trans3D.cpp \
	Graphics/Attribute/Point2D.cpp \
	Graphics/Attribute/Point4D.cpp \
	Graphics/Attribute/ColorF4.cpp
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

WAVEFORM := \
	Waveform/OBJ.cpp \
	Waveform/OBJ_Main.cpp \
	Waveform/OBJ_3D_BufferArray.cpp \
	Waveform/OBJ_3D_Shader.cpp \
	Waveform/MTL.cpp
WAVEFORM_SRC := $(addprefix $(DIR_SRC)/,$(WAVEFORM))
WAVEFORM_OBJ := $(addprefix $(DIR_OBJ)/,$(WAVEFORM:.cpp=.o))

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
	$(ValueType/_SRC) $(DISPLAY_SRC)\
	$(CONTAINER_SRC)\
	$(SHADER_SRC) $(UNIFORM_SRC) $(MULTIFORM_SRC)\
	$(BUFFER_SRC) $(ATTRIBUTE_SRC) $(TEXTURE_SRC)\
	$(INSTANCE_DATA_SRC)\
	$(POLYHEDRA_MAIN_SRC)\
	$(POLYHEDRA_SRC)\
	$(WAVEFORM_SRC)\
	$(USERPARAMETER_SRC)\
	$(OTHER_SRC)

ALL_OBJ := \
	$(ValueType/_OBJ) $(DISPLAY_OBJ)\
	$(CONTAINER_OBJ)\
	$(SHADER_OBJ) $(UNIFORM_OBJ) $(MULTIFORM_OBJ)\
	$(BUFFER_OBJ) $(ATTRIBUTE_OBJ) $(TEXTURE_OBJ)\
	$(INSTANCE_DATA_OBJ)\
	$(POLYHEDRA_MAIN_OBJ)\
	$(POLYHEDRA_OBJ)\
	$(WAVEFORM_OBJ)\
	$(USERPARAMETER_OBJ)\
	$(OTHER_OBJ)

#	these makefiles suck
#	currenty it allways makes stuff
#	instead of checking if it needs to be updatd
#	and then only making that stuff
#	
#	should I check for the .a of repos ?
#	repos already have rules for _clone and _rm
#	have one for making librarys ?
#	for that I first need to check if the repo even exists
#	else it needs to be cloned
#
#	so when comliling
#	check for repo(s)
#		if isnt found : clone
#	check for librarys
#		if isnt found : compile
#
#	how to compile librarys ?
#	they are only required by the findal Executable
#	but the actual file target is different by then because paths gets changed
#	so just have the all target compile the current library
#	and also all the sub librarys
#	still leave checking for librarys before compiling
#
#	the library target is gotten from the repos
#	this causes an error when the repos dont exist
#	so have a check that checks if the directory exists
#	else leave empty ?
#



################################################################
#                  Standard Makefile Commands                  #
################################################################

# having repos as a dependency allways does this stuff
all:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@$(MAKE) $(NAME) -s

clean:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(ALL_OBJ)

fclean:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@$(MAKE) -s clean
	@rm -f $(NAME)

re:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all clean fclean re

# I allways thought that NAME was supposed to be the default ?
# pretty sure its just so the Makefile checks if it needs to be updated
$(NAME) : $(ALL_OBJ)
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@ar -rcs $(NAME) $(ALL_OBJ)

################################################################







################################################################

remake_ValueType/:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(ValueType/_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Display:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(DISPLAY_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Container:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(CONTAINER_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Shader:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(SHADER_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Uniform:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(UNIFORM_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Multiform:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(MULTIFORM_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Buffer:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(BUFFER_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Attribute:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(ATTRIBUTE_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Texture:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(TEXTURE_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Inst:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(INSTANCE_DATA_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Main:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(POLYHEDRA_MAIN_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_PolyHedra:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(POLYHEDRA_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Waveform:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(WAVEFORM_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_UserParameter:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(USERPARAMETER_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

remake_Other:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(OTHER_OBJ)
	@rm -f $(NAME)
	@$(MAKE) -s all

################################################################





include fancy.mk
FANCY_NAME := Engine





$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp
	@$(call fancyEcho,$(FANCY_NAME),Compiling,$@)
	@mkdir -p $(dir $@)
	@$(COMPILER) $(FLAGS) $(ARGS_INCLUDES) -c $< -o $@





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
OPENGL_INCLUDES = $(OPENGL_REPO)/../

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


