


NAME := Engine.a
COMPILER := c++ -std=c++11
FLAGS := -Wall -Wextra -Werror -D ENGINE_DIR='"$(shell pwd)"'



FILES_SRC_NAMES := \
\
	DataStruct/Point3D.cpp \
	DataStruct/Angle3D.cpp \
	DataStruct/Trans3D.cpp \
	DataStruct/Undex3D.cpp \
	DataStruct/AxisBox3D.cpp \
	DataStruct/Point2D.cpp \
	DataStruct/SizeRatio2D.cpp \
	DataStruct/Range.cpp \
	DataStruct/LInter.cpp \
	DataStruct/DepthFactors.cpp \
	DataStruct/Point4D.cpp \
	DataStruct/Color.cpp \
	DataStruct/Depth.cpp \
	DataStruct/LightBase.cpp \
	DataStruct/LightSolar.cpp \
	DataStruct/LightSpot.cpp \
	DataStruct/Ray3D.cpp \
	DataStruct/Matrix3x3.cpp \
	DataShow.cpp \
\
	Miscellaneous/Container/Behaviour.cpp \
\
	Graphics/Shader/Code.cpp \
	Graphics/Shader/Base.cpp \
\
	Graphics/Uniform/Base/Base.cpp \
	Graphics/Uniform/Base/FloatN.cpp \
	Graphics/Uniform/Base/Float1.cpp \
	Graphics/Uniform/Base/Float2.cpp \
	Graphics/Uniform/Base/Float3.cpp \
	Graphics/Uniform/Base/UIntN.cpp \
	Graphics/Uniform/Base/UInt1.cpp \
\
	Graphics/Uniform/Point3D.cpp \
	Graphics/Uniform/Angle3D.cpp \
	Graphics/Uniform/Trans3D.cpp \
	Graphics/Uniform/Point2D.cpp \
	Graphics/Uniform/SizeRatio2D.cpp \
	Graphics/Uniform/DepthFactors.cpp \
	Graphics/Uniform/Range.cpp \
	Graphics/Uniform/Depth.cpp \
	Graphics/Uniform/LInter.cpp \
	Graphics/Uniform/Color.cpp \
	Graphics/Uniform/LightBase.cpp \
	Graphics/Uniform/LightSolar.cpp \
	Graphics/Uniform/LightSpot.cpp \
\
	Graphics/Multiform/Base/Base.cpp \
	Graphics/Multiform/Trans3D.cpp \
	Graphics/Multiform/SizeRatio2D.cpp \
	Graphics/Multiform/DepthFactors.cpp \
	Graphics/Multiform/Range.cpp \
	Graphics/Multiform/Depth.cpp \
	Graphics/Multiform/LInter.cpp \
	Graphics/Multiform/Color.cpp \
\
	Graphics/Buffer/BaseBufferArray.cpp \
	Graphics/Buffer/BaseBuffer.cpp \
\
	Graphics/Attribute/Base/AttributeLocation.cpp \
	Graphics/Attribute/Base/AttributeBase.cpp \
	Graphics/Attribute/Base/FloatN.cpp \
\
	Graphics/Attribute/Point3D.cpp \
	Graphics/Attribute/Angle3D.cpp \
	Graphics/Attribute/Trans3D.cpp \
	Graphics/Attribute/Point2D.cpp \
	Graphics/Attribute/Point4D.cpp \
	Graphics/Attribute/Color.cpp \
\
	Graphics/Texture/Base.cpp \
	Graphics/Texture/2DArray.cpp \
	Graphics/Texture/Generate.cpp \
\
	DataStruct/Inst/Simple3D/Simple3D_InstData.cpp \
	DataStruct/Inst/Simple3D/Simple3D_InstAttrib.cpp \
	DataStruct/Inst/Simple3D/Simple3D_InstBuffer.cpp \
\
	DataStruct/Inst/Physics3D/Physics3D_InstData.cpp \
	DataStruct/Inst/Physics3D/Physics3D_InstAttrib.cpp \
	DataStruct/Inst/Physics3D/Physics3D_InstBuffer.cpp \
\
	DataStruct/Main/PolyHedra/PolyHedra_MainData.cpp \
	DataStruct/Main/PolyHedra/PolyHedra_MainAttrib.cpp \
	DataStruct/Main/PolyHedra/PolyHedra_MainBuffer.cpp \
	DataStruct/Full/PolyHedra_3D/PolyHedra_3D_BufferArray.cpp \
	DataStruct/Full/PolyHedra_3D/PolyHedra_3D_Instances.cpp \
	DataStruct/Full/PolyHedra_3D/PolyHedra_3D_Shader.cpp \
\
	DataStruct/Main/Waveform/OBJ.cpp \
	DataStruct/Main/Waveform/OBJ_Main.cpp \
	DataStruct/Main/Waveform/OBJ_3D_BufferArray.cpp \
	DataStruct/Main/Waveform/OBJ_3D_Shader.cpp \
	DataStruct/Main/Waveform/MTL.cpp \
\
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
	TimeMeasure.cpp \
\
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
	UserParameter/Mouse/Position.cpp \
	UserParameter/Mouse/Click.cpp \
	UserParameter/Mouse/Scroll.cpp \
\
	Window.cpp \
	Debug.cpp

DIR_SRC := src/
DIR_OBJ := obj/

FILES_SRC := $(addprefix $(DIR_SRC)/,$(FILES_SRC_NAMES))
FILES_OBJ := $(addprefix $(DIR_OBJ)/,$(FILES_SRC_NAMES:.cpp=.o))



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
	@$(MAKE) repos_clone -s
	@$(MAKE) $(NAME) -s

clean:
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@rm -f $(FILES_OBJ)

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
$(NAME) : $(FILES_OBJ)
	@$(call fancyEcho,$(FANCY_NAME),Target,$@)
	@ar -rcs $(NAME) $(FILES_OBJ)

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

test:
	@echo '$(shell $(MAKE) includes -s)'

.PHONY: test

################################################################



include repos.mk



################################################################
#                            OpenGL                            #
################################################################

OPENGL_REPO := $(REPOS_DIR)/OpenGL

REPOS_STATIC += $(OPENGL_REPO)

#OPENGL_LIBRARYS = $(call repoLibrarys,$(OPENGL_REPO))
#OPENGL_INCLUDES = $(call repoIncludes,$(OPENGL_REPO))
#OPENGL_ARGUMENTS = $(call repoArguments,$(OPENGL_REPO))

OPENGL_LIBRARYS = $(OPENGL_REPO)/openGL.a
OPENGL_INCLUDES = $(OPENGL_REPO)/../

ifeq ($(CheckOS), Windows)
OPENGL_ARGUMENTS = -lglfw3 -lgdi32
endif

ifeq ($(CheckOS), Darwin)
OPENGL_ARGUMENTS = -lglfw
endif

LIBRARYS += $(OPENGL_LIBRARYS)
INCLUDES += $(OPENGL_INCLUDES)
ARGUMENTS += $(OPENGL_ARGUMENTS)

$(OPENGL_LIBRARYS) : $(OPENGL_REPO)
	$(MAKE) -C $(OPENGL_REPO) $(@:$(OPENGL_REPO)/%=%) -s

################################################################





################################################################
#                         File Manager                         #
################################################################

FM_HTTPS := https://github.com/StaubMaster/CPP-FileManager.git
FM_REPO := $(REPOS_DIR)/FileManager

REPOS_DYNAMIC += $(FM_REPO)

#FM_LIBRARYS = $(call repoLibrarys,$(FM_REPO))
#FM_INCLUDES = $(call repoIncludes,$(FM_REPO))
#FM_ARGUMENTS = $(call repoArguments,$(FM_REPO))

FM_LIBRARYS = $(FM_REPO)/FileManager.a
FM_INCLUDES = $(FM_REPO)/include
FM_ARGUMENTS = 

LIBRARYS += $(FM_LIBRARYS)
INCLUDES += $(FM_INCLUDES)
ARGUMENTS += $(FM_ARGUMENTS)

$(FM_REPO) :
	git clone $(FM_HTTPS) $(FM_REPO) -q

$(FM_LIBRARYS) : $(FM_REPO)
	$(MAKE) -C $(FM_REPO) $(@:$(FM_REPO)/%=%) -s

################################################################


