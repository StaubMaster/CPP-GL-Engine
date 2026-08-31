
NAME := Generics.a

COMPILER := g++ -g -std=c++11
FLAGS := -Wall -Wextra -Werror
ARCHIVER := ar -rcs
REMOVER := rm -f

FANCY_NAME := Engine/Generics
include ../fancy.mk

################################################################





################################################################

DIR_SRC := src/
DIR_OBJ := obj/

################################################################

FILES := \
	Generics/Container/Void.cpp

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
