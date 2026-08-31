
NAME := ValueType.a

COMPILER := g++ -g -std=c++11
FLAGS := -Wall -Wextra -Werror
ARCHIVER := ar -rcs
REMOVER := rm -f

FANCY_NAME := Engine/ValueType
include ../fancy.mk

################################################################





################################################################

DIR_SRC := src/
DIR_OBJ := obj/

################################################################

FILES := \
	ValueType/Bool/2.cpp \
	ValueType/Bool/3.cpp \
	ValueType/Bool/4.cpp \
\
	ValueType/Vector/F2.cpp \
	ValueType/Vector/F3.cpp \
	ValueType/Vector/F4.cpp \
	ValueType/Vector/U2.cpp \
	ValueType/Vector/U3.cpp \
	ValueType/Vector/I2.cpp \
	ValueType/Vector/I3.cpp \
\
	ValueType/Box/F1.cpp \
	ValueType/Box/F2.cpp \
	ValueType/Box/F3.cpp \
	ValueType/Box/U2.cpp \
	ValueType/Box/U3.cpp \
	ValueType/Box/I2.cpp \
	ValueType/Box/I3.cpp \
\
	ValueType/Loop/U2.cpp \
	ValueType/Loop/U3.cpp \
	ValueType/Loop/I2.cpp \
	ValueType/Loop/I3.cpp \
\
	ValueType/Line/F2.cpp \
	ValueType/Line/F3.cpp \
\
	ValueType/Ray/F2.cpp \
	ValueType/Ray/F3.cpp \
	ValueType/Ray/Hit/F3.cpp \
\
	ValueType/Matrix/2x2.cpp \
	ValueType/Matrix/3x3.cpp \
	ValueType/Matrix/4x4.cpp \
\
	ValueType/Trans/2D.cpp \
	ValueType/Trans/3D.cpp \
\
	ValueType/Light/Base.cpp \
	ValueType/Light/Point.cpp \
	ValueType/Light/Direction.cpp \
	ValueType/Light/Spot.cpp \
\
	ValueType/View/2D.cpp \
	ValueType/View/3D.cpp \
\
	ValueType/Color/U4.cpp \
	ValueType/Color/F4.cpp \
\
	ValueType/Undex.cpp \
	ValueType/Angle.cpp \
	ValueType/EulerAngle3D.cpp \
	ValueType/DepthFactors.cpp \
	ValueType/Depth.cpp \
	ValueType/RangeF.cpp \
	ValueType/LInter.cpp \
	ValueType/TriangleF3.cpp \
	ValueType/NormalPlaneF3.cpp \
	ValueType/InteractF3.cpp \
	ValueType/Intersect.cpp \
	ValueType/_Show.cpp

FILES_SRC := $(addprefix $(DIR_SRC)/,$(FILES))
FILES_OBJ := $(addprefix $(DIR_OBJ)/,$(FILES:.cpp=.o))

################################################################





################################################################
#                  Standard Makefile Commands                  #
################################################################

all:
	@$(call fancyNameTargetEcho,$@)
	@$(MAKE) $(NAME) -s

clean:
	@$(call fancyNameTargetEcho,$@)
	@$(REMOVER) $(FILES_OBJ)

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

$(NAME) : $(FILES_OBJ)
	@$(call fancyNameArchivingEcho,$@)
	@$(ARCHIVER) $(NAME) $(FILES_OBJ)

################################################################

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp
	@$(call fancyNameCompilingEcho,$@)
	@mkdir -p $(dir $@)
	@$(COMPILER) $(FLAGS) $(ARGS_INCLUDES) -c $< -o $@

################################################################





################################################################

LIBRARYS = $(NAME)
INCLUDES = include/
ARGUMENTS =

ARGS_LIBRARYS = $(foreach library,$(LIBRARYS),$(library))
ARGS_INCLUDES = $(foreach include,$(INCLUDES),-I$(include))

################################################################
