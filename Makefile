
#NAME := Engine.a
#FANCY_NAME := Engine

################################################################

#DIR_SRC := src/
#DIR_OBJ := obj/

################################################################

#FILES := \

################################################################

#LIBRARYS  := $(NAME)  ValueType/ValueType.a Generics/Generics.a FileManager/FileManager.a PolyHedra/PolyHedra.a OpenGL/OpenGL.a Display/Display.a Graphics/Graphics.a User/User.a
#INCLUDES  := include/ ValueType/include     Generics/include    FileManager/include       PolyHedra/inclide     OpenGL/include  Display/include   Graphics/include    User/include
#ARGUMENTS := 

################################################################

OTHER_LIST := Debug/Debug.a ValueType/ValueType.a Generics/Generics.a FileManager/FileManager.a PolyHedra/PolyHedra.a OpenGL/OpenGL.a Display/Display.a Graphics/Graphics.a User/User.a

BASE_DIR := .

#include $(BASE_DIR)/MakefileArchiver.mk
include $(BASE_DIR)/MakefileOther.mk

################################################################
