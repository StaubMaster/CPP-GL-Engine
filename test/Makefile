
NAME := test.exe
COMPILER := c++ -std=c++11
FLAGS := -Wall -Wextra -Werror
#FLAGS += -fsanitize=address	#	ld ... cannot find -lasan: No such file or directory

DIR_SRC := ../src

FILES := \
	Graphics.cpp
#	Undex.cpp
#	$(DIR_SRC)/Debug.cpp \
#	Container.cpp
#	../src/Miscellaneous/Container/Behaviour.cpp

DIR_MISC := ../include/Miscellaneous

HEADERS_CONTAINER := \
	$(DIR_MISC)/Container/Base.hpp \
	$(DIR_MISC)/Container/Dynamic.hpp \
	$(DIR_MISC)/Container/Entry.hpp \
	$(DIR_MISC)/Container/Behaviour.hpp \
	$(DIR_MISC)/EntryContainer/Base.hpp \
	$(DIR_MISC)/EntryContainer/Dynamic.hpp \
	$(DIR_MISC)/EntryContainer/EntryData.hpp \
	$(DIR_MISC)/EntryContainer/Entry.hpp





all:
	$(MAKE) $(NAME)

fclean:
	rm -f $(NAME)

$(NAME) : $(FILES) $(HEADERS_CONTAINER) $(LIBRARYS)
	@$(call fancyEcho,$(FANCY_NAME),Compiling,$@)
	$(COMPILER) $(FLAGS) $(INCLUDES) -o $(NAME) $(FILES) $(LIBRARYS) $(ARGUMENTS)



include ../fancy.mk
FANCY_NAME := Engine



LIBRARYS := ..//Engine.a ..//other//OpenGL/openGL.a ..//other//FileManager/FileManager.a
INCLUDES := -I..//include/ -I..//other//OpenGL/../ -I..//other//FileManager/include
ARGUMENTS :=

ifeq ($(CheckOS), Windows)
ARGUMENTS := -lglfw3 -lgdi32
endif

ifeq ($(CheckOS), Darwin)
ARGUMENTS := -lglfw
endif
