
NAME := test.exe
#COMPILER := c++ -std=c++11
COMPILER := g++ -g -std=c++11
FLAGS := -Wall -Wextra -Werror

FILES := \
	Container.cpp
#	EntryContainer.cpp
#	Angle3D.cpp
#	CopyConstruct.cpp
#	Graphics.cpp
#	Undex.cpp
#	$(DIR_SRC)/Debug.cpp \
#	../src/Miscellaneous/Container/Behaviour.cpp



test:
	$(MAKE) $(NAME)

tclean:
	rm -f $(NAME)

#$(NAME) : $(FILES) $(LIBRARYS)
$(NAME) : $(FILES)
	@$(call fancyEcho,$(FANCY_NAME),Compiling,$@)
	$(COMPILER) $(FLAGS) $(INCLUDES) -o $(NAME) $(FILES)
#	$(COMPILER) $(FLAGS) $(INCLUDES) -o $(NAME) $(FILES) $(LIBRARYS) $(ARGUMENTS)



include ../fancy.mk
FANCY_NAME := Engine



#LIBRARYS := ..//Engine.a ..//other//OpenGL/openGL.a ..//other//FileManager/FileManager.a
#INCLUDES := -I..//include/ -I..//other//OpenGL/../ -I..//other//FileManager/include
LIBRARYS := ..//Engine.a
INCLUDES := -I..//include/
ARGUMENTS :=

ifeq ($(CheckOS), Windows)
ARGUMENTS := -lglfw3 -lgdi32
endif

ifeq ($(CheckOS), Darwin)
ARGUMENTS := -lglfw
endif
