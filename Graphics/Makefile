
NAME := Graphics.a

COMPILER := g++ -g -std=c++11
FLAGS := -Wall -Wextra -Werror
ARCHIVER := ar -rcs
REMOVER := rm -f

FANCY_NAME := Engine/Graphics
include ../fancy.mk

################################################################





################################################################

DIR_SRC := src/
DIR_OBJ := obj/

################################################################

SHADER := \
	Graphics/Shader/Code.cpp \
	Graphics/Shader/Base.cpp \
	Graphics/Shader/_Log.cpp \
	Graphics/ShaderBlockBinding.cpp \

SHADER_SRC := $(addprefix $(DIR_SRC)/,$(SHADER))
SHADER_OBJ := $(addprefix $(DIR_OBJ)/,$(SHADER:.cpp=.o))

################################################################

UNIFORM := \
	Graphics/Uniform/General/Base.cpp \
	Graphics/Uniform/General/FloatNBase.cpp \
	Graphics/Uniform/General/FloatNTypeBase.cpp \
	Graphics/Uniform/General/UIntNBase.cpp \
	Graphics/Uniform/General/UIntNTypeBase.cpp \
\
	Graphics/Uniform/General/Layout.cpp \
	Graphics/Uniform/General/Buffer.cpp \
\
	Graphics/Uniform/Trans2D.cpp \
	Graphics/Uniform/Trans3D.cpp \
\
	Graphics/Uniform/Depth.cpp \
	Graphics/Uniform/RangeF.cpp \
	Graphics/Uniform/LInter.cpp \
\
	Graphics/Uniform/Light/Base.cpp \
	Graphics/Uniform/Light/Point.cpp \
	Graphics/Uniform/Light/Direction.cpp \
	Graphics/Uniform/Light/Spot.cpp \
\
	Graphics/Uniform/AspectRatio.cpp \
	Graphics/Uniform/PixelSize.cpp \
	Graphics/Uniform/DisplaySize.cpp \
\
	Graphics/Uniform/_Log.cpp

UNIFORM_SRC := $(addprefix $(DIR_SRC)/,$(UNIFORM))
UNIFORM_OBJ := $(addprefix $(DIR_OBJ)/,$(UNIFORM:.cpp=.o))

################################################################

MULTIFORM := \
	Graphics/Multiform/General/Base.cpp \
	Graphics/Multiform/General/Layout.cpp \
	Graphics/Multiform/General/Buffer.cpp \

MULTIFORM_SRC := $(addprefix $(DIR_SRC)/,$(MULTIFORM))
MULTIFORM_OBJ := $(addprefix $(DIR_OBJ)/,$(MULTIFORM:.cpp=.o))

################################################################

BUFFER := \
	Graphics/Buffer/Base.cpp \
	Graphics/Buffer/Array.cpp \
	Graphics/Buffer/Element.cpp \
	Graphics/Buffer/Uniform.cpp \
	Graphics/Buffer/_Log.cpp \
\
	Graphics/VertexArray/Base.cpp \
	Graphics/VertexArray/Main.cpp \
	Graphics/VertexArray/MainInst.cpp \
	Graphics/VertexArray/MainElemInst.cpp \
	Graphics/VertexArray/Multi.cpp \

BUFFER_SRC := $(addprefix $(DIR_SRC)/,$(BUFFER))
BUFFER_OBJ := $(addprefix $(DIR_OBJ)/,$(BUFFER:.cpp=.o))

################################################################

ATTRIBUTE := \
	Graphics/Attribute/General/Base.cpp \
	Graphics/Attribute/General/FloatNBase.cpp \
	Graphics/Attribute/General/UIntNBase.cpp \
	Graphics/Attribute/General/IntNBase.cpp \
\
	Graphics/Attribute/BoxF2.cpp \
\
	Graphics/Attribute/Layout.cpp \
	Graphics/Attribute/_Log.cpp

ATTRIBUTE_SRC := $(addprefix $(DIR_SRC)/,$(ATTRIBUTE))
ATTRIBUTE_OBJ := $(addprefix $(DIR_OBJ)/,$(ATTRIBUTE:.cpp=.o))

################################################################

TEXTURE := \
	Graphics/Texture/Base.cpp \
	Graphics/Texture/Array2D.cpp \
	Graphics/Texture/Generate.cpp
TEXTURE_SRC := $(addprefix $(DIR_SRC)/,$(TEXTURE))
TEXTURE_OBJ := $(addprefix $(DIR_OBJ)/,$(TEXTURE:.cpp=.o))

################################################################

PADDED_BLOCK := \
	Graphics/PaddedBlock/LightBase.cpp \
	Graphics/PaddedBlock/LightDirection.cpp \
	Graphics/PaddedBlock/LightPoint.cpp \
	Graphics/PaddedBlock/LightSpot.cpp \

PADDED_BLOCK_SRC := $(addprefix $(DIR_SRC)/,$(PADDED_BLOCK))
PADDED_BLOCK_OBJ := $(addprefix $(DIR_OBJ)/,$(PADDED_BLOCK:.cpp=.o))

################################################################

ALL_SRC := \
	$(SHADER_SRC) $(UNIFORM_SRC) $(MULTIFORM_SRC) \
	$(BUFFER_SRC) $(ATTRIBUTE_SRC) $(TEXTURE_SRC) \
	$(PADDED_BLOCK_SRC) \

ALL_OBJ := \
	$(SHADER_OBJ) $(UNIFORM_OBJ) $(MULTIFORM_OBJ) \
	$(BUFFER_OBJ) $(ATTRIBUTE_OBJ) $(TEXTURE_OBJ) \
	$(PADDED_BLOCK_OBJ) \

################################################################





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





################################################################

LIBRARYS = $(NAME)
INCLUDES = include/ ../include ../ValueType/include ../Generics/include
ARGUMENTS =

ARGS_LIBRARYS = $(foreach library,$(LIBRARYS),$(library))
ARGS_INCLUDES = $(foreach include,$(INCLUDES),-I$(include))

################################################################



REPOS_DIR := ../../



################################################################
#                            OpenGL                            #
################################################################

OPENGL_REPO := $(REPOS_DIR)/OpenGL

OPENGL_LIBRARYS = $(OPENGL_REPO)/openGL.a
OPENGL_INCLUDES = $(OPENGL_REPO)/include

LIBRARYS += $(OPENGL_LIBRARYS)
INCLUDES += $(OPENGL_INCLUDES)
ARGUMENTS += $(OPENGL_ARGUMENTS)

################################################################





################################################################
#                         File Manager                         #
################################################################

FM_REPO := $(REPOS_DIR)/FileManager

FM_LIBRARYS = $(FM_REPO)/FileManager.a
FM_INCLUDES = $(FM_REPO)/include
FM_ARGUMENTS = 

LIBRARYS += $(FM_LIBRARYS)
INCLUDES += $(FM_INCLUDES)
ARGUMENTS += $(FM_ARGUMENTS)

################################################################
