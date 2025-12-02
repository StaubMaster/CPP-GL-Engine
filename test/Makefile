


NAME := test.exe
COMPILER := c++ -std=c++11
FLAGS := -Wall -Wextra -Werror
#FLAGS += -fsanitize=address	#	ld ... cannot find -lasan: No such file or directory

DIR_SRC = ../src

FILES = \
	$(DIR_SRC)/Debug.cpp \
	Container.cpp
#	../src/Miscellaneous/Container/Behaviour.cpp

DIR_MISC = ../include/Miscellaneous

HEADERS_CONTAINER = \
	$(DIR_MISC)/Container/Base.hpp \
	$(DIR_MISC)/Container/Dynamic.hpp \
	$(DIR_MISC)/Container/Entry.hpp \
	$(DIR_MISC)/Container/Behaviour.hpp \
	$(DIR_MISC)/Container/DebugDefines.hpp \
	$(DIR_MISC)/EntryContainer/Base.hpp \
	$(DIR_MISC)/EntryContainer/Dynamic.hpp \
	$(DIR_MISC)/EntryContainer/EntryData.hpp \
	$(DIR_MISC)/EntryContainer/Entry.hpp \
	$(DIR_MISC)/EntryContainer/DebugDefines.hpp

INCLUDES = -I../include/ -I../other/FileManager/include
LIBRARYS = ../other/FileManager/FileManager.a



all:
	$(MAKE) $(NAME)

fclean:
	rm -f $(NAME)

$(NAME) : $(FILES) $(HEADERS_CONTAINER)
	$(COMPILER) $(FLAGS) $(INCLUDES) $(FILES) $(LIBRARYS) -o $(NAME)


