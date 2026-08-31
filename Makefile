
NAME := Engine.a

COMPILER := g++ -g -std=c++11
FLAGS := -Wall -Wextra -Werror -D ENGINE_DIR='"$(shell pwd)"'
ARCHIVER := ar -rcs
REMOVER := rm -f

FANCY_NAME := Engine
include fancy.mk





################################################################

DIR_SRC := src/
DIR_OBJ := obj/

################################################################

DISPLAY := \
	Display/AspectRatio.cpp \
	Display/PixelSize.cpp \
	Display/DisplaySize.cpp \
	Display/PixelPosition.cpp \
	Display/DisplayPosition.cpp \
	Display/NormalPosition.cpp \

DISPLAY_SRC := $(addprefix $(DIR_SRC)/,$(DISPLAY))
DISPLAY_OBJ := $(addprefix $(DIR_OBJ)/,$(DISPLAY:.cpp=.o))

################################################################

INSTANCE_DATA := \
\
	Instance/Basic2D/Data.cpp \
	Instance/Basic2D/Layout.cpp \
\
	Instance/Basic3D/Data.cpp \
	Instance/Basic3D/Layout.cpp \

INSTANCE_DATA_SRC := $(addprefix $(DIR_SRC)/,$(INSTANCE_DATA))
INSTANCE_DATA_OBJ := $(addprefix $(DIR_OBJ)/,$(INSTANCE_DATA:.cpp=.o))

################################################################

POLYGON := \
	PolyGon/PolyGon.cpp \
\
	PolyGon/Graphics/Full/Main/Data.cpp \
	PolyGon/Graphics/Full/Main/Layout.cpp \
	PolyGon/Graphics/Full/ShaderLayout.cpp \
\
	PolyGon/Graphics/Wire/Main/Layout.cpp \
	PolyGon/Graphics/Wire/ShaderLayout.cpp \
\
	PolyGon/InstanceManager.cpp \
	PolyGon/ObjectData.cpp \
	PolyGon/Manager.cpp \
	PolyGon/Object.cpp \

POLYGON_SRC := $(addprefix $(DIR_SRC)/,$(POLYGON))
POLYGON_OBJ := $(addprefix $(DIR_OBJ)/,$(POLYGON:.cpp=.o))

################################################################

POLYHEDRA := \
	PolyHedra/Data.cpp \
	PolyHedra/PolyHedra.cpp \
	PolyHedra/FileCollection.cpp \
	PolyHedra/Parser.cpp \
	PolyHedra/Generate.cpp \
\
	PolyHedra/Skin/Data.cpp \
	PolyHedra/Skin/Skin.cpp \
	PolyHedra/Skin/Parsing.cpp \
\

POLYHEDRA_SRC := $(addprefix $(DIR_SRC)/,$(POLYHEDRA))
POLYHEDRA_OBJ := $(addprefix $(DIR_OBJ)/,$(POLYHEDRA:.cpp=.o))

################################################################

WAVEFRONT := \
	Wavefront/OBJ.cpp \
	Wavefront/Main/Data.cpp \
	Wavefront/Main/Buffer.cpp \
	Wavefront/Simple3D/BufferArray.cpp \
	Wavefront/Simple3D/Shader.cpp \
	Wavefront/MTL.cpp
WAVEFRONT_SRC := $(addprefix $(DIR_SRC)/,$(WAVEFRONT))
WAVEFRONT_OBJ := $(addprefix $(DIR_OBJ)/,$(WAVEFRONT:.cpp=.o))

################################################################

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

################################################################

OTHER := \
	FrameTime.cpp \
	Window.cpp \
	Debug.cpp
OTHER_SRC := $(addprefix $(DIR_SRC)/,$(OTHER))
OTHER_OBJ := $(addprefix $(DIR_OBJ)/,$(OTHER:.cpp=.o))

################################################################

ALL_SRC := \
	$(DISPLAY_SRC) \
	$(INSTANCE_DATA_SRC) \
	$(POLYGON_SRC) $(POLYHEDRA_SRC) \
	$(USERPARAMETER_SRC) \
	$(OTHER_SRC)

ALL_OBJ := \
	$(DISPLAY_OBJ) \
	$(INSTANCE_DATA_OBJ) \
	$(POLYHEDRA_MAIN_OBJ) \
	$(POLYGON_OBJ) $(POLYHEDRA_OBJ) \
	$(USERPARAMETER_OBJ) \
	$(OTHER_OBJ)

################################################################





################################################################
#                  Standard Makefile Commands                  #
################################################################

all:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) $(NAME) -s
	@$(MAKE) -C ValueType/ -s all
	@$(MAKE) -C Generics/ -s all
	@$(MAKE) -C Graphics/ -s all

clean:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(ALL_OBJ)
	@$(MAKE) -C ValueType/ -s clean
	@$(MAKE) -C Generics/ -s clean
	@$(MAKE) -C Graphics/ -s clean

aclean:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(NAME)
	@$(MAKE) -C ValueType/ -s aclean
	@$(MAKE) -C Generics/ -s aclean
	@$(MAKE) -C Graphics/ -s aclean

fclean:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) -s clean
	@$(MAKE) -s aclean
	@$(MAKE) -C ValueType/ -s fclean
	@$(MAKE) -C Generics/ -s fclean
	@$(MAKE) -C Graphics/ -s fclean

re:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) -s fclean
	@$(MAKE) -s all
	@$(MAKE) -C ValueType/ -s re
	@$(MAKE) -C Generics/ -s re
	@$(MAKE) -C Graphics/ -s re

are:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) -s aclean
	@$(MAKE) -s all
	@$(MAKE) -C ValueType/ -s are
	@$(MAKE) -C Generics/ -s are
	@$(MAKE) -C Graphics/ -s are

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

include ValueType.mk
include Generics.mk
include Graphics.mk

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



################################################################
#                            repos                             #
################################################################

REPOS_DIR := ../

include OpenGL.mk
include FileManager.mk

################################################################
